#ifndef ICE_HPP
# define ICE_HPP

# include "./AMateria.hpp"
# include "./ICharacter.hpp"

class Ice
    : public AMateria
{
    public:
        /* OCCF */
        Ice();
        Ice(const Ice& origin);
        Ice&    operator=(const Ice& origin);
        virtual ~Ice();

        /* member functions */
        virtual AMateria*   clone(void) const;
        virtual void        use(ICharacter &target);
};

#endif
