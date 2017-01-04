void Random(){
  
  int rndlast;
  int rnd;

  for (int b = 0;b<10;b++){
  
    rnd = random(16);
    if (rndlast == rnd){
        rnd = random(16);
        if (rndlast == rnd){
            rnd = random(16);
        }
    }
    
    rndlast = rnd;
  
    Tlc.set(red[rnd],4095);
    for (int a = 0;a<4;a++){
      digitalWrite(layer[a],HIGH);
      delay(100);
      digitalWrite(layer[a],LOW);
    }
    reset();
    
    rnd = random(16);
    if (rndlast == rnd){
        rnd = random(16);
        if (rndlast == rnd){
            rnd = random(16);
        }
    }
    
    rndlast = rnd;
  
    Tlc.set(grn[rnd],4095);
    for (int a = 0;a<4;a++){
      digitalWrite(layer[a],HIGH);
      delay(100);
      digitalWrite(layer[a],LOW);
    }
    reset();
    
    rnd = random(16);
    if (rndlast == rnd){
        rnd = random(16);
        if (rndlast == rnd){
            rnd = random(16);
        }
    }
    
    rndlast = rnd;
  
    Tlc.set(blu[rnd],4095);
    for (int a = 0;a<4;a++){
      digitalWrite(layer[a],HIGH);
      delay(100);
      digitalWrite(layer[a],LOW);
    }
    reset();
  }
  
  
  
}

