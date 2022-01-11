class ADC
{
    int pinNumber;

public:
    ADC(int pinNumber);
    float getVoltage();

private:
    static constexpr int validPinNumbers[] = {0xA1, 0xA2, 0xA3, 0xA4, 0xA5};
    bool validatePinNumber(int pinNumber);
};