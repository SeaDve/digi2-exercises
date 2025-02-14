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

void loop()
{
    int buttonState = digitalRead(BUTTON1_PIN);

    if (buttonState == HIGH)
    {

        digitalWrite(LED1_PIN, LOW);
    }
    else
    {
        digitalWrite(LED1_PIN, HIGH);
    }
}
