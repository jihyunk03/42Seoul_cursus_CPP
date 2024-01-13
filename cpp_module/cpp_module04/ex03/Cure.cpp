#include "./Cure.hpp"

/* OCCF: constructor */
Cure::Cure()
    : AMateria("cure")
{
    // std::cout << "💉 [Cure]: default constructor" << std::endl;
}

/* OCCF: copy constructor */
Cure::Cure(const Cure& origin)
    : AMateria(origin)
{
    // std::cout << "💉 [Cure]: copy constructor" << std::endl;
}

/* OCCF: copy assignment operator overloading */
Cure& Cure::operator=(const Cure& origin)
{
    // std::cout << "💉 [Cure]: copy assignment operator overloading" << std::endl;
    if (this != &origin)
        this->_type = origin._type;
    return *this;
}

/* OCCF: Destructor */
Cure::~Cure()
{
    // std::cout << "💉 [Cure]: destructor" << std::endl;
}

/* member functions */
AMateria* Cure::clone(void) const
{
    return new Cure();
}

void Cure::use(ICharacter &target)
{
    std::cout << "* 💉heals " << target.getName() << "'s wounds *" << std::endl;
}
