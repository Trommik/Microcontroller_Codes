void fadein_out() {
  int bright2;
  byte onlist[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

  bright = map(analogRead(0), 0, 1023, 0, 4095);
  for (bright2 = 0; bright2 < bright; bright2 += 15) {
    if (bright2 > 300) {bright2 += 15;}
    if (bright2 >= 4095) {bright2 = bright;}
    Turnon_red(onlist, 16, bright2, 1);
    Turnon_red(onlist, 16, bright2, 2);
    Turnon_red(onlist, 16, bright2, 3);
    Turnon_red(onlist, 16, bright2, 4);
  }
  for (bright2 = bright2; bright2 > 0; bright2 -= 15) {
    if (bright2 > 300) {bright2 -= 15;}
    Turnon_red(onlist, 16, bright2, 1);
    Turnon_red(onlist, 16, bright2, 2);
    Turnon_red(onlist, 16, bright2, 3);
    Turnon_red(onlist, 16, bright2, 4);
  }
  
  bright = map(analogRead(0), 0, 1023, 0, 4095);
  for (bright2 = 0; bright2 < bright; bright2 += 15) {
    if (bright2 > 300) {bright2 += 15;}
    if (bright2 >= 4095) {bright2 = bright;}
    Turnon_grn(onlist, 16, bright2, 1);
    Turnon_grn(onlist, 16, bright2, 2);
    Turnon_grn(onlist, 16, bright2, 3);
    Turnon_grn(onlist, 16, bright2, 4);
  }
  for (bright2 = bright2; bright2 > 0; bright2 -= 15) {
    if (bright2 > 300) {bright2 -= 15;}
    Turnon_grn(onlist, 16, bright2, 1);
    Turnon_grn(onlist, 16, bright2, 2);
    Turnon_grn(onlist, 16, bright2, 3);
    Turnon_grn(onlist, 16, bright2, 4);
  }

  bright = map(analogRead(0), 0, 1023, 0, 4095);
  for (bright2 = 0; bright2 < bright; bright2 += 15) {
    if (bright2 > 300) {bright2 += 15;}
    if (bright2 >= 4095) {bright2 = bright;}
    Turnon_blu(onlist, 16, bright2, 1);
    Turnon_blu(onlist, 16, bright2, 2);
    Turnon_blu(onlist, 16, bright2, 3);
    Turnon_blu(onlist, 16, bright2, 4);
  }
  for (bright2 = bright2; bright2 > 0; bright2 -= 15) {
    if (bright2 > 300) {bright2 -= 15;}
    Turnon_blu(onlist, 16, bright2, 1);
    Turnon_blu(onlist, 16, bright2, 2);
    Turnon_blu(onlist, 16, bright2, 3);
    Turnon_blu(onlist, 16, bright2, 4);
  }
}

void RGB_Fade(byte Fade_speed){
      bright = 4095;
      //byte Fade_speed = 1;
      for (int i = 0; i < 1; i++) {light_all_red(bright);}
      fadein_grn(Fade_speed, bright);
      fadeout_red(Fade_speed, bright);
      for (int i = 0; i < 1; i++) {light_all_grn(bright);}
      fadein_blu(Fade_speed, bright);
      fadeout_grn(Fade_speed, bright);
      for (int i = 0; i < 1; i++) {light_all_blu(bright);}
      fadein_red(Fade_speed, bright);
      fadeout_blu(Fade_speed, bright);
}

