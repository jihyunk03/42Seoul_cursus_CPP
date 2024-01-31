#include <iostream>
#include <cstdlib>
#include <ctime>
#include "./A.hpp"
#include "./B.hpp"
#include "./C.hpp"

#define COUNT   5

static Base*    generate(void);
static void     identify(Base* ptr);
static void     identify(Base& var);

int main(void)
{
    srand(time(NULL));
    for (int i = 0; i < COUNT; i++)
    {
        std::cout << "------[" << i << "]------" << std::endl;
        Base    *base = generate();

        identify(base);
        identify(*base);

        delete base; base = NULL;
    }

    return 0;
}

static Base*    generate(void)
{
    int num = rand() % 3;
    switch (num)
    {
        case 0:
            std::cout << "Ⓐ constructor of A called" << std::endl;
            return new A;
        case 1:
            std::cout << "Ⓑ constructor of A called" << std::endl;
            return new B;
        case 2:
            std::cout << "Ⓒ constructor of A called" << std::endl;
            return new C;
        default:
            return NULL;
    }
}

static void     identify(Base* ptr)
{
    if (dynamic_cast<A*>(ptr) != NULL)
        std::cout << "Ⓐ type of A" << std::endl;
    else if (dynamic_cast<B*>(ptr) != NULL)
        std::cout << "Ⓑ type of B" << std::endl;
    else if (dynamic_cast<C*>(ptr) != NULL)
        std::cout << "Ⓒ type of C" << std::endl;
    else
        std::cout << "Ⓧ invalid type !!" << std::endl;
}

static void     identify(Base& var)
{
    try {
        (void)dynamic_cast<A&>(var);
        std::cout << "Ⓐ type of A" << std::endl;
    } catch (const std::exception&) {}
    try {
        (void)dynamic_cast<B&>(var);
        std::cout << "Ⓑ type of B" << std::endl;
    } catch(const std::exception&) {}
    try {
        (void)dynamic_cast<C&>(var);
        std::cout << "Ⓒ type of C" << std::endl;
    } catch(const std::exception&) {}
}
