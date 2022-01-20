class AnalogDigitalConversion
{
    int pinNumber;

public:
    AnalogDigitalConversion(int pinNumber);
    float getVoltage();

private:
    static constexpr int validPinNumbers[] = {0xA1, 0xA2, 0xA3, 0xA4, 0xA5};
    bool setup();
    bool validatePinNumber(int pinNumber);
};