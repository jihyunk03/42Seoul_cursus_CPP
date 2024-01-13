#include "Animal.hpp"

/* OCCF: constructor */
Animal::Animal()
    : _type("Animal")
{
    std::cout << "🍄 [Animal]: default constructor" << std::endl;
}

Animal::Animal(std::string type)
    : _type(type)
{
    std::cout << "🍄 [Animal]: type constructor(" << this->_type << ")" << std::endl;
}

/* OCCF: copy constructor */
Animal::Animal(const Animal& origin)
    : _type(origin._type)
{
    std::cout << "🍄 [Animal]: copy constructor" << std::endl;
}

/* OCCF: copy assignment operator overloading */
Animal& Animal::operator=(const Animal& origin)
{
    std::cout << "🍄 [Animal]: copy assignment operator overloading" << std::endl;
    if (this != &origin)
        this->_type = origin._type;
    return *this;
}

/* OCCF: destructor */
Animal::~Animal()
{
    std::cout << "🍄 [Animal]: destructor" << std::endl;
}

/* member functions */
const std::string& Animal::getType(void) const
{
    return this->_type;
}
