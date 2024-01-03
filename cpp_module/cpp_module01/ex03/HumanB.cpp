#include "./HumanB.hpp"

/* Constructor */
HumanB::HumanB(std::string name)
	: _name(name)
{
	std::cout << "HumanB Constructor" << std::endl;
}

/* Destructor */
HumanB::~HumanB()
{
	std::cout << "HumanB Destructor" << std::endl;
}

/* Member Functions */
void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}


void	HumanB::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}
