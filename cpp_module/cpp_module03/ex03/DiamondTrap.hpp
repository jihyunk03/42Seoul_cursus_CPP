#pragma once
#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "./ScavTrap.hpp"
# include "./FragTrap.hpp"

class DiamondTrap
    : public FragTrap, public ScavTrap
{
    private:
        std::string _name;
    public:
        /* OCCF */
        DiamondTrap();
        DiamondTrap(const std::string name);
        DiamondTrap(const DiamondTrap& origin);
        DiamondTrap& operator=(const DiamondTrap& origin);
        ~DiamondTrap();

        /* member functions */
        void    whoAmI(void);
        void    printAll(void);
};

#endif
