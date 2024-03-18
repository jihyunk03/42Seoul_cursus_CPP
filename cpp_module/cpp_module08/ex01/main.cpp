#include "./Span.hpp"
#include <cstdlib>

int main(void)
{
    std::cout << "===============[ex 1]===============" << std::endl;
    try
    {
        Span    mySpan(5);

        // std::cout << "shortest distance: " << mySpan.shortestSpan() << std::endl;      // error
        // std::cout << "longest distance: " << mySpan.longestSpan() << std::endl;        // error

        mySpan.addNumber(5);
        mySpan.addNumber(10);
        mySpan.addNumber(2);
        mySpan.addNumber(100);
        mySpan.addNumber(80);
        // mySpan.addNumber(90);      // error

        mySpan.printNumber();

        std::cout << "shortest distance: " << mySpan.shortestSpan() << std::endl;
        std::cout << "longest distance: " << mySpan.longestSpan() << std::endl;

        mySpan.printNumber();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "===============[ex 2]===============" << std::endl;
    try
    {
        Span                mySpan(10000);
        std::vector<int>    randVec;

        srand(static_cast<unsigned int>(time(NULL)));
        for (int i = 0; i < 10000; ++i)
            randVec.push_back(rand() % 100000000);

        mySpan.addManyNumbers(randVec);
        // mySpan.addNumber(1);                // error
        // mySpan.addManyNumbers(randVec);      // error

        std::cout << "shortest distance: " << mySpan.shortestSpan() << std::endl;
        std::cout << "longest distance: " << mySpan.longestSpan() << std::endl;

        // mySpan.printNumber();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
