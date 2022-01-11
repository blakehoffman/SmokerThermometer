#include <iostream>

namespace FoodProbeConfiguration
{
    constexpr inline int pinNumber = 0xA1;
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