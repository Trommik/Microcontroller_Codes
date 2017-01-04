/********************************** SIGNATURE *********************************\
|                                      ,,                                      |
|                     db             `7MM                                      |
|                    ;MM:              MM                                      |
|                   ,V^MM.    ,pP"Ybd  MMpMMMb.  .gP"Ya `7Mb,od8               |
|                  ,M  `MM    8I   `"  MM    MM ,M'   Yb  MM' "'               |
|                  AbmmmqMA   `YMMMa.  MM    MM 8M""""""  MM                   |
|                 A'     VML  L.   I8  MM    MM YM.    ,  MM                   |
|               .AMA.   .AMMA.M9mmmP'.JMML  JMML.`Mbmmd'.JMML.                 |
|                                                                              |
|                                                                              |
|                                  ,,    ,,                                    |
|                      .g8"""bgd `7MM    db        `7MM                        |
|                    .dP'     `M   MM                MM                        |
|                    dM'       `   MM  `7MM  ,p6"bo  MM  ,MP'                  |
|                    MM            MM    MM 6M'  OO  MM ;Y                     |
|                    MM.    `7MMF' MM    MM 8M       MM;Mm                     |
|                    `Mb.     MM   MM    MM YM.    , MM `Mb.                   |
|                      `"bmmmdPY .JMML..JMML.YMbmd'.JMML. YA.                  |
|                                                                              |
\******************************************************************************/
/*********************************** LICENCE **********************************\
| Copyright (c) 2012, Asher Glick                                              |
| All rights reserved.                                                         |
|                                                                              |
| Redistribution and use in source and binary forms, with or without           |
| modification, are permitted provided that the following conditions are met:  |
|                                                                              |
| * Redistributions of source code must retain the above copyright notice,     |
|   this list of conditions and the following disclaimer.                      |
| * Redistributions in binary form must reproduce the above copyright notice,  |
|   this list of conditions and the following disclaimer in the documentation  |
|   and/or other materials provided with the distribution.                     |
|                                                                              |
| THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  |
| AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    |
| IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   |
| ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE    |
| LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR          |
| CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF         |
| SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS     |
| INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN      |
| CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)      |
| ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   |
| POSSIBILITY OF SUCH DAMAGE.                                                  |
\******************************************************************************/
#ifndef _sphereplex_H_
#define _sphereplex_H_

#define BUFFERSIZE 81
#include "Arduino.h"
#include "mappings.h"
#include "niceTimer.h"

struct _frame_light{
  char pin1;
  char pin2;
  struct _frame_light * next;
};

_frame_light * _cube__frame;
_frame_light * _cube_current_frame;
char * _cube_buffer;

bool continuePattern = false;

/********************************** INIT CUBE *********************************\
| This function will allocate the memory required for the LED cube buffers.    |
| which is about 600bytes
\******************************************************************************/
void initCube() {
  _cube__frame = (_frame_light*)malloc(sizeof(_frame_light) * (BUFFERSIZE+1));
  _cube_buffer = (char*)malloc(sizeof(char) * BUFFERSIZE);
  
  
  for (int i = 0; i < BUFFERSIZE; i++) {
    _cube_buffer[i] = 0;
  }
  _cube__frame->next = _cube__frame;
  _cube__frame->pin1=0;
  _cube__frame->pin2=0;
  _cube_current_frame = _cube__frame;
  
  
  // Configure Interrupt for color display
  setTimer2Prescaler(1);
  enableTimer2OverflowInterrupt();
  setTimer2Mode (TIMER2_NORMAL);
  
  // Configure Interrupt for Animation Progression
  setTimer1Prescaler(256);
  enableTimer1OverflowInterrupt();
  setTimer1Mode (TIMER1_NORMAL);  
}
  //////////////////////////////////////////////////////////////////////////////
 ////////////////////////////// HELPER FUNCTIONS //////////////////////////////
//////////////////////////////////////////////////////////////////////////////

/******************************** CLEAR BUFFER ********************************\
| This function will clear the buffer that you can write to, this will allow   |
| you to draw an eniterly new frame int othe buffer
\******************************************************************************/
void clearBuffer () {
  for (int i = 0; i < BUFFERSIZE; i++) {
    _cube_buffer[i] = 0;
  }
}

/**************************** NEXT COLOR FUNCTIONS ****************************\
| These functions cycle thorugh                                                |
|  the three primary colors red, greed, and blue                               |
|  the secondary colors purple, teal, yellow (every pairing of two leds)       |
|  the ALL THE COLORS (red,green,blue,purple,teal,yellow,white)                |
\******************************************************************************/
int nextPrimaryColor(int color)   { return  (color+1)%3; }
int nextSecondaryColor(int color) { return ((color+1)%3)+3; }
int nextColor(int color)          { return  (color+1)%7; }

/********************************** SWAP INT **********************************\
| This function uses the fast xor swap to change the values of the two         |
| intigers passed into the function                                            |
\******************************************************************************/
void swapint(int & one, int & two) {
  one = one^two;
  two = one^two;
  one = one^two;
}

/******************************* ROUND CLOSTEST *******************************\
| This function takes in a numberator and denominator and rounds to the        |
| nearist number instead of trunkating. It does this by calculating an extra   |
| digit (this function should be changes to be more accurate)                  |
\******************************************************************************/
int roundClostest(int numerator, int denominator) {
  numerator = (numerator << 1)/denominator;
  int output = (numerator>>1) + (numerator % 2);
  return output;
}

  //////////////////////////////////////////////////////////////////////////////
 /////////////////////////////////// DRAWING //////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

#define B 0
#define G 1
#define R 2
#define T 3
#define Y 4
#define P 5
#define W 6
#define O 7

#define blue 0
#define green 1
#define red 2
#define teal 3
#define yellow 4
#define purple 5
#define white 6
#define off -7

/********************************** DRAW LED **********************************\
| This function turns on leds at a specified position. Depending on which      |
| color this function turns on different colors of the LED                     |
\******************************************************************************/
void drawLed(int color, int brightness, int x, int y, int z) {
  
  if ((color/3)==0) {												// single color (red green blue)
  //_cube_buffer[(((color+1)%3)*64)+(x*16)+(y*4)+z] += 0;
    _cube_buffer[(((color)%3)*27)+(x*9)+(y*3)+z] += brightness;
  }else if ((color/3)==1) {											// double color (teal yellow purple)
    _cube_buffer[(((color)%3)*27)+(x*9)+(y*3)+z] += brightness;
    _cube_buffer[(((color+1)%3)*27)+(x*9)+(y*3)+z] += brightness;
  }else if (color == 6){											// all colors (white)
    _cube_buffer[((0)*27)+(x*9)+(y*3)+z] += brightness;
    _cube_buffer[((1)*27)+(x*9)+(y*3)+z] += brightness;
    _cube_buffer[((2)*27)+(x*9)+(y*3)+z] += brightness;
  }else if (color == -7) {											// off all colors = 0
    _cube_buffer[((0)*27)+(x*9)+(y*3)+z] = 0;
    _cube_buffer[((1)*27)+(x*9)+(y*3)+z] = 0;
    _cube_buffer[((2)*27)+(x*9)+(y*3)+z] = 0;
  }
}
void drawLed(int color, int x, int y, int z) {
  drawLed(color,255,x,y,z);
}

/********************************** DRAW BOX **********************************\
| This function will draw a filled in box of the specified color on the cube   |
\******************************************************************************/
void drawBox(int color, int brightness, int startx, int starty, int startz, int endx, int endy, int endz) {
	if (startx > endx) swapint(startx, endx);
	if (starty > endy) swapint(starty, endy);
	if (startz > endz) swapint(startz, endz);

	for (int i = startx; i <= endx; i++) {
		for (int j = starty; j <= endy; j++) {
			for (int k = startz; k <= endz; k++) {
				drawLed(color, brightness, i, j, k);
			}
		}
	}
}
void drawBox(int color, int startx, int starty, int startz, int endx, int endy, int endz) {
	drawBox(color, 8, startx, starty, startz, endx, endy, endz);
}
/******************************* DRAW HOLLOW BOX ******************************\
| This function will draw the walls, celing, and floor of a defined box        |
\******************************************************************************/
void drawHollowBox(int color, int brightness, int startx, int starty, int startz, int endx, int endy, int endz) {
	if (startx > endx) swapint(startx, endx);
	if (starty > endy) swapint(starty, endy);
	if (startz > endz) swapint(startz, endz);


	for (int i = startx; i <= endx; i++) {
		for (int j = starty; j <= endy; j++) {
			for (int k = startz; k <= endz; k++) {
				if (i == startx || i == endx || j == starty || j == endy || k == startz || k == endz) {
					drawLed(color, brightness, i, j, k);
				}
			}
		}
	}
}
void drawHollowBox(int color, int startx, int starty, int startz, int endx, int endy, int endz) {
	drawHollowBox(color, 255, startx, starty, startz, endx, endy, endz);
}
/****************************** DRAW BOX OUTLINE ******************************\
| This function will draw edges of a defined box but none of the planes        |
\******************************************************************************/
void drawBoxOutline(int color, int brightness, int startx, int starty, int startz, int endx, int endy, int endz) {
	if (startx > endx) swapint(startx, endx);
	if (starty > endy) swapint(starty, endy);
	if (startz > endz) swapint(startz, endz);


	for (int i = startx; i <= endx; i++) {
		for (int j = starty; j <= endy; j++) {
			for (int k = startz; k <= endz; k++) {
				int sum = (i == startx) + (i == endy) + (j == starty) + (j == endy) + (k == startz) + (k == endz);
				if (sum >= 2) {
					drawLed(color, brightness, i, j, k);
				}
			}
		}
	}
}
void drawBoxOutline(int color, int startx, int starty, int startz, int endx, int endy, int endz) {
	drawHollowBox(color, 255, startx, starty, startz, endx, endy, endz);
}
/******************************* DRAW BOX WALLS *******************************\
| This function will draw the virtical walls and all four sides of a defined   |
| box                                                                          |
\******************************************************************************/
void drawBoxWalls(int color, int brightness, int startx, int starty, int startz, int endx, int endy, int endz) {
	if (startx > endx) swapint(startx, endx);
	if (starty > endy) swapint(starty, endy);
	if (startz > endz) swapint(startz, endz);

	for (int i = startz; i <= endz; i++) {
		// draw y walls
		for (int j = starty; j <= endy; j++) {
			drawLed(color, brightness, startx, j, i);
			drawLed(color, brightness, endx, j, i);
		}
		// draw x walls
		for (int j = startx; j <= endx; j++) {
			drawLed(color, brightness, j, starty, i);
			drawLed(color, brightness, j, endy, i);
		}
	}
}
void drawBoxWalls(int color, int startx, int starty, int startz, int endx, int endy, int endz) {
	drawBoxWalls(color, 255, startx, starty, startz, endx, endy, endz);
}
/********************************** DRAW LINE *********************************\
| This function will attempt to draw a line between the two points given. Due  |
| to the limited avalibility of pixels the best approximation is chosen for    |
| each pixel value                                                             |
\******************************************************************************/
void drawLine(int color, int brightness, int startx, int starty, int startz, int endx, int endy, int endz) {
	bool reverseX = false;
	bool reverseY = false;
	bool reverseZ = false;
	if (startx > endx) { swapint(startx, endx); reverseX = true; }
	if (starty > endy) { swapint(starty, endy); reverseY = true; }
	if (startz > endz) { swapint(startz, endz); reverseZ = true; }

	int delx = endx - startx;
	int dely = endy - starty;
	int delz = endz - startz;

	int longest = (delx>dely ? delx>delz ? delx : delz>dely ? delz : dely : dely>delz ? dely : delz>delx ? delz : delx);
	for (int i = 0; i < longest; i++) {
		int xpos;
		if (reverseX) xpos = roundClostest(((longest - i)*delx), longest) + startx;
		else xpos = roundClostest((i*delx), longest) + startx;

		int ypos;
		if (reverseY) ypos = roundClostest(((longest - i)*dely), longest) + starty;
		else ypos = roundClostest((i*dely), longest) + starty;

		int zpos;
		if (reverseZ) zpos = roundClostest(((longest - i)*delz), longest) + startz;
		else zpos = roundClostest((i*delz), longest) + startz;

		drawLed(color, brightness, xpos, ypos, zpos);
	}

	if (reverseX) swapint(startx, endx);
	if (reverseY) swapint(starty, endy);
	if (reverseZ) swapint(startz, endz);
	drawLed(color, brightness, endx, endy, endz);
}
void drawLine(int color, int startx, int starty, int startz, int endx, int endy, int endz) {
	drawLine(color, 8, startx, starty, startz, endx, endy, endz);
}

  //////////////////////////////////////////////////////////////////////////////
 /////////////////////////////////// DISPLAY //////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
int pwmm = 0;
int display_length;
void flushElement(_frame_light* &copy_frame,int pin1,int pin2,int brightness) {
  pin1 -= 2;
  pin2 -= 2;
  
  (copy_frame+1)->next=copy_frame;
  copy_frame++;
  copy_frame->pin1=pin1 | ( brightness & 0xF0);
  copy_frame->pin2=pin2 | ((brightness & 0x0F) << 4);
  display_length++;
}
/******************************** FLUSH BUFFER ********************************\
| This takes the buffer frame and sets the display memory to match, because    |
| the display memory needs to be faster it is split up into two arrays instead |
| of just one. The display frame is actually a ciclic linked list which allows |
| the program to just loop through and turn on the LEDs without the need to    |
| check to see if it is at the end of the loop                                 |
\******************************************************************************/

void flushBuffer() {
  _frame_light * copy_frame = _cube__frame;
  display_length = 0;
  
  
  //TODO the pins values need to be changed so that the mapping.h file can
  // change them using #defines

  // Custom Table Mirco
  
  //BLAU ANFANG
  if (_cube_buffer[  0] != 0)flushElement(copy_frame,13,10,_cube_buffer[  0]);
  if (_cube_buffer[  1] != 0)flushElement(copy_frame, 7,13,_cube_buffer[  1]);
  if (_cube_buffer[  2] != 0)flushElement(copy_frame, 4, 7,_cube_buffer[  2]);

  if (_cube_buffer[  3] != 0)flushElement(copy_frame, 2,11,_cube_buffer[  3]);
  if (_cube_buffer[  4] != 0)flushElement(copy_frame, 8, 2,_cube_buffer[  4]);
  if (_cube_buffer[  5] != 0)flushElement(copy_frame, 4, 8,_cube_buffer[  5]);

  if (_cube_buffer[  6] != 0)flushElement(copy_frame, 3,12,_cube_buffer[  6]);
  if (_cube_buffer[  7] != 0)flushElement(copy_frame, 9, 3,_cube_buffer[  7]);
  if (_cube_buffer[  8] != 0)flushElement(copy_frame, 4, 9,_cube_buffer[  8]);


  if (_cube_buffer[  9] != 0)flushElement(copy_frame,13,11,_cube_buffer[  9]);
  if (_cube_buffer[ 10] != 0)flushElement(copy_frame, 9,13,_cube_buffer[ 10]);
  if (_cube_buffer[ 11] != 0)flushElement(copy_frame, 5, 9,_cube_buffer[ 11]);

  if (_cube_buffer[ 12] != 0)flushElement(copy_frame, 2,12,_cube_buffer[ 12]);
  if (_cube_buffer[ 13] != 0)flushElement(copy_frame, 7, 2,_cube_buffer[ 13]);
  if (_cube_buffer[ 14] != 0)flushElement(copy_frame, 5, 7,_cube_buffer[ 14]);

  if (_cube_buffer[ 15] != 0)flushElement(copy_frame, 3,10,_cube_buffer[ 15]);
  if (_cube_buffer[ 16] != 0)flushElement(copy_frame, 8, 3,_cube_buffer[ 16]);
  if (_cube_buffer[ 17] != 0)flushElement(copy_frame, 5, 8,_cube_buffer[ 17]);


  if (_cube_buffer[ 18] != 0)flushElement(copy_frame,13,12,_cube_buffer[ 18]);
  if (_cube_buffer[ 19] != 0)flushElement(copy_frame, 8,13,_cube_buffer[ 19]);
  if (_cube_buffer[ 20] != 0)flushElement(copy_frame, 6, 8,_cube_buffer[ 20]);

  if (_cube_buffer[ 21] != 0)flushElement(copy_frame, 2,10,_cube_buffer[ 21]);
  if (_cube_buffer[ 22] != 0)flushElement(copy_frame, 9, 2,_cube_buffer[ 22]);
  if (_cube_buffer[ 23] != 0)flushElement(copy_frame, 6, 9,_cube_buffer[ 23]);

  if (_cube_buffer[ 24] != 0)flushElement(copy_frame, 3,11,_cube_buffer[ 24]);
  if (_cube_buffer[ 25] != 0)flushElement(copy_frame, 7, 3,_cube_buffer[ 25]);
  if (_cube_buffer[ 26] != 0)flushElement(copy_frame, 6, 7,_cube_buffer[ 26]);
  //BLAU ENDE
  //GRÜN ANFANG
  if (_cube_buffer[ 27] != 0)flushElement(copy_frame,13, 4,_cube_buffer[ 27]);
  if (_cube_buffer[ 28] != 0)flushElement(copy_frame, 7,10,_cube_buffer[ 28]);
  if (_cube_buffer[ 29] != 0)flushElement(copy_frame, 4,13,_cube_buffer[ 29]);

  if (_cube_buffer[ 30] != 0)flushElement(copy_frame, 2, 4,_cube_buffer[ 30]);
  if (_cube_buffer[ 31] != 0)flushElement(copy_frame, 8,11,_cube_buffer[ 31]);
  if (_cube_buffer[ 32] != 0)flushElement(copy_frame, 4, 2,_cube_buffer[ 32]);

  if (_cube_buffer[ 33] != 0)flushElement(copy_frame, 3, 4,_cube_buffer[ 33]);
  if (_cube_buffer[ 34] != 0)flushElement(copy_frame, 9,12,_cube_buffer[ 34]);
  if (_cube_buffer[ 35] != 0)flushElement(copy_frame, 4, 3,_cube_buffer[ 35]);


  if (_cube_buffer[ 36] != 0)flushElement(copy_frame,13, 5,_cube_buffer[ 36]);
  if (_cube_buffer[ 37] != 0)flushElement(copy_frame, 9,11,_cube_buffer[ 37]);
  if (_cube_buffer[ 38] != 0)flushElement(copy_frame, 5,13,_cube_buffer[ 38]);

  if (_cube_buffer[ 39] != 0)flushElement(copy_frame, 2, 5,_cube_buffer[ 39]);
  if (_cube_buffer[ 40] != 0)flushElement(copy_frame, 7,12,_cube_buffer[ 40]);
  if (_cube_buffer[ 41] != 0)flushElement(copy_frame, 5, 2,_cube_buffer[ 41]);

  if (_cube_buffer[ 42] != 0)flushElement(copy_frame, 3, 5,_cube_buffer[ 42]);
  if (_cube_buffer[ 43] != 0)flushElement(copy_frame, 8,10,_cube_buffer[ 43]);
  if (_cube_buffer[ 44] != 0)flushElement(copy_frame, 5, 3,_cube_buffer[ 44]);


  if (_cube_buffer[ 45] != 0)flushElement(copy_frame,13, 6,_cube_buffer[ 45]);
  if (_cube_buffer[ 46] != 0)flushElement(copy_frame, 8,12,_cube_buffer[ 46]);
  if (_cube_buffer[ 47] != 0)flushElement(copy_frame, 6,13,_cube_buffer[ 47]);

  if (_cube_buffer[ 48] != 0)flushElement(copy_frame, 2, 6,_cube_buffer[ 48]);
  if (_cube_buffer[ 49] != 0)flushElement(copy_frame, 9,10,_cube_buffer[ 49]);
  if (_cube_buffer[ 50] != 0)flushElement(copy_frame, 6, 2,_cube_buffer[ 50]);

  if (_cube_buffer[ 51] != 0)flushElement(copy_frame, 3, 6,_cube_buffer[ 51]);
  if (_cube_buffer[ 52] != 0)flushElement(copy_frame, 7,11,_cube_buffer[ 52]);
  if (_cube_buffer[ 53] != 0)flushElement(copy_frame, 6, 3,_cube_buffer[ 53]);
  //GRÜN ENDE
  //ROT  ANFANG
  if (_cube_buffer[ 54] != 0)flushElement(copy_frame,13, 7,_cube_buffer[ 54]);
  if (_cube_buffer[ 55] != 0)flushElement(copy_frame, 7, 4,_cube_buffer[ 55]);
  if (_cube_buffer[ 56] != 0)flushElement(copy_frame, 4,10,_cube_buffer[ 56]);

  if (_cube_buffer[ 57] != 0)flushElement(copy_frame, 2, 8,_cube_buffer[ 57]);
  if (_cube_buffer[ 58] != 0)flushElement(copy_frame, 8, 4,_cube_buffer[ 58]);
  if (_cube_buffer[ 59] != 0)flushElement(copy_frame, 4,11,_cube_buffer[ 59]);

  if (_cube_buffer[ 60] != 0)flushElement(copy_frame, 3, 9,_cube_buffer[ 60]);
  if (_cube_buffer[ 61] != 0)flushElement(copy_frame, 9, 4,_cube_buffer[ 61]);
  if (_cube_buffer[ 62] != 0)flushElement(copy_frame, 4,12,_cube_buffer[ 62]);


  if (_cube_buffer[ 63] != 0)flushElement(copy_frame,13, 9,_cube_buffer[ 63]);
  if (_cube_buffer[ 64] != 0)flushElement(copy_frame, 9, 5,_cube_buffer[ 64]);
  if (_cube_buffer[ 65] != 0)flushElement(copy_frame, 5,11,_cube_buffer[ 65]);

  if (_cube_buffer[ 66] != 0)flushElement(copy_frame, 2, 7,_cube_buffer[ 66]);
  if (_cube_buffer[ 67] != 0)flushElement(copy_frame, 7, 5,_cube_buffer[ 67]);
  if (_cube_buffer[ 68] != 0)flushElement(copy_frame, 5,12,_cube_buffer[ 68]);
  
  if (_cube_buffer[ 69] != 0)flushElement(copy_frame, 3, 8,_cube_buffer[ 69]);
  if (_cube_buffer[ 70] != 0)flushElement(copy_frame, 8, 5,_cube_buffer[ 70]);
  if (_cube_buffer[ 71] != 0)flushElement(copy_frame, 5,10,_cube_buffer[ 71]);


  if (_cube_buffer[ 72] != 0)flushElement(copy_frame,13, 8,_cube_buffer[ 72]);
  if (_cube_buffer[ 73] != 0)flushElement(copy_frame, 8, 6,_cube_buffer[ 73]);
  if (_cube_buffer[ 74] != 0)flushElement(copy_frame, 6,12,_cube_buffer[ 74]);

  if (_cube_buffer[ 75] != 0)flushElement(copy_frame, 2, 9,_cube_buffer[ 75]);
  if (_cube_buffer[ 76] != 0)flushElement(copy_frame, 9, 6,_cube_buffer[ 76]);
  if (_cube_buffer[ 77] != 0)flushElement(copy_frame, 6,10,_cube_buffer[ 77]);

  if (_cube_buffer[ 78] != 0)flushElement(copy_frame, 3, 7,_cube_buffer[ 78]);
  if (_cube_buffer[ 79] != 0)flushElement(copy_frame, 7, 6,_cube_buffer[ 79]);
  if (_cube_buffer[ 80] != 0)flushElement(copy_frame, 6,11,_cube_buffer[ 80]);
  //ROT  ENDE

  (_cube__frame+1)->next=copy_frame;
  _cube_current_frame=_cube__frame+1;
}


/*************************** INTERRUPT DISPLAY LEDS ***************************\
| This is the interrupt function to turn on one led. After it turns that one   |
| on it will 
\******************************************************************************/
byte pinsB[] = {P1B,P2B,P3B,P4B,P5B,P6B,P7B,P8B,P9B,P10B,P11B,P12B,P13B,P14B,P15B,P16B};
byte pinsC[] = {P1C,P2C,P3C,P4C,P5C,P6C,P7C,P8C,P9C,P10C,P11C,P12C,P13C,P14C,P15C,P16C};
byte pinsD[] = {P1D,P2D,P3D,P4D,P5D,P6D,P7D,P8D,P9D,P10D,P11D,P12D,P13D,P14D,P15D,P16D};
#ifndef PWMMAX
  #define PWMMMAX 8
#endif
#define FULL PWMMMAX
#define HALF PWMMMAX/2
// the interrupt function to display the leds
ISR(TIMER2_OVF_vect) {
  int pin1 = _cube_current_frame->pin1;
  int pin2 = _cube_current_frame->pin2;
  int count = (pin1 & 0xF0) | ((pin2 & 0xF0)>>4);
  pin1 = pin1&0x0F;
  pin2 = pin2&0x0F;
  PORTB = 0x00;
  PORTC = 0x00;
  PORTD = 0x00;
  if (count > pwmm){
  
    DDRB = pinsB[pin1] | pinsB[pin2];
    DDRC = pinsC[pin1] | pinsC[pin2];
    DDRD = pinsD[pin1] | pinsD[pin2];
  
    PORTB = pinsB[pin1];
    PORTC = pinsC[pin1];
    PORTD = pinsD[pin1];
    
  }
  _cube_current_frame = _cube_current_frame->next;
  if (_cube_current_frame == _cube__frame+1){
    pwmm = (pwmm+1); //%PWMMMAX; // oooook so the modulus function is just a tincy bit toooooo slow when only one led is on
    if (pwmm == PWMMMAX) pwmm = 0; // by too slow i mean "to slow for the program to process an update" here is the fix
  }
}

/******************************************************************************\
| Some helpfull info for overflowing timers with different prescaler values    |
|  16000000 / (   1*256) = 16000000 / 256    =  62500 Hz                       |
|  16000000 / (   8*256) = 16000000 / 2048   =  ~7812 Hz                       |
|  16000000 / (  32*256) = 16000000 / 8192   =  ~1953 Hz                       |
|  16000000 / (  64*256) = 16000000 / 16384  =   ~976 Hz                       |
|  16000000 / ( 128*256) = 16000000 / 32768  =   ~488 Hz                       | 
|  16000000 / ( 256*256) = 16000000 / 65536  =   ~244 Hz                       |
|  16000000 / (1024*256) = 16000000 / 262144 =    ~61 Hz                       |
\******************************************************************************/
int animationTimer = 0;
int animationMax = 0;

ISR(TIMER1_OVF_vect) {
  animationTimer++;
  if (animationTimer == animationMax) {
    continuePattern = false;
    animationTimer=0;
  }
}

#endif
