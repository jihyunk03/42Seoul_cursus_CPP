#ifndef DOG_HPP
# define DOG_HPP

# include "./Animal.hpp"
# include "./Brain.hpp"

class Dog
    : public Animal
{
    private:
        Brain*  _dogBrain;

    public:
        /* OCCF */
        Dog();
        Dog(const Dog& origin);
        Dog& operator=(const Dog& origin);
        ~Dog();

        /* member functions */
        virtual void    makeSound(void) const;
        Brain*          getBrain() const;
};

#endif
