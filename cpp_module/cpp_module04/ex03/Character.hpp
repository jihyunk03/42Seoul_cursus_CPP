#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "./ICharacter.hpp"

class Character
    : public ICharacter
{
    private:
        std::string _name;
        int         _invCount;
        int         _floorIndex;        // for delete
        AMateria*   _inventory[4];
        AMateria*   _floor[1000];       // for delete

    public:
        /* OCCF */
        Character();
        Character(const std::string& name);
        Character(const Character& origin);
        Character&      operator=(const Character& origin);
        virtual         ~Character();

        /* member functions */
        virtual const   std::string& getName(void) const;
        virtual void    equip(AMateria* m);
        virtual void    unequip(int idx);
        virtual void    use(int idx, ICharacter& target);
};

#endif
