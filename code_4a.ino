#include <Wire.h> 
#define I2C_Out 0x21




void setup() {
  Wire.begin() ; 
}

void loop() {
send (B00000001);
delay (100);
send (B00000010);
delay (100);
send (B00000100);
delay (100);
send (B00001000);
delay (100);
send (B00010000);
delay (100);
send (B00100000);
delay (100);
send (B01000000);
delay (100);
send (B10000000);
delay (100);
}

void send(byte a){
  Wire.beginTransmission (I2C_Out) ; // Envoie de l'adresse du périphérique I²C
  Wire.write(a) ; // Ecriture d’un octet sur la liaison série de type I²C
  Wire.endTransmission() ; // Fin de transmission sur la liaison série de type I²C
}
