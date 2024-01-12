#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
    private:
        std::string     _name;
        unsigned int    _hitPoints;     // 체력
        unsigned int    _energyPoints;  // 행동력
        unsigned int    _attackDamage;  // 공격력

    public:
        /* OCCF */
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& origin);
        ClapTrap& operator=(const ClapTrap& origin);
        ~ClapTrap();

        /* member functions */
        void    attack(const std::string& target);      // 행동력이 있는 경우 공격가능
        void    takeDamage(unsigned int amount);        // 공격을 받아서 체력 줄어듦
        void    beRepaired(unsigned int amount);        // 체력 회복
};

#endif
