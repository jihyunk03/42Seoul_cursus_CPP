#include "./Cat.hpp"

/* OCCF: constructor */
Cat::Cat()
    : Animal("Cat"), _catBrain(new Brain())
{
    std::cout << "🐱 [Cat]: default constructor" << std::endl;
}

/* OCCF: copy constructor */
Cat::Cat(const Cat& origin)
    : Animal(origin), _catBrain(new Brain())
{
    std::cout << "🐱 [Cat]: copy constructor" << std::endl;
    for (int i = 0; i < 100; i++)
        this->_catBrain->setIdeas(i, origin._catBrain->getIdeas(i));
}

/* OCCF: copy assignment operator overloading */
Cat& Cat::operator=(const Cat& origin)
{
    std::cout << "🐱 [Cat]: copy assignment operator overloading" << std::endl;
    if (this != &origin)
    {
        this->_type = origin._type;
        for (int i = 0; i < 100; i++)
            this->_catBrain->setIdeas(i, origin._catBrain->getIdeas(i));
    }
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
