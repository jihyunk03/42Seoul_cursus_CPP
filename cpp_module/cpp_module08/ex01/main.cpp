#include "./Span.hpp"

int main(void)
{
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

    return 0;
}
