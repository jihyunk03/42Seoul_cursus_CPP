#include "./Weapon.hpp"

/* Constructor */
Weapon::Weapon()
{
	std::cout << "Weapon Constructor(default)" << std::endl;
}

Weapon::Weapon(std::string type)
	: _type(type)
{
	std::cout << "Weapon Constructor(" << type << ")" << std::endl;
}

/* Destructor */
Weapon::~Weapon()
{
	std::cout << "Weapon Destructor" << std::endl;
}

/* Member Functions */
const std::string&	Weapon::getType(void) const
{
	return (this->_type);
}

void	Weapon::setType(std::string new_type)
{
	this->_type = new_type;
}
