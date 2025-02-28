// Create a program that will read an analog voltage by varying the resistance value of the
// potentiometer. The voltage and resistance value will only be read and print(display) in
// the serial monitor every time a button is turn On. The button is OFF by default.

// Record the data displayed in the serial Monitor:

#include <Arduino.h>

const int BUTTON1_PIN = 2;

void setup()
{
    pinMode(BUTTON1_PIN, INPUT);

    Serial.begin(9600);
}

int oldVal = 0;
int state = 0;

void loop()
{
    int buttonVal = digitalRead(BUTTON1_PIN);

    if ((buttonVal == HIGH) && (oldVal == LOW))
    {
        state = 1 - state;
        delay(50);
    }

    oldVal = buttonVal;

    if (state == 1)
    {
        int sensorValue = analogRead(A0);

        float voltage = sensorValue * (5.0 / 1023.0);
        float resistance = map(sensorValue, 0, 1023, 0, 10000);

        Serial.print(resistance);
        Serial.print(" Ohm, ");

        Serial.print(voltage);
        Serial.println(" V");
    }
}
