// TEST CODE!!!
// Reads Animation values for a 4x4x4 RGB cube from an EEPROM and stores the in a array. 

#include <Wire.h>

#define eeprom1 0x50    //Address of 24LC256 eeprom chip

unsigned int red[64] = {
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,                      //layer1
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,                      //layer2
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,                      //layer3
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//TLC1 red   values  //layer4
unsigned int grn[64] = {
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,                      //layer1
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,                      //layer2
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,                      //layer3
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//TLC2 green values  //layer4
unsigned int blu[64] = {
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,                      //layer1
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,                      //layer2
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,                      //layer3
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//TLC3 blue  values  //layer4

const byte arrays = 3;
const byte array_lenght = 64;

unsigned int frame = 0;

void setup()
{
  Serial.begin(9600);
  Wire.begin();

  for (int i = 0; i<4; i++){
    frame = i;
    read_cube_values();
    Serial_cube_values();
  }
  
  //write_cube_values();

  //read_cube_values();

  //Serial_cube_values();
}

void loop() {}


void Serial_cube_values()
{
  for (byte i = 0; i < array_lenght; i++) {
    Serial.print(red[i]);
    Serial.print(",");
  }
  Serial.println();
  for (byte i = 0; i < array_lenght; i++) {
    Serial.print(grn[i]);
    Serial.print(",");
  }
  Serial.println();
  for (byte i = 0; i < array_lenght; i++) {
    Serial.print(blu[i]);
    Serial.print(",");
  }
  Serial.println();
}

