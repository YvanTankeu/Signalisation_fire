#include "Timer.h"

long temp_clignote_vert = 3000;
long temp_jaune = 2000;

enum Etat
{
    VERT,
    CLIGNOTE_VERT,
    JAUNE,
    ROUGE
};

Etat etat_actuel = VERT;
Etat etat_souhaiter = ROUGE;

int LED_vert, LED_jaune, LED_rouge;

void initialisation(int LED_vert, int LED_jaune, int LED_rouge);
void go();
void stop();
void loopLights();
void goToVert();
void goToRouge();
void blinkVert();
void vert();
void jaune();
void rouge();
void off();

void initialisation(int LED_vert, int LED_jaune, int LED_rouge)
{

    LED_vert = LED_vert;
    LED_jaune = LED_jaune;
    LED_rouge = LED_rouge;

    pinMode(LED_vert, OUTPUT);
    pinMode(LED_jaune, OUTPUT);
    pinMode(LED_rouge, OUTPUT);

    vert();
}

void go()
{
    etat_souhaiter = VERT;
}

void stop()
{
    etat_souhaiter = ROUGE;
}

void loopLights()
{
    if (etat_souhaiter == VERT)
    {
        goToVert();
    }
    else
    {
        goToRouge();
    }
}

void goToVert()
{
    switch (etat_actuel)
    {
    case ROUGE:
        etat_actuel = JAUNE;
        startTimer(temp_jaune);
        break;

    case JAUNE:
        jaune();
        if (isTimerReady())
        {
            etat_actuel = VERT;
        }
        break;

    case CLIGNOTE_VERT:
        etat_actuel = VERT;
        break;

    case VERT:
        vert();
        break;
    }
}

void goToRouge()
{
    switch (etat_actuel)
    {
    case VERT:
        etat_actuel = CLIGNOTE_VERT;
        startTimer(temp_clignote_vert);
        break;
    case CLIGNOTE_VERT:
        blinkVert();
        if (isTimerReady())
        {
            etat_actuel = JAUNE;
            startTimer(temp_jaune);
        }
        break;
    case JAUNE:
        jaune();
        if (isTimerReady())
        {
            etat_actuel = ROUGE;
        }
        break;
    case ROUGE:
        rouge();
        break;
    }
}

void blinkVert()
{
    if (millis() % 1000 > 500)
    {
        vert();
    }
    else
    {
        off();
    }
}

void vert()
{
    digitalWrite(LED_vert, HIGH);
    digitalWrite(LED_jaune, LOW);
    digitalWrite(LED_rouge, LOW);
}

void jaune()
{
    digitalWrite(LED_vert, LOW);
    digitalWrite(LED_jaune, HIGH);
    digitalWrite(LED_rouge, LOW);
}

void rouge()
{
    digitalWrite(LED_vert, LOW);
    digitalWrite(LED_jaune, LOW);
    digitalWrite(LED_rouge, HIGH);
}

void off()
{
    digitalWrite(LED_vert, LOW);
    digitalWrite(LED_jaune, LOW);
    digitalWrite(LED_rouge, LOW);
}