void Turnon_red(byte liste[], byte anzahl, int bright2, byte layernbr) {
  for (byte i = 0; i < anzahl; i++) {
    Tlc.set(red[liste[i] - 1], bright2);
  }
  Tlc.update();
  delayMicroseconds(1500);
  switch (layernbr) {
    case 1:
      digitalWrite(layer[0], HIGH);
      break;
    case 2:
      digitalWrite(layer[1], HIGH);
      break;
    case 3:
      digitalWrite(layer[2], HIGH);
      break;
    case 4:
      digitalWrite(layer[3], HIGH);
      break;
  }

  delayMicroseconds(1000);

  Tlc.clear();
  digitalWrite(layer[0], LOW);
  digitalWrite(layer[1], LOW);
  digitalWrite(layer[2], LOW);
  digitalWrite(layer[3], LOW);
}

void Turnon_grn(byte liste[], byte anzahl, int bright2, byte layernbr) {
  for (byte i = 0; i < anzahl; i++) {
    Tlc.set(grn[liste[i] - 1], bright2);
  }
  Tlc.update();
  delayMicroseconds(1500);
  switch (layernbr) {
    case 1:
      digitalWrite(layer[0], HIGH);
      break;
    case 2:
      digitalWrite(layer[1], HIGH);
      break;
    case 3:
      digitalWrite(layer[2], HIGH);
      break;
    case 4:
      digitalWrite(layer[3], HIGH);
      break;
  }

  delayMicroseconds(1000);

  Tlc.clear();
  digitalWrite(layer[0], LOW);
  digitalWrite(layer[1], LOW);
  digitalWrite(layer[2], LOW);
  digitalWrite(layer[3], LOW);
}

void Turnon_blu(byte liste[], byte anzahl, int bright2, byte layernbr) {
  for (byte i = 0; i < anzahl; i++) {
    Tlc.set(blu[liste[i] - 1], bright2);
  }
  Tlc.update();
  delayMicroseconds(1500);
  switch (layernbr) {
    case 1:
      digitalWrite(layer[0], HIGH);
      break;
    case 2:
      digitalWrite(layer[1], HIGH);
      break;
    case 3:
      digitalWrite(layer[2], HIGH);
      break;
    case 4:
      digitalWrite(layer[3], HIGH);
      break;
  }

  delayMicroseconds(1000);

  Tlc.clear();
  digitalWrite(layer[0], LOW);
  digitalWrite(layer[1], LOW);
  digitalWrite(layer[2], LOW);
  digitalWrite(layer[3], LOW);
}

void Turnon_rgb(byte lister[], byte listeg[], byte listeb[], byte anzahlr, byte anzahlg, byte anzahlb, int bright2, byte layernbr) {
  for (byte i = 0; i < anzahlr; i++) {
    Tlc.set(red[lister[i] - 1], bright2);
  }
  for (byte i = 0; i < anzahlg; i++) {
    Tlc.set(grn[listeg[i] - 1], bright2);
  }
  for (byte i = 0; i < anzahlb; i++) {
    Tlc.set(blu[listeb[i] - 1], bright2);
  }
  Tlc.update();
  delayMicroseconds(1500);
  switch (layernbr) {
    case 1:
      digitalWrite(layer[0], HIGH);
      break;
    case 2:
      digitalWrite(layer[1], HIGH);
      break;
    case 3:
      digitalWrite(layer[2], HIGH);
      break;
    case 4:
      digitalWrite(layer[3], HIGH);
      break;
  }

  delayMicroseconds(1000);

  Tlc.clear();
  digitalWrite(layer[0], LOW);
  digitalWrite(layer[1], LOW);
  digitalWrite(layer[2], LOW);
  digitalWrite(layer[3], LOW);
}
