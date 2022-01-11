#include <algorithm>
#include <iterator>
#include <stdexcept>

#include "ADC.h";

ADC::ADC(int pinNumber)
{
    if (!validatePinNumber(pinNumber))
    {
        throw std::invalid_argument("Pin numbers must be in [0xA1, 0xA2, 0xA3, 0xA4, 0xA5]");
    }

    this->pinNumber = pinNumber;
}

float ADC::getVoltage()
{
    int sensorValue = analogRead(pinNumber);
    return sensorValue / (5.0 / 1023.0);
}

bool ADC::validatePinNumber(int pinNumber)
{
    bool exists = std::find(std::begin(validPinNumbers), std::end(validPinNumbers), pinNumber) != std::end(validPinNumbers);
    return exists;
}