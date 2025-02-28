// Inverted Switch
// An LED will turn On every time the pushbutton switch is press Off(State 0),
// otherwise(State 1) the LED is Off.

const int BUTTON1_PIN = 2;
const int LED1_PIN = 13;

void setup()
{
    pinMode(LED1_PIN, OUTPUT);
    pinMode(BUTTON1_PIN, INPUT);
}

int old_val = 0;
int state = 0;

void loop()
{
    int buttonVal = digitalRead(BUTTON1_PIN);

    if ((buttonVal == HIGH) && (old_val == LOW))
    {
        state = 1 - state;
        delay(50);
    }

    old_val = buttonVal;

    if (state == 1)
    {
        digitalWrite(LED1_PIN, HIGH);
    }
    if (state != 1)
    {
        digitalWrite(LED1_PIN, LOW);
    }
}
