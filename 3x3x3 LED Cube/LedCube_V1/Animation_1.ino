void Animation_1(){
for (int i = 0; i < 50; i++){
digitalWrite(led[2],HIGH);
digitalWrite(row[0],HIGH);
delay(3);
reset();
digitalWrite(led[1],HIGH);
digitalWrite(row[1],HIGH);
delay(3);
reset();
digitalWrite(led[0],HIGH);
digitalWrite(row[2],HIGH);
delay(3);
reset();
}

for (int i = 0; i < 50; i++){
digitalWrite(led[5],HIGH);
digitalWrite(row[0],HIGH);
delay(3);
reset();
digitalWrite(led[4],HIGH);
digitalWrite(row[1],HIGH);
delay(3);
reset();
digitalWrite(led[3],HIGH);
digitalWrite(row[2],HIGH);
delay(3);
reset();
}

for (int i = 0; i < 50; i++){
digitalWrite(led[8],HIGH);
digitalWrite(row[0],HIGH);
delay(3);
reset();
digitalWrite(led[7],HIGH);
digitalWrite(row[1],HIGH);
delay(3);
reset();
digitalWrite(led[6],HIGH);
digitalWrite(row[2],HIGH);
delay(3);
reset();
}
}

