void Random_leds() {
  
  byte onlist_red1[3];
  byte onlist_red2[3];
  byte onlist_red3[3];
  byte onlist_red4[3];

  byte onlist_grn1[3];
  byte onlist_grn2[3];
  byte onlist_grn3[3];
  byte onlist_grn4[3];

  byte onlist_blu1[3];
  byte onlist_blu2[3];
  byte onlist_blu3[3];
  byte onlist_blu4[3];
  
  for(int i = 0; i < 3; i++){
    onlist_red1[i] = {create_rand(1,17)};
    onlist_red2[i] = {create_rand(1,17)};
    onlist_red3[i] = {create_rand(1,17)};
    onlist_red4[i] = {create_rand(1,17)};

    onlist_grn1[i] = {create_rand(1,17)};
    onlist_grn2[i] = {create_rand(1,17)};
    onlist_grn3[i] = {create_rand(1,17)};
    onlist_grn4[i] = {create_rand(1,17)};

    onlist_blu1[i] = {create_rand(1,17)};
    onlist_blu2[i] = {create_rand(1,17)};
    onlist_blu3[i] = {create_rand(1,17)};
    onlist_blu4[i] = {create_rand(1,17)};
  }
  for(int i = 0; i < 50; i++){
    bright = map(analogRead(0), 0, 1023, 0, 4095);

    Turnon_rgb(onlist_red1, onlist_grn1, onlist_blu1, 3, 3, 3, bright, 1);
    Turnon_rgb(onlist_red2, onlist_grn2, onlist_blu2, 3, 3, 3, bright, 2);
    Turnon_rgb(onlist_red3, onlist_grn3, onlist_blu3, 3, 3, 3, bright, 3);
    Turnon_rgb(onlist_red4, onlist_grn4, onlist_blu4, 3, 3, 3, bright, 4);
  }
}
