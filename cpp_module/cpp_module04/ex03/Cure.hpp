#ifndef CURE_HPP
# define CURE_HPP

# include "./AMateria.hpp"
# include "./ICharacter.hpp"

class Cure
    : public AMateria
{
    public:
        /* OCCF */
        Cure();
        Cure(const Cure& origin);
        Cure&    operator=(const Cure& origin);
        virtual ~Cure();

        /* member functions */
        virtual AMateria*   clone(void) const;
        virtual void        use(ICharacter &target);
};

#endif
