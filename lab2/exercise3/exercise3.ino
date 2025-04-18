// Alternate blinking of Odd and Even LEDs

const int LED0_PIN = 2;
const int LED1_PIN = 3;
const int LED2_PIN = 4;
const int LED3_PIN = 5;
const int LED4_PIN = 6;
const int LED5_PIN = 7;

const int LEDS[] = {LED0_PIN, LED1_PIN, LED2_PIN, LED3_PIN, LED4_PIN, LED5_PIN};

void setup()
{
    for (int i = 0; i < 6; i++)
    {
        pinMode(LEDS[i], OUTPUT);
    }
}

int currentLED = 0;

void loop()

{
    if (currentLED % 2 == 0)
    {
        for (int i = 0; i < 6; i++)
        {
            if (i % 2 == 0)
            {
                digitalWrite(LEDS[i], HIGH);
            }
            else
            {
                digitalWrite(LEDS[i], LOW);
            }
        }
    }
    else
    {
        for (int i = 0; i < 6; i++)
        {
            if (i % 2 == 1)
            {
                digitalWrite(LEDS[i], HIGH);
            }
            else
            {
                digitalWrite(LEDS[i], LOW);
            }
        }
    }

    delay(200);
    currentLED++;
}
