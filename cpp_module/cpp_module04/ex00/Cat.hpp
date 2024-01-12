#ifndef CAT_HPP
# define CAT_HPP

# include "./Animal.hpp"

class Cat
    : public Animal
{
    public:
        /* OCCF */
        Cat();
        Cat(const Cat& origin);
        Cat& operator=(const Cat& origin);
        ~Cat();

        /* member functions */
        virtual void    makeSound(void) const;
};

#endif
