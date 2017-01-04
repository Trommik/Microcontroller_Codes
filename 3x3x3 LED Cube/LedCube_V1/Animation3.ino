void animation3(){
  
int rndlast;
int rnd;

  for (int b = 0;b<10;b++){
  
    rnd = random(9);
    if (rndlast == rnd){
        rnd = random(9);
        if (rndlast == rnd){
            rnd = random(9);
        }
    }
    
    rndlast = rnd;
  
    digitalWrite(led[rnd],HIGH);
    for (int a = 0;a<3;a++){
      digitalWrite(row[a],HIGH);
      delay(200);
      digitalWrite(row[a],LOW);
    }
    digitalWrite(led[rnd],LOW);
  }
}
