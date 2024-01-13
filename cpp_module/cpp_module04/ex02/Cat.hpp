#ifndef CAT_HPP
# define CAT_HPP

# include "./Animal.hpp"
# include "./Brain.hpp"

class Cat
    : public Animal
{
    private:
        Brain*  _catBrain;

    public:
        /* OCCF */
        Cat();
        Cat(const Cat& origin);
        Cat& operator=(const Cat& origin);
        ~Cat();

        /* member functions */
        virtual void    makeSound(void) const;
        Brain*          getBrain(void) const;
};

#endif
