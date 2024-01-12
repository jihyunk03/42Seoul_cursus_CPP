#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "./ClapTrap.hpp"

class FragTrap
    : virtual public ClapTrap
{
    protected:
        static const int _frag_hitPoints = 100;
        static const int _frag_attackDamage = 30;

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
