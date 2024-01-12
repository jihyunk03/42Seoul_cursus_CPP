#include "./Cat.hpp"

/* OCCF: constructor */
Cat::Cat()
    : Animal("Cat")
{
    std::cout << "🐱 [Cat]: default constructor" << std::endl;
}

/* OCCF: copy constructor */
Cat::Cat(const Cat& origin)
    : Animal(origin)
{
    std::cout << "🐱 [Cat]: copy constructor" << std::endl;
}

/* OCCF: copy assignment operator overloading */
Cat& Cat::operator=(const Cat& origin)
{
    std::cout << "🐱 [Cat]: copy assignment operator overloading" << std::endl;
    if (this != &origin)
        this->_type = origin._type;
    return *this;
}

/* OCCF: destructor */
Cat::~Cat()
{
    std::cout << "🐱 [Cat]: destructor" << std::endl;
}

/* member functions */
void    Cat::makeSound(void) const
{
    std::cout << "🐱 meow~~~ meow~~~ 🐱" << std::endl;
}
