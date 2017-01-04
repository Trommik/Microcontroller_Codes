#include <Adafruit_NeoPixel.h>

#define PIN 6
#define num_leds 289

#define BLANK 0
#define SPACESHIP 1
#define ASTEROID 2

#define PIXEL_X 17
#define PIXEL_Y 17

#define nAsteroids 10

// Set the first variable to the NUMBER of pixels. 25 = 25 pixels in a row
Adafruit_NeoPixel strip = Adafruit_NeoPixel(num_leds, PIN, NEO_GRB + NEO_KHZ800);

int pixelC[17][17];

float speed = 2;

boolean gameRunning = true;

class spaceShip {
    public:
    float x, y = 8;

    float xSpeed, ySpeed;

    void dir(float x, float y) {
      if ((xSpeed <= -0.02) && (x >= 0.01)) {
        xSpeed = -0.01;
      }
      if ((xSpeed >= 0.02) && (x <= -0.01)) {
        xSpeed = 0.01;
      }
      if ((ySpeed <= -0.02) && (y >= 0.01)) {
        ySpeed = -0.01;
      }
      if ((ySpeed >= 0.02) && (y <= -0.01)) {
        ySpeed = 0.01;
      }

      xSpeed += x;
      ySpeed += y;

      if (xSpeed > 0.05) {
        xSpeed = 0.05;
      }
      if (xSpeed < -0.05) {
        xSpeed = -0.05;
      }
      if (ySpeed > 0.05) {
        ySpeed = 0.05;
      }
      if (ySpeed < -0.05) {
        ySpeed = -0.05;
      }

    }

    void update() {
      pixelC[int(x)][int(y)] = 0; // Set the color in the array

      x += xSpeed * speed;
      y += ySpeed * speed;

      // Hold it in the Playflield
      if (x < 0) {
        x = 0;
      }
      if (x > 16) {
        x = 16;
      }
      if (y < 0) {
        y = 0;
      }
      if (y > 16) {
        y = 16;
      }

      pixelC[int(x)][int(y)] = 1; // Set the color in the array
    }
};

class Asteroids {
    public:
    float x = 16;
    float y = int(random(0, 17));

    float xSpeed = random(-0.05, -0.01);
    float ySpeed = random(-0.05, 0.05);

    void update() {
      pixelC[int(x)][int(y)] = 0; // Set the color in the array

      x += xSpeed * speed;
      y += ySpeed * speed;

      if (x < 0) {
        x = 16;
        y = int(random(0, 17));
        xSpeed = random(-0.05, -0.01);
        ySpeed = random(-0.05, 0.05);
      }
      if (x > 17) {
        x = 16;
        y = int(random(0, 17));
        xSpeed = random(-0.05, -0.01);
        ySpeed = random(-0.05, 0.05);
      }
      if (y < 0) {
        x = 16;
        y = int(random(0, 17));
        xSpeed = random(-0.05, -0.01);
        ySpeed = random(-0.05, 0.05);
      }
      if (y > 17) {
        x = 16;
        y = int(random(0, 17));
        xSpeed = random(-0.05, -0.01);
        ySpeed = random(-0.05, 0.05);
      }

      pixelC[int(x)][int(y)] = 2; // Set the color in the array
    }
    /*
      void checkCollision() {
        if ((int(x)  == int(*spaceShip_x))&&(int(*spaceShip_y) == int(P.y))) {
          //Serial.println("COLLISION");
          //gameRunning = false;
        }
      }*/
};

spaceShip P;
Asteroids A[nAsteroids];

void setup() {
  Serial.begin(9600);

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'


}

void loop() {

  P.update();

  for (int i = 0; i < nAsteroids; i++) {
    A[i].update();
    //A[i].checkCollision();
  }

  updatePixels();
}

void updatePixels() {
  for (int y = 1; y < PIXEL_Y; y++)
  {
    for (int x = 1; x < PIXEL_X; x++)
    {
      switch (pixelC[x][y]) {
        case BLANK:
          setXYpixel((x - 1), (y - 1), 0, 0, 0);
          break;
        case SPACESHIP:
            setXYpixel((x - 1), (y - 1), 0, 255, 0);
          break;
        case ASTEROID:
          setXYpixel((x - 1), (y - 1), 255, 0, 0);
          
          break;
      }
    }
  }
  strip.show();
}

void clearLEDs() {
  for (int i = 0; i < num_leds; i++) {
    strip.setPixelColor(i, 0);
  }
}

void setXYpixel(char x, char y, unsigned char R, unsigned char G, unsigned char B) {
  if ((y % 2) > 0)
    strip.setPixelColor((((16 - y + 1) * 17) - (16 - x + 1)), strip.Color( R, G, B));
  else
    strip.setPixelColor((((16 - y) * 17) + (16 - x)), strip.Color( R, G, B));
}

