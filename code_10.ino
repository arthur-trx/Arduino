#include <Wire.h>
#include <LiquidCrystal.h>
#define adresse_out 0x20
#define adresse_in 0x24 
#define adreese_ihm


LiquidCrystal lcd(7, 8, 9, 13, 12, 11, 10); // déclare une variable LiquidCrystal appelée lcd

//capteur :
const byte TRIGGER_PIN = 3; // Broche TRIGGER
const byte ECHO_PIN = 3;    // Broche ECHO
 
/* Constantes pour le timeout */
const unsigned long MEASURE_TIMEOUT = 25000UL; // 25ms = ~8m à 340m/s

/* Vitesse du son dans l'air en mm/us */
const float SOUND_SPEED = 340.0 / 1000;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); // baud
  Wire.begin();
  lcd.begin(16, 2);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
   pinMode(TRIGGER_PIN, OUTPUT);
  digitalWrite(TRIGGER_PIN, LOW); // La broche TRIGGER doit être à LOW au repos
  pinMode(ECHO_PIN, INPUT);
  
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


  
lcd.setCursor(0,0); lcd.print("dir : "); lcd.setCursor(7, 0);
  if (A == B00000001) { out = av; lcd.print("avancer"); }
  if (A == B00000010) { out = re; lcd.print("reculer"); }
  if (A == B00000101) { out = dra; lcd.print("droite a"); }
  if (A == B00001001) { out = gaa; lcd.print("gauche a"); }
  if (A == B00000110) { out = drr; lcd.print("droite r"); }
  if (A == B00001101) { out = av; lcd.print("avancer a"); vitesse = 255; }
  if (A == B00001110) { out = re; lcd.print("reculer r"); vitesse = 255; }
  
  if (A == B00001010) { out = gar; lcd.print("gauche r"); }

  Wire.beginTransmission(adresse_out);
  Wire.write(out);       
  Wire.endTransmission();                                                                                                                                
  
 /* 1. Lance une mesure de distance en envoyant une impulsion HIGH de 10µs sur la broche TRIGGER */
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  
  /* 2. Mesure le temps entre l'envoi de l'impulsion ultrasonique et son écho (si il existe) */
  long measure = pulseIn(ECHO_PIN, HIGH, MEASURE_TIMEOUT);
   
  /* 3. Calcul la distance à partir du temps mesuré */
  float distance_mm = measure / 2.0 * SOUND_SPEED;
   
  /* Affiche les résultats en mm, cm et m */
  Serial.print(F("Distance: "));
  Serial.print(distance_mm);
  Serial.print(F("mm ("));
  Serial.print(distance_mm / 10.0, 2);
  Serial.print(F("cm, "));
  Serial.print(distance_mm / 1000.0, 2);
  Serial.println(F("m)"));
  lcd.setCursor(12, 1);
  lcd.print(distance_mm / 1000.0, 2);
    delay(5);


if (distance_mm <= 50) vitesse = 0;
  analogWrite(5, vitesse);
  analogWrite(6, vitesse);   
  
}
/*
 télécommande
 byte : i1 i2 i3 i4 MG MD R A
 */
