#include "./BitcoinExchange.hpp"

int main(int ac, char** av)
{
    if (ac != 2) {
        std::cout << "Error: only one database to input" << std::endl;
        return 1;
    }

    try {
        BitcoinExchange btc;
        btc.calculate_bitcoin(av[1]);
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}