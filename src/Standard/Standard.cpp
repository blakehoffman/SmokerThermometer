namespace Standard
{
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