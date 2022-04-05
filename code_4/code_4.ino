#include <Wire.h> 
#define I2C_Out 0x21
#define I2C_In 0x24




void setup() {
  Serial.begin(9600);
  Serial.println("init");
}

void loop() {
  Serial.println ("new");
  Wire.begin() ; 
  Wire.requestFrom(I2C_In,1); // On lit 1 Octet
  byte C_I2C = Wire.read() ; 
  Serial.println(C_I2C);
  Wire.beginTransmission (I2C_Out) ; // Envoie de l'adresse du périphérique I²C
  Wire.write(C_I2C) ; // Ecriture d’un octet sur la liaison série de type I²C
  Wire.endTransmission() ; // Fin de transmission sur la liaison série de type I²C
  delay (5);
}
