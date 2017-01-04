int led[] = {5,9,10,4,2,3,8,7,6};
int row[] = {13,12,11};


void setup()
{
  int pin;      // loop counter
  // set up LED pins as output (active HIGH)
  for (pin=0; pin<9; pin++) {
    pinMode( led[pin], OUTPUT );
  }
  // set up plane pins as outputs (active LOW) 
  for (pin=0; pin<3; pin++) {
    pinMode( row[pin], OUTPUT );
  }

  randomSeed(analogRead(0));
}


void loop(){

  // animation2();
  delay(10);
  // animation3();
   //animation4();

  //Animation_1();
  
  //animation5();
}






void animation5(){


for (int i = 0; i < 600; i++){
digitalWrite(led[0],HIGH);
digitalWrite(led[1],HIGH);
digitalWrite(led[2],HIGH);
digitalWrite(led[3],HIGH);
digitalWrite(led[4],HIGH);
digitalWrite(led[5],HIGH);
digitalWrite(led[6],HIGH);
digitalWrite(led[7],HIGH);
digitalWrite(led[8],HIGH);
digitalWrite(row[0],HIGH);
reset();
digitalWrite(led[0],HIGH);
digitalWrite(led[1],HIGH);
digitalWrite(led[2],HIGH);
digitalWrite(led[3],HIGH);
digitalWrite(led[4],HIGH);
digitalWrite(led[5],HIGH);
digitalWrite(led[6],HIGH);
digitalWrite(led[7],HIGH);
digitalWrite(led[8],HIGH);
digitalWrite(row[1],HIGH);
reset();
digitalWrite(led[0],HIGH);
digitalWrite(led[1],HIGH);
digitalWrite(led[2],HIGH);
digitalWrite(led[3],HIGH);
digitalWrite(led[4],HIGH);
digitalWrite(led[5],HIGH);
digitalWrite(led[6],HIGH);
digitalWrite(led[7],HIGH);
digitalWrite(led[8],HIGH);
digitalWrite(row[2],HIGH);

clear_all();
}
for (int i = 0;i<300;i++){
digitalWrite(led[0],HIGH);

digitalWrite(row[0],HIGH);

reset();

digitalWrite(row[1],HIGH);

reset();

digitalWrite(row[2],HIGH);

clear_all();


}  
  
}

void reset(){
  
  delayMicroseconds(333);
  
  int pin;      // loop counter
  // set up LED pins as output (active HIGH)
  for (pin=0; pin<9; pin++) {
    digitalWrite( led[pin], LOW );
  }
  // set up plane pins as outputs (active LOW) 
  for (pin=0; pin<3; pin++) {
    digitalWrite( row[pin], LOW );
  }

}
void clear_all(){
  delayMicroseconds(333);
  
  int pin;      // loop counter
  // set up LED pins as output (active HIGH)
  for (pin=0; pin<9; pin++) {
    digitalWrite( led[pin], LOW );
  }
  // set up plane pins as outputs (active LOW) 
  for (pin=0; pin<3; pin++) {
    digitalWrite( row[pin], LOW );
  }
  delayMicroseconds(1);
}

