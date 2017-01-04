/*void Rain(){
  
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
    for (int a = 3;a>=0;a--){
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
    for (int a = 3;a>=0;a--){
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
    for (int a = 3;a>=0;a--){
      digitalWrite(layer[a],HIGH);
      delay(100);
      digitalWrite(layer[a],LOW);
    }
    reset();
  }
}


void Rain(int dely){
  for(int l = 0; l < 4; l++){
    for(int r = 0; r < 4; r++){
      int rnd = random(47);
      random_nbrs[l][r] = rnd;
    }
  }
  
  for(int w = 0; w < dely; w++){
    
        Tlc.set(random_nbrs[0][0],4095);
        Tlc.set(random_nbrs[0][1],4095);
        Tlc.set(random_nbrs[0][2],4095);
        Tlc.set(random_nbrs[0][3],4095);
        layer_on(1);
        
        Tlc.set(random_nbrs[1][0],4095);
        Tlc.set(random_nbrs[1][1],4095);
        Tlc.set(random_nbrs[1][2],4095);
        Tlc.set(random_nbrs[1][3],4095);
        layer_on(2);
        
        
        Tlc.set(random_nbrs[1][0],4095);
        Tlc.set(random_nbrs[1][1],4095);
        Tlc.set(random_nbrs[1][2],4095);
        Tlc.set(random_nbrs[1][3],4095);
        layer_on(3);
        

        Tlc.set(random_nbrs[1][0],4095);
        Tlc.set(random_nbrs[1][1],4095);
        Tlc.set(random_nbrs[1][2],4095);
        Tlc.set(random_nbrs[1][3],4095);
        layer_on(4);
    
  }
  
  
}
*/
