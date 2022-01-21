class AnalogDigitalConversion
{
    int pinNumber;

public:
    AnalogDigitalConversion(int pinNumber);
    float getVoltage();

private:
    static constexpr int validPinNumbers[] = {14, 15, 16, 17, 18};
    bool setup();
    bool validatePinNumber(int pinNumber);
};