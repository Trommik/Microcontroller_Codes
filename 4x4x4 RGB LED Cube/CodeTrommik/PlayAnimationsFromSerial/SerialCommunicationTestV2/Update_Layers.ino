void update_layers(){
  switch (layer_update){
    case 1:
  
      //layer1
      Tlc.set( 0, red[ 0]);//first TLC5940 
      Tlc.set( 1, red[ 1]);
      Tlc.set( 2, red[ 2]);
      Tlc.set( 3, red[ 3]);
      Tlc.set( 4, red[ 4]);
      Tlc.set( 5, red[ 5]);
      Tlc.set( 6, red[ 6]);
      Tlc.set( 7, red[ 7]);
      Tlc.set( 8, red[ 8]);
      Tlc.set( 9, red[ 9]);
      Tlc.set(10, red[10]);
      Tlc.set(11, red[11]);
      Tlc.set(12, red[12]);
      Tlc.set(13, red[13]);
      Tlc.set(14, red[14]);
      Tlc.set(15, red[15]);
      Tlc.set(16, grn[ 0]);//second TLC5940
      Tlc.set(17, grn[ 1]);
      Tlc.set(18, grn[ 2]);
      Tlc.set(19, grn[ 3]);
      Tlc.set(20, grn[ 4]);
      Tlc.set(21, grn[ 5]);
      Tlc.set(22, grn[ 6]);
      Tlc.set(23, grn[ 7]);
      Tlc.set(24, grn[ 8]);
      Tlc.set(25, grn[ 9]);
      Tlc.set(26, grn[10]);
      Tlc.set(27, grn[11]);
      Tlc.set(28, grn[12]);
      Tlc.set(29, grn[13]);
      Tlc.set(30, grn[14]);
      Tlc.set(31, grn[15]);
      Tlc.set(32, blu[ 0]);//third TLC5940
      Tlc.set(33, blu[ 1]);
      Tlc.set(34, blu[ 2]);
      Tlc.set(35, blu[ 3]);
      Tlc.set(36, blu[ 4]);
      Tlc.set(37, blu[ 5]);
      Tlc.set(38, blu[ 6]);
      Tlc.set(39, blu[ 7]);
      Tlc.set(40, blu[ 8]);
      Tlc.set(41, blu[ 9]);
      Tlc.set(42, blu[10]);
      Tlc.set(43, blu[11]);
      Tlc.set(44, blu[12]);
      Tlc.set(45, blu[13]);
      Tlc.set(46, blu[14]);
      Tlc.set(47, blu[15]);

      digitalWrite(layer[0],LOW);
      digitalWrite(layer[1],LOW);
      digitalWrite(layer[2],LOW);
      digitalWrite(layer[3],LOW);
      
      Tlc.update(); 
      
      delayMicroseconds(1200);
  
      digitalWrite(layer[0],HIGH);
  
      layer_update += 1;
      
      break;
    case 2:
  
      //layer2
      Tlc.set( 0, red[16]);//first TLC5940 
      Tlc.set( 1, red[17]);
      Tlc.set( 2, red[18]);
      Tlc.set( 3, red[19]);
      Tlc.set( 4, red[20]);
      Tlc.set( 5, red[21]);
      Tlc.set( 6, red[22]);
      Tlc.set( 7, red[23]);
      Tlc.set( 8, red[24]);
      Tlc.set( 9, red[25]);
      Tlc.set(10, red[26]);
      Tlc.set(11, red[27]);
      Tlc.set(12, red[28]);
      Tlc.set(13, red[29]);
      Tlc.set(14, red[30]);
      Tlc.set(15, red[31]);
      Tlc.set(16, grn[16]);//second TLC5940
      Tlc.set(17, grn[17]);
      Tlc.set(18, grn[18]);
      Tlc.set(19, grn[19]);
      Tlc.set(20, grn[20]);
      Tlc.set(21, grn[21]);
      Tlc.set(22, grn[22]);
      Tlc.set(23, grn[23]);
      Tlc.set(24, grn[24]);
      Tlc.set(25, grn[25]);
      Tlc.set(26, grn[26]);
      Tlc.set(27, grn[27]);
      Tlc.set(28, grn[28]);
      Tlc.set(29, grn[29]);
      Tlc.set(30, grn[30]);
      Tlc.set(31, grn[31]);
      Tlc.set(32, blu[16]);//third TLC5940
      Tlc.set(33, blu[17]);
      Tlc.set(34, blu[18]);
      Tlc.set(35, blu[19]);
      Tlc.set(36, blu[20]);
      Tlc.set(37, blu[21]);
      Tlc.set(38, blu[22]);
      Tlc.set(39, blu[23]);
      Tlc.set(40, blu[24]);
      Tlc.set(41, blu[25]);
      Tlc.set(42, blu[26]);
      Tlc.set(43, blu[27]);
      Tlc.set(44, blu[28]);
      Tlc.set(45, blu[29]);
      Tlc.set(46, blu[30]);
      Tlc.set(47, blu[31]);
  
      digitalWrite(layer[0],LOW);
      digitalWrite(layer[1],LOW);
      digitalWrite(layer[2],LOW);
      digitalWrite(layer[3],LOW);
      
      Tlc.update(); 
      
      delayMicroseconds(1200);
  
      digitalWrite(layer[1],HIGH);
  
      layer_update += 1;
  
      break;
    case 3:
  
      //layer3
      Tlc.set( 0, red[32]);//first TLC5940 
      Tlc.set( 1, red[33]);
      Tlc.set( 2, red[34]);
      Tlc.set( 3, red[35]);
      Tlc.set( 4, red[36]);
      Tlc.set( 5, red[37]);
      Tlc.set( 6, red[38]);
      Tlc.set( 7, red[39]);
      Tlc.set( 8, red[40]);
      Tlc.set( 9, red[41]);
      Tlc.set(10, red[42]);
      Tlc.set(11, red[43]);
      Tlc.set(12, red[44]);
      Tlc.set(13, red[45]);
      Tlc.set(14, red[46]);
      Tlc.set(15, red[47]);
      Tlc.set(16, grn[32]);//second TLC5940
      Tlc.set(17, grn[33]);
      Tlc.set(18, grn[34]);
      Tlc.set(19, grn[35]);
      Tlc.set(20, grn[36]);
      Tlc.set(21, grn[37]);
      Tlc.set(22, grn[38]);
      Tlc.set(23, grn[39]);
      Tlc.set(24, grn[40]);
      Tlc.set(25, grn[41]);
      Tlc.set(26, grn[42]);
      Tlc.set(27, grn[43]);
      Tlc.set(28, grn[44]);
      Tlc.set(29, grn[45]);
      Tlc.set(30, grn[46]);
      Tlc.set(31, grn[47]);
      Tlc.set(32, blu[32]);//third TLC5940
      Tlc.set(33, blu[33]);
      Tlc.set(34, blu[34]);
      Tlc.set(35, blu[35]);
      Tlc.set(36, blu[36]);
      Tlc.set(37, blu[37]);
      Tlc.set(38, blu[38]);
      Tlc.set(39, blu[39]);
      Tlc.set(40, blu[40]);
      Tlc.set(41, blu[41]);
      Tlc.set(42, blu[42]);
      Tlc.set(43, blu[43]);
      Tlc.set(44, blu[44]);
      Tlc.set(45, blu[45]);
      Tlc.set(46, blu[46]);
      Tlc.set(47, blu[47]);
  
      digitalWrite(layer[0],LOW);
      digitalWrite(layer[1],LOW);
      digitalWrite(layer[2],LOW);
      digitalWrite(layer[3],LOW);
      
      Tlc.update(); 
      
      delayMicroseconds(1200);
  
      digitalWrite(layer[2],HIGH);
  
      layer_update += 1;
  
      break;
    case 4:
  
      //layer4
      Tlc.set( 0, red[48]);//first TLC5940 
      Tlc.set( 1, red[49]);
      Tlc.set( 2, red[50]);
      Tlc.set( 3, red[51]);
      Tlc.set( 4, red[52]);
      Tlc.set( 5, red[53]);
      Tlc.set( 6, red[54]);
      Tlc.set( 7, red[55]);
      Tlc.set( 8, red[56]);
      Tlc.set( 9, red[57]);
      Tlc.set(10, red[58]);
      Tlc.set(11, red[59]);
      Tlc.set(12, red[60]);
      Tlc.set(13, red[61]);
      Tlc.set(14, red[62]);
      Tlc.set(15, red[63]);
      Tlc.set(16, grn[48]);//second TLC5940
      Tlc.set(17, grn[49]);
      Tlc.set(18, grn[50]);
      Tlc.set(19, grn[51]);
      Tlc.set(20, grn[52]);
      Tlc.set(21, grn[53]);
      Tlc.set(22, grn[54]);
      Tlc.set(23, grn[55]);
      Tlc.set(24, grn[56]);
      Tlc.set(25, grn[57]);
      Tlc.set(26, grn[58]);
      Tlc.set(27, grn[59]);
      Tlc.set(28, grn[60]);
      Tlc.set(29, grn[61]);
      Tlc.set(30, grn[62]);
      Tlc.set(31, grn[63]);
      Tlc.set(32, blu[48]);//third TLC5940
      Tlc.set(33, blu[49]);
      Tlc.set(34, blu[50]);
      Tlc.set(35, blu[51]);
      Tlc.set(36, blu[52]);
      Tlc.set(37, blu[53]);
      Tlc.set(38, blu[54]);
      Tlc.set(39, blu[55]);
      Tlc.set(40, blu[56]);
      Tlc.set(41, blu[57]);
      Tlc.set(42, blu[58]);
      Tlc.set(43, blu[59]);
      Tlc.set(44, blu[60]);
      Tlc.set(45, blu[61]);
      Tlc.set(46, blu[62]);
      Tlc.set(47, blu[63]);
  
      digitalWrite(layer[0],LOW);
      digitalWrite(layer[1],LOW);
      digitalWrite(layer[2],LOW);
      digitalWrite(layer[3],LOW);
      
      Tlc.update(); 
      
      delayMicroseconds(1200);
  
      digitalWrite(layer[3],HIGH);
  
      layer_update = 1;

    break;
  }
}

