#include <Arduino.h>

const int LED_PIN = 9;
const int POTENTIOMETER_PIN = 0;

void setup()
{
    pinMode(POTENTIOMETER_PIN, OUTPUT);
    pinMode(LED_PIN, OUTPUT);

    Serial.begin(9600);
}

void loop()
{
    int potentiometer = analogRead(POTENTIOMETER_PIN);
    float brightness = potentiometer / 4;

    analogWrite(LED_PIN, brightness);

    if (Serial.available() > 0)
    {
        String serial = Serial.readStringUntil('\n');
        serial.trim();

        if (serial == "Vled")
        {

            float LEDvoltage = (5 * brightness) / 255;
            Serial.print("LED voltage: ");
            Serial.print(LEDvoltage);
            Serial.println(" V");
        }
        else if (serial == "Vpot")
        {
            float potentiometerVoltage = 5 - potentiometer * (5.0 / 1023.0);
            Serial.print("potentiometer voltage: ");
            Serial.print(potentiometerVoltage);
            Serial.println(" V");
        }
    }
}
