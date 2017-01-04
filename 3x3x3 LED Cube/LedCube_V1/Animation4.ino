void animation4(){

int rndlast;
int rnd;

int rndlast2;
int rnd2;

  for (int b = 0;b<100;b++){
  
    rnd = random(9);
    if (rndlast == rnd){
        rnd = random(9);
        if (rndlast == rnd){
            rnd = random(9);
        }
    }
  
    rnd2 = random(3);
    if (rndlast2 == rnd2){
        rnd2 = random(3);
        if (rndlast2 == rnd2){
            rnd2 = random(3);
        }
    }
    rndlast2 = rnd2;
    rndlast = rnd;
    
    digitalWrite(led[rnd],HIGH);
    digitalWrite(row[rnd2],HIGH);
    delay(200);
    digitalWrite(row[rnd2],LOW);
    digitalWrite(led[rnd],LOW);
  }
}
