#include "./Ice.hpp"

/* OCCF: constructor */
Ice::Ice()
    : AMateria("ice")
{
    // std::cout << "🧊 [Ice]: default constructor" << std::endl;
}

/* OCCF: copy constructor */
Ice::Ice(const Ice& origin)
    : AMateria(origin)
{
    // std::cout << "🧊 [Ice]: copy constructor" << std::endl;
}

/* OCCF: copy assignment operator overloading */
Ice& Ice::operator=(const Ice& origin)
{
    // std::cout << "🧊 [Ice]: copy assignment operator overloading" << std::endl;
    if (this != &origin)
        this->_type = origin._type;
    return *this;
}

/* OCCF: Destructor */
Ice::~Ice()
{
    // std::cout << "🧊 [Ice]: destructor" << std::endl;
}

/* member functions */
AMateria* Ice::clone(void) const
{
    return new Ice();
}

void Ice::use(ICharacter &target)
{
    std::cout << "* 🧊shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
