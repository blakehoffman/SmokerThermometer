namespace ArduinoConfiguration
{
    constexpr inline float VoltageSupply = 5.0;
}

namespace FoodProbeConfiguration
{
    constexpr inline int pinNumber = 0xA1;
}

namespace GeneralProbeConfiguration
{
    constexpr float steinConstants[] = {2.4723753e-04, 2.3402251e-04, 1.3879768e-07};
}

namespace GrateProbeConfiguration
{
    constexpr inline int pinNumber = 0xA2;
}

namespace OLEDConfiguration
{
    constexpr inline int screenHeight = 64;
    constexpr inline int reset = 1;
    constexpr inline int screenWidth = 128;
    constexpr inline int screenAddress = 0x3C;
}

namespace ResistorTwoConfiguration
{
    constexpr inline float Resistance = 10000;
}