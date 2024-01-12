#include "./Dog.hpp"

/* OCCF: constructor */
Dog::Dog()
    : Animal("Dog"), _dogBrain(new Brain())
{
    std::cout << "🐶 [Dog]: default constructor" << std::endl;
}

/* OCCF: copy constructor */
Dog::Dog(const Dog& origin)
    : Animal(origin), _dogBrain(new Brain())
{
    std::cout << "🐶 [Dog]: copy constructor" << std::endl;
    for (int i = 0; i < 100; i++)
        this->_dogBrain->setIdeas(i, origin._dogBrain->getIdeas(i));
}

/* OCCF: copy assignment operator overloading */
Dog& Dog::operator=(const Dog& origin)
{
    std::cout << "🐶 [Dog]: copy assignment operator overloading" << std::endl;
    if (this != &origin)
    {
        this->_type = origin._type;
        for (int i = 0; i < 100; i++)
            this->_dogBrain->setIdeas(i, origin._dogBrain->getIdeas(i));
    }
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
