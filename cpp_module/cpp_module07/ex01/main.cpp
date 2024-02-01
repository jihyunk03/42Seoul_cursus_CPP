#include "./iter.hpp"

template<typename T>
void _printValue(const T& tvalue)
{
    std::cout << tvalue << std::endl;
}

int main(void)
{
    const size_t    arraySize = 5;

    const int       arrInt[arraySize] = {1, 2, 3, 4, 5};
    double          arrDou[arraySize] = {111, 222, 333, 444, 555};
    char            arrCha[arraySize] = {'a', 'b', 'c', 'd', 'e'};

    std::cout << "=============" << std::endl;
    iter(arrInt, arraySize, _printValue);
    std::cout << "=============" << std::endl;
    iter(arrDou, arraySize, _printValue);
    std::cout << "=============" << std::endl;
    iter(arrCha, arraySize, _printValue);
    std::cout << "=============" << std::endl;

    return 0;
}
