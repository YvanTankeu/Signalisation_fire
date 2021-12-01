/*
  Titre      : Feu de singalisation
  Auteur     : Yvan Tankeu
  Date       : 30/11/2021
  Description: Gère les feux de signalisation
  Version    : 0.0.1
*/
#include <Arduino.h>

//Feu de signalisation N1
#define ledRouge1  2     
#define ledOrange1 1   
#define ledVert1   0

//Feu de signalisation N2
#define ledRouge2  5
#define ledOrange2 4
#define ledVert2   3

//Feu de signalisation virage
#define ledRouge3  6
#define ledRouge4  7

int timer1 = 2000;    // Le temps est fixé à 2 secondes
int timer2 = 3000;    // Le temps est fixé à 3 secondes

// Des define qui permettent d'allumer et d'éteindre les led
#define ledVert1On digitalWrite(ledVert1, HIGH)
#define ledVert1Off digitalWrite(ledVert1, LOW)
#define ledVert2On digitalWrite(ledVert2, HIGH)
#define ledVert2Off digitalWrite(ledVert2, LOW)

#define ledRouge1On digitalWrite(ledRouge1, HIGH)
#define ledRouge1Off digitalWrite(ledRouge1, LOW)
#define ledRouge2On digitalWrite(ledRouge2, HIGH)
#define ledRouge2Off digitalWrite(ledRouge2, LOW)

#define ledOrange1On digitalWrite(ledOrange1, HIGH)
#define ledOrange1Off digitalWrite(ledOrange1, LOW)
#define ledOrange2On digitalWrite(ledOrange2, HIGH)
#define ledOrange2Off digitalWrite(ledOrange2, LOW)

void setup() {
   // On initialise les sorties
    pinMode(ledRouge1, OUTPUT);
    pinMode(ledOrange1, OUTPUT);
    pinMode(ledVert1, OUTPUT);

    pinMode(ledRouge2, OUTPUT);
    pinMode(ledOrange2, OUTPUT);
    pinMode(ledVert2, OUTPUT);
}

void loop() {
   // Phase 1 : ledRouge1 et  ledVert2 sont allumés, ledRouge2, ledOrange1 et  ledOrange2 sont éteints
    ledRouge2Off;   // ledRouge2 éteint
    ledOrange1Off;   // ledOrange1 éteint
    ledOrange2Off;   // ledOrange2 éteint
    ledRouge1On;  // ledRouge1 allumé
    ledVert2On;  // ledVert2 allumé
    delay(timer1);           // durée: 6000 millisecondes, soit 6 secondes

    // Phase 2 : ledRouge1, ledOrange1, ledOrange2 allumés et ledVert2 éteint
   ledVert2Off;   // ledVert2 éteint
    ledOrange1On;  // ledOrange1 allumé
    ledOrange2On;  // ledOrange2 allumé
    delay(timer1);           // durée: 2000 millisecondes, soit 2 secondes

    // Phase 3 : ledRouge1, ledOrange1, ledOrange2 éteints et ledVert1 et ledVert2 allumés
    ledRouge1Off;   // ledRouge1 éteint
    ledOrange1Off;   // ledOrange1 éteint
    ledOrange2Off;   // ledOrange2 éteint
    ledVert1On;  // ledVert1 allumé
    ledRouge2On;  // ledVert2 allumé
    delay(timer2);

    // Phase 4 : ledVert1 éteint et ledOrange1, ledOrange2 et ledVert2 allumés
    ledVert1Off;   // ledVert1 éteint
    ledOrange1On;  // ledOrange1 allumé
    ledOrange2On;  // ledOrange2 allumé
    ledRouge2On;  // ledVert2 allumé
    delay(timer1);
}