void Serial_get(){
  switch(_ser){
    case 1://NORMAL
      while (Serial.available() == 2){
        str = "";
        for(int i = 0; i < 2; i++){
          incomingByte = (char)Serial.read();
          str += incomingByte;
        }
      }

      if (str == "CL"){
        Serial.println("CLEAR");
        str = "";
      }else if( str == "SA"){//START

        show_layers = 1;

      }else if( str == "ST"){//STOP

        show_layers = 0;

        digitalWrite(layer[0],LOW);
        digitalWrite(layer[1],LOW);
        digitalWrite(layer[2],LOW);
        digitalWrite(layer[3],LOW);

        /*//DEBUG
        for(int i = 0; i < 64; i++){
          Serial.print("ROT : ");
          Serial.print(i);
          Serial.print(" ");
          Serial.println(red[i]);
        }
        for(int i = 0; i < 64; i++){
          Serial.print("GRN : ");
          Serial.print(i);
          Serial.print(" ");
          Serial.println(grn[i]);
        }
        for(int i = 0; i < 64; i++){
          Serial.print("BLU : ");
          Serial.print(i);
          Serial.print(" ");
          Serial.println(blu[i]);
        }*///DEBUG
        
      }else if( str == "R1"){
        _ser = 2;
        str = "";   
        Start_millis = millis();

      }
      break;
    case 2:
      while(Serial.available()){
        char input = Serial.read();
        //Serial.print(input);
        bytes_get += 1;
        str += input;
      }



      if(bytes_get > string_lenght-1){//anzahl Zeichen
        //ROT to Array
        for(int i = 0; i < 64; i++){
          zahl = str.substring(0,3);
          
          str.remove(0,4);
          red[i] = zahl.toInt();
          red[i] = map(red[i],0,255,0,4095);
    
        }
        //GRN to Array
        for(int i = 0; i < 64; i++){
          zahl = str.substring(0,3);
          
          str.remove(0,4);
          grn[i] = zahl.toInt();
          grn[i] = map(grn[i],0,255,0,4095);
          
        }
        //BLU to Array
        for(int i = 0; i < 64; i++){
          zahl = str.substring(0,3);
          
          str.remove(0,4);
          blu[i] = zahl.toInt();
          blu[i] = map(blu[i],0,255,0,4095);

        }

        //Serial.println("");
        //Serial.println("GOT_ALL");
        _ser = 1;
        bytes_get = 0;
      }else if(Start_millis + 2000 <= millis()){
        //Serial.println("");
        //Serial.println("ERROR");
        _ser = 1;
        bytes_get = 0;
      }
    break;
  }
}
