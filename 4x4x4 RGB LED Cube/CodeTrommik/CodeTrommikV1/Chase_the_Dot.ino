void Chase_the_Dot() {



  byte richtung = create_rand(1, 7);

  switch (richtung) {
    case 1://y+=1
      if (y < 4) {
        y += 1;
      } else {
        col = create_rand(1, 8);

        y -= 1;
      }
      break;
    case 2://y-=1
      if (y > 1) {
        y -= 1;
      } else {
        col = create_rand(1, 8);

        y += 1;
      }
      break;
    case 3://x+=1
      if (x < 4) {
        x += 1;
      } else {
        col = create_rand(1, 8);

        x -= 1;
      }
      break;
    case 4://x-=1
      if (x > 1) {
        x -= 1;
      } else {
        col = create_rand(1, 8);

        x += 1;
      }
      break;
    case 5://z+=1
      if (z < 4) {
        z += 1;
      } else {
        col = create_rand(1, 8);

        z -= 1;
      }
      break;
    case 6://z-=1
      if (z > 1) {
        z -= 1;
      } else {
        col = create_rand(1, 8);

        z += 1;
      }
      break;
  }

  for (int i = 0; i < 30; i++) {
    byte onlist[1] = {kordinates_to_pins(x, y)};
    bright = map(analogRead(0), 0, 1023, 0, 4095);
    switch (col) {
      case 1:
        Turnon_red(onlist, 1, bright, z);
        break;
      case 2:
        Turnon_grn(onlist, 1, bright, z);
        break;
      case 3:
        Turnon_blu(onlist, 1, bright, z);
        break;
      case 4:
        Turnon_rgb(onlist, onlist, onlist, 1, 1, 0, bright, z);
        break;
      case 5:
        Turnon_rgb(onlist, onlist, onlist, 1, 0, 1, bright, z);
        break;
      case 6:
        Turnon_rgb(onlist, onlist, onlist, 0, 1, 1, bright, z);
        break;
      case 7:
        Turnon_rgb(onlist, onlist, onlist, 1, 1, 1, bright, z);
        break;
    }
  }
}

byte kordinates_to_pins(byte x, byte y) {

  byte xy = x * y;

  if (x > 1) {
    if (y == 1) {
      switch (x) {
        case 2:
          xy += 3;
          break;
        case 3:
          xy += 6;
          break;
        case 4:
          xy += 9;
          break;
      }
    } else if (y == 2) {
      switch (x) {
        case 2:
          xy += 2;
          break;
        case 3:
          xy += 4;
          break;
        case 4:
          xy += 6;
          break;
      }
    } else if (y == 3) {
      switch (x) {
        case 2:
          xy += 1;
          break;
        case 3:
          xy += 2;
          break;
        case 4:
          xy += 3;
          break;
      }
    }
  }

  return xy;

}

