namespace AnalogToDigitalConversionConfiguration
{
    constexpr inline int sampleRate = 100;
}

namespace ArduinoConfiguration
{
    constexpr inline float voltageSupply = 5.0;
}

namespace FoodProbeConfiguration
{
    constexpr inline int pinNumber = 14;
}

namespace GeneralProbeConfiguration
{
    constexpr float steinConstants[] = {7.3431401e-4, 2.1574370e-4, 9.5156860e-8};
}

namespace GrateProbeConfiguration
{
    constexpr inline int pinNumber = 15;
}

namespace OLEDConfiguration
{
    constexpr inline int screenHeight = 64;
    constexpr inline int reset = 1;
    constexpr inline int screenWidth = 128;
    constexpr inline int screenAddress = 0x3C;
}

namespace ResistorOneConfiguration
{
    constexpr inline float Resistance = 10000;
}

namespace WifiConfiguration
{
    constexpr inline char wifiName[] = "network name";
    constexpr inline char wifiPassword[] = "wifi password";
}