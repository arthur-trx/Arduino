#include <Wire.h> 
#define I2C_Out 0x21




void setup() {
  Wire.begin() ;
  Serial.begin(9600); 
}

void loop() {
  byte A = 2; 
  send (1);
  delay (50);
  send (2);
  delay (50);
  for (int i = 0; i < 7; i++) 
  {
    A *= 2;
    Serial.println (A);
    send (A);
    delay (50);
  }
}

void send(byte a){
  Wire.beginTransmission (I2C_Out) ; // Envoie de l'adresse du périphérique I²C
  Wire.write(a) ; // Ecriture d’un octet sur la liaison série de type I²C
  Wire.endTransmission() ; // Fin de transmission sur la liaison série de type I²C
}
