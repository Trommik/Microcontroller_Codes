void serialEvent() {
  while (Serial.available()){
    char inChar = (char)Serial.read();// get the new byte
    
    if (inChar == '#'){ // if the incoming character is a #, set a flag
      
      if (inputString.length() == 384){ // checks if all data arrived
        stringComplete = true; // so the main loop can do something about it
      }else{
        Serial.println("ERROR"); // print an error if less or more data arrived
        inputString = ""; // clear the string
      }
      
    }else{
      inputString += inChar; // add it to the inputString
    }    
  }
}


void convertString() {
//PORTD |= 1<<4;//debug

byte channel = 0;
byte layr = 0;
byte rgb = 0;
  
  for(i = 0; i <= 382; i += 2){
    char zahl_thg[3];
    int zahl1;
    int zahl2;

    inputString.substring(0+i,2+i).toCharArray(zahl_thg,3); // takes the input string and feds the 2 first characters into the char zahl  

    for(j = 0; j < sizeof(tetrahexagesimal)-1; j++){
      if(zahl_thg[1] == tetrahexagesimal[j]){
        zahl1 = j;
      }
      if(zahl_thg[0] == tetrahexagesimal[j]){
        zahl2 = j;
      }
    }
    
//SET TLC
    int zahl_dec = zahl1 + zahl2*64; 

    spibit=0;
    if(bitRead((channel+rgb), 0))// if the read of the value is ODD, the start is at a 4
    spibit=4;
    
    // This is a simplification of channel * 12 bits / 8 bits
    spibyte = int((channel+rgb)*3/2);// this assignes which byte the 12 bit value starts in
  
    for(chbit=0; chbit<12; chbit++, spibit++){        // start right at where the update will go
      if(spibit==8){                                  // during the 12 bit cycle, the limit of byte will be reached
        spibyte++;                                    // roll into the next byte
        spibit=0;                                     // reset the bit count in the byte
      }
      if(bitRead(zahl_dec, chbit))                       // check the value for 1's and 0's
      bitSet(transferbyte[layr][spibyte], spibit); // transferbyte is what is written to the TLC
      else
      bitClear(transferbyte[layr][spibyte], spibit);
    }
//SET TLC
    
    /*
     //DEBUG
    Serial.print("k: ");
    Serial.print(channel+rgb);
    Serial.print("    l: ");
    Serial.println(layr);
    
    
     //DEBUG
    Serial.print("DEC = ");
    Serial.print(zahl_dec);
    Serial.print("   THG = ");
    Serial.print(zahl_thg[0]);
    Serial.println(zahl_thg[1]);
    */
    
    channel++;
    
    if(channel > 15){
      channel = 0;
      layr ++;
    }
    if(layr > 3){
      layr = 0;
      rgb += 16;
    }
    if(rgb > 32){
      rgb = 0;
    }
    
  }
  
//PORTD &= ~(1<<4);//debug
}

