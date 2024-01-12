#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "./ClapTrap.hpp"

class FragTrap
    : public ClapTrap
{
    public:
        /* OCCF */
        FragTrap();
        FragTrap(const std::string name);
        FragTrap(const FragTrap& origin);
        FragTrap& operator=(const FragTrap& origin);
        ~FragTrap();

        /* member functons */
        void            highFivesGuys(void);
};

#endif
