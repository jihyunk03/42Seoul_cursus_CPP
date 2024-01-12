#include "./DiamondTrap.hpp"

/* OCCF: constructor */
DiamondTrap::DiamondTrap()
    : _name(ClapTrap::_name)
{
    std::cout << "👼 [DiamondTrap]: default constructor" << std::endl;
    ClapTrap::_name = this->_name + "_clap_name";
    this->_hitPoints = FragTrap::_frag_hitPoints;
    this->_energyPoints = ScavTrap::_scav_energyPoints;
    this->_attackDamage = FragTrap::_frag_attackDamage;
}

DiamondTrap::DiamondTrap(const std::string name)
    : ClapTrap(name), _name(ClapTrap::_name)
{
    std::cout << "👼 [DiamondTrap]: name constructor" << std::endl;
    ClapTrap::_name = this->_name + "_clap_name";
    this->_hitPoints = FragTrap::_frag_hitPoints;
    this->_energyPoints = ScavTrap::_scav_energyPoints;
    this->_attackDamage = FragTrap::_frag_attackDamage;
}

/* OCCF: copy constructor */
DiamondTrap::DiamondTrap(const DiamondTrap& origin)
    : ClapTrap(origin), FragTrap(origin), ScavTrap(origin)
{
    std::cout << "👼 [DiamondTrap]: copy constructor" << std::endl;
    this->_name = origin._name;
    this->_hitPoints = origin._hitPoints;
    this->_energyPoints = origin._energyPoints;
    this->_attackDamage = origin._attackDamage;
}

/* OCCF: copy assignment operator overloading */
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& origin)
{
    std::cout << "👼 [DiamondTrap]: copy constructor" << std::endl;
    if (this != &origin)
    {
        this->_name = origin._name;
        this->_hitPoints = origin._hitPoints;
        this->_energyPoints = origin._energyPoints;
        this->_attackDamage = origin._attackDamage;
    }
    return *this;
}

/* OCCF: destructor */
DiamondTrap::~DiamondTrap()
{
    std::cout << "👼 [DiamondTrap]: destructor" << std::endl;
}

/* member functions */
void    DiamondTrap::whoAmI(void)
{
    std::cout << "👼 my name is '" << this->_name << "' and 🤰 name is '" << ClapTrap::_name << "'" << std::endl;
}

void    DiamondTrap::printAll(void)
{
    std::cout << "👼 name(" << this->_name << "), clap_name(" << ClapTrap::_name << "), HP(" << this->_hitPoints << "), EP(" << this->_energyPoints << "), AD(" << this->_attackDamage << ")" << std::endl;
}
