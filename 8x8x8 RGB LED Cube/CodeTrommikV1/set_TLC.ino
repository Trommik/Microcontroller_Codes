
//***************************************************************************************
// TLC    TLC    TLC   TLC   TLC   TLC    TLC   TLC   TLC   TLC   TLC   TLC    TLC    TLC 
/*
void set_TLC(int channel, int value, byte layer){

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
  if(bitRead(channel, 0)) // if the read of the value is ODD, the start is at a 4
  spibit=4;
  
  spibyte = int(channel*3/2); // This is a simplification of channel * 12 bits / 8 bits
                              // this assignes which byte the 12 bit value starts in

  for(chbit=0; chbit<12; chbit++, spibit++){        // start right at where the update will go
    if(spibit==8){                                  // during the 12 bit cycle, the limit of byte will be reached
      spibyte++;                                    // roll into the next byte
      spibit=0;                                     // reset the bit count in the byte
    }
    
    if(bitRead(value, chbit)){                       // check the value for 1's and 0's
      bitSet(transferbyte[layer-1][spibyte], spibit); // transferbyte is what is written to the TLC
    }else{
      bitClear(transferbyte[layer-1][spibyte], spibit);
    }
  }
}
*/

/*
void clear_TLC(void) { // Clears the TLCs
  for (int i = 0; i < 12*numTLCs*16/8; i++)
    for (int j = 0; j < numLayers; j++)
      transferbyte[j][i] = 0;
}*/

void clear_TLC(void) { // Clears the TLCs
  for (int i = 0; i < 12*numTLCs*16/8; i++)
    transferbyte[i] = 0;
}
// TLC    TLC    TLC   TLC   TLC   TLC    TLC   TLC   TLC   TLC   TLC   TLC    TLC    TLC 
//***************************************************************************************


void tlc(int channel, int value){// TLC to UPDATE TLC to UPDATE TLC to UPDATE TLC to UPDATE

  //Limit check
  if(value>4095){
    value=4095;
  }else if(value<0){
    value=0;
  }
  
   // We need to convert the 12 bit value into an 8 bit BYTE, the SPI can't write 12bits
   
   // We figure out where in all of the bytes to write to, so we don't have to waste time
   // updating everything
   
   // 12 bits into bytes, a start of 12 bits will either at 0 or 4 in a byte
    spibit=0;
    if(bitRead(channel, 0)) // if the read of the value is ODD, the start is at a 4
    spibit=4;
    
    //This is a simplification of channel * 12 bits / 8 bits
    spibyte = int(channel*3/2);// this assignes which byte the 12 bit value starts in
  
    for(chbit=0; chbit<12; chbit++, spibit++){// start right at where the update will go
      if(spibit==8){//during the 12 bit cycle, the limit of byte will be reached
      spibyte++;//roll into the next byte
      spibit=0;//reset the bit count in the byte
      }
    if(bitRead(value, chbit))//check the value for 1's and 0's
    bitSet(transferbyte[spibyte], spibit);//transferbyte is what is written to the TLC
    else
    bitClear(transferbyte[spibyte], spibit);
    }//0-12 bit loop

  }//  END OF TLC WRITE  END OF TLC WRITE  END OF TLC WRITE  END OF TLC WRITE  END OF TLC WRITE
