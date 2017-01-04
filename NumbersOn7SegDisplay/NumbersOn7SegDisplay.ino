// Uses a 74HC595 shift register to display all numbers on a 7 Segment display

int latchPin = 8; // Pin connected to ST_CP of 74HC595
int clockPin = 12; // Pin connected to SH_CP of 74HC595
int dataPin = 11; // Pin connected to DS of 74HC595

byte numbersWithDP[10] = {0x02,0x9E,0x24,0x0C,0x98,0x48,0x40,0x1E,0x0,0x08};   // for numbers without a the Dezimalpoint add 1

void setup() {
  //set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {

  for(int i = 0; i < 10; i++){ // cycle throught all numbers with DP

    digitalWrite(latchPin, LOW); // take the latchPin low so the LEDs don't change while you're sending in bits
    shiftOut(dataPin, clockPin, LSBFIRST, numbersWithDP[i]); // shift out the bits
    digitalWrite(latchPin, HIGH); // take the latch pin high so the LEDs will light up
    
    delay(1000); // pause before next value
  }
	
  for(int i = 0; i < 10; i++){ // cycle throught all numbers without DP
  
    digitalWrite(latchPin, LOW); // take the latchPin low so the LEDs don't change while you're sending in bits
    shiftOut(dataPin, clockPin, LSBFIRST, numbersWithDP[i] + 1); // shift out the bits
    digitalWrite(latchPin, HIGH); // take the latch pin high so the LEDs will light up
    
    delay(1000); // pause before next value
  }
}

