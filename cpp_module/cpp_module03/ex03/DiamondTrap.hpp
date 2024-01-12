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
        DiamondTrap(const DiamondTrap& origin);
        DiamondTrap& operator=(const DiamondTrap& origin);
        ~DiamondTrap();

        /* member functions */
};

/* OCCF: constructor */
DiamondTrap::DiamondTrap()
    : ClapTrap(), _name(ClapTrap::_name)
{
}

/* OCCF: copy constructor */
DiamondTrap::DiamondTrap(const DiamondTrap& origin)
{

}

/* OCCF: copy assignment operator overloading */


/* OCCF: destructor */
DiamondTrap::~DiamondTrap()
{
}


#endif
