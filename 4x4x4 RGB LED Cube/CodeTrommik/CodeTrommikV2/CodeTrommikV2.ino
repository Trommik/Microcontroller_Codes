#include "Tlc5940.h"               // don't forget to download the Tlc5940 lib from arduino playground and place it in you lib folder ( http://tlc5940arduino.googlecode.com/files/Tlc5940_r014_2.zip )
#include "digitalIOPerformance.h"  // don't forget to download the digitalIOPerformance lib from arduino playground and place it in you lib folder ( https://github.com/projectgus/digitalIOPerformance )

const int layer[4] = {5,6,7,8};

const int red[16] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15};//TLC1 red
const int grn[16] = {16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31};//TLC2 green
const int blu[16] = {32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47};//TLC3 blue

int redv[64] = {
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,                      //layer1
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,                      //layer2
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,                      //layer3
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//TLC1 red   values  //layer4
int grnv[64] = {
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,                      //layer1
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,                      //layer2
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,                      //layer3
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//TLC2 green values  //layer4
int bluv[64] = {
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,                      //layer1
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,                      //layer2
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,                      //layer3
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//TLC3 blue  values  //layer4
    

int bright = 4095;

const int tlc_update_time = 1000;


//

char incomingByte = 0;   // for incoming serial data

String str = "";

String str_r1 = "255,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000";
String str_r2 = "000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000";
String str_r3 = "000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000";
String str_r4 = "000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000";

String str_g1 = "000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000";
String str_g2 = "000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000";
String str_g3 = "000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000";
String str_g4 = "000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000";

String str_b1 = "000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000";
String str_b2 = "000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000";
String str_b3 = "000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000";
String str_b4 = "000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000";

int _ser = 1;

//

void setup() {
  for (int pin=0; pin<4; pin++) {
    pinMode( layer[pin], OUTPUT );
  }

  Tlc.init();
  
  randomSeed(analogRead(5));
  Serial.begin(9600);
}

void loop() {

  Serial_get_String();
  Strings_to_arrays();

  show_layer(1,0);
  show_layer(2,0);
  show_layer(3,0);
  show_layer(4,0);
/*
   if(analogRead(1) > 500){
     bright = map(analogRead(0),0,1023,0,4095);
     Random_led(bright);
   }
   if(analogRead(2) > 500){
   }
   if(analogRead(3) > 500){
   }
   if(analogRead(4) > 500){
   }
*/

}
