#include "Tlc5940.h"               // don't forget to download the Tlc5940 lib from arduino playground and place it in you lib folder ( http://tlc5940arduino.googlecode.com/files/Tlc5940_r014_2.zip )
#include "digitalIOPerformance.h"  // don't forget to download the digitalIOPerformance lib from arduino playground and place it in you lib folder ( https://github.com/projectgus/digitalIOPerformance )

const int layer[4] = {5, 6, 7, 8};

const int red[16] = { 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15}; //TLC1 red
const int grn[16] = {16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31}; //TLC2 green
const int blu[16] = {32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47}; //TLC3 blue

int bright = 4095;         // set brightness for all Strings(4095=20mA, 0=0ma, 1000=4.88mA,....). If you want individually brightness for a String you have to change the value in tab "function"

byte rnd;
byte rndlast;

byte col = random(1, 8);

byte x = random(1, 5);
byte y = random(1, 5);
byte z = random(1, 5);

void setup() {
  for (byte pin = 0; pin < 4; pin++) {
    pinMode( layer[pin], OUTPUT );
  }

  Tlc.init();
  randomSeed(analogRead(5));
}

void loop() {

  if (analogRead(1) > 500) {
    if (analogRead(2) > 500) {
      reset();
      RGB_Fade(1);
    } else {
      reset();
      fadein_out();
    }
  } else if (analogRead(2) > 500) {
    reset();
    Moving_boxes(18);
  }
  if (analogRead(3) > 500) {
    if (analogRead(4) > 500) {
      reset();
      Random_rgb_rain();
    } else {
      reset();
      Chase_the_Dot();
    }
  } else if (analogRead(4) > 500) {
    reset();
    Random_leds();
  }
}

void reset() {
  Tlc.update();
  delayMicroseconds(1500);

  delayMicroseconds(1000);

  Tlc.clear();
  digitalWrite(layer[0], LOW);
  digitalWrite(layer[1], LOW);
  digitalWrite(layer[2], LOW);
  digitalWrite(layer[3], LOW);
}


byte create_rand(byte _min, byte _max) {

  rnd = random(_min, _max);
  if (rndlast == rnd) {
    rnd = random(_min, _max);
    if (rndlast == rnd) {
      rnd = random(_min, _max);
    }
  }

  rndlast = rnd;

  return rnd;
}
