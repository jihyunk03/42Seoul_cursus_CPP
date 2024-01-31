#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "./Data.hpp"

class Serializer
{
    private:
        /* OCCF */
        Serializer();
        Serializer(const Serializer& origin);
        Serializer operator=(const Serializer& origin);
        ~Serializer();

    public:
        /* static member functions */
        static uintptr_t    serialize(Data* ptr);
        static Data*        deserialize(uintptr_t raw);
};

#endif
