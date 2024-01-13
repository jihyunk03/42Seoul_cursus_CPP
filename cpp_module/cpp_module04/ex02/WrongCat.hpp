#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "./WrongAnimal.hpp"
# include "./Brain.hpp"

class WrongCat
    : public WrongAnimal
{
    private:
        Brain*  _wrongCatBrain;

    public:
        /* OCCF */
        WrongCat();
        WrongCat(const WrongCat& origin);
        WrongCat& operator=(const WrongCat& origin);
        ~WrongCat();

        /* member functions */
        void    makeSound(void) const;
        Brain*  getBrain(void) const;
};

#endif
