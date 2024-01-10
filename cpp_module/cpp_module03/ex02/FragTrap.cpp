#include "./FragTrap.hpp"

/* OCCF: constructor */
FragTrap::FragTrap()
    : ClapTrap()            // constructor of deault-c
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "👧 [FragTrap]: default constructor" << std::endl;
}

FragTrap::FragTrap(const std::string name)
    : ClapTrap(name)        // constructor of initialize by parameter
{
    // this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "👧 [FragTrap]: name constructor(" << this->_name << ")" << std::endl;
}

/* OCCF: copy constructor */
FragTrap::FragTrap(const FragTrap& origin)
    : ClapTrap(origin)      // auto casting
{
    // this->_name = origin._name;
    this->_hitPoints = origin._hitPoints;
    this->_energyPoints = origin._energyPoints;
    this->_attackDamage = origin._attackDamage;
    std::cout << "👧 [FragTrap]: copy constructor(" << this->_name << ")" << std::endl;
}

/* OCCF: copy assignment operator overloading */
FragTrap&   FragTrap::operator=(const FragTrap& origin)
{
    std::cout << "👧 [FragTrap]: copy assignment operator overloading" << std::endl;
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
FragTrap::~FragTrap()
{
    std::cout << "👧 [FragTrap]: destructor" << std::endl;
}

/* parent-class member function overloading */
void    FragTrap::attack(const std::string& target)
{
    std::cout << "👧 '" << this->_name << "'";
    if (this->_energyPoints > 0)
    {
        this->_energyPoints--;
        std::cout << " attacks '" << target << "', causing " << this->_attackDamage << " points of damage! 😁" << std::endl;
    }
    else
        std::cout << " has no Energy 😵" << std::endl;

}

/* member functions */
void    FragTrap::highFivesGuys(void)
{
    std::cout << "👧 '" << this->_name << "'";
    if (this->_energyPoints > 0)
    {
        this->_energyPoints--;
        std::cout << " has changed to high-five mode(with guys)" << std::endl;
    }
    else
        std::cout << " has no Energy 😵" << std::endl;
}
