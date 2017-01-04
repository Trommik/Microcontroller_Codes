//WRITE EEPROM
void write_cube_values()
{
  for (byte p = 0; p < array_lenght; p++){
    writeEEPROM(eeprom1, p + frame * 192 +   0, red[p]);
    writeEEPROM(eeprom1, p + frame * 192 +  64, grn[p]);
    writeEEPROM(eeprom1, p + frame * 192 + 128, blu[p]);
  }
}

void writeEEPROM(int deviceaddress, unsigned int eeaddress, byte data )
{
  Wire.beginTransmission(deviceaddress);
  Wire.write((int)(eeaddress >> 8));   // MSB
  Wire.write((int)(eeaddress & 0xFF)); // LSB
  Wire.write(data);
  Wire.endTransmission();

  delay(5);
}
//WRITE EEPROM


//READ EEPROM
byte readEEPROM(int deviceaddress, unsigned int eeaddress )
{
  unsigned int rdata = 0xFF;

  Wire.beginTransmission(deviceaddress);
  Wire.write((int)(eeaddress >> 8));   // MSB
  Wire.write((int)(eeaddress & 0xFF)); // LSB
  Wire.endTransmission();

  Wire.requestFrom(deviceaddress, 1);

  if (Wire.available()) rdata = Wire.read();

  return rdata;
}

void read_cube_values()
{
  for (byte p = 0; p < array_lenght; p++) {
    red[p] = readEEPROM(eeprom1, p + frame * 192 +   0);
    grn[p] = readEEPROM(eeprom1, p + frame * 192 +  64);
    blu[p] = readEEPROM(eeprom1, p + frame * 192 + 128);
  }
}
//READ EEPROM
