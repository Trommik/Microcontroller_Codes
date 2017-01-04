void Strings_to_arrays(){
  String zahl = "";

  for(int i = 0; i < 16; i++){
    zahl = str_r1.substring(i*4,3+i*4);
    redv[i] = zahl.toInt();
    redv[i] = map(redv[i],0,255,0,4095);
  }
  for(int i = 0; i < 16; i++){
    zahl = str_r2.substring(i*4,3+i*4);
    redv[i+16] = zahl.toInt();
    redv[i+16] = map(redv[i],0,255,0,4095);
  }  
  for(int i = 0; i < 16; i++){
    zahl = str_r3.substring(i*4,3+i*4);
    redv[i+16*2] = zahl.toInt();
    redv[i+16*2] = map(redv[i],0,255,0,4095);
  }
  for(int i = 0; i < 16; i++){
    zahl = str_r4.substring(i*4,3+i*4);
    redv[i+16*3] = zahl.toInt();
    redv[i+16*3] = map(redv[i],0,255,0,4095);
  }  

  for(int i = 0; i < 16; i++){
    zahl = str_g1.substring(i*4,3+i*4);
    grnv[i] = zahl.toInt();
    grnv[i] = map(grnv[i],0,255,0,4095);
  }
  for(int i = 0; i < 16; i++){
    zahl = str_g2.substring(i*4,3+i*4);
    grnv[i+16] = zahl.toInt();
    grnv[i+16] = map(grnv[i],0,255,0,4095);
  }  
  for(int i = 0; i < 16; i++){
    zahl = str_g3.substring(i*4,3+i*4);
    grnv[i+16*2] = zahl.toInt();
    grnv[i+16*2] = map(grnv[i],0,255,0,4095);
  }
  for(int i = 0; i < 16; i++){
    zahl = str_g4.substring(i*4,3+i*4);
    grnv[i+16*3] = zahl.toInt();
    grnv[i+16*3] = map(grnv[i],0,255,0,4095);
  }  

  for(int i = 0; i < 16; i++){
    zahl = str_b1.substring(i*4,3+i*4);
    bluv[i] = zahl.toInt();
    bluv[i] = map(bluv[i],0,255,0,4095);
  }
  for(int i = 0; i < 16; i++){
    zahl = str_b2.substring(i*4,3+i*4);
    bluv[i+16] = zahl.toInt();
    bluv[i+16] = map(bluv[i],0,255,0,4095);
  }  
  for(int i = 0; i < 16; i++){
    zahl = str_b3.substring(i*4,3+i*4);
    bluv[i+16*2] = zahl.toInt();
    bluv[i+16*2] = map(bluv[i],0,255,0,4095);
  }
  for(int i = 0; i < 16; i++){
    zahl = str_b4.substring(i*4,3+i*4);
    bluv[i+16*3] = zahl.toInt();
    bluv[i+16*3] = map(bluv[i],0,255,0,4095);
  }  
}



















void Serial_get_String(){
  switch(_ser){
    case 1://NORMAL
      while (Serial.available() == 2){
        str = "";
        
        for(int i = 0; i < 2; i++){
          incomingByte = (char)Serial.read();
          str += incomingByte;
        }
        
        //Serial.println(str);
        if (str == "CL"){
          Serial.println("CLEAR");
          str = "";
        }else if( str == "ST"){//START
          //#TODO flush arrays to tlcs and set layers
        }else if( str == "R1"){

          _ser = 2;
        }//else if( str == "G1"){
          
          //_ser = 6;
        //}else if( str == "B1"){

        //  _ser = 10;
        //}
      }
      break;
    case 2://r1
      while (Serial.available() == 63){ // Wait 'till there are 63 Bytes waiting
        str = "";
        for(int i = 0; i < 63; i++){
          incomingByte = (char)Serial.read();
          str += incomingByte;
        }
        str_r1 = str;
        _ser = 3;//r2
      }
      break;
    case 3://r2
      while (Serial.available() == 63){ // Wait 'till there are 63 Bytes waiting
        str = "";
        for(int i = 0; i < 63; i++){
          incomingByte = (char)Serial.read();
          str += incomingByte;
        }
        str_r2 = str;
        _ser = 4;//r3
      }
      break;
    case 4://r3
      while (Serial.available() == 63){ // Wait 'till there are 63 Bytes waiting
        str = "";
        for(int i = 0; i < 63; i++){
          incomingByte = (char)Serial.read();
          str += incomingByte;
        }
        str_r3 = str;
        _ser = 5;//r4
      }
      break;
    case 5://r4
      while (Serial.available() == 63){ // Wait 'till there are 63 Bytes waiting
        str = "";
        for(int i = 0; i < 63; i++){
          incomingByte = (char)Serial.read();
          str += incomingByte;
        }
        str_r4 = str;
        //_ser = 1;//backtostart
        _ser = 6;//g1
      }
      break;
    case 6://g1
      while (Serial.available() == 63){ // Wait 'till there are 63 Bytes waiting
        str = "";
        for(int i = 0; i < 63; i++){
          incomingByte = (char)Serial.read();
          str += incomingByte;
        }
        str_g1 = str;
        _ser = 7;//g2
      }
      break;
    case 7://g2
      while (Serial.available() == 63){ // Wait 'till there are 63 Bytes waiting
        str = "";
        for(int i = 0; i < 63; i++){
          incomingByte = (char)Serial.read();
          str += incomingByte;
        }
        str_g2 = str;
        _ser = 8;//g3
      }
      break;
    case 8://g3
      while (Serial.available() == 63){ // Wait 'till there are 63 Bytes waiting
        str = "";
        for(int i = 0; i < 63; i++){
          incomingByte = (char)Serial.read();
          str += incomingByte;
        }
        str_g3 = str;
        _ser = 9;//g4
      }
      break;
    case 9://g4
      while (Serial.available() == 63){ // Wait 'till there are 63 Bytes waiting
        str = "";
        for(int i = 0; i < 63; i++){
          incomingByte = (char)Serial.read();
          str += incomingByte;
        }
        str_g4 = str;
        //_ser = 1;//backtostart
        _ser = 10;//b1
      }
      break;
    case 10://b1
      while (Serial.available() == 63){ // Wait 'till there are 63 Bytes waiting
        str = "";
        for(int i = 0; i < 63; i++){
          incomingByte = (char)Serial.read();
          str += incomingByte;
        }
        str_b1 = str;
        _ser = 11;//b1
      }
      break;
    case 11://b2
      while (Serial.available() == 63){ // Wait 'till there are 63 Bytes waiting
        str = "";
        for(int i = 0; i < 63; i++){
          incomingByte = (char)Serial.read();
          str += incomingByte;
        }
        str_b2 = str;
        _ser = 12;//b2
      }
      break;
    case 12://b3
      while (Serial.available() == 63){ // Wait 'till there are 63 Bytes waiting
        str = "";
        for(int i = 0; i < 63; i++){
          incomingByte = (char)Serial.read();
          str += incomingByte;
        }
        str_b3 = str;
        _ser = 13;//b4
      }
      break;
    case 13://b4
      while (Serial.available() == 63){ // Wait 'till there are 63 Bytes waiting
        str = "";
        for(int i = 0; i < 63; i++){
          incomingByte = (char)Serial.read();
          str += incomingByte;
        }
        str_b4 = str;
        _ser = 1;//backtostart
      }
      break;
  }
}

