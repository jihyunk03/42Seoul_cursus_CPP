#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "./WrongAnimal.hpp"

class WrongCat
    : public WrongAnimal
{
    public:
        /* OCCF */
        WrongCat();
        WrongCat(const WrongCat& origin);
        WrongCat& operator=(const WrongCat& origin);
        ~WrongCat();

        /* member functions */
        void    makeSound(void) const;
};

#endif
