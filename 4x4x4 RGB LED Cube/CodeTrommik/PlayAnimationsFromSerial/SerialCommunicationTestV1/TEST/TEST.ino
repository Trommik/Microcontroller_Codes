/*
  Serial Event example

 When new serial data arrives, this sketch adds it to a String.
 When a newline is received, the loop prints the string and
 clears it.

 A good test for this is to try it with a GPS receiver
 that sends out NMEA 0183 sentences.

 Created 9 May 2011
 by Tom Igoe
/*

 123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234#

 384 charecters = 4x4x4x3x2 charecters 
 
 4x4x4 -> LEDs in Cube
 x3 -> 3 Colors (RGB)
 x2 -> Values from 0-4095 if you convert the values to tetrahexagesimal you get 2 characters 
 = 384 charecters to send to the cube per frame
 
*/

const char tetrahexagesimal[] = {"0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_-"};

String inputString = "";        // a string to hold incoming data
boolean stringComplete = false; // whether the string is complete

int i,j,k,l;

void setup() {
  
  Serial.begin(9600);       // initialize serial
  inputString.reserve(400); // reserve 400 bytes(characters) for the inputString

}

void loop() {
  serialEvent(); // call the function
  
  if (stringComplete){
    Serial.println(inputString);
    
    convertString(); // Convert the string into an array
    
    inputString = ""; // clear the string and reset the flag
    stringComplete = false;
  }  
}

/*
  SerialEvent occurs whenever a new data comes in the
  hardware serial RX.  This routine is run between each
  time loop() runs, so using delay inside loop can delay
  response.  Multiple bytes of data may be available.
*/

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
    
    // tlc(int channel, int value, byte layer);
    tlc(k,zahl1 + zahl2*64,l+1);
    
    k++;
    if(k >= 16){
      k = 0;
      l ++;
    }
    if(l > 4){
      l = 0;
    }
    
    /* //DEBUG
    Serial.print("k: ");
    Serial.println(k);
    Serial.print("l: ");
    Serial.println(l);
    */
    
    /* //DEBUG
    int zahl_dec = zahl1 + zahl2*64; 
   
    Serial.print("DEC = ");
    Serial.print(zahl_dec);
    Serial.print("   THG = ");
    Serial.print(zahl_thg[0]);
    Serial.println(zahl_thg[1]);
    */
  }
}


