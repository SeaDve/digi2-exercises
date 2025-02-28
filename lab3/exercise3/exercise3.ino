// Pushbutton-Controlled Running Light
// Every time the pushbutton is turn On (State 1), it will switch On a running light in forward
// direction using 6 LEDs. Otherwise (State 0), the direction of the running light will be
// reverse.

#include <Arduino.h>

const int LED0_PIN = 13;
const int LED1_PIN = 11;
const int LED2_PIN = 7;
const int LED3_PIN = 6;
const int LED4_PIN = 5;
const int LED5_PIN = 8;

const int LEDS[] = {LED0_PIN, LED1_PIN, LED2_PIN, LED3_PIN, LED4_PIN, LED5_PIN};

const int BUTTON_PIN = 2;

const int DELAY_MS = 300;

void setup()
{
    for (int i = 0; i < 6; i++)
    {
        pinMode(LEDS[i], OUTPUT);
    }

    pinMode(BUTTON_PIN, INPUT);
}

int oldVal = 0;
int state = 0;

void updateButtonState()
{
    int buttonVal = digitalRead(BUTTON_PIN);

    if ((buttonVal == HIGH) && (oldVal == LOW))
    {
        state = 1 - state;
        delay(200);
    }

    oldVal = buttonVal;
}

void loop()
{

    if (state == 1)
    {
        for (int i = 0; i < 6; i++)
        {
            digitalWrite(LEDS[i], HIGH);
            delay(DELAY_MS);
            digitalWrite(LEDS[i], LOW);

            updateButtonState();

            if (state != 1)
            {
                break;
            }
        }
    }
    if (state != 1)
    {
        for (int i = 5; i >= 0; i--)
        {
            digitalWrite(LEDS[i], HIGH);
            delay(DELAY_MS);
            digitalWrite(LEDS[i], LOW);

            updateButtonState();

            if (state == 1)
            {
                break;
            }
        }
    }
}
