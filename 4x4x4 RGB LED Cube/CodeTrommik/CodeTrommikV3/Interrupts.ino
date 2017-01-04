// INTERRUPTS  INTERRUPTS   INTERRUPTS   INTERRUPTS   INTERRUPTS   INTERRUPTS  INTERRUPTS  

ISR(TIMER1_OVF_vect){}  // Over Limit Flag Interrupt  you need this even if you don't use it
ISR(TIMER1_COMPB_vect){}// Compare B - Not Used
ISR(TIMER1_COMPA_vect){ // Interrupt to count 4096 Pulses on GSLCK //needs 228us to execute
  
  //PORTD |= 1<<4;//debug
  
  switch(layer){                               //Set layer off
    case 0:  //layer 4 == LOW
      PORTB &= ~(1<<0);
    break;
    case 64: //layer 1 == LOW
      PORTD &= ~(1<<5);
    break;
    case 128://layer 2 == LOW
      PORTD &= ~(1<<6);
    break;
    case 192://layer 3 == LOW
      PORTD &= ~(1<<7);
    break;
  }                                            //Set layer off

  PORTB |= 1<<2; // write blank HIGH to reset the 4096 counter in the TLC
  PORTB |= 1<<1; // write XLAT HIGH to latch in data from the last data stream

  switch(layer){                               //Set layer  on
    case 0:  //layer 1 == HIGH
      PORTD |= 1<<5;
    break;
    case 64: //layer 2 == HIGH
      PORTD |= 1<<6;
    break;
    case 128://layer 3 == HIGH
      PORTD |= 1<<7;
    break;
    case 192://layer 4 == HIGH
      PORTB |= 1<<0;
    break;
  }                                            //Set layer  on

  PORTB &= ~(1<<1); // XLAT can go low now
  PORTB &= ~(1<<2); // Blank goes LOW to start the next cycle

  //PORTD &= ~(1<<4);//debug
  //PORTD |= 1<<4;//debug
  
  SPI.end();        // end the SPI so we can write to the clock pin
  PORTB |= 1<<5;    // SPI Clock pin to give it the extra count
  PORTB &= ~(1<<5); // The data sheet says you need this for some reason?
  SPI.begin();      // start the SPI back up

  switch(layer){                               //Set layer  on
    case 0:  //layer 1 == HIGH --> Send Data layer 2 out!
      for(SINData=12*numTLC*16/8-1; SINData>=0; SINData--)
      SPI.transfer(transferbyte[1][SINData]);
    break;
    case 64: //layer 2 == HIGH --> Send Data layer 3 out!
      for(SINData=12*numTLC*16/8-1; SINData>=0; SINData--)
      SPI.transfer(transferbyte[2][SINData]);
    break;
    case 128://layer 3 == HIGH --> Send Data layer 4 out!
      for(SINData=12*numTLC*16/8-1; SINData>=0; SINData--)
      SPI.transfer(transferbyte[3][SINData]);
    break;
    case 192://layer 4 == HIGH --> Send Data layer 1 out!
      for(SINData=12*numTLC*16/8-1; SINData>=0; SINData--)
      SPI.transfer(transferbyte[0][SINData]);
    break;
  }  
  // The SPI port only understands bytes-8 bits wide
  // The TLC needs 12 bits for each channel, so 12bits times 32 channels gives 384 bits
  // 384/8=48 bytes, 0-47
  
  layer += 64; 
  // count the layer up.
  // 0+4(layers)*64 = 256 but 1 byte can only store 255 so it starts again from 0   
  //PORTD &= ~(1<<4);//debug
}

// INTERRUPTS  INTERRUPTS   INTERRUPTS   INTERRUPTS   INTERRUPTS   INTERRUPTS  INTERRUPTS  
