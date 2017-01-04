#include <SPI.h> // Serial Peripheral Interface Library

const byte numLayers = 8; // Number of Layers the cube have

const byte numTLCs = 1;   // Number of TLC connected 
                          // e.g. we have 8 Leds x 8 Leds = 64 Leds so 64 Leds x 3 Colors = 192 PWM Outputs
                          // Every TLC has 16 Outputs so 192 Outputs / 16 TLC Outputs = 12 TLCs

byte ch=0, chbit=0, spibit=0, spibyte=0;       // variables used by tlc sub routine
int SINData;                                   // variable used to shift data to the TLC
byte transferbyte[12*numTLCs*16/8]; // bytes that are sent out to the tlc5940 via SPI //for each layer
                                               // 48 because 16 channels @ 12bits gives 384bits, 384/8 = 48 bytes, 12 bit to 8 bit conversion


//****************************************************************************************
// SETUP    SETUP   SETUP   SETUP   SETUP   SETUP   SETUP   SETUP   SETUP   SETUP    SETUP
void setup() {
  Serial.begin(9600); // initialize serial
  Serial.println("baud = 9600");

  pinMode(14,OUTPUT); // DEBUG

  pinMode(15,OUTPUT); // pin 15 -- layer 1
  pinMode(22,OUTPUT); // pin 22 -- layer 2
  pinMode(23,OUTPUT); // pin 23 -- layer 3
  pinMode( 9,OUTPUT); // pin  9 -- layer 4
  pinMode(10,OUTPUT); // pin 10 -- layer 5
  pinMode(13,OUTPUT); // pin 13 -- layer 6
  pinMode(11,OUTPUT); // pin 11 -- layer 7
  pinMode(12,OUTPUT); // pin 12 -- layer 8
  
  /*
   * set all pins on PORTD to OUTPUT
   * PTC0 = TeensyLC pin #15 -> Layer 1
   * PTC1 = TeensyLC pin #22 -> Layer 2
   * PTC2 = TeensyLC pin #23 -> Layer 3
   * PTC3 = TeensyLC pin # 9 -> Layer 4
   * PTC4 = TeensyLC pin #10 -> Layer 5
   * PTC5 = TeensyLC pin #13 -> Layer 6
   * PTC6 = TeensyLC pin #11 -> Layer 7
   * PTC7 = TeensyLC pin #12 -> Layer 8
   */
  
  pinMode( 8,OUTPUT); // BLANK       // pin  8
  pinMode( 7,OUTPUT); // XLAT        // pin  7
  pinMode( 2,OUTPUT); // GSCLK       // pin  2

  pinMode(21,OUTPUT); // MOSI DATA   // pin 21
  pinMode( 5,OUTPUT); // MISO DATA   // pin  5
  pinMode(20,OUTPUT); // SPI Clock   // pin 20

  cli();// STOP INTERRUPTS
//#################################################################################TIMER 1 START

  // This Timer is used to generate the GSCLK for the TLC

  // We use a Prescaler of 4 and set the overflow value to 0 to get a 6MHz Clock
  // The Teensy runs with 48MHz so 48MHz / 4(prescaler) = 12MHz
  // so every 12MHz the pin gets toggled so we get a Output off 6MHz

  // The order of setting the TPMx_SC, TPMx_CNT, and TPMx_MOD
  // seems to matter. You must clear _SC, set _CNT to 0, set _MOD
  // to the desired value, then you can set the bit fields in _SC.
  
  // Clear TPM0_SC register (p. 572)
  FTM0_SC = 0;
  
  // Reset the TPM0_CNT counter (p. 574)
  FTM0_CNT = 0;
  
  // Set overflow value (modulo) (p. 574)
  FTM0_MOD = 0;
  
  // Set TPM0_SC register (p. 572)
  // Bits | Va1ue | Description
  //  8   |    0  | DMA: Disable DMA
  //  7   |    1  | TOF: Clear Timer Overflow Flag
  //  6   |    1  | TOIE: Enable Timer Overflow Interrupt
  //  5   |    0  | CPWMS: TPM in up counting mode
  // 4-3  |   01  | CMOD: Counter incrememnts every TPM clock
  // 2-0  |  010  | PS: Prescaler = 4
  FTM0_SC = 0b011001010;
  
  // Set TPM0_C0SC register (Teensy LC - pin 14) (p. 575)
  // As per the note on p. 575, we must disable the channel
  // first before switching channel modes. We also introduce
  // a magical 1 us delay to allow the new value to take.
  // Bits | Va1ue | Description
  //  7   |    0  | CHF: Do nothing
  //  6   |    1  | CHIE: Enable channel Interrupt 
  // 5-4  |   01  | MSA/MSB: Output Compare Mode
  // 3-2  |   01  | ELSA/ELSB: Toggle Output on Match
  //  1   |    0  | Reserved
  //  0   |    0  | DMA: Disable DMA
  FTM0_C0SC = 0;
  delayMicroseconds(1);
  FTM0_C0SC = 0b01010100;
  
  // Set PORTC_PCR1 register (Teensy LC - pin 14) (p. 199)
  // Bits | Value | Description
  // 10-8 |   100 | MUX: Alt 4 attach to TPM0_CH0 (p. 179)
  //  7   |     0 | Reserved
  //  6   |     0 | DSE: Low drive strength
  //  5   |     0 | Reserved
  //  4   |     0 | PFE: Disable input filter
  //  3   |     0 | Reserved
  //  2   |     0 | SRE: Fast slew rate if output
  //  1   |     0 | PE: Disable pull-up/down
  //  0   |     0 | PS: Internal pull-down
  PORTD_PCR1 = 0b10000000000; 

  // Nested Vector Interrupt Controller (NVIC) (p. 57)
  // Also: Chapter 4.2 of the Generic User Guide
  // We use that to set up our interrupt vector and priority.
 
  // Set the urgency of the interrupt. Lower numbers mean higher
  // urgency (they will happen first). Acceptable values are
  // 0, 64, 128, and 192. Default is 128. We set the priority
  // (2nd byte) in the register for the FTM0 interrupt to 192.
  NVIC_SET_PRIORITY(IRQ_FTM0, 192); // not sure which values are good
  
  // Enable the interrupt vector. In this case, we want to execute
  // the ISR (named "ftm0_isr()" for Teensy) every time TPM0
  // overflows.
  //NVIC_ENABLE_IRQ(IRQ_FTM0);
  
//#################################################################################TIMER 1 END

//#################################################################################TIMER 2 START

  // This Timer is used to count the 4095 Pulses of the TLC

  // We use a Prescaler of 8 to get a 6MHz Clock
  // The Teensy runs with 48MHz so 48MHz / 8(prescaler) = 6MHz 
  // The Count register is set to 4096 so when the TLC got 4096 Pulses from GSCLK, 
  // we will reset him and latch the new data in
  
  // The order of setting the TPMx_SC, TPMx_CNT, and TPMx_MOD
  // seems to matter. You must clear _SC, set _CNT to 0, set _MOD
  // to the desired value, then you can set the bit fields in _SC.
  
  // Clear TPM1_SC register (p. 572)
  FTM1_SC = 0;
  
  // Reset the TPM1_CNT counter (p. 574)
  FTM1_CNT = 0;
  
  // Set overflow value (modulo) (p.574)
  FTM1_MOD = 4095;
  
  // Set TPM1_SC register (p. 572)
  // Bits | Va1ue | Description
  //  8   |    0  | DMA: Disable DMA
  //  7   |    1  | TOF: Clear Timer Overflow Flag
  //  6   |    1  | TOIE: Enable Timer Overflow Interrupt
  //  5   |    0  | CPWMS: TPM in up counting mode
  // 4-3  |   01  | CMOD: Counter incrememnts every TPM clock
  // 2-0  |  011  | PS: Prescaler = 8
  FTM1_SC = 0b011001011;
  
  // Nested Vector Interrupt Controller (NVIC) (p. 57)
  // Also: Chapter 4.2 of the Generic User Guide
  // We use that to set up our interrupt vector and priority.
 
  // Set the urgency of the interrupt. Lower numbers mean higher
  // urgency (they will happen first). Acceptable values are
  // 0, 64, 128, and 192. Default is 128. We set the priority
  // (2nd byte) in the register for the FTM1 interrupt to 128.
  NVIC_SET_PRIORITY(IRQ_FTM1, 128);
  
  // Enable the interrupt vector. In this case, we want to execute
  // the ISR (named "ftm1_isr()" for Teensy) every time TPM1 
  // overflows.
  NVIC_ENABLE_IRQ(IRQ_FTM1);
  
//#################################################################################TIMER 2 END  
  sei();// START INTERRUPTS

  clear_TLC();

  //pinMode(10, OUTPUT); // BLANK      // pin 10
                       // We set this pin up here, so it remains in a high impedance
                       // state throughout the setup, otherwise the LEDs go crazy!  even if you write this HIGH
                       
  SPI1.setMISO(5);
  SPI1.setMOSI(21);

  SPI1.beginTransaction(SPISettings(24000000, MSBFIRST, SPI_MODE0));

  /*
  SPI1.setBitOrder(MSBFIRST);           // Most Significant Bit First
  SPI1.setDataMode(SPI_MODE0);          // Mode 0 Rising edge of data, keep clock low
  SPI1.setClockDivider(SPI_CLOCK_DIV2); // Run the data in at 12MHz // Teensy LC
  */
}
// END OF SETUP   END OF SETUP   END OF SETUP   END OF SETUP   END OF SETUP   END OF SETUP
//****************************************************************************************


//****************************************************************************************
// MAIN LOOP    MAIN LOOP    MAIN LOOP    MAIN LOOP    MAIN LOOP    MAIN LOOP    MAIN LOOP

void loop() {
  for(int i = 0; i < 16*numTLCs; i+=3){
    tlc(i,1000);
  }
  delay(1000);
  clear_TLC();
  
  for(int i = 0; i < 16*numTLCs; i+=3){
    tlc(i+1,1000);
  }
  delay(1000);
  clear_TLC();
  
  for(int i = 0; i < 16*numTLCs; i+=3){
    tlc(i+2,1000);
  }
  delay(1000);
  clear_TLC();
}

// END OF LOOP    END OF LOOP    END OF LOOP    END OF LOOP    END OF LOOP    END OF LOOP
//***************************************************************************************
