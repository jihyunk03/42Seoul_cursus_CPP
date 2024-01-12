#include "./Dog.hpp"

/* OCCF: constructor */
Dog::Dog()
    : Animal("Dog")
{
    std::cout << "🐶 [Dog]: default constructor" << std::endl;
}

/* OCCF: copy constructor */
Dog::Dog(const Dog& origin)
    : Animal(origin)
{
    std::cout << "🐶 [Dog]: copy constructor" << std::endl;
}

/* OCCF: copy assignment operator overloading */
Dog& Dog::operator=(const Dog& origin)
{
    std::cout << "🐶 [Dog]: copy assignment operator overloading" << std::endl;
    if (this != &origin)
        this->_type = origin._type;
    return *this;
}

/* OCCF: destructor */
Dog::~Dog()
{
    std::cout << "🐶 [Dog]: destructor" << std::endl;
}

/* member functions */
void    Dog::makeSound(void) const
{
    std::cout << "🐶 bark!!! bark!!! 🐶" << std::endl;
}
