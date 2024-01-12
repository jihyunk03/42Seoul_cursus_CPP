#include "WrongAnimal.hpp"

/* OCCF: constructor */
WrongAnimal::WrongAnimal()
    : _type("WrongAnimal")
{
    std::cout << "❌ [WrongAnimal]: default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
    : _type(type)
{
    std::cout << "❌ [WrongAnimal]: type constructor(" << this->_type << ")" << std::endl;
}

/* OCCF: copy constructor */
WrongAnimal::WrongAnimal(const WrongAnimal& origin)
    : _type(origin._type)
{
    std::cout << "❌ [WrongAnimal]: copy constructor" << std::endl;
}

/* OCCF: copy assignment operator overloading */
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& origin)
{
    std::cout << "❌ [WrongAnimal]: copy assignment operator overloading" << std::endl;
    if (this != &origin)
        this->_type = origin._type;
    return *this;
}

/* OCCF: destructor */
WrongAnimal::~WrongAnimal()
{
    std::cout << "❌ [WrongAnimal]: destructor" << std::endl;
}

/* member functions */
const std::string& WrongAnimal::getType(void) const
{
    return this->_type;
}

void    WrongAnimal::makeSound(void) const
{
    std::cout << "❌🐰🐬🐷🐵" << std::endl;
}
