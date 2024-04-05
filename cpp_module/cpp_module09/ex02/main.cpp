#include "./PmergeMe.hpp"

int main(int ac, char** av)
{
    try {
        PmergeMe    fordJohnson(ac, av);

        // clock -> vector
        // clock -> deque
        // print compare results
        fordJohnson.runFordJohnson();
        for (int i = 0; i < ac - 1; ++i) {
            std::cout << fordJohnson.getSortedVec()[i] << std::endl;
        }
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}