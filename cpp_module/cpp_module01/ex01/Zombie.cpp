#include "./Zombie.hpp"

Zombie::Zombie()
{
	/* Constructor */
	this->_name = "";
}

Zombie::Zombie(std::string name)
{
	/* Constructor */
	this->_name = name;
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