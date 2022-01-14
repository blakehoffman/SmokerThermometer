#include <cmath>

namespace Calculations
{
    float getTemp(float voltageSupply, float currentVoltage, float r2, float steinhartA, float steinhartB, float steinhartC)
    {
        float rT, temp, tInv, ln;

        rT = r2 * (voltageSupply - currentVoltage) / currentVoltage;
        ln = log(rT);
        tInv = steinhartA + steinhartB * ln + steinhartC * pow(ln, 3);
        temp = 1.8 * (1.0 / tInv - 273.15) + 32.0;

        return temp;
    }
}