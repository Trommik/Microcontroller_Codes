#include <SPI.h> // Serial Peripheral Interface Library

const int numTLC = 3;


byte ch=0, chbit=0, spibit=0, spibyte=0; // variables used by tlc sub routine
int SINData;                             // variable used to shift data to the TLC
byte transferbyte[4][12*numTLC*16/8];    // bytes that are sent out to the tlc5940 via SPI //for each layer
                                         // 48 because 16 channels @ 12bits gives 384bits, 384/8 = 48 bytes, 12 bit to 8 bit conversion

int i, j, k, l, m, n; // misc variables


volatile byte layer = 0;

//123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234#
//--0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000#
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------#

const char tetrahexagesimal[] = {"0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_-"};

String inputString = "";        // a string to hold incoming data
boolean stringComplete = false; // whether the string is complete


//****************************************************************************************
// SETUP    SETUP   SETUP   SETUP   SETUP   SETUP   SETUP   SETUP   SETUP   SETUP    SETUP
  
void setup() {
  
  Serial.begin(19200); // initialize serial
  Serial.println("baud = 19200");
  inputString.reserve(400); // reserve 400 bytes(characters) for the inputString
  
  
  pinMode(9,OUTPUT);// XLAT // pin 9
  pinMode(3,OUTPUT);// OSC2B GSCLK // pin 3

  pinMode(4,OUTPUT);// PORTD bit 4 //status 

  pinMode(5,OUTPUT);// PORTD bit 5 //LAYER 1
  pinMode(6,OUTPUT);// PORTD bit 6 //LAYER 2
  pinMode(7,OUTPUT);// PORTD bit 7 //LAYER 3
  pinMode(8,OUTPUT);// PORTB bit 0 //LAYER 4
  
  digitalWrite(6,LOW);// All Layers OFF
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(5,LOW);
  
  pinMode(11,OUTPUT);// MOSI DATA // pin 11
  pinMode(13,OUTPUT);// SPI Clock // pin 13
  
  // Set up the SPI
  SPI.setBitOrder(MSBFIRST);// Most Significant Bit First
  SPI.setDataMode(SPI_MODE0);// Mode 0 Rising edge of data, keep clock low
  SPI.setClockDivider(SPI_CLOCK_DIV2);// Run the data in at 16MHz/2 - 8MHz
  

  cli();// STOP INTERRUPTS
//#################################################################################TIMER 1 START
  TCCR1A=B00000000;
  // Timer 1 doesn't toggle anything, used for counting
  // Timer 1 prescaler set to Fclk/256
  // Why? We need to count 4096 pulses out of Timer 2 - pin 5
  // 1 MHz = 1 pulse every 1us - - 4096 pulses would need 4096us
  // Timer 1 runs at 16MHz/1024=244,140625kHz, we need a match at every 4096us
  // Basically, I can get an interrupt to get called every 4096us, so...
  // I need to run Timer 2 @ 1MHz for 4096us to get 4096 pulses
  // I can't count those pulses directy (too fast) , so
  // The counter starts at 0, so we'll set it to 63 to get an interrupt after 4096us
  
  TCCR1B=B00001101;
  // Mode=CTC with OSCR1A = TOP and 1024 as the prescaler
  // Mask set up, will call ISR (Inerrupt Service Routine) for Compare match on A
  
  TIMSK1=B00000010;
  // These are the match values for the counters
  // 0 here means it will match on one cycle of the clock/prescaler
  
  OCR1A= 63;
  // to get our 512us Interrupt
//#################################################################################TIMER 1 ENDE

//#################################################################################TIMER 2 START
  TCCR2A=B00010010;
  // Timer 2 set to Compare Mode Toggling pin 5 @ 1MHz, Arduino Digital 3
  // TIMER 2 IS GSCLCK
  
  TCCR2B=B00000010;
  // Timer 2 prescaler set to 8, 16/8=2 MHz, but toggles pin 5 every other cycle, 1MHz
//#################################################################################TIMER 2 ENDE  
  sei();// START INTERRUPTS

  clear_TLC();
  
  pinMode(10, OUTPUT); // BLANK  // pin 10
                       // We set this pin up here, so it remains in a high impedance
                       // state throughout the setup, otherwise the LEDs go crazy!  even if you write this HIGH

  randomSeed(analogRead(5));

}

// END OF SETUP   END OF SETUP   END OF SETUP   END OF SETUP   END OF SETUP   END OF SETUP
//****************************************************************************************

//****************************************************************************************
// MAIN LOOP    MAIN LOOP    MAIN LOOP    MAIN LOOP    MAIN LOOP    MAIN LOOP    MAIN LOOP

void loop() {
  
  serialEvent(); // call the SERIAL function
  
  if (stringComplete){
    //Serial.println(inputString);
    
    convertString(); // Convert the string into an array
    
    inputString = ""; // clear the string and reset the flag
    stringComplete = false;
  }  
  
  //tlc(0,4095,1);
  
}

// END OF LOOP    END OF LOOP    END OF LOOP    END OF LOOP    END OF LOOP    END OF LOOP
//***************************************************************************************

//***************************************************************************************
// TLC    TLC    TLC   TLC   TLC   TLC    TLC   TLC   TLC   TLC   TLC   TLC    TLC    TLC 

void tlc(int channel, int value, byte layer){

  // Limit check
  if(value>4095)
  value=4095;
  if(value<0)
  value=0;
  
    // We need to convert the 12 bit value into an 8 bit BYTE, the SPI can't write 12bits
   
    // We figure out where in all of the bytes to write to, so we don't have to waste time
    // updating everything
   
    // 12 bits into bytes, a start of 12 bits will either at 0 or 4 in a byte
    spibit=0;
    if(bitRead(channel, 0))// if the read of the value is ODD, the start is at a 4
    spibit=4;
    
    // This is a simplification of channel * 12 bits / 8 bits
    spibyte = int(channel*3/2);// this assignes which byte the 12 bit value starts in
  
    for(chbit=0; chbit<12; chbit++, spibit++){        // start right at where the update will go
      if(spibit==8){                                  // during the 12 bit cycle, the limit of byte will be reached
        spibyte++;                                    // roll into the next byte
        spibit=0;                                     // reset the bit count in the byte
      }
      if(bitRead(value, chbit))                       // check the value for 1's and 0's
      bitSet(transferbyte[layer-1][spibyte], spibit); // transferbyte is what is written to the TLC
      else
      bitClear(transferbyte[layer-1][spibyte], spibit);
    }
    
}

// TLC    TLC    TLC   TLC   TLC   TLC    TLC   TLC   TLC   TLC   TLC   TLC    TLC    TLC 
//***************************************************************************************
