#include <Arduino.h>

const int LED0_PIN = 2;
const int LED1_PIN = 3;
const int LED2_PIN = 4;
const int LED3_PIN = 5;
const int LED4_PIN = 6;
const int LED5_PIN = 7;

const int EVEN_LEDS[] = {LED0_PIN, LED2_PIN, LED4_PIN};
const int ODD_LEDS[] = {LED1_PIN, LED3_PIN, LED5_PIN};

const int DELAY_MS = 200;

void setup()
{
    for (int i = 0; i < 3; i++)
    {
        pinMode(EVEN_LEDS[i], OUTPUT);
    }

    for (int i = 0; i < 3; i++)
    {
        pinMode(ODD_LEDS[i], OUTPUT);
    }

    Serial.begin(9600);
}

void loop()
{
    if (Serial.available() > 0)
    {
        int serial = Serial.read();

        switch (serial)
        {
        case 'O':
            for (int i = 0; i < 3; i++)
            {
                digitalWrite(ODD_LEDS[i], HIGH);
                digitalWrite(EVEN_LEDS[i], LOW);
            }
            break;
        case 'E':
            for (int i = 0; i < 3; i++)
            {
                digitalWrite(EVEN_LEDS[i], HIGH);
                digitalWrite(ODD_LEDS[i], LOW);
            }
            break;
        default:
            break;
        }
    }
}
