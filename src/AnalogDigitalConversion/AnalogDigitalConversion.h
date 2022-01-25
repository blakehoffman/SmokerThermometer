class AnalogDigitalConversion
{
    int pinNumber;

public:
    AnalogDigitalConversion(int pinNumber);
    float getVoltage();

private:
    static constexpr int validPinNumbers[] = {14, 15, 16, 17, 18};
    int getReading(int pinNumber);
    bool setup();
    bool validatePinNumber(int pinNumber);
};