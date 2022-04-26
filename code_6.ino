#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 13, 12, 11, 10); // déclare une variable LiquidCrystal appelée lcd
// mode 4 bits et RW pas utilisé

void setup() {
 lcd.begin(16, 2);
 lcd.print("1"); // affiche le désormais célèbre texte "Hello World!"
 lcd.setCursor(15, 0);
 lcd.print("2");
 lcd.setCursor(0, 1);
 lcd.print("3");
 lcd.setCursor(15, 1);
 lcd.print("4");
 }

void loop() {
  // put your main code here, to run repeatedly:

}
