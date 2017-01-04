#include <digitalIOPerformance.h>

const int led[9] = {5,9,10,4,2,3,8,7,6};
const int row[3] = {13,12,11};

int dely = 200;
int dly = 265;
int wied = 160;

void setup(){
  int pin;
  for (pin=0; pin<9; pin++) {
    pinMode( led[pin], OUTPUT);
  }

  for (pin=0; pin<3; pin++) {
    pinMode( row[pin], OUTPUT );
  }
  
  randomSeed(analogRead(0));
}


void loop(){
  Animation_5();
  
  for (int w = 0;w<2;w++){
    Animation_2();
  }
  
  digitalWrite(led[0],HIGH);
  for (int a = 0;a<3;a++){
    digitalWrite(row[a],HIGH);
    delay(200);
  }
  
  Animation_3();
  Animation_4();
  
  Animation_7();
  
  Animation_8();
  Animation_9();
  dly = 265;
  
  Animation_14();
  
  for (int i = 0; i < 500; i++){
  reset();
  reset();
  digitalWrite(led[0],HIGH);
  digitalWrite(row[2],HIGH);
  clear_all();
  }
  for (int i = 0; i < 500; i++){
  reset();
  digitalWrite(led[0],HIGH);
  digitalWrite(row[1],HIGH);
  reset();
  digitalWrite(led[4],HIGH);
  digitalWrite(row[2],HIGH);
  clear_all();
  }
  for (int i = 0; i < 500; i++){
  digitalWrite(led[0],HIGH);
  digitalWrite(row[0],HIGH);
  reset();
  digitalWrite(led[4],HIGH);
  digitalWrite(row[1],HIGH);
  reset();
  digitalWrite(led[8],HIGH);
  digitalWrite(row[2],HIGH);
  clear_all();
  }
  
  for (int w = 0;w<10;w++){
    wied -= 10;
    Animation_10();
  }
  for (int w = 0;w<5;w++){
    Animation_10();
  }
   for (int w = 0;w<5;w++){
     wied -= 10;
    Animation_10();
  }
   for (int w = 0;w<5;w++){
    Animation_10();
  }
  
  for (int w = 0;w<7;w++){
    Animation_12();
  }
  
  wied = 100;
  
  for (int w = 0;w<5;w++){
    wied -= 10;
    Animation_13();
  }
  
  Animation_11();
  
  wied = 160;
  
  for (int w = 0;w<7;w++){
    Animation_1();
  }
  
  Animation_6();
  if (dely <= 70){dely=200;}
  
  for (int w = 0;w<5;w++){
    Animation_1();
  }
}

void reset(){
  delayMicroseconds(333);
  int pin;
  for (pin=0; pin<9; pin++) {
    digitalWrite( led[pin], LOW );
  }
  for (pin=0; pin<3; pin++) {
    digitalWrite( row[pin], LOW );
  }
}

void clear_all(){
  delayMicroseconds(333);
  int pin;
  for (pin=0; pin<9; pin++) {
    digitalWrite( led[pin], LOW );
  }
  for (pin=0; pin<3; pin++) {
    digitalWrite( row[pin], LOW );
  }
  delayMicroseconds(1);
}

