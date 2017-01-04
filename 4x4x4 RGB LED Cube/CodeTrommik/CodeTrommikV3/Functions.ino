void clear_TLC(void) { //        ##CLEAR ALL##
  for (i = 0; i < 12*numTLC*16/8; i++)
    for (j = 0; j < 4; j++)
      transferbyte[j][i] = 0;
}

