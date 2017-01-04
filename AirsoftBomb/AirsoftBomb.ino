#include <LiquidCrystal.h>

LiquidCrystal lcd(12,8,7,6,5,4,2);

const int ledbc = 3;

const int btn1 = 1;
const int btn2 = 2;

const int ledrot = 11;
const int ledgrun = 10;
const int beeper = 9;

int input1 = false;
int input2 = false;

int ablauf = 1;
 
int zahl = 0;

const long code1 = 96544;
const long code2 = 19598;
const long code3 = 92989;
const long code4 = 51326;
const long code5 = 38498;

const int c1z1 = 9;
const int c1z2 = 6;
const int c1z3 = 5;
const int c1z4 = 4;
const int c1z5 = 4;

const int c2z1 = 1;
const int c2z2 = 9;
const int c2z3 = 5;
const int c2z4 = 9;
const int c2z5 = 8;

const int c3z1 = 9;
const int c3z2 = 2;
const int c3z3 = 9;
const int c3z4 = 8;
const int c3z5 = 9;

const int c4z1 = 5;
const int c4z2 = 1;
const int c4z3 = 3;
const int c4z4 = 2;
const int c4z5 = 6;

const int c5z1 = 3;
const int c5z2 = 8;
const int c5z3 = 4;
const int c5z4 = 9;
const int c5z5 = 8;

boolean zahl_true = false;


int zahl1;
int zahl2;
int zahl3;
int zahl4;
int zahl5;

byte p20[8] = {
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
};
byte p40[8] = {
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
};
byte p60[8] = {
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
};
byte p80[8] = {
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
};
byte p100[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};

int code_s = 1;

int versuch = 0;

long S = 0;
long Secms;
long verbleibend;
long start_count;
long vergangen;


void setup() {
  Serial.begin(9600);
  
  lcd.begin(16, 2);
  
  //pinMode(ledbc, OUTPUT);
  analogWrite(ledbc, 0);
  
  pinMode(ledrot, OUTPUT);
  pinMode(beeper, OUTPUT);
  
  lcd.createChar(0, p20);
  lcd.createChar(1, p40);
  lcd.createChar(2, p60);
  lcd.createChar(3, p80);
  lcd.createChar(4, p100);
  
}
void loop() {

  lcd.setCursor(0, 0);
 
  if (analogRead(btn1) >= 100){input1 = HIGH;}else{input1 = LOW;}
  if (analogRead(btn2) >= 100){input2 = HIGH;}else{input2 = LOW;}
  
  //Serial.println(analogRead(btn1));
  
  if (ablauf == 1){
     if (analogRead(btn1) >= 100){input1 = HIGH;}else{input1 = LOW;}
     if (analogRead(btn2) >= 100){input2 = HIGH;}else{input2 = LOW;} 
    
    
    lcd.clear();
    
    lcd.print("MISSILE LAUNCHER");
    lcd.setCursor(0,1);
    lcd.print(" [PRESS  ENTER] ");
    
    if (input1 == HIGH){
      ablauf = 12;
      delay(100);
    } 
    
  }
  
  if (ablauf == 12){
      if (analogRead(btn1) >= 100){input1 = HIGH;}else{input1 = LOW;}
      if (analogRead(btn2) >= 100){input2 = HIGH;}else{input2 = LOW;} 
    
    
      lcd.clear();
      lcd.print("ENTER LINK CODE");
      lcd.setCursor(0,1);  
      lcd.print(" Code ");
      lcd.print(code_s);
      lcd.print(" = ");
      if (code_s == 1){lcd.print(code1);}
      if (code_s == 2){lcd.print(code2);}
      if (code_s == 3){lcd.print(code3);}
      if (code_s == 4){lcd.print(code4);}
      if (code_s == 5){lcd.print(code5);}
      
      
      if (input2 == HIGH){
       
        code_s += 1;

        if (code_s >= 6){code_s = 1;}
      }
      
      if (input1 == HIGH){
      lcd.clear();
      lcd.setCursor(0,0);      
      lcd.print(" LINK TO MISSILE");
      lcd.setCursor(0,1);
        
      for (int i = 0; i<16; i++){
        for (int j=0; j<5; j++){
          lcd.setCursor(i, 1);   
          lcd.write(j);
          delay(100);
        } 
      }
      delay(100);
      
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("     LINKED     ");
      
      digitalWrite(ledgrun, HIGH);
      digitalWrite(beeper, HIGH);
      delay(100);
      digitalWrite(beeper, LOW);
      delay(400);
      digitalWrite(ledgrun, LOW);

      ablauf = 2;
      }
  
  }
  
  if (ablauf == 2){
      if (analogRead(btn1) >= 100){input1 = HIGH;}else{input1 = LOW;}
      if (analogRead(btn2) >= 100){input2 = HIGH;}else{input2 = LOW;}
    
    
      lcd.clear();
      lcd.setCursor(0,0);      
      lcd.print("     SELECT     ");
      lcd.setCursor(0,1);
      lcd.print(" COUNTDOWN TIME ");

     delay(1000);
     ablauf += 1;
  }
  
  if (ablauf == 3){
      if (analogRead(btn1) >= 100){input1 = HIGH;}else{input1 = LOW;}
      if (analogRead(btn2) >= 100){input2 = HIGH;}else{input2 = LOW;}
    
   
    lcd.clear();
    lcd.print("  ");
    lcd.print(S);
    lcd.print(" SECONDS");
    lcd.setCursor(0,1);
    lcd.print("  ENTER TO ARM  ");
    
    if (input2 == HIGH){
       S += 5;
       

       lcd.clear();
       lcd.print("  ");
       lcd.print(S);
       lcd.print(" SECONDS");
       lcd.setCursor(0,1);
       lcd.print("  ENTER TO ARM  ");
       
       
       delay(50);
    }
      if (input1 == HIGH){ablauf += 1;}
    
    }
  
  /*if (ablauf == 4){
  
    lcd.clear();
    lcd.print(" ENTER PASSWORD ")
    
  if (input2 == HIGH){
  
  }*/
  
  if (ablauf == 4){
      if (analogRead(btn1) >= 100){input1 = HIGH;}else{input1 = LOW;}
      if (analogRead(btn2) >= 100){input2 = HIGH;}else{input2 = LOW;}
    
  
    lcd.clear();
    lcd.print("  ARM  MISSILE  ");
    
    for (int i = 0; i<16; i++){
        for (int j=0; j<5; j++){
          lcd.setCursor(i, 1);   
          lcd.write(j);
          delay(100);
        } 
     }
     
    ablauf += 1;
    
  }
  
  if (ablauf == 5){
      if (analogRead(btn1) >= 100){input1 = HIGH;}else{input1 = LOW;}
      if (analogRead(btn2) >= 100){input2 = HIGH;}else{input2 = LOW;}
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(" MISSILE  ARMED ");
    lcd.setCursor(0,1);
    lcd.print("OUTSET COUNTDOWN");
    delay(1500);
    ablauf += 1;
  }
  
if (ablauf == 6){
    Secms = S * 1000;
    start_count = millis();
    
    ablauf += 1;
  }
  
  if (ablauf == 7){

    vergangen =  millis() - start_count;
    verbleibend = Secms - vergangen;     
    verbleibend = verbleibend / 1000; 
    

  

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("   ");
    lcd.print(verbleibend);
    lcd.print(" SECONDS");
    lcd.setCursor(0,1);
    lcd.print(" ENTER TO ABORT ");
    
      
  
  
  
    
    if (versuch != 3){if (input1 == HIGH){ablauf = 9;}}else{lcd.setCursor(0,1); lcd.print("                ");}
    
    
    if (verbleibend <= 0){
      
      ablauf += 1;
    }
    delay(100);
  }
  
  if (ablauf == 8){
   lcd.clear();
   lcd.print("MISSILE LAUNCHED");
   lcd.setCursor(0,1);
   lcd.print("[ENTER TO RESET]");
  }
  
  if (ablauf == 9){
  
    lcd.clear();
    lcd.print("ENTER ABORT CODE");
    lcd.setCursor(0,1);

    lcd.print("     ");
    lcd.blink();
    lcd.print(zahl1);
    lcd.print(zahl2);
    lcd.print(zahl3);
    lcd.print(zahl4);
    lcd.print(zahl5);
    lcd.setCursor(zahl + 4,1);
    
    if (input1 == HIGH){
      zahl += 1;
      
      if (zahl >= 6){
        ablauf += 1;
        lcd.noBlink();
        zahl = 0;
      }
    }
    
    if (zahl == 1){
      if (input2 == HIGH){
        zahl1 += 1;
        if (zahl1 >= 10){zahl1 = 0;}
      }
    }
    
    if (zahl == 2){
      if (input2 == HIGH){
        zahl2 += 1;
        if (zahl2 >= 10){zahl2 = 0;}
      }
    }
    
    if (zahl == 3){
      if (input2 == HIGH){
        zahl3 += 1;
        if (zahl3 >= 10){zahl3 = 0;}
      }
    } 
 
    if (zahl == 4){
      if (input2 == HIGH){
        zahl4 += 1;
        if (zahl4 >= 10){zahl4 = 0;}
      }
    } 
 
    if (zahl == 5){
      if (input2 == HIGH){
        zahl5 += 1;
        if (zahl5 >= 10){zahl5 = 0;}
      }
    }  
    
  }
  if (ablauf == 10){
    
    lcd.clear();
    lcd.print("CHECK ABORT CODE");
    lcd.setCursor(0,1);
        
      for (int i = 0; i<16; i++){
        for (int j=0; j<5; j++){
          lcd.setCursor(i, 1);   
          lcd.write(j);
          delay(100);
        } 
      }
    delay(100);
 
    if (code_s == 1){
      if (zahl1 == c1z1){zahl_true = true;}else{zahl_true = false;} 
      if (zahl2 == c1z2){zahl_true = true;}else{zahl_true = false;} 
      if (zahl3 == c1z3){zahl_true = true;}else{zahl_true = false;} 
      if (zahl4 == c1z4){zahl_true = true;}else{zahl_true = false;} 
      if (zahl5 == c1z5){zahl_true = true;}else{zahl_true = false;} 
    }
    if (code_s == 2){
      if (zahl1 == c2z1){zahl_true = true;}else{zahl_true = false;} 
      if (zahl2 == c2z2){zahl_true = true;}else{zahl_true = false;} 
      if (zahl3 == c2z3){zahl_true = true;}else{zahl_true = false;} 
      if (zahl4 == c2z4){zahl_true = true;}else{zahl_true = false;} 
      if (zahl5 == c2z5){zahl_true = true;}else{zahl_true = false;} 
    }  
    if (code_s == 3){
      if (zahl1 == c3z1){zahl_true = true;}else{zahl_true = false;} 
      if (zahl2 == c3z2){zahl_true = true;}else{zahl_true = false;} 
      if (zahl3 == c3z3){zahl_true = true;}else{zahl_true = false;} 
      if (zahl4 == c3z4){zahl_true = true;}else{zahl_true = false;} 
      if (zahl5 == c3z5){zahl_true = true;}else{zahl_true = false;} 
    } 
    if (code_s == 4){
      if (zahl1 == c4z1){zahl_true = true;}else{zahl_true = false;} 
      if (zahl2 == c4z2){zahl_true = true;}else{zahl_true = false;} 
      if (zahl3 == c4z3){zahl_true = true;}else{zahl_true = false;} 
      if (zahl4 == c4z4){zahl_true = true;}else{zahl_true = false;} 
      if (zahl5 == c4z5){zahl_true = true;}else{zahl_true = false;} 
    }  
    if (code_s == 3){
      if (zahl1 == c5z1){zahl_true = true;}else{zahl_true = false;} 
      if (zahl2 == c5z2){zahl_true = true;}else{zahl_true = false;} 
      if (zahl3 == c5z3){zahl_true = true;}else{zahl_true = false;} 
      if (zahl4 == c5z4){zahl_true = true;}else{zahl_true = false;} 
      if (zahl5 == c5z5){zahl_true = true;}else{zahl_true = false;} 
    } 
    if (zahl_true == true){
      lcd.clear();
      lcd.print("   RIGHT CODE   ");
      lcd.setCursor(0,1);
      lcd.print("MISSILE DISARMED");
      delay(1000000);
    }else{
       versuch += 1;
       lcd.clear();
       lcd.print("FALSE CODE [");
       lcd.print(versuch);
       lcd.print("|3]");
       lcd.setCursor(0,1);
       lcd.print("ENTER RIGHT CODE");
       
       zahl1 = 0;
       zahl2 = 0;
       zahl3 = 0;
       zahl4 = 0;
       zahl5 = 0;
       
       delay(1500);
       
       if (versuch == 3){ablauf = 11;}else{ablauf = 7;}
    }
  }
  
  if (ablauf == 11){
  
    lcd.clear();
    lcd.print(" MISSILE LOCKED ");
    delay(1500);
    ablauf = 7;
  }
  
  delay(100);
}
