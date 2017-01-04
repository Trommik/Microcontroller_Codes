/*
 Reads an IR Sensor
 
 Lock at the Datasheet to find the right pinnout for your IR Sensor!!!
 Pin 1 to Pin 11
 Pin 2 to GND
 Pin 3 to Vcc
*/

#include <IRremote.h>

int IRpin = 11;
IRrecv irrecv(IRpin);
decode_results results;

void setup(){
  Serial.begin(9600); // Start Serial
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)){
	Serial.println(results.value, DEC); // Print the Serial 'results.value'
	irrecv.resume(); // Receive the next value
  }
}
