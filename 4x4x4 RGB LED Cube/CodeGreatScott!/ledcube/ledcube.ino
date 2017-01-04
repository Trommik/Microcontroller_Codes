//Build your own RGB LED Cube v2 Code
//http://www.youtube.com/user/greatscottlab 

#include "Tlc5940.h"               // don't forget to download the Tlc5940 lib from arduino playground and place it in you lib folder ( http://tlc5940arduino.googlecode.com/files/Tlc5940_r014_2.zip )
#include "digitalIOPerformance.h"  // don't forget to download the digitalIOPerformance lib from arduino playground and place it in you lib folder ( https://github.com/projectgus/digitalIOPerformance )
#define LayerOne 5                // Gate of 1.MOSFET which connects to Layer "a" (anodes of all Strings in Layer "a")
#define LayerTwo 6                // Gate of 2.MOSFET which connects to Layer "b" (anodes of all StringS in Layer "b")
#define LayerThree 7              // Gate of 3.MOSFET which connects to Layer "c" (anodes of all Strings in Layer "c")
#define LayerFour 8               // Gate of 4.MOSFET which connects to Layer "d" (anodes of all Strings in Layer "d")
#define Potentiometer 18           // 10k potentiometer to set the brightness of the cube


                   
int LayerDuration = 4000;   // ON time of each Layer in microseconds      
int layer = 0;              // starting with Layer 0 (Layer "a")
unsigned long oldMicros = 0;// starting counter to decide when if(micros()>=oldMicros)is true to change active layer, count++1, MatrixUpdate(); don't know what micros() is? Look here: http://arduino.cc/de/Reference/Micros#.UygzAIWmWd4
int count=0;                // starting counter which is included in if() statement to change the shown picture, not necessary when using a static picture
int stretch=2;             // set timer for the change of the shown picture, if animation should move really fast then low stretch value, if animation should move really slow than big stretch value
int bright;                 // set brightness for all Strings(4095=20mA, 0=0ma, 1000=4.88mA,....). If you want individually brightness for a String you have to change the value in tab "function"
int p;                      // used in functions for-loop
int q;                      // used in functions for-loop
int x;                      // used in functions for-loop, does not work yet
int r1;int r2;int r3;int r4;// variables for RED colour values between (0-4095)
int g1;int g2;int g3;int g4;// variables for GREEN colour values between (0-4095)
int b1;int b2;int b3;int b4;// variables for BLUE colour values between (0-4095)
int c1;                     // used in functions as counter


void setup()    
{
  pinMode(LayerOne, OUTPUT);                   // declare arduino nano pin A0(LayerOne) as OUTPUT
  pinMode(LayerTwo, OUTPUT);                   // declare arduino nano pin A1(LayerTwo) as OUTPUT
  pinMode(LayerThree, OUTPUT);                 // declare arduino nano pin A2(LayerThree) as OUTPUT
  pinMode(LayerFour, OUTPUT);                      // declare arduino nano pin A3(LayerFour) as OUTPUT
  pinMode(Potentiometer, INPUT);               // declare arduino nano pin A4(Potentiometer) as INPUT for brightness value
  Tlc.init();                                  // configures the arduino to use the tlc5940, be sure to connect the arduino correctly to the tlc 
  c1=r1=r2=r3=r4=g1=g2=g3=g4=b1=b2=b3=b4=p=q=0;//all int start with value 0
 
 
 /*          ARDUINO                                         TLC5940                            
              13|-> SCLK (pin 25)           OUT1 String "B" |1     28| OUT0 String "A"
              12|                           OUT2 String "C" |2     27|-> GND (VPRG)
              11|-> SIN (pin 26)            OUT3 String "D" |3     26|-> SIN (pin 11)
              10|-> BLANK (pin 23)          OUT4 String "E" |4     25|-> SCLK (pin 13)
               9|-> XLAT (pin 24)           OUT5 String "F" |5     24|-> XLAT (pin 9)
               8|                           OUT6 String "G" |6     23|-> BLANK (pin 10)
               7|                           OUT7 String "H" |7     22|-> GND
               6|                           OUT8 String "I" |8     21|-> VCC (+5V)
               5|                           OUT9 String "J" |9     20|-> 2K Resistor -> GND  
               4|                          OUT10 String "K" |10    19|-> +5V (DCPRG)
               3|-> GSCLK (pin 18)         OUT11 String "L" |11    18|-> GSCLK (pin 3)
               2|                          OUT12 String "M" |12    17|-> SOUT (only used when you want to use more than one tlc5940)
               1|                          OUT13 String "N" |13    16|-> XERR (can be used as error report, but not necessary)
               0|                          OUT14 String "O" |14    15| OUT15 String "P"       */
  }

void loop(){
  
  if(micros()>= oldMicros){                                           // waits until LayerDuration is reached and than goes through cycle
    oldMicros=micros()+LayerDuration;                                 // updates oldMicros value by adding the micros() with LayerDuration
   //if(count==9*stretch){reset();randomRED(bright);randomGREEN(bright);randomBLUE(bright);}    
   //if(count==0){reset();allred(bright);}                           
   
   //if(count==stretch){reset();allgreen(bright);}                         
   //if(count==2*stretch){reset();allblue(bright);} 
   //if(count==3*stretch){reset();allred(bright);allgreen(bright);}    
   //if(count==4*stretch){reset();allred(bright);allblue(bright);}     
   //if(count==5*stretch){reset();allgreen(bright);allblue(bright);}        
   if(count==1){reset();colorchange();}                                  
   //if(count==7*stretch){reset();}                                 
   //if(count==1){reset();wall(bright);}                                  
   CubeUpdate(layer);                                                 // sets the values for the tlc5940 Outputs and puts all MOSFET Gates HIGH (not active) except for one MOSFET Low (active) -->this layer is ON, also look under tab "function"  
   layer++;                                                           // layer counter +1, so MatrixUpdate(layer) will affect the next layer during the next if() cycle 
   count++;                                                           // count counter +1, to change the picture in next if() cycle
   bright=1023;                                  // use analogRead to set value for int bright from 0-1023
   bright=map(bright,0,1023,0,4095);                                  // convert 10 bit value(0-1023) from analogRead into 12 bit value(0-4095) for TLC5940 
   if(layer==5){
    layer = 1;}                                                       // we only have 5 layers, so we start with layer 1 again if layer counter goes to 6                                          
   if (count==stretch){count=0;}                                    // we have 8 static picture for the moving sine wave, so if count counter would hit the 9.(not existing) pic, it goes back to count=0
   }}
