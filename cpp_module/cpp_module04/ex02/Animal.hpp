#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
    protected:
        std::string _type;

    public:
        /* OCCF */
        Animal();
        Animal(std::string type);
        Animal(const Animal& origin);
        Animal& operator=(const Animal& origin);
        virtual ~Animal();

        /* member functions */
        const std::string&  getType(void) const;
        virtual void        makeSound(void) const;
};

#endif
