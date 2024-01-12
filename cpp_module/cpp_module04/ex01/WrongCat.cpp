#include "./WrongCat.hpp"

/* OCCF: constructor */
WrongCat::WrongCat()
    : WrongAnimal("WrongCat")
{
    std::cout << "🆇  [WrongCat]: default constructor" << std::endl;
}

/* OCCF: copy constructor */
WrongCat::WrongCat(const WrongCat& origin)
    : WrongAnimal(origin)
{
    std::cout << "🆇  [WrongCat]: copy constructor" << std::endl;
}

/* OCCF: copy assignment operator overloading */
WrongCat& WrongCat::operator=(const WrongCat& origin)
{
    std::cout << "🆇  [WrongCat]: copy assignment operator overloading" << std::endl;
    if (this != &origin)
        this->_type = origin._type;
    return *this;
}

/* OCCF: destructor */
WrongCat::~WrongCat()
{
    std::cout << "🆇  [WrongCat]: destructor" << std::endl;
}

/* member functions */
void    WrongCat::makeSound(void) const
{
    std::cout << "🆇 meow~~~ meow~~~ 🆇" << std::endl;
}
