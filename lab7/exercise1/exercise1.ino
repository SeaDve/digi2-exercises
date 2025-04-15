
#include <Stepper.h>
#include <Arduino.h>

const int stepsPerRevolution = 200;
const int stepFactor = 10.25;
Stepper stepper(stepsPerRevolution, 8, 9, 10, 11);

void setup()
{
    Serial.begin(115200);

    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);

    stepper.setSpeed(100);
}

void loop()
{
    if (Serial.available() > 0)
    {
        int serial = Serial.read();

        switch (serial)
        {
        case '1':
            // Rotate stepper motor clockwise and counterclockwise
            Serial.println("Rotate stepper motor clockwise and counterclockwise");
            stepper.step(stepsPerRevolution * stepFactor);
            delay(1000);
            stepper.step(-stepsPerRevolution * stepFactor);
            delay(1000);
            break;
        case '2':
            // Rotate stepper motor counterclockwise by 45
            Serial.println("Rotate stepper motor counterclockwise by 45");
            stepper.step(-stepsPerRevolution / 8 * stepFactor);
            delay(1000);
            break;
        case '3':
            // Rotate stepper motor counterclockwise by 90
            Serial.println("Rotate stepper motor counterclockwise by 90");
            stepper.step(-stepsPerRevolution / 4 * stepFactor);
            delay(1000);
            break;
        case '4':
            // Rotate stepper motor counterclockwise by 135
            Serial.println("Rotate stepper motor counterclockwise by 135");
            stepper.step(-stepsPerRevolution * 3 / 8 * stepFactor);
            delay(1000);
            break;
        case '5':
            // Rotate stepper motor counterclockwise by 180
            Serial.println("Rotate stepper motor counterclockwise by 180");
            stepper.step(-stepsPerRevolution / 2 * stepFactor);
            delay(1000);
            break;
        case '6':
            // Rotate stepper motor counterclockwise by 270
            Serial.println("Rotate stepper motor counterclockwise by 270");
            stepper.step(-stepsPerRevolution * 3 / 4 * stepFactor);
            delay(1000);
            break;
        case '7':
            // Rotate stepper motor counterclockwise by 360 OR 1 revolution
            Serial.println("Rotate stepper motor counterclockwise by 360 OR 1 revolution");
            stepper.step(-stepsPerRevolution * stepFactor);
            delay(1000);
            break;
        default:
            break;
        }
    }
}
