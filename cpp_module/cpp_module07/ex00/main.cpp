#include "./whatever.hpp"

int main(void)
{
    {
        std::cout << "========[Test 1]========" << std::endl;
        int a = 4;
        int b = 16;

        _printValue(a, b);
        ::swap(a, b);
        _printValue(a, b);
        std::cout << "Minimum value: " << ::min(a, b) << std::endl;
        std::cout << "Maximum value: " << ::max(a, b) << std::endl;
    }

    std::cout << std::endl;

    {
        std::cout << "========[Test 2]========" << std::endl;
        float   a = 4;
        float   b = 16;

        _printValue(a, b);
        ::swap(a, b);
        _printValue(a, b);
        std::cout << "Minimum value: " << ::min(a, b) << std::endl;
        std::cout << "Maximum value: " << ::max(a, b) << std::endl;
    }

    std::cout << std::endl;

    {
        std::cout << "========[Test 3]========" << std::endl;
        double  a = 4;
        double  b = 16;

        _printValue(a, b);
        ::swap(a, b);
        _printValue(a, b);
        std::cout << "Minimum value: " << ::min(a, b) << std::endl;
        std::cout << "Maximum value: " << ::max(a, b) << std::endl;
    }

    std::cout << std::endl;

    {
        std::cout << "========[Test 4]========" << std::endl;
        char    a = 'a';
        char    b = 'b';

        _printValue(a, b);
        ::swap(a, b);
        _printValue(a, b);
        std::cout << "Minimum value: " << ::min(a, b) << std::endl;
        std::cout << "Maximum value: " << ::max(a, b) << std::endl;
    }

    return 0;
}

