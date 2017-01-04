void Random_2(){

int rndlast;
int rnd;

int rndlast2;
int rnd2;

int rndlast3;
int rnd3;

  for (int b = 0;b<50;b++){
  
    rnd = random(16);
    if (rndlast == rnd){
        rnd = random(16);
        if (rndlast == rnd){
            rnd = random(16);
        }
    }
  
    rnd2 = random(4);
    if (rndlast2 == rnd2){
        rnd2 = random(4);
        if (rndlast2 == rnd2){
            rnd2 = random(4);
        }
    }
    
    rnd3 = random(3);
    if (rndlast3 == rnd3){
        rnd3 = random(3);
        if (rndlast3 == rnd3){
            rnd3 = random(3);
        }
    }
    rndlast3 = rnd3;
    rndlast2 = rnd2;
    rndlast = rnd;
    


    if (rnd3 == 1){
      
      Tlc.set(red[rnd],2047);
      digitalWrite(layer[rnd2],HIGH);
      delay(200);
      reset_layer();
      
    }else if(rnd3 == 2){
      
      Tlc.set(grn[rnd],2047);
      digitalWrite(layer[rnd2],HIGH);
      delay(200);
      reset_layer();
      
    }else{
      
      Tlc.set(blu[rnd],2047);
      digitalWrite(layer[rnd2],HIGH);
      delay(200);
      reset_layer();
      
    }
  }
}
