#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

class ICharacter;

class AMateria
{
    protected:
        std::string _type;

    public:
        /* OCCF */
        AMateria();
        AMateria(const std::string& type);
        AMateria(const AMateria& origin);
        AMateria&   operator=(const AMateria& origin);
        virtual     ~AMateria();

        /* member functions */
        const std::string&  getType(void) const;
        virtual AMateria*   clone(void) const = 0;
        virtual void        use(ICharacter& target);
};

#endif
