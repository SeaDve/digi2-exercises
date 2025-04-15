#include <Arduino.h>
#include <Servo.h>

const int servoPin = 9;

Servo servo;

void setup()
{
    servo.attach(servoPin);
}

void loop()
{
    int potentiometer = analogRead(0);
    int speedDelay = map(potentiometer, 0, 1023, 1, 50);

    for (int position = 0; position <= 180; position++)
    {
        servo.write(position);
        delay(speedDelay);
    }

    for (int position = 180; position >= 0; position--)
    {
        servo.write(position);
        delay(speedDelay);
    }
}
