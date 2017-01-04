
void reset_layer() {
  Tlc.update();
  delayMicroseconds(100);

  digitalWrite(layer[0], LOW);
  digitalWrite(layer[1], LOW);
  digitalWrite(layer[2], LOW);
  digitalWrite(layer[3], LOW);
}

void light_all_red(int bright) {
  for (int i = 0; i < 16; i++) {
    Tlc.set(red[i] , bright);
  }
  digitalWrite(layer[0], HIGH);
  reset_layer();
  digitalWrite(layer[1], HIGH);
  reset_layer();
  digitalWrite(layer[2], HIGH);
  reset_layer();
  digitalWrite(layer[3], HIGH);
  reset_layer();
}

void light_all_grn(int bright) {
  for (int i = 0; i < 16; i++) {
    Tlc.set(grn[i] , bright);
  }
  digitalWrite(layer[0], HIGH);
  reset_layer();
  digitalWrite(layer[1], HIGH);
  reset_layer();
  digitalWrite(layer[2], HIGH);
  reset_layer();
  digitalWrite(layer[3], HIGH);
  reset_layer();
}

void light_all_blu(int bright) {
  for (int i = 0; i < 16; i++) {
    Tlc.set(blu[i] , bright);
  }
  digitalWrite(layer[0], HIGH);
  reset_layer();
  digitalWrite(layer[1], HIGH);
  reset_layer();
  digitalWrite(layer[2], HIGH);
  reset_layer();
  digitalWrite(layer[3], HIGH);
  reset_layer();
}

void fadein_red(int dely, int max_) {
  for (int b = 0; b < max_; b++) {
    for (byte i = 0; i < 16; i++) {
      Tlc.set(red[i] , b);
    }
    for (int w = 0; w < dely; w++) {
      digitalWrite(layer[0], HIGH);
      reset_layer();
      digitalWrite(layer[1], HIGH);
      reset_layer();
      digitalWrite(layer[2], HIGH);
      reset_layer();
      digitalWrite(layer[3], HIGH);
      reset_layer();
    }
  }
}
void fadeout_red(int dely, int min_) {
  for (int b = min_; b > 0; b--) {
    for (byte i = 0; i < 16; i++) {
      Tlc.set(red[i] , b);
    }
    for (int w = 0; w < dely; w++) {
      digitalWrite(layer[0], HIGH);
      reset_layer();
      digitalWrite(layer[1], HIGH);
      reset_layer();
      digitalWrite(layer[2], HIGH);
      reset_layer();
      digitalWrite(layer[3], HIGH);
      reset_layer();
    }
  }
}
void fadein_grn(int dely, int max_) {
  for (int b = 0; b < max_; b++) {
    for (int i = 0; i < 16; i++) {
      Tlc.set(grn[i] , b);
    }
    for (byte w = 0; w < dely; w++) {
      digitalWrite(layer[0], HIGH);
      reset_layer();
      digitalWrite(layer[1], HIGH);
      reset_layer();
      digitalWrite(layer[2], HIGH);
      reset_layer();
      digitalWrite(layer[3], HIGH);
      reset_layer();
    }
  }
}
void fadeout_grn(int dely, int min_) {
  for (int b = min_; b > 0; b--) {
    for (byte i = 0; i < 16; i++) {
      Tlc.set(grn[i] , b);
    }
    for (int w = 0; w < dely; w++) {
      digitalWrite(layer[0], HIGH);
      reset_layer();
      digitalWrite(layer[1], HIGH);
      reset_layer();
      digitalWrite(layer[2], HIGH);
      reset_layer();
      digitalWrite(layer[3], HIGH);
      reset_layer();
    }
  }
}
void fadein_blu(int dely, int max_) {
  for (int b = 0; b < max_; b++) {
    for (byte i = 0; i < 16; i++) {
      Tlc.set(blu[i] , b);
    }
    for (int w = 0; w < dely; w++) {
      digitalWrite(layer[0], HIGH);
      reset_layer();
      digitalWrite(layer[1], HIGH);
      reset_layer();
      digitalWrite(layer[2], HIGH);
      reset_layer();
      digitalWrite(layer[3], HIGH);
      reset_layer();
    }
  }
}
void fadeout_blu(int dely, int min_) {
  for (int b = min_; b > 0; b--) {
    for (byte i = 0; i < 16; i++) {
      Tlc.set(blu[i] , b);
    }
    for (int w = 0; w < dely; w++) {
      digitalWrite(layer[0], HIGH);
      reset_layer();
      digitalWrite(layer[1], HIGH);
      reset_layer();
      digitalWrite(layer[2], HIGH);
      reset_layer();
      digitalWrite(layer[3], HIGH);
      reset_layer();
    }
  }
}
