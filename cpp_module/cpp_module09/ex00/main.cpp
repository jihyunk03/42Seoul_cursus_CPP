#include "./BitcoinExchange.hpp"

int main(int ac, char** av)
{
    try
    {
        BitcoinExchange btc();

        // btc.exec(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}