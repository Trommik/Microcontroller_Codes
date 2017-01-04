#include <Adafruit_NeoPixel.h>

//##NEOPIXELS##//
#define PIN 6
#define num_leds 289

Adafruit_NeoPixel strip = Adafruit_NeoPixel(num_leds, PIN, NEO_GRB + NEO_KHZ800);
//##NEOPIXELS##//

//##SERIAL##//
char incomingByte = 0;   // for incoming serial data
String str = "";
byte p = 6;

byte serial = 2;
//##SERIAL##//

//##CONTROLLS##//
String aixs_v_str = "";
String aixs_h_str = "";

float right;
float left;
float up;
float down;
//##CONTROLLS##//




//##GAME##//
const byte gridX = 17;
const byte gridY = 17;

int numPixels = gridX * gridY;

boolean GameRunning;

int moveSpeed = 50;

byte spaceshipPosX;
byte spaceshipPosY;

byte spaceshipPosX_OLD;
byte spaceshipPosY_OLD;

byte spaceshipDirection = 0;

byte rockCount = 0;
byte rocks;
byte minRocks = 1;
byte maxRocks = 4;

byte rockPosX[50];
byte rockPosY[50];

byte rockPosX_OLD[50];
byte rockPosY_OLD[50];

float rockMoveX[50];
float rockMoveY[50];

//##PLAYFIELD##//
byte Playfield[gridX][gridY];

#define BLANK 0
#define SPACESHIP_ROT 1
#define SPACESHIP_GRUN 2
#define SPACESHIP_BLAU 3
#define POWERUP 4
#define EXPLODED 5
#define ROCK 6
//##PLAYFIELD##//

//##MOVEMENT##//
#define STOP 0
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
//##MOVEMENT##//

//##COLORS##//


//##COLORS##//

//##CHARACTERS##//

byte spaceship_lenght = 4;
byte spaceship_height = 2;

byte rock_lenght = 2;
byte rock_height = 2;

//##CHARACTERS##//        


//##GAME##//

void setup(){  
  Serial.begin(9600);
  Serial1.begin(9600);

  randomSeed(A0);

  strip.begin();
  strip.show();
  // Initialize all pixels to 'off'
}

long timeBefore = millis();

void loop() {
  if(serial == 1){
    if ((millis() >= (timeBefore+moveSpeed)) && (GameRunning == true)) {
      moveItems();
      timeBefore = millis();
    }
    
    if(Serial1.available() >= 1){
      str = "";
      for(int i = 0; i < 1; i++){
        incomingByte = (char)Serial1.read();
        str += incomingByte;
      }
      Serial.println(str);
      if (str == "g"){//Start
        serial = 2;
      }else if( str == "d"){
        spaceshipDirection = RIGHT;
      }else if( str == "a"){
        spaceshipDirection = LEFT;
      }else if( str == "s"){
        spaceshipDirection = DOWN;
      }else if( str == "w"){
        spaceshipDirection = UP;
      }else if( str == "v"){
        delay(8);
        if(Serial1.available() >= 6){
          aixs_v_str  = "";
          for(int i = 0; i < p; i++){
            incomingByte = (char)Serial1.read();
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
        if(up > 0.800){
          spaceshipDirection = UP;
          up = 0;
        }else if(down > 0.800){
          spaceshipDirection = DOWN;
          down = 0;
        }
      }else if( str == "h"){
        delay(8);
        if(Serial1.available() >= 6){
          aixs_h_str  = "";
          for(int i = 0; i < p; i++){
            incomingByte = (char)Serial1.read();
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
        if(right > 0.800){
          spaceshipDirection = RIGHT;
          right = 0;
        }else if(left > 0.800){
          spaceshipDirection = LEFT;
          left = 0;
        }
      }
    }
  }else if(serial == 2){
    clearLEDs(); 
    
    for(int i = 0; i < moveSpeed/5 ; i++){
      strip.setPixelColor(i, strip.Color(0,0,255));
    }
    strip.show(); 
    
    if(Serial1.available() >= 1){
      str = "";
      for(int i = 0; i < 1; i++){
        incomingByte = (char)Serial1.read();
        str += incomingByte;
      }
      
      if( str == "s"){
        moveSpeed -= 5;
      }else if( str == "w"){
        moveSpeed += 5;
      }else if( str == "d"){
        serial = 1;
        newGame();
      }else if( str == "a"){
        if (GameRunning == true){
          serial = 1;
        }
      }
    }
  }
}

void clearLEDs(){for (int i=0; i<num_leds; i++){strip.setPixelColor(i, 0);}}

void newGame(void){

  for (int y = 0; y <= gridY; y++){
    for (int x = 0; x <= gridX; x++){
      Playfield[x][y] = BLANK;
    }
  }
  
  clearLEDs();

  spaceshipPosX = random(gridX - spaceship_height);
  spaceshipPosY = random(gridY - spaceship_lenght);

  spaceshipDirection = STOP;

  setSpaceship(spaceshipPosX_OLD, spaceshipPosY_OLD,1);
  setSpaceship(spaceshipPosX, spaceshipPosY,0);
    
  rockCount = 0;
  randomRocks(random(minRocks,maxRocks));
  
  GameRunning = true; 
  render(); 
  timeBefore = millis();
}

void randomRocks(int rocks){
  for(int i = 0; i < rocks; i++){
    rockPosX[i] = random(0,17);
    rockPosY[i] = 17;

    float X = random(-1000,1000);
    float Y = random(-1000,0);

    rockMoveX[i] = X/1000;
    rockMoveY[i] = Y/1000;

    rockCount = rocks;
  }
}

void moveItems(void){

  spaceshipPosX_OLD = spaceshipPosX;
  spaceshipPosY_OLD = spaceshipPosY;

  switch (spaceshipDirection) {
    case UP:
      spaceshipPosX -= 1;
      spaceshipDirection = STOP;
      break;
    case DOWN:
      spaceshipPosX += 1;
      spaceshipDirection = STOP;
      break;
    case LEFT:
      spaceshipPosY -= 1;
      spaceshipDirection = STOP;
      break;
    case RIGHT:
      spaceshipPosY += 1;
      spaceshipDirection = STOP;
      break;
    case STOP:
      spaceshipPosY == spaceshipPosY;
      spaceshipPosX == spaceshipPosX;
      break;
  }

  for(int i = 0; i < rockCount; i++){ 
    rockPosX_OLD[i] = rockPosX[i];
    rockPosY_OLD[i] = rockPosY[i];
  
    rockPosX[i] += rockMoveX[i];
    rockPosY[i] += rockMoveY[i];

    if(rockPosX[i] > gridX+3 || rockPosY[i] > gridY+3 || rockPosX[i] < -3 || rockPosY[i] < -3){
      randomRocks(3);
      
    }else{
      setRock(rockPosX_OLD[i], rockPosY_OLD[i],1);
      setRock(rockPosX[i], rockPosY[i],0);
    }
  }
  if(spaceshipPosX > gridX - spaceship_height || spaceshipPosY > gridY - spaceship_lenght || spaceshipPosX < 0 || spaceshipPosY < 0){
    //SPACASHIP OUT OF MATRIX 
    GameRunning = false;
    
    for (int y = 0; y <= gridY; y++){
      for (int x = 0; x <= gridX; x++){
        Playfield[x][y] = BLANK;
      }
    }

    render();

    YouLost();
  }else{
    setSpaceship(spaceshipPosX_OLD, spaceshipPosY_OLD,1);
    setSpaceship(spaceshipPosX, spaceshipPosY,0);
    render();
  }
}

void render(void){
  
  for (int x = 0; x <= gridX -1; x++){
    for (int y = 0; y <= gridY -1 ; y++){
      switch (Playfield[x][y]) {
        case BLANK:
          setXYpixel(x, y, 0, 0, 0); // Weisses Welltall
          break;
        case SPACESHIP_ROT:
          setXYpixel(x, y, 255, 0, 0); // Rotes Spaceship
          break;
        case SPACESHIP_GRUN:
          setXYpixel(x, y, 0, 255, 0); // Grünes Spaceship
          break;
        case SPACESHIP_BLAU:
          setXYpixel(x, y, 0, 0, 255); // Blaues Spaceship
          break;
        case ROCK:
          setXYpixel(x, y, 153, 76, 0); // Brauner Rock
          break;
        case EXPLODED:
          setXYpixel(x, y, 255, 0, 0); // Rote Explosion
          break;
      }
    }
  }

  strip.show();
}

void YouLost(void){
  strip.setPixelColor( 35  , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 66  , strip.Color( 255, 0, 0));   
  strip.setPixelColor( 70  , strip.Color( 255, 0, 0));   
  strip.setPixelColor( 99  , strip.Color( 255, 0, 0));   
  strip.setPixelColor( 104 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 37  , strip.Color( 255, 0, 0));   
  strip.setPixelColor( 64  , strip.Color( 255, 0, 0));   
  strip.setPixelColor( 39  , strip.Color( 255, 0, 0));   
  strip.setPixelColor( 62  , strip.Color( 255, 0, 0));   
  strip.setPixelColor( 73  , strip.Color( 255, 0, 0));   
  strip.setPixelColor( 96  , strip.Color( 255, 0, 0));   
  strip.setPixelColor( 107 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 108 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 109 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 41  , strip.Color( 255, 0, 0));   
  strip.setPixelColor( 60  , strip.Color( 255, 0, 0));   
  strip.setPixelColor( 75  , strip.Color( 255, 0, 0));   
  strip.setPixelColor( 94  , strip.Color( 255, 0, 0));   
  strip.setPixelColor( 44  , strip.Color( 255, 0, 0));   
  strip.setPixelColor( 45  , strip.Color( 255, 0, 0));   
  strip.setPixelColor( 46  , strip.Color( 255, 0, 0));   
  strip.setPixelColor( 55  , strip.Color( 255, 0, 0));   
  strip.setPixelColor( 80  , strip.Color( 255, 0, 0));   
  strip.setPixelColor( 89  , strip.Color( 255, 0, 0));   
  strip.setPixelColor( 112 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 113 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 114 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 171 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 202 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 205 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 236 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 239 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 240 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 241 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 175 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 176 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 177 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 178 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 198 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 209 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 232 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 243 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 244 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 245 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 195 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 212 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 229 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 246 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 180 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 181 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 182 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 193 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 214 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 215 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 216 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 225 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 248 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 249 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 250 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 184 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 185 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 186 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 188 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 219 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 222 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 253 , strip.Color( 255, 0, 0));    
  strip.setPixelColor( 43  , strip.Color( 255, 0, 0));   
  strip.setPixelColor( 58  , strip.Color( 255, 0, 0));   
  strip.setPixelColor( 77  , strip.Color( 255, 0, 0));   
  strip.setPixelColor( 111 , strip.Color( 255, 0, 0));
  strip.setPixelColor( 92  , strip.Color( 255, 0, 0));
  
  strip.show();
}


void setRock(int x, int y, boolean blank){
  if(blank == 0){

    for (int i = 1; i < rock_lenght; i++){
      Playfield[x+1][y+i] = ROCK;
    }

    Playfield[x][y+1] = ROCK;
    Playfield[x+2][y+3] = ROCK;
  }else if(blank == 1){
    for (int i = 1; i < rock_lenght; i++){
      Playfield[x+1][y+i] = BLANK;
    }

    Playfield[x][y+1] = BLANK;
    Playfield[x+2][y+3] = BLANK;
  }
}

void setSpaceship(int x, int y, boolean blank){
  if(blank == 0){
    Playfield[x+1][y] = SPACESHIP_ROT;

    for (int i = 1; i < spaceship_lenght; i++){
      Playfield[x+1][y+i] = SPACESHIP_GRUN;
    }

    Playfield[x][y+1] = SPACESHIP_BLAU;
    Playfield[x][y+2] = SPACESHIP_BLAU;
  }else if(blank == 1){
    Playfield[x+1][y] = BLANK;
    
    for (int i = 1; i < spaceship_lenght; i++){
      Playfield[x+1][y+i] = BLANK;
    }
    
    Playfield[x][y+1] = BLANK;
    Playfield[x][y+2] = BLANK;
  }
}

void setXYpixel(int x, int y, int R, int G, int B) {
  if ((x % 2) > 0){
    strip.setPixelColor(((x*17)+16)-y, strip.Color( R, G, B)); //Formel: xy_PIXEL gerades Y= (x*gridX)+y
    //Serial.println(((x*17)+16)-y);
  }else{
    strip.setPixelColor((x*17)+y, strip.Color( R, G, B)); //Formel: xy_PIXEL ungerades Y= ((x*gridX)+(gridY-1))-y
    //Serial.println((x*17)+y);
  }
}

