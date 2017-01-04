void ftm1_isr(void) {
  
  // First, we need to clear the timer flag so that the interrupt
  // will happen again. We can take care of the rest of the 
  // interrupt after that.
  
  // Write a 1 to the TOF bit to clear the timer overflow flag
  FTM1_SC |= (1 << 7);

  /*
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
  */
  
  GPIOD_PSOR |= 1<<3; // write BLANK HIGH to reset the 4096 counter in the TLC
  GPIOD_PSOR |= 1<<2; // write XLAT HIGH to latch in data from the last data stream
  
  /*
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
  */
  
  GPIOD_PCOR |= 1<<2; // XLAT can go low now
  GPIOD_PCOR |= 1<<3; // BLANK goes LOW to start the next cycle
  
  
  GPIOD_PSOR |= 1<<5;                // SPI Clock pin to give it the extra count
  GPIOD_PCOR |= 1<<5;                // The data sheet says you need this for some reason?
  

  /*
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
  */
  SPI1.begin(); // start the SPI back up
    
  for(SINData=12*numTLCs*16/8; SINData>=0; SINData--) // send the data out!       //for 1tlc = 23 ; 2tlc = 47
    SPI1.transfer(transferbyte[SINData]); // The SPI port only understands bytes-8 bits wide
    
  /*
  SPI.transfer(B11111111);
  SPI.transfer(B11110000);
  SPI.transfer(B00000000);
  SPI.transfer(B00000000);
  SPI.transfer(B00001111);
  SPI.transfer(B11111111);
  SPI.transfer(B00000000);
  SPI.transfer(B00000000);
  SPI.transfer(B00000000);
  SPI.transfer(B11111111);
  SPI.transfer(B11110000);
  SPI.transfer(B00000000);
  SPI.transfer(B00000000);
  SPI.transfer(B00001111);
  SPI.transfer(B11111111);
  SPI.transfer(B00000000);
  SPI.transfer(B00000000);
  SPI.transfer(B00000000);
  SPI.transfer(B11111111);
  SPI.transfer(B11110000);
  SPI.transfer(B00000000);
  SPI.transfer(B00000000);
  SPI.transfer(B00001111);
  SPI.transfer(B11111111);
  
  SPI.transfer(B00000000);
  SPI.transfer(B00000000);
  SPI.transfer(B00000000);
  SPI.transfer(B00001111);
  SPI.transfer(B11111111);
  SPI.transfer(B00000000);
  SPI.transfer(B00000000);
  SPI.transfer(B00000000);
  SPI.transfer(B11111111);
  SPI.transfer(B11110000);
  SPI.transfer(B00000000);
  SPI.transfer(B00000000);
  SPI.transfer(B00001111);
  SPI.transfer(B11111111);
  SPI.transfer(B00000000);
  SPI.transfer(B00000000);
  SPI.transfer(B00000000);
  SPI.transfer(B11111111);
  SPI.transfer(B11110000);
  SPI.transfer(B00000000);
  SPI.transfer(B00000000);
  SPI.transfer(B00001111);
  SPI.transfer(B11111111);
  */
  SPI1.end(); // End the SPI because the Teensy Crashes if you don't add this
  
  // The SPI port only understands bytes-8 bits wide
  // The TLC needs 12 bits for each channel, so 12bits times 32 channels gives 384 bits
  // 384/8=48 bytes, 0-47
  
  //layer += 64; 
  // count the layer up.
  // 0+4(layers)*64 = 256 but 1 byte can only store 255 so it starts again from 0   

  GPIOD_PTOR |= 1<<1; // debug
}
