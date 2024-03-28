#include "./RPN.hpp"

int main(int ac, char** av)
{
    if (ac != 2) {
        std::cerr << "Error: only one argument needed" << std::endl;
        return 1;
    }

    RPN rpn;
    rpn.calculate(av[1]);

    return 0;
}