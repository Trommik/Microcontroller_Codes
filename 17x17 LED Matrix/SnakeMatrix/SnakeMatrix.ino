#include <Adafruit_NeoPixel.h>

#define PIN 6
#define num_leds 289

// Set the first variable to the NUMBER of pixels. 25 = 25 pixels in a row
Adafruit_NeoPixel strip = Adafruit_NeoPixel(num_leds, PIN, NEO_GRB + NEO_KHZ800);

int SnakeSpeed = 340;
byte oldSnakeItems = 0;
byte oldSnakeItemPosX[70];
byte oldSnakeItemPosY[70];
byte SnakeItems = 0;
byte SnakeItemPosX[70];
byte SnakeItemPosY[70];
byte ApplePosX;
byte ApplePosY;
byte AppleMoveCountDown;
#define APPLE_COUNTDOWN_STEPS_MIN 17
#define APPLE_COUNTDOWN_STEPS_MAX 17*2

#define BaneGridXmax 17 // Bredden på banen
#define BaneGridYmax 17 // Højden på banen
#define BLANK 0
#define SNAKE 1
#define APPLE 2
byte Playfield[BaneGridXmax+1][BaneGridYmax+1];

	
byte SnakeHeadID = 0; // Array ID på forreste Snake item (Hoved)
byte SnakeBackID = 0; // Array ID på bagerste Snake item

byte AppleCount = 0;
	
#define SNAKE_RIGHT 0
#define SNAKE_LEFT 1
#define SNAKE_DOWN 2
#define SNAKE_UP 3
byte movingDirection = SNAKE_RIGHT; // Vores nuværende retning
byte snakeDirection = SNAKE_RIGHT; // Piletasternes/vores næste retning

byte AddSnakeItem = 0; // Tilføj et snake item næste gang vi flytter os

byte Score = 0;
boolean GameRunning = false;

char incomingByte = 0;   // for incoming serial data
String str = "";
byte p = 6;

byte serial = 2;

String aixs_v_str = "";
String aixs_h_str = "";

float right;
float left;
float up;
float down;

void setup()
{  
  Serial.begin(9600);
    
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

long timeBefore = millis();
void loop(){
  if(serial == 1){
    if ((millis() >= (timeBefore+SnakeSpeed)) && (GameRunning == true)) {
      moveSnake();
      timeBefore = millis();
    }
    
    if(Serial.available() >= 1){
      str = "";
      for(int i = 0; i < 1; i++){
        incomingByte = (char)Serial.read();
        str += incomingByte;
      }
      if (str == "g"){//Start
        serial = 2;
      }else if( str == "d"){
        if (snakeDirection != SNAKE_RIGHT){
          snakeDirection = SNAKE_LEFT;
        }
      }else if( str == "a"){
        if (snakeDirection != SNAKE_LEFT){
          snakeDirection = SNAKE_RIGHT;  
        }
      }else if( str == "s"){
        if (snakeDirection != SNAKE_DOWN){
          snakeDirection = SNAKE_UP;  
        }
      }else if( str == "w"){
        if (snakeDirection != SNAKE_UP){
          snakeDirection = SNAKE_DOWN;  
        }
      }else if( str == "v"){
        delay(8);
        if(Serial.available() >= 6){
          aixs_v_str  = "";
          for(int i = 0; i < p; i++){
            incomingByte = (char)Serial.read();
            aixs_v_str += incomingByte;
            if (i == 0 && aixs_v_str == "-"){p = 7;}
          }
          p = 6;
        }
        if(aixs_v_str.startsWith("-")){
          aixs_v_str = aixs_v_str.substring(1);
          up = aixs_v_str.toFloat();
        }else{
          down = aixs_v_str.toFloat();
        }
        if(down > 0){
          if (snakeDirection != SNAKE_DOWN){
            snakeDirection = SNAKE_UP;  
          }
          down = 0;
        }else if(up > 0){
          if (snakeDirection != SNAKE_UP){
            snakeDirection = SNAKE_DOWN;  
          }
          up = 0;
        }
      }else if( str == "h"){
        delay(8);
        if(Serial.available() >= 6){
          aixs_h_str  = "";
          for(int i = 0; i < p; i++){
            incomingByte = (char)Serial.read();
            aixs_h_str += incomingByte;
            if (i == 0 && aixs_h_str == "-"){p = 7;}
          }
          p = 6;
        }
        if(aixs_h_str.startsWith("-")){
          aixs_h_str = aixs_h_str.substring(1);
          left = aixs_h_str.toFloat();
        }else{
          right = aixs_h_str.toFloat();
        }
        if(right > 0){
          if (snakeDirection != SNAKE_RIGHT){
            snakeDirection = SNAKE_LEFT;  
          }
          right = 0;
        }else if(left > 0){
          if (snakeDirection != SNAKE_LEFT){
            snakeDirection = SNAKE_RIGHT;  
          }
          left = 0;
        }
      }
    }
  }else if(serial == 2){
    
    clearLEDs(); 
    for(int i = 0; i < SnakeSpeed/5 ; i++){
      strip.setPixelColor(i, strip.Color(0,0,255));
    }
    strip.show(); 
    
    if(Serial.available() >= 1){
      str = "";
      for(int i = 0; i < 1; i++){
        incomingByte = (char)Serial.read();
        str += incomingByte;
      }
      if( str == "s"){
        SnakeSpeed -= 5;
      }else if( str == "w"){
        SnakeSpeed += 5;
      }else if( str == "g"){
        serial = 1;
        NewGame();
      }else if( str == "a"){
        serial = 1;
      }
    }
  }
}

void clearLEDs(){for (int i=0; i<num_leds; i++){strip.setPixelColor(i, 0);}}

void NewGame(void){
  byte x, y;

  clearLEDs();
  
  SnakeItems = 2;
  SnakeHeadID = 1;
  SnakeItemPosX[1] = random(17);
  SnakeItemPosY[1] = random(17);
  movingDirection = SNAKE_RIGHT;
  snakeDirection = SNAKE_RIGHT;

  for (y = 1; y <= BaneGridYmax; y++)
  {
    for (x = 1; x <= BaneGridXmax; x++)
    {
      Playfield[x][y] = BLANK;
    }
  }
		
  AddSnakeItem = 0;
  AppleCount = 0;
  placeRandomApple();
  
  GameRunning = true; 
  render(); 
  timeBefore = millis();
}



void placeApple(byte x, byte y){
  if (x > 0 && y > 0 && x <= BaneGridXmax && y <= BaneGridYmax) {
    Playfield[x][y] = APPLE;
    ApplePosX = x;
    ApplePosY = y;
    AppleMoveCountDown = random(APPLE_COUNTDOWN_STEPS_MIN, APPLE_COUNTDOWN_STEPS_MAX);
			
    AppleCount++;
  }
}

void removeApple(void) {
  Playfield[ApplePosX][ApplePosY] = BLANK;
  AppleCount = 0; 
}

void render(void) { // Render de forskellige snake Items
  byte i, x, y;
  
  for (i=1; i <= oldSnakeItems; i++) {
    if (oldSnakeItemPosX[i] > 0 && oldSnakeItemPosY[i] > 0 && oldSnakeItemPosX[i] <= BaneGridXmax && oldSnakeItemPosY[i] <= BaneGridYmax) {
      Playfield[oldSnakeItemPosX[i]][oldSnakeItemPosY[i]] = BLANK;
    }
  }
		
  for (i=1; i <= SnakeItems; i++) {
    if (SnakeItemPosX[i] > 0 && SnakeItemPosY[i] > 0 && SnakeItemPosX[i] <= BaneGridXmax && SnakeItemPosY[i] <= BaneGridYmax) {			
      Playfield[SnakeItemPosX[i]][SnakeItemPosY[i]] = SNAKE;
      oldSnakeItemPosX[i] = SnakeItemPosX[i];
      oldSnakeItemPosY[i] = SnakeItemPosY[i];			
    }
  }
  oldSnakeItems = SnakeItems;
  
  if (AppleCount > 0 && AppleMoveCountDown == 0) {
    removeApple();
    placeRandomApple();
  } else if (AppleCount > 0) {
    AppleMoveCountDown--;
  }
  
  for (y = 1; y <= BaneGridYmax; y++)
  {
    for (x = 1; x <= BaneGridXmax; x++)
    {
      switch (Playfield[x][y]) {
        case BLANK:       
          setXYpixel((x-1), (y-1), 0, 0, 0);
          break;       
        case SNAKE:
          if (SnakeItemPosX[SnakeHeadID] == x && SnakeItemPosY[SnakeHeadID] == y)
            setXYpixel((x-1), (y-1), 0, 255, 0); // Yellow snake head
          else
            setXYpixel((x-1), (y-1), 0, 255, 0); // Green snake body
          break;  
        case APPLE:
          setXYpixel((x-1), (y-1), 255, 0, 0);
          break;   
      }          
    }
  }
  strip.show();
}

void moveSnake(void) {
  byte i;
  movingDirection = snakeDirection; // Sæt movingDirection til den retning vi har valgt med piletasterne

  if (AddSnakeItem == 0) { // Flyt det bagerste Snake Objekt til fronten, og sæt SnakeHeadID til dette objekts ID
    SnakeBackID = SnakeHeadID - 1;
    if (SnakeBackID == 0) SnakeBackID = SnakeItems;
    SnakeItemPosX[SnakeBackID] = SnakeItemPosX[SnakeHeadID];
    SnakeItemPosY[SnakeBackID] = SnakeItemPosY[SnakeHeadID];
    switch (movingDirection) {
      case SNAKE_RIGHT:
  SnakeItemPosX[SnakeBackID] += 1;
	break;
      case SNAKE_LEFT:
	SnakeItemPosX[SnakeBackID] -= 1;
	break;
      case SNAKE_DOWN:
	SnakeItemPosY[SnakeBackID] += 1;
	break;
      case SNAKE_UP:
	SnakeItemPosY[SnakeBackID] -= 1;
	break;
    }			
    SnakeHeadID = SnakeBackID;
  } else { // Skal vi tilføje et Snake objekt (AddSnakeItem > 0), da skal vi tilføje én foran, UDEN at fjerne den bagved
    for (i = SnakeItems; i >= SnakeHeadID; i--) {
      SnakeItemPosX[i+1] = SnakeItemPosX[i];
      SnakeItemPosY[i+1] = SnakeItemPosY[i];
    }
    SnakeItemPosX[SnakeHeadID] = SnakeItemPosX[SnakeHeadID+1];
    SnakeItemPosY[SnakeHeadID] = SnakeItemPosY[SnakeHeadID+1];
    switch (movingDirection) {
      case SNAKE_RIGHT:
  SnakeItemPosX[SnakeHeadID] += 1;
  break;
      case SNAKE_LEFT:
	SnakeItemPosX[SnakeHeadID] -= 1;
	break;
      case SNAKE_DOWN:
	SnakeItemPosY[SnakeHeadID] += 1;
	break;
      case SNAKE_UP:
	SnakeItemPosY[SnakeHeadID] -= 1;
	break;
    }	
			
    SnakeItems++;			
    AddSnakeItem--;
  }
		
    // Befinder vi os inden for banen?						
    if (SnakeItemPosX[SnakeHeadID] > 0 && SnakeItemPosX[SnakeHeadID] <= BaneGridXmax && SnakeItemPosY[SnakeHeadID] > 0 && SnakeItemPosY[SnakeHeadID] <= BaneGridYmax) {
      if (Playfield[SnakeItemPosX[SnakeHeadID]][SnakeItemPosY[SnakeHeadID]] != SNAKE) { // Er hovedets position på et blankt eller æble felt?
	if (Playfield[SnakeItemPosX[SnakeHeadID]][SnakeItemPosY[SnakeHeadID]] == APPLE) { // Er hovedets position på et æble felt
	  Score++;
	  AddSnakeItem += random(3); // Tilføj x-antal snake items (bliver tilføjet til fronten af snake løbende)
	  AppleCount--; // Fjern et æble fra RAM'en
	}			
	if (AppleCount == 0) { // Hvis der ikke er flere æbler på banen
	  placeRandomApple(); // placer da et æble et tilfældigt sted
	}
	render(); // Render Snake objekterne i de rigtige felter
      } else { // Game over da vi ramte ind i os selv (snake felt)
	GameOver();				
      }
    } else { // Game over da vi ramte ind i kanten
      GameOver();
    }		
  }


void placeRandomApple(void) {
  byte x, y;
  x = random(1, BaneGridXmax);
  y = random(1, BaneGridYmax);
  while (Playfield[x][y] != BLANK) {
    x = random(1, BaneGridXmax);
    y = random(1, BaneGridYmax);  
  }
  placeApple(x, y);
}

void setXYpixel(char x, char y, unsigned char R, unsigned char G, unsigned char B){ 
  if ((y % 2) > 0)
    strip.setPixelColor((((16-y+1) * 17) - (16-x+1)),strip.Color( R, G, B));
  else
    strip.setPixelColor((((16-y) * 17) + (16-x)),strip.Color( R, G, B));
}

void GameOver(void) {
  if (SnakeItemPosX[SnakeHeadID] == 0) SnakeItemPosX[SnakeHeadID]++;
  else if (SnakeItemPosX[SnakeHeadID] > BaneGridXmax) SnakeItemPosX[SnakeHeadID]--;
  if (SnakeItemPosY[SnakeHeadID] == 0) SnakeItemPosY[SnakeHeadID]++;
  else if (SnakeItemPosY[SnakeHeadID] > BaneGridYmax) SnakeItemPosY[SnakeHeadID]--;	
  
  if (SnakeHeadID < SnakeItems)	
    setXYpixel(SnakeItemPosX[SnakeHeadID+1]-1, SnakeItemPosY[SnakeHeadID+1]-1, 0, 255, 0); // Set second snake object to green (from yellow head color)
  else
    setXYpixel(SnakeItemPosX[1]-1, SnakeItemPosY[1]-1, 0, 255, 0); // Set second snake object to green (from yellow head color)
    
  setXYpixel(SnakeItemPosX[SnakeHeadID]-1, SnakeItemPosY[SnakeHeadID]-1, 255, 0, 0); // Dark orange if dead snake head
  strip.show();
  
  GameRunning = false;
}
