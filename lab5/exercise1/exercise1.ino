#include <Arduino.h>

int ledPin = 9;
float potentiometermaxvalue = 5000;
float resistance;
float voltage;
float brightness;
void setup()
{
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    int potentiometer = analogRead(0);
    float potentiometervoltage = potentiometer * (5.0 / 1023.0);
    resistance = ((potentiometermaxvalue / 1023) * potentiometer);
    brightness = potentiometer / 4;
    float LEDvoltage = (5 * brightness) / 255;

    Serial.print("resistance =");
    Serial.println(resistance);

    Serial.print("potentiometer voltage =");
    Serial.println(5 - potentiometervoltage);

    Serial.print("LED voltage =");
    Serial.println(LEDvoltage);

    Serial.println();

    analogWrite(ledPin, brightness);

    delay(200);
}
