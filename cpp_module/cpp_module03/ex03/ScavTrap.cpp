#include "./ScavTrap.hpp"

/* OCCF: constructor */
ScavTrap::ScavTrap()
    : ClapTrap()            // constructor of deault-c
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "👦 [ScavTrap]: default constructor" << std::endl;
}

ScavTrap::ScavTrap(const std::string name)
    : ClapTrap(name)        // constructor of initialize by parameter
{
    // this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "👦 [ScavTrap]: name constructor(" << this->_name << ")" << std::endl;
}

/* OCCF: copy constructor */
ScavTrap::ScavTrap(const ScavTrap& origin)
    : ClapTrap(origin)      // auto casting
{
    // this->_name = origin._name;
    this->_hitPoints = origin._hitPoints;
    this->_energyPoints = origin._energyPoints;
    this->_attackDamage = origin._attackDamage;
    std::cout << "👦 [ScavTrap]: copy constructor(" << this->_name << ")" << std::endl;
}

/* OCCF: copy assignment operator overloading */
ScavTrap&   ScavTrap::operator=(const ScavTrap& origin)
{
    std::cout << "👦 [ScavTrap]: copy assignment operator overloading" << std::endl;
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
ScavTrap::~ScavTrap()
{
    std::cout << "👦 [ScavTrap]: destructor" << std::endl;
}

/* parent-class member function overloading */
void    ScavTrap::attack(const std::string& target)
{
    std::cout << "👦 '" << this->_name << "'";
    if (this->_energyPoints > 0)
    {
        this->_energyPoints--;
        std::cout << " attacks '" << target << "', causing " << this->_attackDamage << " points of damage! 😁" << std::endl;
    }
    else
        std::cout << " has no Energy 😵" << std::endl;

}

/* member functions */
void    ScavTrap::guardGate(void)
{
    std::cout << "👦 '" << this->_name << "'";
    if (this->_energyPoints > 0)
    {
        this->_energyPoints--;
        std::cout << " has changed to guard gate mode" << std::endl;
    }
    else
        std::cout << " has no Energy 😵" << std::endl;
}
