// Pushbutton-Controlled Running Light
// Every time the pushbutton is turn On (State 1), it will switch On a running light in forward
// direction using 6 LEDs. Otherwise (State 0), the direction of the running light will be
// reverse.

const int LED0_PIN = 2;
const int LED1_PIN = 3;
const int LED2_PIN = 4;
const int LED3_PIN = 5;
const int LED4_PIN = 6;
const int LED5_PIN = 7;

const int LEDS[] = {LED0_PIN, LED1_PIN, LED2_PIN, LED3_PIN, LED4_PIN, LED5_PIN};

const int BUTTON_PIN = 8;

const int DELAY_MS = 300;

void setup()
{
    for (int i = 0; i < 6; i++)
    {
        pinMode(LEDS[i], OUTPUT);
    }

    pinMode(BUTTON_PIN, INPUT);
}

void loop()
{
    const int buttonState = digitalRead(BUTTON_PIN);

    if (buttonState == HIGH)
    {
        for (int i = 0; i < 6; i++)
        {
            digitalWrite(LEDS[i], HIGH);
            delay(DELAY_MS);
            digitalWrite(LEDS[i], LOW);
        }
    }
    else
    {
        for (int i = 5; i >= 0; i--)
        {
            digitalWrite(LEDS[i], HIGH);
            delay(DELAY_MS);
            digitalWrite(LEDS[i], LOW);
        }
    }
}
