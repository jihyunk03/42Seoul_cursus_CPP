#include "./ClapTrap.hpp"

/* OCCF: constructor */
ClapTrap::ClapTrap()
    : _name("(default)"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "🤰 [ClapTrap]: default constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "🤰 [ClapTrap]: name constructor(" << this->_name << ")" << std::endl;
}

/* OCCF: copy constructor */
ClapTrap::ClapTrap(const ClapTrap& origin)
    : _name(origin._name), _hitPoints(origin._hitPoints) \
    , _energyPoints(origin._energyPoints), _attackDamage(origin._attackDamage)
{
    std::cout << "🤰 [ClapTrap]: copy constructor(" << this->_name << ")" << std::endl;
}

/* OCCF: copy assignment operator overloading */
ClapTrap&   ClapTrap::operator=(const ClapTrap& origin)
{
    std::cout << "🤰 [ClapTrap]: copy assignment operator overloading" << std::endl;
    if (this != &origin)
    {
        this->_name = origin._name;         // string 클래스 내부에서 대입 연산자에 대해 기본적으로 deep-copy를 하도록 오버로딩 되어 있음
        this->_hitPoints = origin._hitPoints;
        this->_energyPoints = origin._energyPoints;
        this->_attackDamage = origin._attackDamage;
    }
    return *this;
}

/* OCCF: destructor */
ClapTrap::~ClapTrap()
{
    std::cout << "🤰 [ClapTrap]: destructor" << std::endl;
}

/* member functions */
void    ClapTrap::attack(const std::string& target)
{
    std::cout << "🤰 '" << this->_name << "'";
    if (this->_energyPoints > 0)
    {
        this->_energyPoints--;
        std::cout << " attacks '" << target << "', causing " << this->_attackDamage << " points of damage! 😁" << std::endl;
    }
    else
        std::cout << " has no Energy 😵" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "🤰 '" << this->_name << "'";
    if (this->_hitPoints == 0)
        std::cout << " has no HP 😵" << std::endl;
    else if (amount < this->_hitPoints)
    {
        this->_hitPoints -= amount;
        std::cout << " has taken damage '" << amount << "' and '" << this->_hitPoints << "' energy is left 🤪" << std::endl;
    }
    else
    {
        this->_hitPoints = 0;
        std::cout << " has taken damage '" << amount << "' and losts all HP 😱" << std::endl;
    }
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << "🤰 '" << this->_name << "'";
    if (this->_energyPoints > 0)
    {
        this->_energyPoints--;
        this->_hitPoints += amount;
        std::cout << " has repaired '" << amount << "' to HP and has '" << this->_hitPoints << "' HPs 😋" << std::endl;
    }
    else
        std::cout << " has no Energy 😵" << std::endl;

}
