#include "./ScalarConverter.hpp"

int main(int ac, char** av)
{
    // (void) ac; (void) av;
    // float a = -422323233987429834708925723238475923875.1232134213213;
    // std::cout << std::fixed <<  a << std::endl;
    // // if (f != f)

    if (ac != 2)
    {
        std::cout << "❌ invalid arguments ❌" << std::endl;
        return 1;
    }

    ScalarConverter::convert(av[1]);
    return 0;
}
