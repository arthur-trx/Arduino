#include <Wire.h>
#include <LiquidCrystal.h>
#define adresse_out 0x20
#define adresse_in 0x24 
#define adreese_ihm


LiquidCrystal lcd(7, 8, 9, 13, 12, 11, 10); // déclare une variable LiquidCrystal appelée lcd

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // baud
  Wire.begin();
  lcd.begin(16, 2);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  
}

void loop() {
  int vitesse = 0;
  Wire.requestFrom(adresse_in, 1);
  byte I = Wire.read();
  Serial.println(I, BIN);
  byte mask_a = B00001111;
  byte A = I&mask_a;
  byte mask_b = B11110000;
  byte B = I&mask_b;
  byte av = B00000101;
  byte re = B00001010;
  byte dra = B00000001;
  byte gaa = B00000100;
  
  byte drr = B00000010;
  byte gar = B00001000;
  byte out;
lcd.clear();
lcd.setCursor(0,1); lcd.print("vitesse : "); lcd.setCursor(10, 1);
  if(B == B00000000) { vitesse = 0; lcd.print("0"); }
  if(B == B10000000) { vitesse = 100; lcd.print("100"); }
  if(B == B11000000) { vitesse = 150; lcd.print("150"); }
  if(B == B11100000) { vitesse = 200; lcd.print("200"); }
  if(B == B11110000) { vitesse = 250; lcd.print("250"); }

  analogWrite(5, vitesse);
  analogWrite(6, vitesse);   
  
lcd.setCursor(0,0); lcd.print("dir : "); lcd.setCursor(7, 0);
  if (A == B00000001) { out = av; lcd.print("avancer"); }
  if (A == B00000010) { out = re; lcd.print("reculer"); }
  if (A == B00000101) { out = dra; lcd.print("droite a"); }
  if (A == B00001001) { out = gaa; lcd.print("gauche a"); }
  if (A == B00000110) { out = drr; lcd.print("droite r"); }
  
  if (A == B00001010) { out = gar; lcd.print("gauche r"); }

  Wire.beginTransmission(adresse_out);
  Wire.write(out);       
  Wire.endTransmission();                                                                                                                                
  delay(5);
  
 
  

  
}
/*
 télécommande
 byte : i1 i2 i3 i4 MG MD R A
 */
