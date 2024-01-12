#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "./ClapTrap.hpp"

class ScavTrap
    : virtual public ClapTrap
{
    protected:
        static const int _scav_energyPoints = 50;

    public:
        /* OCCF */
        ScavTrap();
        ScavTrap(const std::string name);
        ScavTrap(const ScavTrap& origin);
        ScavTrap& operator=(const ScavTrap& origin);
        ~ScavTrap();

        /* parent-class member function overloading */
        virtual void    attack(const std::string& target);

        /* member functons */
        void            guardGate(void);
};

#endif
