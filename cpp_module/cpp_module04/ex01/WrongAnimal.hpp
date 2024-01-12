#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
    protected:
        std::string _type;

    public:
        /* OCCF */
        WrongAnimal();
        WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal& origin);
        WrongAnimal& operator=(const WrongAnimal& origin);
        virtual ~WrongAnimal();

        /* member functions */
        const std::string&  getType(void) const;
        void                makeSound(void) const;
};

#endif
