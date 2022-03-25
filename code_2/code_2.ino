#define LED_1 12   // il n'y a pas de ;
#define IN 3       // On crée des variables qui stoque les pins

void setup() {
  pinMode (LED_1, OUTPUT); // on informe l'arduino que le pin est une sortie (+5V)
  pinMode (IN, INPUT);     // on informe l'arduino que le pin est une entré (lecture)

}

void loop() {
  bool etat = digitalRead (IN); // on crée une variable bool (true/false;high/low) 
                                // on y affecte l'état de l'intérupteur
  if (etat == HIGH) {                 // si l'intérupteur est fermé
    digitalWrite (LED_1, HIGH);       // On allume (génére +5V)
    }
  else {
    delay (5000); // temps en ms      //on attend 5 s
    digitalWrite (LED_1, LOW);        //on éteint  (0V)
    }                           
}
