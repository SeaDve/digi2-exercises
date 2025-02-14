// Opposite Switch Function
// The first LED will turn On (or Off) if the first pushbutton switch is press On( or Off). The
// second LED will turn On if the second pushbutton switch is press Off (State 0), otherwise
// the second LED is Off.

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

void loop()
{
    int button1State = digitalRead(BUTTON1_PIN);

    if (button1State == HIGH)
    {
        digitalWrite(LED1_PIN, HIGH);
    }
    else
    {
        digitalWrite(LED1_PIN, LOW);
    }

    int button2State = digitalRead(BUTTON2_PIN);

    if (button2State == HIGH)
    {
        digitalWrite(LED2_PIN, LOW);
    }
    else
    {
        digitalWrite(LED2_PIN, HIGH);
    }
}
