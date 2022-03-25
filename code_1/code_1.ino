#define LED_1 12       // il n'y a pas de ;
#define LED_2 13       // On crée une variable qui stoque le pin

void setup() {
  pinMode (LED_1, OUTPUT); // on informe l'arduino que les pins
  pinMode (LED_2, OUTPUT); // sont des sortie (+5V)

}

void loop() {
  digitalWrite (LED_1, HIGH);       // On allume (génére +5V)
  delay (500); // temps en ms   //on attend 500 ms
  digitalWrite (LED_1, LOW);        // On éteint (génére 0V)
  delay (500); // temps en ms   //on attend 500 ms
   digitalWrite (LED_2, HIGH);      // On allume (génére +5V)
  delay (500); // temps en ms   //on attend 500 ms
  digitalWrite (LED_2, LOW);        // On éteint (génére 0V)
  delay (500); // temps en ms   //on attend 500 ms

}
