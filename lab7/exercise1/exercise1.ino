#include <Arduino.h>
#include <Stepper.h>

const int stepsPerRevolution = 200;
const int stepFactor = 20.25;
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
            stepper.step(stepsPerRevolution * stepFactor);
            delay(3000);
            stepper.step(-stepsPerRevolution * stepFactor);
            delay(1000);
            break;
        case '2':
            stepper.step(-stepsPerRevolution / 8 * stepFactor);
            delay(1000);
            break;
        case '3':
            stepper.step(-stepsPerRevolution / 4 * stepFactor);
            delay(1000);
            break;
        case '4':
            stepper.step(-stepsPerRevolution * 3 / 8 * stepFactor);
            delay(1000);
            break;
        case '5':
            stepper.step(-stepsPerRevolution / 2 * stepFactor);
            delay(1000);
            break;
        case '6':
            stepper.step(-stepsPerRevolution * 3 / 4 * stepFactor);
            delay(1000);
            break;
        case '7':
            stepper.step(-stepsPerRevolution * stepFactor);
            delay(1000);
            break;
        default:
            break;
        }
    }
}
