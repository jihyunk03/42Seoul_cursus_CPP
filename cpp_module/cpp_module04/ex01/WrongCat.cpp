#include "./WrongCat.hpp"

/* OCCF: constructor */
WrongCat::WrongCat()
    : WrongAnimal("WrongCat"), _wrongCatBrain(new Brain())
{
    std::cout << "🆇  [WrongCat]: default constructor" << std::endl;
}

/* OCCF: copy constructor */
WrongCat::WrongCat(const WrongCat& origin)
    : WrongAnimal(origin), _wrongCatBrain(new Brain())
{
    this->_wrongCatBrain = origin.getBrain();
    std::cout << "🆇  [WrongCat]: copy constructor" << std::endl;
}

/* OCCF: copy assignment operator overloading */
WrongCat& WrongCat::operator=(const WrongCat& origin)
{
    std::cout << "🆇  [WrongCat]: copy assignment operator overloading" << std::endl;
    if (this != &origin)
    {
        this->_type = origin._type;
        delete _wrongCatBrain; _wrongCatBrain = NULL;
        this->_wrongCatBrain = origin.getBrain();
    }
    return *this;
}

/* OCCF: destructor */
WrongCat::~WrongCat()
{
    delete this->_wrongCatBrain; this->_wrongCatBrain = NULL;
    std::cout << "🆇  [WrongCat]: destructor" << std::endl;
}

/* member functions */
void    WrongCat::makeSound(void) const
{
    std::cout << "🆇 meow~~~ meow~~~ 🆇" << std::endl;
}

Brain*  WrongCat::getBrain(void) const
{
    return this->_wrongCatBrain;
}
