#include "sphereplex.h"

int color = green;

int animationSpeed = 40;

const int input[4] = { 14, 15, 16, 17};

void setup() {
  initCube();
  // how many secconds until the animation is told to progress
  animationMax = 10;
 
}
void loop() {
  /*
  if(analogRead(input[0])==0){
    for(int i = 0; i < 6; i++){
      kreisel(20 * i + 30);
      if(i < 3){
        kreisel(20 * i + 30);
      }
    }
    for(int i = 6; i > 0; i--){
      kreisel(20 * i + 30);
      if(i < 3){
        kreisel(20 * i + 30);
      }
    }
    color = nextColor(color);
    
  }else if(analogRead(input[1])==0){
  //planarFlop3D();
    trifade();
    
  }else if(analogRead(input[2])==0){
    fountian();
    
  }else if(analogRead(input[3])==0){
    chaseTheDot();
    
  }*/
  drawLed(2,0,0,0);
    flushBuffer();
    clearBuffer();
    delay(animationSpeed);
}


void kreisel(int animationSpeed) {
  
    drawLine(color, 0, 0, 0, 0, 0, 2);     
    flushBuffer();
    clearBuffer();
    delay(animationSpeed);  

    drawLine(color, 1, 0, 0, 1, 0, 2);     
    flushBuffer();
    clearBuffer();
    delay(animationSpeed); 

    drawLine(color, 2, 0, 0, 2, 0, 2);     
    flushBuffer();
    clearBuffer();
    delay(animationSpeed);  

    drawLine(color, 2, 1, 0, 2, 1, 2);     
    flushBuffer();
    clearBuffer();
    delay(animationSpeed); 

    drawLine(color, 2, 2, 0, 2, 2, 2);     
    flushBuffer();
    clearBuffer();
    delay(animationSpeed); 

    drawLine(color, 1, 2, 0, 1, 2, 2);     
    flushBuffer();
    clearBuffer();
    delay(animationSpeed); 

    drawLine(color, 0, 2, 0, 0, 2, 2);     
    flushBuffer();
    clearBuffer();
    delay(animationSpeed);  

    drawLine(color, 0, 1, 0, 0, 1, 2);     
    flushBuffer();
    clearBuffer();
    delay(animationSpeed);  
}

void fountian() {
  continuePattern = true;
  int animationSpeed = 150;
  while (continuePattern) {
    for (int z = 0; z <= 2; z++) {
      drawLed(color, 1, 1, z); 
      //drawBoxWalls(color,1,1,z,2,2,z);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed-30);
    }
    for (int z = 2; z >= 0; z--) {
      
      drawBoxWalls(color,0,0,z,2,2,z);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    color=nextColor(color);
  }
}

void chaseTheDot() {
  continuePattern = true;
  int animationSpeed = 100;
  
  int xpos = 0;
  int ypos = 0;
  int zpos = 0;
  
  while (continuePattern) {
    switch(random(0,6)) {
      case 0:
        if (xpos > 0) {xpos--;break;}
        else color=nextColor(color);
      case 1:
        if (xpos < 2) {xpos++;break;}
        else color=nextColor(color);
        xpos--; break;
        
      case 2:
        if (ypos > 0) {ypos--;break;}
        else color=nextColor(color);
      case 3:
        if (ypos < 2) {ypos++;break;}
        else color=nextColor(color);
        ypos--; break;
      
      case 4:
        if (zpos > 0) {zpos--;break;}
        else color=nextColor(color);
      case 5:
        if (zpos < 2) {zpos++;break;}
        else color=nextColor(color);
        zpos--; break;
    }
    drawLed(color,xpos,ypos,zpos);
    flushBuffer();
    clearBuffer();
    delay(animationSpeed);
  }
}

void trifade() {
  continuePattern = true;
  int animationSpeed = 100;
  while (continuePattern) {
    // blue fade out, red fade in
    for (int i = 1; i <= 8; i++) {
      drawBox(blue,9-i,0,0,0,2,2,2);
      drawBox(red,i,0,0,0,2,2,2);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    // red fade out, green fade in
    for (int i = 1; i <= 8; i++) {
      drawBox(red,9-i,0,0,0,2,2,2);
      drawBox(green,i,0,0,0,2,2,2);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    // green fade out, blue fade in
    for (int i = 1; i <= 8; i++) {
      drawBox(green,9-i,0,0,0,2,2,2);
      drawBox(blue,i,0,0,0,2,2,2);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
  }
}

void planarFlop3D() {
  continuePattern = true;
  int animationSpeed = 120;
  while (continuePattern) {
    
    for (int y = 2; y>0; y--){
      for (int z = 0; z < 3; z++) drawLine(color,0,2,z,2,y,z);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    for (int x = 2; x > 0; x--) {
      for (int z = 0; z < 3; z++) drawLine(color,0,2,z,x,0,z);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    
    
    for (int x = 0; x < 2; x++) {
      for (int y = 0; y < 3; y++) drawLine(color,0,y,0,x,y,2);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    for (int z = 2; z > 0; z--) {
      for (int y = 0; y < 3; y++) drawLine(color,0,y,0,2,y,z);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    
    for (int z = 0; z < 2; z++) {
      for (int x = 0; x < 3; x++) drawLine(color,x,0,0,x,2,z);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    for (int y = 2; y > 0; y--) {
      for (int x = 0; x < 3; x++) drawLine(color,x,0,0,x,y,2);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    
    for (int y = 0; y < 2; y++) {
      for (int z = 0; z < 3; z++) drawLine(color,2,0,z,0,y,z);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    for (int x = 0; x < 2; x++) {
      for (int z = 0; z < 3; z++) drawLine(color,2,0,z,x,2,z);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    
    for (int x = 2; x > 0; x--) {
      for (int y = 0; y < 3; y++) drawLine(color,2,y,2,x,y,0);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    for (int z = 0; z < 2; z++) {
      for (int y = 0; y < 3; y++) drawLine(color,2,y,2,0,y,z);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    
    for (int z = 2; z > 0; z--) {
      for (int x = 0; x < 3; x++) drawLine(color,x,2,2,x,0,z);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    } 
    for (int y = 0; y < 2; y++) {
      for (int x = 0; x < 3; x++) drawLine(color,x,2,2,x,y,0);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    color = nextColor(color);
  }
}
