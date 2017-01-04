void animation2(){
  for (int b = 0; b<3;b++){
      for (int a = 0; a<9;a++){
        digitalWrite(led[a],HIGH);
        digitalWrite(row[b],HIGH);
        delay(50);
        digitalWrite(row[b],LOW);
        digitalWrite(led[a],LOW);
      }
  }
}

