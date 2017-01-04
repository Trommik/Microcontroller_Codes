void blue_turnon(int liste[], int anzahl, int bright2){
    for (int i = 0; i < anzahl; i++){
        bluv[liste[i]] = bright2;
    }
}

void green_turnon(int liste[], int anzahl, int bright2){
    for (int i = 0; i < anzahl; i++){
        grnv[liste[i]] = bright2;
    }
}

void red_turnon(int liste[], int anzahl, int bright2){
    for (int i = 0; i < anzahl; i++){
        redv[liste[i]] = bright2;
    }
}

void show_layer(int layernbr, int reset_tlc){
  switch (layernbr){
  case 1:

    delayMicroseconds(500);
    
    digitalWrite(layer[1],LOW);
    digitalWrite(layer[2],LOW);
    digitalWrite(layer[3],LOW);
    
    Tlc.update(); 

    //layer2
    Tlc.set(red[0], redv[16]);//first TLC5940 
    Tlc.set(red[1], redv[17]);
    Tlc.set(red[2], redv[18]);
    Tlc.set(red[3], redv[19]);
    Tlc.set(red[4], redv[20]);
    Tlc.set(red[5], redv[21]);
    Tlc.set(red[6], redv[22]);
    Tlc.set(red[7], redv[23]);
    Tlc.set(red[8], redv[24]);
    Tlc.set(red[9], redv[25]);
    Tlc.set(red[10], redv[26]);
    Tlc.set(red[11], redv[27]);
    Tlc.set(red[12], redv[28]);
    Tlc.set(red[13], redv[29]);
    Tlc.set(red[14], redv[30]);
    Tlc.set(red[15], redv[31]);
    Tlc.set(grn[0], grnv[16]);//second TLC5940
    Tlc.set(grn[1], grnv[17]);
    Tlc.set(grn[2], grnv[18]);
    Tlc.set(grn[3], grnv[19]);
    Tlc.set(grn[4], grnv[20]);
    Tlc.set(grn[5], grnv[21]);
    Tlc.set(grn[6], grnv[22]);
    Tlc.set(grn[7], grnv[23]);
    Tlc.set(grn[8], grnv[24]);
    Tlc.set(grn[9], grnv[25]);
    Tlc.set(grn[10], grnv[26]);
    Tlc.set(grn[11], grnv[27]);
    Tlc.set(grn[12], grnv[28]);
    Tlc.set(grn[13], grnv[29]);
    Tlc.set(grn[14], grnv[30]);
    Tlc.set(grn[15], grnv[31]);
    Tlc.set(blu[0], bluv[16]);//third TLC5940
    Tlc.set(blu[1], bluv[17]);
    Tlc.set(blu[2], bluv[18]);
    Tlc.set(blu[3], bluv[19]);
    Tlc.set(blu[4], bluv[20]);
    Tlc.set(blu[5], bluv[21]);
    Tlc.set(blu[6], bluv[22]);
    Tlc.set(blu[7], bluv[23]);
    Tlc.set(blu[8], bluv[24]);
    Tlc.set(blu[9], bluv[25]);
    Tlc.set(blu[10], bluv[26]);
    Tlc.set(blu[11], bluv[27]);
    Tlc.set(blu[12], bluv[28]);
    Tlc.set(blu[13], bluv[29]);
    Tlc.set(blu[14], bluv[30]);
    Tlc.set(blu[15], bluv[31]);
    //layer2

    delayMicroseconds(tlc_update_time);
    
    digitalWrite(layer[0],HIGH);
 
    break;
  case 2:

    delayMicroseconds(500);
  
    digitalWrite(layer[0],LOW);
    digitalWrite(layer[2],LOW);
    digitalWrite(layer[3],LOW);
    
    Tlc.update(); 

    //layer3
    Tlc.set(red[0], redv[32]);//first TLC5940 
    Tlc.set(red[1], redv[33]);
    Tlc.set(red[2], redv[34]);
    Tlc.set(red[3], redv[35]);
    Tlc.set(red[4], redv[36]);
    Tlc.set(red[5], redv[37]);
    Tlc.set(red[6], redv[38]);
    Tlc.set(red[7], redv[39]);
    Tlc.set(red[8], redv[40]);
    Tlc.set(red[9], redv[41]);
    Tlc.set(red[10], redv[42]);
    Tlc.set(red[11], redv[43]);
    Tlc.set(red[12], redv[44]);
    Tlc.set(red[13], redv[45]);
    Tlc.set(red[14], redv[46]);
    Tlc.set(red[15], redv[47]);
    Tlc.set(grn[0], grnv[32]);//second TLC5940
    Tlc.set(grn[1], grnv[33]);
    Tlc.set(grn[2], grnv[34]);
    Tlc.set(grn[3], grnv[35]);
    Tlc.set(grn[4], grnv[36]);
    Tlc.set(grn[5], grnv[37]);
    Tlc.set(grn[6], grnv[38]);
    Tlc.set(grn[7], grnv[39]);
    Tlc.set(grn[8], grnv[40]);
    Tlc.set(grn[9], grnv[41]);
    Tlc.set(grn[10], grnv[42]);
    Tlc.set(grn[11], grnv[43]);
    Tlc.set(grn[12], grnv[44]);
    Tlc.set(grn[13], grnv[45]);
    Tlc.set(grn[14], grnv[46]);
    Tlc.set(grn[15], grnv[47]);
    Tlc.set(blu[0], bluv[32]);//third TLC5940
    Tlc.set(blu[1], bluv[33]);
    Tlc.set(blu[2], bluv[34]);
    Tlc.set(blu[3], bluv[35]);
    Tlc.set(blu[4], bluv[36]);
    Tlc.set(blu[5], bluv[37]);
    Tlc.set(blu[6], bluv[38]);
    Tlc.set(blu[7], bluv[39]);
    Tlc.set(blu[8], bluv[40]);
    Tlc.set(blu[9], bluv[41]);
    Tlc.set(blu[10], bluv[42]);
    Tlc.set(blu[11], bluv[43]);
    Tlc.set(blu[12], bluv[44]);
    Tlc.set(blu[13], bluv[45]);
    Tlc.set(blu[14], bluv[46]);
    Tlc.set(blu[15], bluv[47]);
    //layer3

    delayMicroseconds(tlc_update_time);
    
    digitalWrite(layer[1],HIGH);

    break;
  case 3:

    delayMicroseconds(500);
    
    digitalWrite(layer[0],LOW);
    digitalWrite(layer[1],LOW);
    digitalWrite(layer[3],LOW);
    
    Tlc.update(); 

    //layer4
    Tlc.set(red[0], redv[48]);//first TLC5940 
    Tlc.set(red[1], redv[49]);
    Tlc.set(red[2], redv[50]);
    Tlc.set(red[3], redv[51]);
    Tlc.set(red[4], redv[52]);
    Tlc.set(red[5], redv[53]);
    Tlc.set(red[6], redv[54]);
    Tlc.set(red[7], redv[55]);
    Tlc.set(red[8], redv[56]);
    Tlc.set(red[9], redv[57]);
    Tlc.set(red[10], redv[58]);
    Tlc.set(red[11], redv[59]);
    Tlc.set(red[12], redv[60]);
    Tlc.set(red[13], redv[61]);
    Tlc.set(red[14], redv[62]);
    Tlc.set(red[15], redv[63]);
    Tlc.set(grn[0], grnv[48]);//second TLC5940
    Tlc.set(grn[1], grnv[49]);
    Tlc.set(grn[2], grnv[50]);
    Tlc.set(grn[3], grnv[51]);
    Tlc.set(grn[4], grnv[52]);
    Tlc.set(grn[5], grnv[53]);
    Tlc.set(grn[6], grnv[54]);
    Tlc.set(grn[7], grnv[55]);
    Tlc.set(grn[8], grnv[56]);
    Tlc.set(grn[9], grnv[57]);
    Tlc.set(grn[10], grnv[58]);
    Tlc.set(grn[11], grnv[59]);
    Tlc.set(grn[12], grnv[60]);
    Tlc.set(grn[13], grnv[61]);
    Tlc.set(grn[14], grnv[62]);
    Tlc.set(grn[15], grnv[63]);
    Tlc.set(blu[0], bluv[48]);//third TLC5940
    Tlc.set(blu[1], bluv[49]);
    Tlc.set(blu[2], bluv[50]);
    Tlc.set(blu[3], bluv[51]);
    Tlc.set(blu[4], bluv[52]);
    Tlc.set(blu[5], bluv[53]);
    Tlc.set(blu[6], bluv[54]);
    Tlc.set(blu[7], bluv[55]);
    Tlc.set(blu[8], bluv[56]);
    Tlc.set(blu[9], bluv[57]);
    Tlc.set(blu[10], bluv[58]);
    Tlc.set(blu[11], bluv[59]);
    Tlc.set(blu[12], bluv[60]);
    Tlc.set(blu[13], bluv[61]);
    Tlc.set(blu[14], bluv[62]);
    Tlc.set(blu[15], bluv[63]);
    //layer4

    delayMicroseconds(tlc_update_time);
    
    digitalWrite(layer[2],HIGH);

    break;
  case 4:

    delayMicroseconds(500);
    
    digitalWrite(layer[0],LOW);
    digitalWrite(layer[1],LOW);
    digitalWrite(layer[2],LOW);

    Tlc.update(); 

    delayMicroseconds(tlc_update_time);

    //layer1
    Tlc.set(red[0], redv[0]);//first TLC5940 
    Tlc.set(red[1], redv[1]);
    Tlc.set(red[2], redv[2]);
    Tlc.set(red[3], redv[3]);
    Tlc.set(red[4], redv[4]);
    Tlc.set(red[5], redv[5]);
    Tlc.set(red[6], redv[6]);
    Tlc.set(red[7], redv[7]);
    Tlc.set(red[8], redv[8]);
    Tlc.set(red[9], redv[9]);
    Tlc.set(red[10], redv[10]);
    Tlc.set(red[11], redv[11]);
    Tlc.set(red[12], redv[12]);
    Tlc.set(red[13], redv[13]);
    Tlc.set(red[14], redv[14]);
    Tlc.set(red[15], redv[15]);
    Tlc.set(grn[0], grnv[0]);//second TLC5940
    Tlc.set(grn[1], grnv[1]);
    Tlc.set(grn[2], grnv[2]);
    Tlc.set(grn[3], grnv[3]);
    Tlc.set(grn[4], grnv[4]);
    Tlc.set(grn[5], grnv[5]);
    Tlc.set(grn[6], grnv[6]);
    Tlc.set(grn[7], grnv[7]);
    Tlc.set(grn[8], grnv[8]);
    Tlc.set(grn[9], grnv[9]);
    Tlc.set(grn[10], grnv[10]);
    Tlc.set(grn[11], grnv[11]);
    Tlc.set(grn[12], grnv[12]);
    Tlc.set(grn[13], grnv[13]);
    Tlc.set(grn[14], grnv[14]);
    Tlc.set(grn[15], grnv[15]);
    Tlc.set(blu[0], bluv[0]);//third TLC5940
    Tlc.set(blu[1], bluv[1]);
    Tlc.set(blu[2], bluv[2]);
    Tlc.set(blu[3], bluv[3]);
    Tlc.set(blu[4], bluv[4]);
    Tlc.set(blu[5], bluv[5]);
    Tlc.set(blu[6], bluv[6]);
    Tlc.set(blu[7], bluv[7]);
    Tlc.set(blu[8], bluv[8]);
    Tlc.set(blu[9], bluv[9]);
    Tlc.set(blu[10], bluv[10]);
    Tlc.set(blu[11], bluv[11]);
    Tlc.set(blu[12], bluv[12]);
    Tlc.set(blu[13], bluv[13]);
    Tlc.set(blu[14], bluv[14]);
    Tlc.set(blu[15], bluv[15]);
    //layer1
    
    digitalWrite(layer[3],HIGH);

    break;
  }
  if(reset_tlc >= 1){
    for (int p=0;p<64;p++){
       redv[p]=0;
       grnv[p]=0;
       bluv[p]=0;
    }
  }
  
}



