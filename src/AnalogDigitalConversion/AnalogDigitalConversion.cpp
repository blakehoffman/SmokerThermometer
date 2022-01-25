#include "AnalogDigitalConversion.h"
#include "../Standard/Standard.h"
#include <Arduino.h>
#include "../configuration.h"
;
AnalogDigitalConversion::AnalogDigitalConversion(int pinNumber)
{
    this->pinNumber = pinNumber;
}

float AnalogDigitalConversion::getVoltage()
{
    int sensorValue = getReading(pinNumber);
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

int AnalogDigitalConversion::getReading(int pinNumber)
{
    int sampleRate = AnalogToDigitalConversionConfiguration::sampleRate;
    int readings[sampleRate];

    for (int i = 0; i < sampleRate; i++)
    {
        readings[i] = analogRead(pinNumber);

    }

    return Standard::avg(readings, sampleRate);
}

bool AnalogDigitalConversion::validatePinNumber(int pinNumber)
{
    int test[] = {1, 2};
    bool exists = Standard::find(pinNumber, test, 5);
    return exists;
}