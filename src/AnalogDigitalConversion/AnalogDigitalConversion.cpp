#include "AnalogDigitalConversion.h"
#include "../Standard/Standard.h"
#include <Arduino.h>

AnalogDigitalConversion::AnalogDigitalConversion(int pinNumber)
{
    this->pinNumber = pinNumber;
}

float AnalogDigitalConversion::getVoltage()
{
    int sensorValue = analogRead(pinNumber);
    return sensorValue * (5.0 / 1023.0);
}

bool AnalogDigitalConversion::setup()
{
    if (!validatePinNumber(pinNumber))
    {
        return false;
    }

    return true;
}

bool AnalogDigitalConversion::validatePinNumber(int pinNumber)
{
    int test[] = {1, 2};
    bool exists = Standard::find(pinNumber, test, 5);
    return exists;
}