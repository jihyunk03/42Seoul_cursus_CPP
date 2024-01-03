#include "./HumanA.hpp"

/* Constructor */
HumanA::HumanA(std::string name, Weapon& weapon)
	: _name(name), _weapon(weapon)
{
	std::cout << "HumanA Constructor" << std::endl;
}

/* Destructor */
HumanA::~HumanA()
{
	std::cout << "HumanA Destructor" << std::endl;
}

/* Member Functions */
void	HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
