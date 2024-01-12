#ifndef DOG_HPP
# define DOG_HPP

# include "./Animal.hpp"

class Dog
    : public Animal
{
    public:
        /* OCCF */
        Dog();
        Dog(const Dog& origin);
        Dog& operator=(const Dog& origin);
        ~Dog();

        /* member functions */
        virtual void    makeSound(void) const;
};

#endif
