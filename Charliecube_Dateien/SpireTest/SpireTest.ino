//CharlieCube Spire Test Program

#define PIN_A 3
#define PIN_B 4
#define PIN_C 6
#define PIN_D 5
int delayTime = 300;

void setup()
{
// first set all pins to input, or high impedance
// (not strictly necessary as all pins are inputs by default)
pinMode(PIN_A, INPUT);
pinMode(PIN_B, INPUT);
pinMode(PIN_C, INPUT);
pinMode(PIN_C, INPUT);
}

void loop()
{

set_pins(PIN_B, PIN_A);
delay(delayTime);
set_pins(PIN_C, PIN_A);
delay(delayTime);
set_pins(PIN_D, PIN_A);
delay(delayTime);

set_pins(PIN_C, PIN_B);
delay(delayTime);
set_pins(PIN_D, PIN_B);
delay(delayTime);
set_pins(PIN_A, PIN_B);
delay(delayTime);

set_pins(PIN_D, PIN_C);
delay(delayTime);
set_pins(PIN_A, PIN_C);
delay(delayTime);
set_pins(PIN_B, PIN_C);
delay(delayTime);

set_pins(PIN_A, PIN_D);
delay(delayTime);
set_pins(PIN_B, PIN_D);
delay(delayTime);
set_pins(PIN_C, PIN_D);
delay(delayTime);



}

void set_pins(int low_pin, int high_pin)
{
// reset all the pins
reset_pins();

// set the high and low pins to output
pinMode(high_pin, OUTPUT);
pinMode(low_pin, OUTPUT);

// set high pin to logic high, low to logic low
digitalWrite(high_pin, HIGH);
digitalWrite(low_pin,LOW);
}

void reset_pins()
{
// start by ensuring all pins are at input and low
pinMode(PIN_A, INPUT);
pinMode(PIN_B, INPUT);
pinMode(PIN_C, INPUT);
pinMode(PIN_D, INPUT);

digitalWrite(PIN_A, LOW);
digitalWrite(PIN_B, LOW);
digitalWrite(PIN_C, LOW);
digitalWrite(PIN_D, LOW);
}
