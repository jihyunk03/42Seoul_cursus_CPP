#include "./Span.hpp"

int main(void)
{
    std::cout << "===============[ex 1]===============" << std::endl;
    try
    {
        Span    example(5);

        // std::cout << "shortest distance: " << example.shortestSpan() << std::endl;      // error
        // std::cout << "longest distance: " << example.longestSpan() << std::endl;        // error

        example.addNumber(5);
        example.addNumber(10);
        example.addNumber(2);
        example.addNumber(100);
        example.addNumber(80);
        // example.addNumber(90);      // error

        example.printNumber();

        std::cout << "shortest distance: " << example.shortestSpan() << std::endl;
        std::cout << "longest distance: " << example.longestSpan() << std::endl;

        example.printNumber();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "===============[ex 2]===============" << std::endl;
    try
    {
        Span example(15000);

        example.addManyRandNumber(10000);
        // example.addManyRandNumber(10000);    // error

        // example.printNumber();

        std::cout << "shortest distance: " << example.shortestSpan() << std::endl;
        std::cout << "longest distance: " << example.longestSpan() << std::endl;

        // example.printNumber();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }


    return 0;
}
