//#include "TimerOne.h"
#include "Tlc5940.h"               // don't forget to download the Tlc5940 lib from arduino playground and place it in you lib folder ( http://tlc5940arduino.googlecode.com/files/Tlc5940_r014_2.zip )
#include "digitalIOPerformance.h"  // don't forget to download the digitalIOPerformance lib from arduino playground and place it in you lib folder ( https://github.com/projectgus/digitalIOPerformance )

int layer_update = 1;

const int layer[4] = {5,6,7,8};

int bytes_get = 0;
int _ser = 1;

String zahl = "";

String str = "";
char incomingByte;

int string_lenght = 64*4*3-1;//16values * 4 layers * 3 farben - 1komma (letztes komma) 

unsigned long Start_millis;

unsigned long previousMillis = 0;       

int show_layers = 1;

int red[64] = {4095,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4095,                      //layer1
               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,                      //layer2
               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,                      //layer3
               4095,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4095};//TLC1 red   values  //layer4
int grn[64] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,                      //layer1
               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,                      //layer2
               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,                      //layer3
               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//TLC2 green values  //layer4
int blu[64] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,                      //layer1
               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,                      //layer2
               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,                      //layer3
               0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//TLC3 blue  values  //layer4


void setup() {
  for (int pin=0; pin<4; pin++) {
    pinMode( layer[pin], OUTPUT );
    digitalWrite(layer[pin],LOW);
  }

  Tlc.attachInterrupt(update_layers);
  
  Tlc.init();
  
  Serial.begin(9600);
  Serial.println("ready");
  
}


void loop(){
  
  Serial_get();

  //update_layers();

}


