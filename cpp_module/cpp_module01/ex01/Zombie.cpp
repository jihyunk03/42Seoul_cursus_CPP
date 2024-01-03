#include "./Zombie.hpp"

Zombie::Zombie()
	: _name("")
{
	/* Constructor */
	std::cout << "[Zombie Constructor] default" << std::endl;
}

Zombie::Zombie(std::string name)
	: _name(name)
{
	/* Constructor */
	std::cout << "[Zombie Constructor] name: " << this->_name << std::endl;
}

Zombie::~Zombie()
{
	/* Destructor */
	std::cout << "[Zombie Destructor] name: " << this->_name << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}
