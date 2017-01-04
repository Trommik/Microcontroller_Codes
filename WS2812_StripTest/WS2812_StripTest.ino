#include <Adafruit_NeoPixel.h>

#define PIN 6
#define num_leds 10

#define DELAY_TIME 7
#define MAX_BRIGHT 255

int red = 0;
int green = 170;
int blue = 170;

int incR = 1;
int incG = 1;
int incB = 0;

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_RGB     Pixels are wired for RGB bitstream
//   NEO_GRB     Pixels are wired for GRB bitstream
//   NEO_KHZ400  400 KHz bitstream (e.g. FLORA pixels)
//   NEO_KHZ800  800 KHz bitstream (e.g. High Density LED strip)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(num_leds, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {

  // Some example procedures showing how to display to the pixels:
  colorWipe(strip.Color(255, 0, 0), 100); // Red
  colorWipe(strip.Color(0, 255, 0), 100); // Green
  colorWipe(strip.Color(0, 0, 255), 100); // Blue
  colorWipe(strip.Color(0, 255, 255), 100); // Blue
  colorWipe(strip.Color(255, 0, 255), 100); // Blue
  colorWipe(strip.Color(255, 255, 0), 100); // Blue
  //rainbow(20);
  //rainbowCycle(20);
  for(int i = 0; i < 6; i++){
    cylon(255,0,0,1000);
  }
  for(int i = 0; i < 10000; i++){
    transition();
    for(int i = 0; i < num_leds; i++){
      strip.setPixelColor(i, strip.Color(red, green, blue));
    }
    strip.show();
    delay(DELAY_TIME);
  }
}

void clearLEDs()
{
  for (int i=0; i<num_leds; i++)
  {
    strip.setPixelColor(i, strip.Color(0,0,0));
  }
}

// Implements a little larson "cylon" sanner.
// This'll run one full cycle, down one way and back the other
void cylon(byte red, byte green, byte blue, byte wait)
{
  // weight determines how much lighter the outer "eye" colors are
  const byte weight = 1;  
  // It'll be easier to decrement each of these colors individually
  // so we'll split them out of the 24-bit color value
  
  // Start at closest LED, and move to the outside
  for (int i=0; i<=num_leds-1; i++)
  {
    clearLEDs();
    strip.setPixelColor(i, strip.Color(red, green, blue));  // Set the bright middle eye
    // Now set two eyes to each side to get progressively dimmer


    for (int j=1; j<3; j++)
    {
      if (i-j >= 0){
        strip.setPixelColor(i-j, strip.Color(red/(weight*j), green/(weight*j), blue/(weight*j)));
        if (i == 0)strip.setPixelColor(num_leds -1, strip.Color(red/(weight*j), green/(weight*j), blue/(weight*j)));
      }
      if (i-j <= num_leds){
         strip.setPixelColor(i+j, strip.Color(red/(weight*j), green/(weight*j), blue/(weight*j)));
         if (i == num_leds-1)strip.setPixelColor(0, strip.Color(red/(weight*j), green/(weight*j), blue/(weight*j)));
      }
      
    
    }
    strip.show();  // Turn the LEDs on
    delay(wait);  // Delay for visibility
  }
  /*
  // Now we go back to where we came. Do the same thing.
  for (int i=num_leds-2; i>=1; i--)
  {
    clearLEDs();
    strip.setPixelColor(i, strip.Color(red, green, blue));
    for (int j=1; j<3; j++)
    {
      if (i-j >= 0)
         strip.setPixelColor(i-j, strip.Color(red/(weight*j), green/(weight*j), blue/(weight*j)));
      if (i-j <= num_leds)
         strip.setPixelColor(i+j, strip.Color(red/(weight*j), green/(weight*j), blue/(weight*j)));
      }
    
    strip.show();
    delay(wait);
  }
  */
}

void transition()
{
  if (red >= MAX_BRIGHT)
    incR = 0;
  else if (red <= 0)
    incR = 1;
  if (green >= MAX_BRIGHT)
    incG = 0;
  else if (green <= 0)
    incG = 1;
  if (blue >= MAX_BRIGHT)
    incB = 0;
  else if (blue <= 0)
    incB = 1;
  
  if (incR)
    red++;
  else
    red--;
  if(incG)
    green++;
  else
    green--;
  if(incB)
    blue++;
  else
    blue--;
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

