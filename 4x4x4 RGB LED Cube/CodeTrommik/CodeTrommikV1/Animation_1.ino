void light_collums(int farbe,int bright,int dely){
 
  reset();
  
  if(farbe == 1){
    for(int i = 0; i < 16; i++){
      for(int w = 0; w < dely; w++){
          
        Tlc.set(red[i] , bright);
        digitalWrite(layer[0],HIGH);
        reset_layer();
        digitalWrite(layer[1],HIGH);
        reset_layer();
        digitalWrite(layer[2],HIGH);
        reset_layer();
        digitalWrite(layer[3],HIGH);
        reset_layer();
        
      }
      
      if(i == 15){
        for(int w = 0; w < dely*2; w++){
          Tlc.set(red[i] , bright);
          digitalWrite(layer[0],HIGH);
          reset_layer();
          digitalWrite(layer[1],HIGH);
          reset_layer();
          digitalWrite(layer[2],HIGH);
          reset_layer();
          digitalWrite(layer[3],HIGH);
          reset_layer();
        }
      }
    }
  }else if(farbe == 2){
    for(int i = 0; i < 16; i++){
      for(int w = 0; w < dely; w++){
        
        Tlc.set(grn[i] , bright);
        digitalWrite(layer[0],HIGH);
        reset_layer();
        digitalWrite(layer[1],HIGH);
        reset_layer();
        digitalWrite(layer[2],HIGH);
        reset_layer();
        digitalWrite(layer[3],HIGH);
        reset_layer();
        
      }
      
      if(i == 15){
        for(int w = 0; w < dely*2; w++){
          Tlc.set(grn[i] , bright);
          digitalWrite(layer[0],HIGH);
          reset_layer();
          digitalWrite(layer[1],HIGH);
          reset_layer();
          digitalWrite(layer[2],HIGH);
          reset_layer();
          digitalWrite(layer[3],HIGH);
          reset_layer();          
        }
      }
    }
  }else{
    for(int i = 0; i < 16; i++){
      for(int w = 0; w < dely; w++){
        
        Tlc.set(blu[i] , bright);
        digitalWrite(layer[0],HIGH);
        reset_layer();
        digitalWrite(layer[1],HIGH);
        reset_layer();
        digitalWrite(layer[2],HIGH);
        reset_layer();
        digitalWrite(layer[3],HIGH);
        reset_layer();
        
      }
      
      if(i == 15){
        for(int w = 0; w < dely*2; w++){
          Tlc.set(blu[i] , bright);
          digitalWrite(layer[0],HIGH);
          reset_layer();
          digitalWrite(layer[1],HIGH);
          reset_layer();
          digitalWrite(layer[2],HIGH);
          reset_layer();
          digitalWrite(layer[3],HIGH);
          reset_layer();
        }
      }
    }
  }
}

void light_all_red(int bright,int dely){

    for(int w = 0; w < dely; w++){
        for(int i = 0; i < 16; i++){Tlc.set(red[i] , bright);}
        digitalWrite(layer[0],HIGH);
        reset_layer();
        digitalWrite(layer[1],HIGH);
        reset_layer();
        digitalWrite(layer[2],HIGH);
        reset_layer();
        digitalWrite(layer[3],HIGH);
        reset_layer();
    }
}
  
void light_all_grn(int bright,int dely){

    for(int w = 0; w < dely; w++){
        for(int i = 0; i < 16; i++){Tlc.set(grn[i] , bright);}
        digitalWrite(layer[0],HIGH);
        reset_layer();
        digitalWrite(layer[1],HIGH);
        reset_layer();      
        digitalWrite(layer[2],HIGH);
        reset_layer();      
        digitalWrite(layer[3],HIGH);
        reset_layer();
    }
}

void light_all_blu(int bright,int dely){
  
    for(int w = 0; w < dely; w++){
        for(int i = 0; i < 16; i++){Tlc.set(blu[i] , bright);}
        digitalWrite(layer[0],HIGH);
        reset_layer();
        digitalWrite(layer[1],HIGH);
        reset_layer();
        digitalWrite(layer[2],HIGH);
        reset_layer();
        digitalWrite(layer[3],HIGH);
        reset_layer();
    } 
}



