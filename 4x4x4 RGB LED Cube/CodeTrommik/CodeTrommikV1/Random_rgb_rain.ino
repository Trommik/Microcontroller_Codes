void Random_rgb_rain() {
  
  byte onlist[1] = {create_rand(1,17)};
  

  byte _rnd = create_rand(1,8);
  
    for(int i = 0; i<35;i++){
      bright = map(analogRead(0), 0, 1023, 0, 4095);
      switch (_rnd) {
        case 1:
          Turnon_red(onlist, 1, bright, 1);
          break;
        case 2:
          Turnon_grn(onlist, 1, bright, 1);
          break;
        case 3:
          Turnon_blu(onlist, 1, bright, 1);
          break;
        case 4:
          Turnon_rgb(onlist, onlist, onlist, 1, 1, 0, bright, 1);
          break;
        case 5:
          Turnon_rgb(onlist, onlist, onlist, 1, 0, 1, bright, 1);
          break;
        case 6:
          Turnon_rgb(onlist, onlist, onlist, 0, 1, 1, bright, 1);
          break;
        case 7:
          Turnon_rgb(onlist, onlist, onlist, 1, 1, 1, bright, 1);
          break;
      }
    }
    for(int i = 0; i<35;i++){
      bright = map(analogRead(0), 0, 1023, 0, 4095);
      switch (_rnd) {
        case 1:
          Turnon_red(onlist, 1, bright, 2);
          break;
        case 2:
          Turnon_grn(onlist, 1, bright, 2);
          break;
        case 3:
          Turnon_blu(onlist, 1, bright, 2);
          break;
        case 4:
          Turnon_rgb(onlist, onlist, onlist, 1, 1, 0, bright, 2);
          break;
        case 5:
          Turnon_rgb(onlist, onlist, onlist, 1, 0, 1, bright, 2);
          break;
        case 6:
          Turnon_rgb(onlist, onlist, onlist, 0, 1, 1, bright, 2);
          break;
        case 7:
          Turnon_rgb(onlist, onlist, onlist, 1, 1, 1, bright, 2);
          break;
      }
    }
    for(int i = 0; i<35;i++){
      bright = map(analogRead(0), 0, 1023, 0, 4095);
      switch (_rnd) {
        case 1:
          Turnon_red(onlist, 1, bright, 3);
          break;
        case 2:
          Turnon_grn(onlist, 1, bright, 3);
          break;
        case 3:
          Turnon_blu(onlist, 1, bright, 3);
          break;
        case 4:
          Turnon_rgb(onlist, onlist, onlist, 1, 1, 0, bright, 3);
          break;
        case 5:
          Turnon_rgb(onlist, onlist, onlist, 1, 0, 1, bright, 3);
          break;
        case 6:
          Turnon_rgb(onlist, onlist, onlist, 0, 1, 1, bright, 3);
          break;
        case 7:
          Turnon_rgb(onlist, onlist, onlist, 1, 1, 1, bright, 3);
          break;
      }
    }
    for(int i = 0; i<35;i++){
      bright = map(analogRead(0), 0, 1023, 0, 4095);
      switch (_rnd) {
        case 1:
          Turnon_red(onlist, 1, bright, 4);
          break;
        case 2:
          Turnon_grn(onlist, 1, bright, 4);
          break;
        case 3:
          Turnon_blu(onlist, 1, bright, 4);
          break;
        case 4:
          Turnon_rgb(onlist, onlist, onlist, 1, 1, 0, bright, 4);
          break;
        case 5:
          Turnon_rgb(onlist, onlist, onlist, 1, 0, 1, bright, 4);
          break;
        case 6:
          Turnon_rgb(onlist, onlist, onlist, 0, 1, 1, bright, 4);
          break;
        case 7:
          Turnon_rgb(onlist, onlist, onlist, 1, 1, 1, bright, 4);
          break;
      }
    }
}


