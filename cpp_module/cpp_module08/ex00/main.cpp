#include "./easyfind.hpp"
#include <vector>
#include <deque>

int main(void)
{
    {
        std::vector<int>            vecInt;
        std::vector<int>::iterator  itInt;

        vecInt.push_back(4);
        vecInt.push_back(16);
        vecInt.push_back(54);
        vecInt.push_back(64);
        vecInt.push_back(256);

        itInt = easyfind(vecInt, 16);
        if (itInt != vecInt.end())
            std::cout << "find value: " << *itInt << std::endl;

        itInt = easyfind(vecInt, 77);
        if (itInt != vecInt.end())
            std::cout << "find value: " << *itInt << std::endl;
    }

    std::cout << "=====================================" << std::endl;

    {
        std::deque<int>             vecDq;
        std::deque<int>::iterator   itInt;

        vecDq.push_back(4);
        vecDq.push_back(16);
        vecDq.push_back(54);
        vecDq.push_back(64);
        vecDq.push_back(256);

        itInt = easyfind(vecDq, 16);
        if (itInt != vecDq.end())
            std::cout << "find value: " << *itInt << std::endl;

        itInt = easyfind(vecDq, 77);
        if (itInt != vecDq.end())
            std::cout << "find value: " << *itInt << std::endl;
    }

    return 0;
}
