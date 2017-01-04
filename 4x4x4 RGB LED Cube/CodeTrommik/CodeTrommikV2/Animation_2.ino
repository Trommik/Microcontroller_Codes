void Random_led(int bright){
    for (int p=0;p<random(3,20);p++){    
      redv[random(64)]=bright;
    }
    for (int p=0;p<random(3,20);p++){
      grnv[random(64)]=bright;
    }
    for (int p=0;p<random(3,20);p++){
      bluv[random(64)]=bright;
    }
    
    for(int p=0;p<100;p++){
      show_layer(1,0);
      show_layer(2,0);
      show_layer(3,0);
      show_layer(4,0);
    }
    for (int p=0;p<64;p++){
       redv[p]=0;
       grnv[p]=0;
       bluv[p]=0;
    }
}
