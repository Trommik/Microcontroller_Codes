int led[] = {5,9,10,4,2,3,8,7,6};
int row[] = {13,12,11};
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
Animation_1();
}


void Animation_1(){
for (int i = 0; i < 100; i++){
digitalWrite(led[0],HIGH);
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
for (int i = 0; i < 100; i++){
digitalWrite(led[0],HIGH);
digitalWrite(led[1],HIGH);
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
digitalWrite(led[3],HIGH);
digitalWrite(led[4],HIGH);
digitalWrite(led[5],HIGH);
digitalWrite(led[6],HIGH);
digitalWrite(led[7],HIGH);
digitalWrite(led[8],HIGH);
digitalWrite(row[2],HIGH);
clear_all();
}
for (int i = 0; i < 100; i++){
digitalWrite(led[0],HIGH);
digitalWrite(led[1],HIGH);
digitalWrite(led[2],HIGH);
digitalWrite(led[3],HIGH);
digitalWrite(led[4],HIGH);
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
digitalWrite(led[6],HIGH);
digitalWrite(led[7],HIGH);
digitalWrite(led[8],HIGH);
digitalWrite(row[2],HIGH);
clear_all();
}
for (int i = 0; i < 100; i++){
digitalWrite(led[0],HIGH);
digitalWrite(led[1],HIGH);
digitalWrite(led[2],HIGH);
digitalWrite(led[3],HIGH);
digitalWrite(led[4],HIGH);
digitalWrite(led[5],HIGH);
digitalWrite(led[6],HIGH);
digitalWrite(led[7],HIGH);
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
digitalWrite(row[2],HIGH);
clear_all();
}
for (int i = 0; i < 100; i++){
digitalWrite(led[0],HIGH);
digitalWrite(led[1],HIGH);
digitalWrite(led[2],HIGH);
digitalWrite(led[3],HIGH);
digitalWrite(led[4],HIGH);
digitalWrite(led[5],HIGH);
digitalWrite(led[6],HIGH);
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
digitalWrite(led[8],HIGH);
digitalWrite(row[2],HIGH);
clear_all();
}
for (int i = 0; i < 100; i++){
digitalWrite(led[0],HIGH);
digitalWrite(led[1],HIGH);
digitalWrite(led[2],HIGH);
digitalWrite(led[3],HIGH);
digitalWrite(led[4],HIGH);
digitalWrite(led[5],HIGH);
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
digitalWrite(led[7],HIGH);
digitalWrite(led[8],HIGH);
digitalWrite(row[2],HIGH);
clear_all();
}
for (int i = 0; i < 100; i++){
digitalWrite(led[0],HIGH);
digitalWrite(led[1],HIGH);
digitalWrite(led[2],HIGH);
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
digitalWrite(led[4],HIGH);
digitalWrite(led[5],HIGH);
digitalWrite(led[6],HIGH);
digitalWrite(led[7],HIGH);
digitalWrite(led[8],HIGH);
digitalWrite(row[2],HIGH);
clear_all();
}
for (int i = 0; i < 100; i++){
reset();
reset();
clear_all();
}
for (int i = 0; i < 100; i++){
reset();
reset();
clear_all();
}
}



void reset(){
delayMicroseconds(333);
int pin;
for (pin=0; pin<9; pin++) {
digitalWrite( led[pin], LOW );}
for (pin=0; pin<3; pin++) {
digitalWrite( row[pin], LOW );}
}

void clear_all(){
delayMicroseconds(333);
int pin;
for (pin=0; pin<9; pin++) {
digitalWrite( led[pin], LOW );}
for (pin=0; pin<3; pin++) {
digitalWrite( row[pin], LOW );}
delayMicroseconds(1);
}
digitalWrite(row[1],HIGH);
reset();
digitalWrite(led[0],HIGH);
digitalWrite(led[1],HIGH);
digitalWrite(led[2],HIGH);
digitalWrite(led[4],HIGH);
digitalWrite(led[5],HIGH);
digitalWrite(led[6],HIGH);
digitalWrite(led[7],HIGH);
digitalWrite(led[8],HIGH);
digitalWrite(row[2],HIGH);
clear_all();
}
for (int i = 0; i < 100; i++){
reset();
reset();
clear_all();
}
for (int i = 0; i < 100; i++){
reset();
reset();
clear_all();
}
for (int i = 0; i < 100; i++){
reset();
reset();
clear_all();
}
for (int i = 0; i < 100; i++){
reset();
reset();
clear_all();
}
for (int i = 0; i < 100; i++){
reset();
reset();
clear_all();
}
for (int i = 0; i < 100; i++){
reset();
reset();
clear_all();
}
}



void reset(){
delayMicroseconds(333);
int pin;
for (pin=0; pin<9; pin++) {
digitalWrite( led[pin], LOW );}
for (pin=0; pin<3; pin++) {
digitalWrite( row[pin], LOW );}
}

void clear_all(){
delayMicroseconds(333);
int pin;
for (pin=0; pin<9; pin++) {
digitalWrite( led[pin], LOW );}
for (pin=0; pin<3; pin++) {
digitalWrite( row[pin], LOW );}
delayMicroseconds(1);
}
te(led[3],HIGH);
digitalWrite(row[1],HIGH);
reset();
digitalWrite(led[3],HIGH);
digitalWrite(row[2],HIGH);
clear_all();
}
for (int i = 0; i < 70; i++){
digitalWrite(led[0],HIGH);
digitalWrite(row[0],HIGH);
reset();
digitalWrite(led[0],HIGH);
digitalWrite(row[1],HIGH);
reset();
digitalWrite(led[0],HIGH);
digitalWrite(row[2],HIGH);
clear_all();
}
for (int i = 0; i < 70; i++){
digitalWrite(led[0],HIGH);
digitalWrite(led[1],HIGH);
digitalWrite(row[0],HIGH);
reset();
digitalWrite(led[0],HIGH);
digitalWrite(led[1],HIGH);
digitalWrite(row[1],HIGH);
reset();
digitalWrite(led[0],HIGH);
digitalWrite(led[1],HIGH);
digitalWrite(row[2],HIGH);
clear_all();
}
for (int i = 0; i < 70; i++){
digitalWrite(led[0],HIGH);
digitalWrite(led[1],HIGH);
digitalWrite(led[2],HIGH);
digitalWrite(row[0],HIGH);
reset();
digitalWrite(led[0],HIGH);
digitalWrite(led[1],HIGH);
digitalWrite(led[2],HIGH);
digitalWrite(row[1],HIGH);
reset();
digitalWrite(led[0],HIGH);
digitalWrite(led[1],HIGH);
digitalWrite(led[2],HIGH);
digitalWrite(row[2],HIGH);
clear_all();
}
for (int i = 0; i < 70; i++){
digitalWrite(led[0],HIGH);
digitalWrite(led[1],HIGH);
digitalWrite(led[2],HIGH);
digitalWrite(led[5],HIGH);
digitalWrite(row[0],HIGH);
reset();
digitalWrite(led[0],HIGH);
digitalWrite(led[1],HIGH);
digitalWrite(led[2],HIGH);
digitalWrite(led[5],HIGH);
digitalWrite(row[1],HIGH);
reset();
digitalWrite(led[0],HIGH);
digitalWrite(led[1],HIGH);
digitalWrite(led[2],HIGH);
digitalWrite(led[5],HIGH);
digitalWrite(row[2],HIGH);
clear_all();
}
for (int i = 0; i < 70; i++){
digitalWrite(led[0],HIGH);
digitalWrite(led[1],HIGH);
digitalWrite(led[2],HIGH);
digitalWrite(led[5],HIGH);
digitalWrite(led[8],HIGH);
digitalWrite(row[0],HIGH);
reset();
digitalWrite(led[0],HIGH);
digitalWrite(led[1],HIGH);
digitalWrite(led[2],HIGH);
digitalWrite(led[5],HIGH);
digitalWrite(led[8],HIGH);
digitalWrite(row[1],HIGH);
reset();
digitalWrite(led[0],HIGH);
digitalWrite(led[1],HIGH);
digitalWrite(led[2],HIGH);
digitalWrite(led[5],HIGH);
digitalWrite(led[8],HIGH);
digitalWrite(row[2],HIGH);
clear_all();
}
for (int i = 0; i < 70; i++){
digitalWrite(led[0],HIGH);
digitalWrite(led[1],HIGH);
digitalWrite(led[2],HIGH);
digitalWrite(led[5],HIGH);
digitalWrite(led[7],HIGH);
digitalWrite(led[8],HIGH);
digitalWrite(row[0],HIGH);
reset();
digitalWrite(led[0],HIGH);
digitalWrite(led[1],HIGH);
digitalWrite(led[2],HIGH);
digitalWrite(led[5],HIGH);
digitalWrite(led[7],HIGH);
digitalWrite(led[8],HIGH);
digitalWrite(row[1],HIGH);
reset();
digitalWrite(led[0],HIGH);
digitalWrite(led[1],HIGH);
digitalWrite(led[2],HIGH);
digitalWrite(led[5],HIGH);
digitalWrite(led[7],HIGH);
digitalWrite(led[8],HIGH);
digitalWrite(row[2],HIGH);
clear_all();
}
for (int i = 0; i < 70; i++){
digitalWrite(led[0],HIGH);
digitalWrite(led[1],HIGH);
digitalWrite(led[2],HIGH);
digitalWrite(led[5],HIGH);
digitalWrite(led[6],HIGH);
digitalWrite(led[7],HIGH);
digitalWrite(led[8],HIGH);
digitalWrite(row[0],HIGH);
reset();
digitalWrite(led[0],HIGH);
digitalWrite(led[1],HIGH);
digitalWrite(led[2],HIGH);
digitalWrite(led[5],HIGH);
digitalWrite(led[6],HIGH);
digitalWrite(led[7],HIGH);
digitalWrite(led[8],HIGH);
digitalWrite(row[1],HIGH);
reset();
digitalWrite(led[0],HIGH);
digitalWrite(led[1],HIGH);
digitalWrite(led[2],HIGH);
digitalWrite(led[5],HIGH);
digitalWrite(led[6],HIGH);
digitalWrite(led[7],HIGH);
digitalWrite(led[8],HIGH);
digitalWrite(row[2],HIGH);
clear_all();
}
for (int i = 0; i < 70; i++){
digitalWrite(led[0],HIGH);
digitalWrite(led[1],HIGH);
digitalWrite(led[2],HIGH);
digitalWrite(led[3],HIGH);
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
digitalWrite(led[5],HIGH);
digitalWrite(led[6],HIGH);
digitalWrite(led[7],HIGH);
digitalWrite(led[8],HIGH);
digitalWrite(row[2],HIGH);
clear_all();
}
for (int i = 0; i < 100; i++){
reset();
reset();
clear_all();
}
}



void reset(){
delayMicroseconds(333);
int pin;
for (pin=0; pin<9; pin++) {
digitalWrite( led[pin], LOW );}
for (pin=0; pin<3; pin++) {
digitalWrite( row[pin], LOW );}
}

void clear_all(){
delayMicroseconds(333);
int pin;
for (pin=0; pin<9; pin++) {
digitalWrite( led[pin], LOW );}
for (pin=0; pin<3; pin++) {
digitalWrite( row[pin], LOW );}
delayMicroseconds(1);
}
e(led[7],HIGH);
digitalWrite(row[0],HIGH);
reset();
digitalWrite(led[5],HIGH);
digitalWrite(led[6],HIGH);
digitalWrite(row[1],HIGH);
reset();
digitalWrite(led[0],HIGH);
digitalWrite(led[4],HIGH);
digitalWrite(led[8],HIGH);
digitalWrite(row[2],HIGH);
clear_all();
}
for (int i = 0; i < 100; i++){
digitalWrite(led[0],HIGH);
digitalWrite(led[2],HIGH);
digitalWrite(led[7],HIGH);
digitalWrite(row[0],HIGH);
reset();
digitalWrite(led[5],HIGH);
digitalWrite(led[6],HIGH);
digitalWrite(row[1],HIGH);
reset();
digitalWrite(led[0],HIGH);
digitalWrite(led[4],HIGH);
digitalWrite(led[8],HIGH);
digitalWrite(row[2],HIGH);
clear_all();
}
for (int i = 0; i < 100; i++){
digitalWrite(led[0],HIGH);
digitalWrite(led[2],HIGH);
digitalWrite(row[0],HIGH);
reset();
digitalWrite(led[5],HIGH);
digitalWrite(led[6],HIGH);
digitalWrite(row[1],HIGH);
reset();
digitalWrite(led[0],HIGH);
digitalWrite(led[4],HIGH);
digitalWrite(led[8],HIGH);
digitalWrite(row[2],HIGH);
clear_all();
}
for (int i = 0; i < 100; i++){
digitalWrite(led[0],HIGH);
digitalWrite(led[2],HIGH);
digitalWrite(row[0],HIGH);
reset();
digitalWrite(led[6],HIGH);
digitalWrite(row[1],HIGH);
reset();
digitalWrite(led[0],HIGH);
digitalWrite(led[4],HIGH);
digitalWrite(led[8],HIGH);
digitalWrite(row[2],HIGH);
clear_all();
}
for (int i = 0; i < 100; i++){
digitalWrite(led[2],HIGH);
digitalWrite(row[0],HIGH);
reset();
digitalWrite(led[6],HIGH);
digitalWrite(row[1],HIGH);
reset();
digitalWrite(led[0],HIGH);
digitalWrite(led[4],HIGH);
digitalWrite(led[8],HIGH);
digitalWrite(row[2],HIGH);
clear_all();
}
for (int i = 0; i < 100; i++){
digitalWrite(led[2],HIGH);
digitalWrite(row[0],HIGH);
reset();
digitalWrite(led[6],HIGH);
digitalWrite(row[1],HIGH);
reset();
digitalWrite(led[4],HIGH);
digitalWrite(led[8],HIGH);
digitalWrite(row[2],HIGH);
clear_all();
}
for (int i = 0; i < 100; i++){
reset();
digitalWrite(led[6],HIGH);
digitalWrite(row[1],HIGH);
reset();
digitalWrite(led[4],HIGH);
digitalWrite(led[8],HIGH);
digitalWrite(row[2],HIGH);
clear_all();
}
for (int i = 0; i < 100; i++){
reset();
reset();
digitalWrite(led[4],HIGH);
digitalWrite(led[8],HIGH);
digitalWrite(row[2],HIGH);
clear_all();
}
for (int i = 0; i < 100; i++){
reset();
reset();
digitalWrite(led[4],HIGH);
digitalWrite(row[2],HIGH);
clear_all();
}
for (int i = 0; i < 100; i++){
reset();
reset();
clear_all();
}
for (int i = 0; i < 100; i++){
reset();
reset();
clear_all();
}
for (int i = 0; i < 100; i++){
reset();
reset();
clear_all();
}
}



void reset(){
delayMicroseconds(333);
int pin;
for (pin=0; pin<9; pin++) {
digitalWrite( led[pin], LOW );}
for (pin=0; pin<3; pin++) {
digitalWrite( row[pin], LOW );}
}

void clear_all(){
delayMicroseconds(333);
int pin;
for (pin=0; pin<9; pin++) {
digitalWrite( led[pin], LOW );}
for (pin=0; pin<3; pin++) {
digitalWrite( row[pin], LOW );}
delayMicroseconds(1);
}
all();
}
for (int i = 0; i < 50; i++){
reset();
digitalWrite(led[8],HIGH);
digitalWrite(row[1],HIGH);
reset();
clear_all();
}
for (int i = 0; i < 100; i++){
digitalWrite(led[8],HIGH);
digitalWrite(row[0],HIGH);
reset();
reset();
clear_all();
}
for (int i = 0; i < 50; i++){
digitalWrite(led[8],HIGH);
digitalWrite(row[0],HIGH);
reset();
reset();
clear_all();
}
for (int i = 0; i < 50; i++){
digitalWrite(led[7],HIGH);
digitalWrite(led[8],HIGH);
digitalWrite(row[0],HIGH);
reset();
reset();
clear_all();
}
for (int i = 0; i < 50; i++){
digitalWrite(led[3],HIGH);
digitalWrite(led[7],HIGH);
digitalWrite(led[8],HIGH);
digitalWrite(row[0],HIGH);
reset();
reset();
clear_all();
}
for (int i = 0; i < 50; i++){
digitalWrite(led[0],HIGH);
digitalWrite(led[3],HIGH);
digitalWrite(led[7],HIGH);
digitalWrite(led[8],HIGH);
digitalWrite(row[0],HIGH);
reset();
reset();
clear_all();
}
for (int i = 0; i < 50; i++){
digitalWrite(led[0],HIGH);
digitalWrite(led[3],HIGH);
digitalWrite(led[5],HIGH);
digitalWrite(led[7],HIGH);
digitalWrite(led[8],HIGH);
digitalWrite(row[0],HIGH);
reset();
reset();
clear_all();
}
for (int i = 0; i < 50; i++){
digitalWrite(led[0],HIGH);
digitalWrite(led[3],HIGH);
digitalWrite(led[5],HIGH);
digitalWrite(led[7],HIGH);
digitalWrite(led[8],HIGH);
digitalWrite(row[0],HIGH);
reset();
reset();
clear_all();
}
for (int i = 0; i < 50; i++){
digitalWrite(led[0],HIGH);
digitalWrite(led[1],HIGH);
digitalWrite(led[3],HIGH);
digitalWrite(led[5],HIGH);
digitalWrite(led[7],HIGH);
digitalWrite(led[8],HIGH);
digitalWrite(row[0],HIGH);
reset();
reset();
clear_all();
}
for (int i = 0; i < 50; i++){
digitalWrite(led[0],HIGH);
digitalWrite(led[1],HIGH);
digitalWrite(led[3],HIGH);
digitalWrite(led[5],HIGH);
digitalWrite(led[6],HIGH);
digitalWrite(led[7],HIGH);
digitalWrite(led[8],HIGH);
digitalWrite(row[0],HIGH);
reset();
reset();
clear_all();
}
for (int i = 0; i < 50; i++){
digitalWrite(led[0],HIGH);
digitalWrite(led[1],HIGH);
digitalWrite(led[2],HIGH);
digitalWrite(led[4],HIGH);
digitalWrite(led[5],HIGH);
digitalWrite(led[6],HIGH);
digitalWrite(led[7],HIGH);
digitalWrite(led[8],HIGH);
digitalWrite(row[0],HIGH);
reset();
reset();
clear_all();
}
for (int i = 0; i < 50; i++){
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
reset();
clear_all();
}
}





void Animation_2(){
for (int i = 0; i < 100; i++){
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
reset();
clear_all();
}
for (int i = 0; i < 100; i++){
digitalWrite(led[1],HIGH);
digitalWrite(led[2],HIGH);
digitalWrite(led[4],HIGH);
digitalWrite(led[5],HIGH);
digitalWrite(led[7],HIGH);
digitalWrite(led[8],HIGH);
digitalWrite(row[0],HIGH);
reset();
reset();
clear_all();
}
for (int i = 0; i < 100; i++){
digitalWrite(led[0],HIGH);
digitalWrite(led[2],HIGH);
digitalWrite(led[3],HIGH);
digitalWrite(led[5],HIGH);
digitalWrite(led[6],HIGH);
digitalWrite(led[8],HIGH);
digitalWrite(row[0],HIGH);
reset();
reset();
clear_all();
}
for (int i = 0; i < 100; i++){
digitalWrite(led[2],HIGH);
digitalWrite(led[5],HIGH);
digitalWrite(led[8],HIGH);
digitalWrite(row[0],HIGH);
reset();
reset();
clear_all();
}
for (int i = 0; i < 100; i++){
digitalWrite(led[1],HIGH);
digitalWrite(led[4],HIGH);
digitalWrite(led[7],HIGH);
digitalWrite(row[0],HIGH);
reset();
reset();
clear_all();
}
for (int i = 0; i < 100; i++){
digitalWrite(led[0],HIGH);
digitalWrite(led[3],HIGH);
digitalWrite(led[6],HIGH);
digitalWrite(row[0],HIGH);
reset();
reset();
clear_all();
}
for (int i = 0; i < 100; i++){
reset();
reset();
clear_all();
}
for (int i = 0; i < 100; i++){
reset();
reset();
clear_all();
}
}




void reset(){
delayMicroseconds(333);
int pin;
for (pin=0; pin<9; pin++) {
digitalWrite( led[pin], LOW );}
for (pin=0; pin<3; pin++) {
digitalWrite( row[pin], LOW );}
}

void clear_all(){
delayMicroseconds(333);
int pin;
for (pin=0; pin<9; pin++) {
digitalWrite( led[pin], LOW );}
for (pin=0; pin<3; pin++) {
digitalWrite( row[pin], LOW );}
delayMicroseconds(1);
}
