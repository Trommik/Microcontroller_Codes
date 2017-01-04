#include "sphereplex.h"

int color = green;

int animationSpeed = 40;

const byte input[4] = {A0,A1,A2,A3};

void setup() {
  initCube();
  // how many secconds until the animation is told to progress
  animationMax = 10;
  for(int i = 0; i < 4; i++){
    pinMode(input[i], INPUT);
  }
}
void loop() {
  
  //tunnel();

  if (analogRead(input[0]) < 500) {
    if (analogRead(input[1]) > 500) {
      planarFlop3D();
    } else {
      for (int i = 0; i < 6; i++) {
        kreisel(20 * i + 30);
        if (i < 3) {
          kreisel(20 * i + 30);
        }
      }
      for (int i = 6; i > 0; i--) {
        kreisel(20 * i + 30);
        if (i < 3) {
          kreisel(20 * i + 30);
        }
      }
      color = nextColor(color);
    }
  } else if (analogRead(input[1]) < 500) {
    planarSpin();
  }
  if (analogRead(input[2]) < 500) {
    if (analogRead(input[3]) < 500) {
      trifade();
    } else {
      fountian();
    }
  } else if (analogRead(input[3]) < 500) {
    chaseTheDot();
  }
  
}

void planarSpin() {
  continuePattern = true;
  int animationSpeed = 100;
  int spinsPerColor = 5; // a spin is actually half a revolution
  while (continuePattern) {
    for (int i = 0; i < spinsPerColor; i++) {
      for (int x = 0; x < 2; x++) {
        drawLine(color,x,0,0,2-x,2,0);
        drawLine(color,x,0,1,2-x,2,1);
        drawLine(color,x,0,2,2-x,2,2);
        flushBuffer();
        clearBuffer();
        delay(animationSpeed);
      }
      for (int y = 0; y < 2; y++) {
        drawLine(color,2,y,0,0,2-y,0);
        drawLine(color,2,y,1,0,2-y,1);
        drawLine(color,2,y,2,0,2-y,2);
        flushBuffer();
        clearBuffer();
        delay(animationSpeed);
      }
    }
    color = nextColor(color);
  }
}

void tunnel() {
  continuePattern = true;
  int animationSpeed =150;
  
  int color1[]  = {R,R,R,R,B,B,B,B};
  int bright1[] = {2,4,6,8,2,4,6,8};
  int color2[]  = {B,B,B,B,R,R,R,R};
//int bright2[] = {6,4,2,0,6,4,2,0};
  int bright2[] = {8,6,4,2,8,6,4,2};
  
  int index[]   = {0,1,2,3,4,5,6,7};
  
  while (continuePattern) {
    drawBoxWalls(color1[index[0]],bright1[index[0]],1,1,0,2,2,0);
    drawBoxWalls(color2[index[0]],bright2[index[0]],1,1,0,2,2,0);
    drawBoxWalls(color1[index[1]],bright1[index[1]],1,1,1,2,2,1);
    drawBoxWalls(color2[index[1]],bright2[index[1]],1,1,1,2,2,1);
    drawBoxWalls(color1[index[2]],bright1[index[2]],1,1,2,2,2,2);
    drawBoxWalls(color2[index[2]],bright2[index[2]],1,1,2,2,2,2);
    drawBoxWalls(color1[index[3]],bright1[index[3]],1,1,2,2,2,2);
    drawBoxWalls(color2[index[3]],bright2[index[3]],1,1,2,2,2,2);
    
    drawBoxWalls(color1[index[4]],bright1[index[4]],0,0,2,2,2,2);
    drawBoxWalls(color2[index[4]],bright2[index[4]],0,0,3,3,3,3);
    drawBoxWalls(color1[index[5]],bright1[index[5]],0,0,2,3,3,2);
    drawBoxWalls(color2[index[5]],bright2[index[5]],0,0,2,3,3,2);
    drawBoxWalls(color1[index[6]],bright1[index[6]],0,0,1,3,3,1);
    drawBoxWalls(color2[index[6]],bright2[index[6]],0,0,1,3,3,1);
    drawBoxWalls(color1[index[7]],bright1[index[7]],0,0,0,3,3,0);
    drawBoxWalls(color2[index[7]],bright2[index[7]],0,0,0,3,3,0);
    
    
    flushBuffer();
    clearBuffer();
    for (int i = 0; i < 3; i++){
      //index[i] = index[i]==7?0:index[i]+1;
      index[i] = (index[i]+1)%8;
    }
    delay(animationSpeed);
    
  }
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
      delay(animationSpeed - 30);
    }
    for (int z = 2; z >= 0; z--) {

      drawBoxWalls(color, 0, 0, z, 2, 2, z);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    color = nextColor(color);
  }
}

void chaseTheDot() {
  continuePattern = true;
  int animationSpeed = 100;

  int xpos = 0;
  int ypos = 0;
  int zpos = 0;

  while (continuePattern) {
    switch (random(0, 6)) {
      case 0:
        if (xpos > 0) {
          xpos--;
          break;
        }
        else color = nextColor(color);
      case 1:
        if (xpos < 2) {
          xpos++;
          break;
        }
        else color = nextColor(color);
        xpos--; break;

      case 2:
        if (ypos > 0) {
          ypos--;
          break;
        }
        else color = nextColor(color);
      case 3:
        if (ypos < 2) {
          ypos++;
          break;
        }
        else color = nextColor(color);
        ypos--; break;

      case 4:
        if (zpos > 0) {
          zpos--;
          break;
        }
        else color = nextColor(color);
      case 5:
        if (zpos < 2) {
          zpos++;
          break;
        }
        else color = nextColor(color);
        zpos--; break;
    }
    drawLed(color, xpos, ypos, zpos);
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
      drawBox(blue, 9 - i, 0, 0, 0, 2, 2, 2);
      drawBox(red, i, 0, 0, 0, 2, 2, 2);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    // red fade out, green fade in
    for (int i = 1; i <= 8; i++) {
      drawBox(red, 9 - i, 0, 0, 0, 2, 2, 2);
      drawBox(green, i, 0, 0, 0, 2, 2, 2);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    // green fade out, blue fade in
    for (int i = 1; i <= 8; i++) {
      drawBox(green, 9 - i, 0, 0, 0, 2, 2, 2);
      drawBox(blue, i, 0, 0, 0, 2, 2, 2);
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

    for (int y = 2; y > 0; y--) {
      for (int z = 0; z < 3; z++) drawLine(color, 0, 2, z, 2, y, z);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    for (int x = 2; x > 0; x--) {
      for (int z = 0; z < 3; z++) drawLine(color, 0, 2, z, x, 0, z);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }


    for (int x = 0; x < 2; x++) {
      for (int y = 0; y < 3; y++) drawLine(color, 0, y, 0, x, y, 2);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    for (int z = 2; z > 0; z--) {
      for (int y = 0; y < 3; y++) drawLine(color, 0, y, 0, 2, y, z);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }

    for (int z = 0; z < 2; z++) {
      for (int x = 0; x < 3; x++) drawLine(color, x, 0, 0, x, 2, z);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    for (int y = 2; y > 0; y--) {
      for (int x = 0; x < 3; x++) drawLine(color, x, 0, 0, x, y, 2);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }

    for (int y = 0; y < 2; y++) {
      for (int z = 0; z < 3; z++) drawLine(color, 2, 0, z, 0, y, z);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    for (int x = 0; x < 2; x++) {
      for (int z = 0; z < 3; z++) drawLine(color, 2, 0, z, x, 2, z);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }

    for (int x = 2; x > 0; x--) {
      for (int y = 0; y < 3; y++) drawLine(color, 2, y, 2, x, y, 0);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    for (int z = 0; z < 2; z++) {
      for (int y = 0; y < 3; y++) drawLine(color, 2, y, 2, 0, y, z);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }

    for (int z = 2; z > 0; z--) {
      for (int x = 0; x < 3; x++) drawLine(color, x, 2, 2, x, 0, z);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    for (int y = 0; y < 2; y++) {
      for (int x = 0; x < 3; x++) drawLine(color, x, 2, 2, x, y, 0);
      flushBuffer();
      clearBuffer();
      delay(animationSpeed);
    }
    color = nextColor(color);
  }
}
