#include <Arduino.h>
namespace Standard
{
    int avg(int values[], int size)
    {
        unsigned int long sum = 0;

        for (int i = 0; i < size; i++)
        {
            sum += values[i];
        }

        return sum / size;
    }

    template <class T>
    bool find(T value, T array[], int arrayLength)
    {
        for (int i = 0; i < arrayLength; i++)
        {
            if (array[i] == value)
            {
                return true;
            }
        }

        return false;
    }
}