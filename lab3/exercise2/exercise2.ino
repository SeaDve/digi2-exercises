// Opposite Switch Function
// The first LED will turn On (or Off) if the first pushbutton switch is press On( or Off). The
// second LED will turn On if the second pushbutton switch is press Off (State 0), otherwise
// the second LED is Off.

#include <Arduino.h>

const int LED1_PIN = 13;
const int LED2_PIN = 11;
const int BUTTON1_PIN = 2;
const int BUTTON2_PIN = 4;

void setup()
{
    pinMode(LED1_PIN, OUTPUT);
    pinMode(LED2_PIN, OUTPUT);
    pinMode(BUTTON1_PIN, INPUT);
    pinMode(BUTTON2_PIN, INPUT);
}

int oldVal = 0;
int state = 0;

int oldVal2 = 0;
int state2 = 0;

void loop()
{
    int buttonVal1 = digitalRead(BUTTON1_PIN);

    if ((buttonVal1 == HIGH) && (oldVal == LOW))
    {
        state = 1 - state;
        delay(50);
    }

    oldVal = buttonVal1;

    if (state == 1)
    {
        digitalWrite(LED1_PIN, HIGH);
    }
    if (state != 1)
    {
        digitalWrite(LED1_PIN, LOW);
    }

    int buttonVal2 = digitalRead(BUTTON2_PIN);

    if ((buttonVal2 == HIGH) && (oldVal2 == LOW))
    {
        state2 = 1 - state2;
        delay(50);
    }

    oldVal2 = buttonVal2;

    if (state2 == 1)
    {
        digitalWrite(LED2_PIN, LOW);
    }
    if (state2 != 1)
    {
        digitalWrite(LED2_PIN, HIGH);
    }
}
