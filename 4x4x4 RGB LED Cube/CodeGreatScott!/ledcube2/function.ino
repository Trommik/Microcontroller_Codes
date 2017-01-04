#include "digitalIOPerformance.h"

void rotate(int red, int green, int blue, int rotation){
    if(rotation==0){
		int turnonlist[] = {0,3, 48,51, 4,8,12,7,11,15,52,56,60,55,59,63};
		turnon(turnonlist, 16, red, green, blue);			 		   
	}
    if(rotation==1){
		int turnonlist[] = {1,19,32,50, 5,9,13,23,27,31,36,40,44,54,58,62};
		turnon(turnonlist, 16, red, green, blue);			 		   
	}
    if(rotation==2){
		int turnonlist[] = {2,35,16,49, 6,10,14,39,43,47,20,24,28,53,57,61};
		turnon(turnonlist, 16, red, green, blue);			 			
    }
}

// ns x shape - display whole cube at once
void nsx(int red, int green, int blue, int row){
    if(row==0){
		int turnonlist[] = { 0,3,17,18,33,34,48,51};		
		turnon(turnonlist, 8, red, green, blue);		
	}
	
    if(row==1){
		int turnonlist[] = { 4,7,21,22,37,38,52,55};		
		turnon(turnonlist, 8, red, green, blue);		
	}
    if(row==2){
		int turnonlist[] = { 8,11,25,26,41,42,56,59};		
		turnon(turnonlist, 8, red, green, blue);		
    }
    if(row==3){
		int turnonlist[] = {12,15,29,30,45,46,60,63};		
		turnon(turnonlist, 8, red, green, blue);		
    } 
}

void ewx(int red, int green, int blue, int row){
    if(row==0){
		int turnonlist[] = { 0,12,20,24,36,40,48,60};		
		turnon(turnonlist, 8, red, green, blue);		
	}
	
    if(row==1){
		int turnonlist[] = { 1,13,21,25,37,41,49,61};		
		turnon(turnonlist, 8, red, green, blue);		
	}
    if(row==2){
		int turnonlist[] = { 2,14,22,26,38,42,50,62};		
		turnon(turnonlist, 8, red, green, blue);		
    }
    if(row==3){
		int turnonlist[] = {3,15,23,27,39,43,51,63};		
		turnon(turnonlist, 8, red, green, blue);		
    } 
}

// up and down X - display a layer at a time.
void udx(int red, int green, int blue, int level){
    if(level==0){
		int turnonlist[] = { 0, 5,10,15,  12, 9, 6, 3};
		turnon(turnonlist, 8, red, green, blue);			 		   
	}
    if(level==1){
		int turnonlist[] = {16,21,26,31,  28,25,22,19};
		turnon(turnonlist, 8, red, green, blue);			 		   
	}
    if(level==2){
		int turnonlist[] = {32,37,42,47,  44,41,38,35};
		turnon(turnonlist, 8, red, green, blue);			 			
    }
    if(level==3){
		int turnonlist[] = {48,53,58,63,  60,57,54,51};
		turnon(turnonlist, 8, red, green, blue);			 			
    }
}

void nsslice(int red, int green, int blue, int level){
    if(level==0){
		int turnonlist[] = {0,1,2,3,  16,17,18,19,    32,33,34,35,    48,49,50,51};
		turnon(turnonlist, 16, red, green, blue);			 		   
	}
    if(level==1){
		int turnonlist[] = {4,5,6,7,   20,21,22,23,   37,37,38,39,    52,53,54,55};
		turnon(turnonlist, 16, red, green, blue);			 		   
	}
    if(level==2){
		int turnonlist[] = {8,9,10,11,   24,25,26,27,    40,41,42,43,   56,57,58,59};
		turnon(turnonlist, 16, red, green, blue);			 			
    }
    if(level==3){
		int turnonlist[] = {12,13,14,15,   28,29,30,31,   44,45,46,47,    60,61,62,63};
		turnon(turnonlist, 16, red, green, blue);			 			
    }
}

void ewslice(int red, int green, int blue, int level){
    if(level==0){
        int turnonlist[] = {0,4,8,12,    16,20,24,28,     32,36,40,44,   48,52,56,60};
		turnon(turnonlist, 16, red, green, blue);			 		
	}
    if(level==1){
        int turnonlist[] = {1,5,9,13,     17,21,25,29,     33,37,41,45,    49,53,57,61};
		turnon(turnonlist, 16, red, green, blue);			 				
	}
    if(level==2){
        int turnonlist[] = {2,6,10,14,    18,22,26,30,     34,38,42,46,     50,54,58,62};
		turnon(turnonlist, 16, red, green, blue);			 				
	}
    if(level==3){
        int turnonlist[] = {3,7,11,15,   19,23,27,31,    35,39,43,47,    51,55,59,63};
		turnon(turnonlist, 16, red, green, blue);			 				
	}
}
      
// travels around the outside - 12 steps
void wall(int red, int green, int blue, int position){
    if(position==0){
             int turnonlist[] = {0,1,2,3,  16,17,18,19,    32,33,34,35,    48,49,50,51};
             turnon(turnonlist, 16, red, green, blue);}
    if(position==1){
             int turnonlist[] = {1,2,3,7,   17,18,19,23,   33,34,35,39,   49,50,51,55};
             turnon(turnonlist, 16, red, green, blue);}
    if(position==2){
             int turnonlist[] = {2,3,7,11,   18,19,23,27,   34,35,39,43,   50,51,55,59};
             turnon(turnonlist, 16, red, green, blue);}
    if(position==3){
             int turnonlist[] = {3,7,11,15,   19,23,27,31,   35,39,43,47,   51,55,59,63};
             turnon(turnonlist, 16, red, green, blue);}
    if(position==4){
             int turnonlist[] = {7,11,15,14,   23,27,31,30,   39,43,47,46,   55,59,63,62};
             turnon(turnonlist, 16, red, green, blue);}
    if(position==5){
             int turnonlist[] = {11,15,14,13,   27,31,30,29,   43,47,46,45,   59,63,62,61};
             turnon(turnonlist, 16, red, green, blue);}
    if(position==6){
             int turnonlist[] = {15,14,13,12,   31,30,29,28,   47,46,45,44,   63,62,61,60};
             turnon(turnonlist, 16, red, green, blue);}
    if(position==7){
             int turnonlist[] = {14,13,12,8,   30,29,28,24,   46,45,44,40,   62,61,60,56};
             turnon(turnonlist, 16, red, green, blue);}
    if(position==8){
             int turnonlist[] = {13,12,8,4,   29,28,24,20,   45,44,40,36,   61,60,56,52};
             turnon(turnonlist, 16, red, green, blue);}
    if(position==9){
             int turnonlist[] = {12,8,4,0,   28,24,20,16,   44,40,36,32,   60,56,52,48};
             turnon(turnonlist, 16, red, green, blue);}
    if(position==10){
             int turnonlist[] = {8,4,0,1,   24,20,16,17,   40,36,32,33,   56,52,48,49};
             turnon(turnonlist, 16, red, green, blue);}
    if(position==11){
             int turnonlist[] = {4,0,1,2,   20,16,17,18,   36,32,33,34,   52,48,49,50};
             turnon(turnonlist, 16, red, green, blue);}
}
 
// utility to turn on an array of leds
void turnon(int liste[], int count, int red, int green, int blue){
	for (int i = 0; i < count; i++) {
			REDLEDs[liste[i]]=red;
			GREENLEDs[liste[i]]=green;
			BLUELEDs[liste[i]]=blue;
	}
}
// turn them all off
void reset(){       
	for (int p=0;p<64;p++){
		REDLEDs[p]=0;
		GREENLEDs[p]=0;
		BLUELEDs[p]=0;
	}
}

void getrand() {
	randred=random(0,1548);
	randgreen=random(0,750);
	randblue=random(0,1250);

/*
	randred=random(1020, brightr);
	randgreen=random(20, brightg/2);
	randblue=random(720, brightb/2);*/
}
// set all leds to RGB values
void all(int red, int green, int blue){
	for (int p=0;p<64;p++){
		REDLEDs[p]=red;
		GREENLEDs[p]=green;		
		BLUELEDs[p]=blue;		
	}
}

// turn on 10 random leds of RGB
void randomall(int red, int blue, int green) {
    for (int p=0;p<10;p++){
		REDLEDs[random(64)]=random(20, red);
		GREENLEDs[random(64)]=random(20,green);		
		BLUELEDs[random(64)]=random(20,blue);		
    }
}

// read the potentiometer
void brightness(){
	potent=1023;                   // use analogRead to set value for int bright from 0-1023
	factor=map(potent,0,1023,0,4095);                   // convert 10 bit value(0-1023) from analogRead into 12 bit value(0-4095) for TLC5940 
	brightr=factor*0.99;
	brightb=factor*0.90;
	brightg=factor*0.70;
}

// send the colours to the TLC5940 and turn on the layer
void CubeUpdate(int layerno){ 

  brightness();  // check potentiometer

  if(layerno == 1 | layerno == 0){                 
                                  // Tlc.set(OUTPUT, BRIGHTNESS VALUE (0-4095)), general use of Tlc.set      
    Tlc.set(AchR, REDLEDs[0]);             // set AaR brightness to AchR OUTPUT(OUTPUT 0); first TLC5940 
    Tlc.set(BchR, REDLEDs[1]);             // set BaR brightness to BchR OUTPUT(OUTPUT 1);
    Tlc.set(CchR, REDLEDs[2]);             // set CaR brightness to CchR OUTPUT(OUTPUT 2);
    Tlc.set(DchR, REDLEDs[3]);             // set DaR brightness to DchR OUTPUT(OUTPUT 3);
    Tlc.set(EchR, REDLEDs[4]);             // set EaR brightness to EchR OUTPUT(OUTPUT 4);
    Tlc.set(FchR, REDLEDs[5]);             // set FaR brightness to FchR OUTPUT(OUTPUT 5);
    Tlc.set(GchR, REDLEDs[6]);             // set GaR brightness to GchR OUTPUT(OUTPUT 6);
    Tlc.set(HchR, REDLEDs[7]);             // set HaR brightness to HchR OUTPUT(OUTPUT 7);
    Tlc.set(IchR, REDLEDs[8]);             // set IaR brightness to IchR OUTPUT(OUTPUT 8);
    Tlc.set(JchR, REDLEDs[9]);             // set JaR brightness to JchR OUTPUT(OUTPUT 9);
    Tlc.set(KchR, REDLEDs[10]);             // set KaR brightness to KchR OUTPUT(OUTPUT 10);
    Tlc.set(LchR, REDLEDs[11]);             // set LaR brightness to LchR OUTPUT(OUTPUT 11);
    Tlc.set(MchR, REDLEDs[12]);             // set MaR brightness to MchR OUTPUT(OUTPUT 12);
    Tlc.set(NchR, REDLEDs[13]);             // set NaR brightness to NchR OUTPUT(OUTPUT 13);
    Tlc.set(OchR, REDLEDs[14]);             // set OaR brightness to OchR OUTPUT(OUTPUT 14);
    Tlc.set(PchR, REDLEDs[15]);             // set PaR brightness to PchR OUTPUT(OUTPUT 15);
    Tlc.set(AchG, GREENLEDs[0]);             // set AaG brightness to AchG OUTPUT(OUTPUT 0); second TLC5940
    Tlc.set(BchG, GREENLEDs[1]);             // set BaG brightness to BchG OUTPUT(OUTPUT 1);
    Tlc.set(CchG, GREENLEDs[2]);             // set CaG brightness to CchG OUTPUT(OUTPUT 2);
    Tlc.set(DchG, GREENLEDs[3]);             // set DaG brightness to DchG OUTPUT(OUTPUT 3);
    Tlc.set(EchG, GREENLEDs[4]);             // set EaG brightness to EchG OUTPUT(OUTPUT 4);
    Tlc.set(FchG, GREENLEDs[5]);             // set FaG brightness to FchG OUTPUT(OUTPUT 5);
    Tlc.set(GchG, GREENLEDs[6]);             // set GaG brightness to GchG OUTPUT(OUTPUT 6);
    Tlc.set(HchG, GREENLEDs[7]);             // set HaG brightness to HchG OUTPUT(OUTPUT 7);
    Tlc.set(IchG, GREENLEDs[8]);             // set IaG brightness to IchG OUTPUT(OUTPUT 8);
    Tlc.set(JchG, GREENLEDs[9]);             // set JaG brightness to JchG OUTPUT(OUTPUT 9);
    Tlc.set(KchG, GREENLEDs[10]);             // set KaG brightness to KchG OUTPUT(OUTPUT 10);
    Tlc.set(LchG, GREENLEDs[11]);             // set LaG brightness to LchG OUTPUT(OUTPUT 11);
    Tlc.set(MchG, GREENLEDs[12]);             // set MaG brightness to MchG OUTPUT(OUTPUT 12);
    Tlc.set(NchG, GREENLEDs[13]);             // set NaG brightness to NchG OUTPUT(OUTPUT 13);
    Tlc.set(OchG, GREENLEDs[14]);             // set OaG brightness to OchG OUTPUT(OUTPUT 14);
    Tlc.set(PchG, GREENLEDs[15]);             // set PaG brightness to PchG OUTPUT(OUTPUT 15);
    Tlc.set(AchB, BLUELEDs[0]);             // set AaB brightness to AchB OUTPUT(OUTPUT 0); third TLC5940
    Tlc.set(BchB, BLUELEDs[1]);             // set BaB brightness to BchB OUTPUT(OUTPUT 1);
    Tlc.set(CchB, BLUELEDs[2]);             // set CaB brightness to CchB OUTPUT(OUTPUT 2);
    Tlc.set(DchB, BLUELEDs[3]);             // set DaB brightness to DchB OUTPUT(OUTPUT 3);
    Tlc.set(EchB, BLUELEDs[4]);             // set EaB brightness to EchB OUTPUT(OUTPUT 4);
    Tlc.set(FchB, BLUELEDs[5]);             // set FaB brightness to FchB OUTPUT(OUTPUT 5);
    Tlc.set(GchB, BLUELEDs[6]);             // set GaB brightness to GchB OUTPUT(OUTPUT 6);
    Tlc.set(HchB, BLUELEDs[7]);             // set HaB brightness to HchB OUTPUT(OUTPUT 7);
    Tlc.set(IchB, BLUELEDs[8]);             // set IaB brightness to IchB OUTPUT(OUTPUT 8);
    Tlc.set(JchB, BLUELEDs[9]);             // set JaB brightness to JchB OUTPUT(OUTPUT 9);
    Tlc.set(KchB, BLUELEDs[10]);             // set KaB brightness to KchB OUTPUT(OUTPUT 10);
    Tlc.set(LchB, BLUELEDs[11]);             // set LaB brightness to LchB OUTPUT(OUTPUT 11);
    Tlc.set(MchB, BLUELEDs[12]);             // set MaB brightness to MchB OUTPUT(OUTPUT 12);
    Tlc.set(NchB, BLUELEDs[13]);             // set NaB brightness to NchB OUTPUT(OUTPUT 13);
    Tlc.set(OchB, BLUELEDs[14]);             // set OaB brightness to OchB OUTPUT(OUTPUT 14);    
    Tlc.set(PchB, BLUELEDs[15]);             // set PaB brightness to PchB OUTPUT(OUTPUT 15);
    
    if(layerno == 1) { 
		digitalWrite(LayerOne, LOW);   // sets LayerOne (pin A0) High (not active)--> Layer one OFF
		digitalWrite(LayerTwo, LOW);   // sets LayerTwo (pin A1) High (not active)--> Layer two OFF
		digitalWrite(LayerThree, LOW); // sets LayerThree (pin A2) High (not active)--> Layer three OFF
		digitalWrite(LayerFour, LOW);  // sets LayerFour (pin A3) High (not active)--> Layer four OFF
		Tlc.update();                   // writes the values for the LEDs brightness to the tlc
		delay(1);                                // give the tlc some time to let the value settle
		digitalWrite(LayerOne, HIGH);    // sets LayerOne (pin A0) Low (active)--> Layer one ON
	}    
  }
  
    if(layerno == 2 | layerno == 0){
    
  
    Tlc.set(AchR, REDLEDs[16]);             // same as if(layerno == 1) but we use different brightness, so we define LEDs in the second layer
    Tlc.set(BchR, REDLEDs[17]);
    Tlc.set(CchR, REDLEDs[18]);
    Tlc.set(DchR, REDLEDs[19]);    
    Tlc.set(EchR, REDLEDs[20]);
    Tlc.set(FchR, REDLEDs[21]);
    Tlc.set(GchR, REDLEDs[22]);
    Tlc.set(HchR, REDLEDs[23]);    
    Tlc.set(IchR, REDLEDs[24]);
    Tlc.set(JchR, REDLEDs[25]);
    Tlc.set(KchR, REDLEDs[26]);
    Tlc.set(LchR, REDLEDs[27]);
    Tlc.set(MchR, REDLEDs[28]);
    Tlc.set(NchR, REDLEDs[29]);
    Tlc.set(OchR, REDLEDs[30]);
    Tlc.set(PchR, REDLEDs[31]);
    Tlc.set(AchG, GREENLEDs[16]);            
    Tlc.set(BchG, GREENLEDs[17]);
    Tlc.set(CchG, GREENLEDs[18]);
    Tlc.set(DchG, GREENLEDs[19]);    
    Tlc.set(EchG, GREENLEDs[20]);
    Tlc.set(FchG, GREENLEDs[21]);
    Tlc.set(GchG, GREENLEDs[22]);
    Tlc.set(HchG, GREENLEDs[23]);    
    Tlc.set(IchG, GREENLEDs[24]);
    Tlc.set(JchG, GREENLEDs[25]);
    Tlc.set(KchG, GREENLEDs[26]);
    Tlc.set(LchG, GREENLEDs[27]);
    Tlc.set(MchG, GREENLEDs[28]);
    Tlc.set(NchG, GREENLEDs[29]);
    Tlc.set(OchG, GREENLEDs[30]);
    Tlc.set(PchG, GREENLEDs[31]);
    Tlc.set(AchB, BLUELEDs[16]);             
    Tlc.set(BchB, BLUELEDs[17]);
    Tlc.set(CchB, BLUELEDs[18]);
    Tlc.set(DchB, BLUELEDs[19]);    
    Tlc.set(EchB, BLUELEDs[20]);
    Tlc.set(FchB, BLUELEDs[21]);
    Tlc.set(GchB, BLUELEDs[22]);
    Tlc.set(HchB, BLUELEDs[23]);    
    Tlc.set(IchB, BLUELEDs[24]);
    Tlc.set(JchB, BLUELEDs[25]);
    Tlc.set(KchB, BLUELEDs[26]);
    Tlc.set(LchB, BLUELEDs[27]);
    Tlc.set(MchB, BLUELEDs[28]);
    Tlc.set(NchB, BLUELEDs[29]);
    Tlc.set(OchB, BLUELEDs[30]);
    Tlc.set(PchB, BLUELEDs[31]);
    
    if(layerno == 2){
		digitalWrite(LayerOne, LOW);  // same as if(layerno==1)
		digitalWrite(LayerTwo, LOW);
		digitalWrite(LayerThree, LOW);
		digitalWrite(LayerFour, LOW);
		Tlc.update();
		delay(1);
		digitalWrite(LayerTwo, HIGH);  // sets LayerTwo (pin A1) Low (active)--> Layer two ON
	}
  }
  
  
  if(layerno == 3 | layerno == 0){
    
    Tlc.set(AchR, REDLEDs[32]);             // same as if(layerno == 1) but we use different brightness, so we define LEDs in the third layer
    Tlc.set(BchR, REDLEDs[33]);
    Tlc.set(CchR, REDLEDs[34]);
    Tlc.set(DchR, REDLEDs[35]);    
    Tlc.set(EchR, REDLEDs[36]);
    Tlc.set(FchR, REDLEDs[37]);
    Tlc.set(GchR, REDLEDs[38]);
    Tlc.set(HchR, REDLEDs[39]);    
    Tlc.set(IchR, REDLEDs[40]);
    Tlc.set(JchR, REDLEDs[41]);
    Tlc.set(KchR, REDLEDs[42]);
    Tlc.set(LchR, REDLEDs[43]);
    Tlc.set(MchR, REDLEDs[44]);
    Tlc.set(NchR, REDLEDs[45]);
    Tlc.set(OchR, REDLEDs[46]);
    Tlc.set(PchR, REDLEDs[47]);
    Tlc.set(AchG, GREENLEDs[32]);            
    Tlc.set(BchG, GREENLEDs[33]);
    Tlc.set(CchG, GREENLEDs[34]);
    Tlc.set(DchG, GREENLEDs[35]);    
    Tlc.set(EchG, GREENLEDs[36]);
    Tlc.set(FchG, GREENLEDs[37]);
    Tlc.set(GchG, GREENLEDs[38]);
    Tlc.set(HchG, GREENLEDs[39]);    
    Tlc.set(IchG, GREENLEDs[40]);
    Tlc.set(JchG, GREENLEDs[41]);
    Tlc.set(KchG, GREENLEDs[42]);
    Tlc.set(LchG, GREENLEDs[43]);
    Tlc.set(MchG, GREENLEDs[44]);
    Tlc.set(NchG, GREENLEDs[45]);
    Tlc.set(OchG, GREENLEDs[46]);
    Tlc.set(PchG, GREENLEDs[47]);
    Tlc.set(AchB, BLUELEDs[32]);             
    Tlc.set(BchB, BLUELEDs[33]);
    Tlc.set(CchB, BLUELEDs[34]);
    Tlc.set(DchB, BLUELEDs[35]);    
    Tlc.set(EchB, BLUELEDs[36]);
    Tlc.set(FchB, BLUELEDs[37]);
    Tlc.set(GchB, BLUELEDs[38]);
    Tlc.set(HchB, BLUELEDs[39]);    
    Tlc.set(IchB, BLUELEDs[40]);
    Tlc.set(JchB, BLUELEDs[41]);
    Tlc.set(KchB, BLUELEDs[42]);
    Tlc.set(LchB, BLUELEDs[43]);
    Tlc.set(MchB, BLUELEDs[44]);
    Tlc.set(NchB, BLUELEDs[45]);
    Tlc.set(OchB, BLUELEDs[46]);
    Tlc.set(PchB, BLUELEDs[47]);
    
    if(layerno == 3){    
		digitalWrite(LayerOne, LOW);   // same as if(layerno==1)
		digitalWrite(LayerTwo, LOW);
		digitalWrite(LayerThree, LOW);
		digitalWrite(LayerFour, LOW);
		Tlc.update();
		delay(1);
		digitalWrite(LayerThree, HIGH);   // sets LayerThree (pin A2) Low (active)--> Layer three ON 
	}
  }
  
  
  if(layerno == 4 | layerno == 0){
    
    Tlc.set(AchR, REDLEDs[48]);             // same as if(layerno == 1) but we use different brightness, so we define LEDs in the fourth layer
    Tlc.set(BchR, REDLEDs[49]);
    Tlc.set(CchR, REDLEDs[50]);
    Tlc.set(DchR, REDLEDs[51]);    
    Tlc.set(EchR, REDLEDs[52]);
    Tlc.set(FchR, REDLEDs[53]);
    Tlc.set(GchR, REDLEDs[54]);
    Tlc.set(HchR, REDLEDs[55]);    
    Tlc.set(IchR, REDLEDs[56]);
    Tlc.set(JchR, REDLEDs[57]);
    Tlc.set(KchR, REDLEDs[58]);
    Tlc.set(LchR, REDLEDs[59]);
    Tlc.set(MchR, REDLEDs[60]);
    Tlc.set(NchR, REDLEDs[61]);
    Tlc.set(OchR, REDLEDs[62]);
    Tlc.set(PchR, REDLEDs[63]);
    Tlc.set(AchG, GREENLEDs[48]);            
    Tlc.set(BchG, GREENLEDs[49]);
    Tlc.set(CchG, GREENLEDs[50]);
    Tlc.set(DchG, GREENLEDs[51]);    
    Tlc.set(EchG, GREENLEDs[52]);
    Tlc.set(FchG, GREENLEDs[53]);
    Tlc.set(GchG, GREENLEDs[54]);
    Tlc.set(HchG, GREENLEDs[55]);    
    Tlc.set(IchG, GREENLEDs[56]);
    Tlc.set(JchG, GREENLEDs[57]);
    Tlc.set(KchG, GREENLEDs[58]);
    Tlc.set(LchG, GREENLEDs[59]);
    Tlc.set(MchG, GREENLEDs[60]);
    Tlc.set(NchG, GREENLEDs[61]);
    Tlc.set(OchG, GREENLEDs[62]);
    Tlc.set(PchG, GREENLEDs[63]);
    Tlc.set(AchB, BLUELEDs[48]);             
    Tlc.set(BchB, BLUELEDs[49]);
    Tlc.set(CchB, BLUELEDs[50]);
    Tlc.set(DchB, BLUELEDs[51]);    
    Tlc.set(EchB, BLUELEDs[52]);
    Tlc.set(FchB, BLUELEDs[53]);
    Tlc.set(GchB, BLUELEDs[54]);
    Tlc.set(HchB, BLUELEDs[55]);    
    Tlc.set(IchB, BLUELEDs[56]);
    Tlc.set(JchB, BLUELEDs[57]);
    Tlc.set(KchB, BLUELEDs[58]);
    Tlc.set(LchB, BLUELEDs[59]);
    Tlc.set(MchB, BLUELEDs[60]);
    Tlc.set(NchB, BLUELEDs[61]);
    Tlc.set(OchB, BLUELEDs[62]);
    Tlc.set(PchB, BLUELEDs[63]);
    
    if(layerno == 4){   
		digitalWrite(LayerOne, LOW);  // same as if(layerno==1)
		digitalWrite(LayerTwo, LOW);
		digitalWrite(LayerThree, LOW);
		digitalWrite(LayerFour, LOW);
		Tlc.update();
		delay(1);
		digitalWrite(LayerFour, HIGH);  // sets LayerFour (pin A3) Low (active)--> Layer four ON
	}
  }
  // this does all layers at once.
    if(layerno == 0){     
		digitalWrite(LayerOne, LOW);  // same as if(layerno==1)
		digitalWrite(LayerTwo, LOW);
		digitalWrite(LayerThree, LOW);
		digitalWrite(LayerFour, LOW);
		Tlc.update();
		delay(1);
		digitalWrite(LayerOne, HIGH);  // same as if(layerno==1)
		digitalWrite(LayerTwo, HIGH);
		digitalWrite(LayerThree, HIGH);
		digitalWrite(LayerFour, HIGH);  // sets LayerFour (pin A3) Low (active)--> Layer four ON
	}
}



/* below is a different way to do EWX and NSX using a different technique.... why would you?

// ns x shape - display whole cube at once
void nsx(int red, int green, int blue, int row){
    if(row==0){
		for(int q=0;q<15;q++) {
			for (int n=1;n<5;n++) { // 4 layers
				reset();	
				if(n==1) {
					int turnonlist[] = { 0,3};		
					turnon(turnonlist, 2, red, green, blue);		
				}
				if(n==2) {
					int turnonlist[] = {17,18};		
					turnon(turnonlist, 2, red, green, blue);		
				}
				if(n==3) {
					int turnonlist[] = {34,33};		
					turnon(turnonlist, 2, red, green, blue);		
				}
				if(n==4) {
					int turnonlist[] = {51,48};		
					turnon(turnonlist, 2, red, green, blue);		
				}
				
				while(micros() < oldMicros) {
				}
//				oldMicros=micros()+LayerDuration;           								
				oldMicros=micros()+1000;           												
				CubeUpdate(n);                 // just show that layer on that row
			}
		}
	}
	
    if(row==1){
		for(int q=0;q<15;q++) {
			for (int n=1;n<5;n++) { // 4 layers
				reset();	
				if(n==1) {
					int turnonlist[] = { 4,7};		
					turnon(turnonlist, 2, red, green, blue);		
				}
				if(n==2) {
					int turnonlist[] = {21,22};		
					turnon(turnonlist, 2, red, green, blue);		
				}
				if(n==3) {
					int turnonlist[] = {38,37};		
					turnon(turnonlist, 2, red, green, blue);		
				}
				if(n==4) {
					int turnonlist[] = {55,52};		
					turnon(turnonlist, 2, red, green, blue);		
				}
				
				while(micros() < oldMicros) {
				}
//				oldMicros=micros()+LayerDuration;           								
				oldMicros=micros()+1000;           																
				CubeUpdate(n);                 // just show that layer on that row
			}
		}
	}
    if(row==2){
		for(int q=0;q<15;q++) {
			for (int n=1;n<5;n++) { // 4 layers
				reset();	
				if(n==1) {
					int turnonlist[] = { 8,11};		
					turnon(turnonlist, 2, red, green, blue);		
				}
				if(n==2) {
					int turnonlist[] = {25,26};		
					turnon(turnonlist, 2, red, green, blue);		
				}
				if(n==3) {
					int turnonlist[] = {42,41};		
					turnon(turnonlist, 2, red, green, blue);		
				}
				if(n==4) {
					int turnonlist[] = {56,59};		
					turnon(turnonlist, 2, red, green, blue);		
				}
				
				while(micros() < oldMicros) {
				}
//				oldMicros=micros()+LayerDuration;           								
				oldMicros=micros()+1000;           												
				CubeUpdate(n);                 // just show that layer on that row
			}
		}
    }
    if(row==3){
		for(int q=0;q<15;q++) {
			for (int n=1;n<5;n++) { // 4 layers
				reset();	
				if(n==1) {
					int turnonlist[] = {12,15};		
					turnon(turnonlist, 2, red, green, blue);		
				}
				if(n==2) {
					int turnonlist[] = {29,30};		
					turnon(turnonlist, 2, red, green, blue);		
				}
				if(n==3) {
					int turnonlist[] = {45,46};		
					turnon(turnonlist, 2, red, green, blue);		
				}
				if(n==4) {
					int turnonlist[] = {60,63};		
					turnon(turnonlist, 2, red, green, blue);		
				}
				
				while(micros() < oldMicros) {
				}
				oldMicros=micros()+LayerDuration;           								
//				oldMicros=micros()+1000;           																
				CubeUpdate(n);                 // just show that layer on that row
			}
		}
    } 
}

// ew x shape - display whole cube at once
void ewx(int red, int green, int blue, int column){
    if(column==0){
		for(int q=0;q<15;q++) {
			for (int n=1;n<5;n++) { // 4 layers
				reset();	
				if(n==1) {
					int turnonlist[] = { 0,12};		
					turnon(turnonlist, 2, red, green, blue);		
				}
				if(n==2) {
					int turnonlist[] = {20,24};		
					turnon(turnonlist, 2, red, green, blue);		
				}
				if(n==3) {
					int turnonlist[] = {36,40};		
					turnon(turnonlist, 2, red, green, blue);		
				}
				if(n==4) {
					int turnonlist[] = {48,60};		
					turnon(turnonlist, 2, red, green, blue);		
				}
				
				while(micros() < oldMicros) {
				}
//				oldMicros=micros()+LayerDuration;           								
				oldMicros=micros()+1000;           																
				CubeUpdate(n);                 // just show that layer on that row
			}
		}	
	}
    if(column==1){
		for(int q=0;q<15;q++) {
			for (int n=1;n<5;n++) { // 4 layers
				reset();	
				if(n==1) {
					int turnonlist[] = { 1,13};		
					turnon(turnonlist, 2, red, green, blue);		
				}
				if(n==2) {
					int turnonlist[] = {21,25};		
					turnon(turnonlist, 2, red, green, blue);		
				}
				if(n==3) {
					int turnonlist[] = {41,37};		
					turnon(turnonlist, 2, red, green, blue);		
				}
				if(n==4) {
					int turnonlist[] = {49,61};		
					turnon(turnonlist, 2, red, green, blue);		
				}
				
				while(micros() < oldMicros) {
				}
//				oldMicros=micros()+LayerDuration;           								
				oldMicros=micros()+1000;           												
				CubeUpdate(n);                 // just show that layer on that row
			}
		}	
	}
    if(column==2){
		for(int q=0;q<15;q++) {
			for (int n=1;n<5;n++) { // 4 layers
				reset();	
				if(n==1) {
					int turnonlist[] = { 2,14};		
					turnon(turnonlist, 2, red, green, blue);		
				}
				if(n==2) {
					int turnonlist[] = {22,26};		
					turnon(turnonlist, 2, red, green, blue);		
				}
				if(n==3) {
					int turnonlist[] = {38,42};		
					turnon(turnonlist, 2, red, green, blue);		
				}
				if(n==4) {
					int turnonlist[] = {50,62};		
					turnon(turnonlist, 2, red, green, blue);		
				}
				
				while(micros() < oldMicros) {
				}
//				oldMicros=micros()+LayerDuration;           								
				oldMicros=micros()+1000;           																
				CubeUpdate(n);                 // just show that layer on that row
			}
		}	
    }
    if(column==3){
		for(int q=0;q<15;q++) {
			for (int n=1;n<5;n++) { // 4 layers
				reset();	
				if(n==1) {
					int turnonlist[] = { 3,15};		
					turnon(turnonlist, 2, red, green, blue);		
				}
				if(n==2) {
					int turnonlist[] = {23,27};		
					turnon(turnonlist, 2, red, green, blue);		
				}
				if(n==3) {
					int turnonlist[] = {39,43};		
					turnon(turnonlist, 2, red, green, blue);		
				}
				if(n==4) {
					int turnonlist[] = {51,63};		
					turnon(turnonlist, 2, red, green, blue);		
				}
				
				while(micros() < oldMicros) {
				}
//				oldMicros=micros()+LayerDuration;           								
				oldMicros=micros()+1000;           												
				CubeUpdate(n);                 // just show that layer on that row
			}
		}	
    }
}
*/
	/*	
	for (int p=0;p<64;p++){
		Serial.print (REDLEDs[p]);
		Serial.print ("-");
	}	
	Serial.print ("\n");					

	for (int p=0;p<64;p++){
		Serial.print (REDLEDs[p]);
		Serial.print ("-");
		Serial.print (GREENLEDs[p]);
		Serial.print ("-");
		Serial.print (BLUELEDs[p]);
		Serial.print ("\n");		
	}	
	delay(5000);
	*/
