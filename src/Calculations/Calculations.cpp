#include <math.h>

namespace Calculations
{
    float getTemp(float voltageSupply, float currentVoltage, float r1, float steinhartA, float steinhartB, float steinhartC)
    {
        float r2, temp, tInv, ln;

        r2 = (r1 * currentVoltage) / (voltageSupply - currentVoltage);
        ln = log(r2);
        tInv = steinhartA + steinhartB * ln + steinhartC * pow(ln, 3);
        temp = 1.8 * (1.0 / tInv - 273.15) + 32.0;

        return temp;
    }
}