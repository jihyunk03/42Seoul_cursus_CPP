#include "./AMateria.hpp"

/* OCCF: constructor */
AMateria::AMateria()
    : _type("(default)")
{
    // std::cout << "✭  [A-Materia]: default constructor" << std::endl;
}

AMateria::AMateria(const std::string& type)
    : _type(type)
{
    // std::cout << "✭  [A-Materia]: type constructor" << std::endl;
}

/* OCCF: copy constructor */
AMateria::AMateria(const AMateria& origin)
    : _type(origin._type)
{
    // std::cout << "✭  [A-Materia]: copy constructor" << std::endl;
}

/* OCCF: copy assignment operator overloading */
AMateria& AMateria::operator=(const AMateria& origin)
{
    // std::cout << "✭  [A-Materia]: copy assignment operator overloading" << std::endl;
    // if (this != &origin)
    //     this->_type = origin._type;
    (void) origin;
    return *this;
}

/* OCCF: Destructor */
AMateria::~AMateria()
{
    // std::cout << "✭  [A-Materia]: destructor" << std::endl;
}

/* member functions */
const std::string& AMateria::getType(void) const
{
    return this->_type;
}

void AMateria::use(ICharacter& target)
{
    (void) target;
}
