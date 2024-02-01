#include "./iter.hpp"

template<typename T>
static void _printValue(T tvalue)
{
    std::cout << tvalue << std::endl;
}

int main(void)
{
    const size_t    arraySize = 5;
    int             arrInt[arraySize] = {1, 2, 3, 4, 5};
    double          arrDou[arraySize] = {111, 222, 333, 444, 555};
    char            arrCha[arraySize] = {'a', 'b', 'c', 'd', 'e'};

    iter(arrInt, arraySize, _printValue);
    iter(arrDou, arraySize, _printValue);
    iter(arrCha, arraySize, _printValue);

    return 0;
}
