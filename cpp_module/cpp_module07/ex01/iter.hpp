#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename Type>
void iter(Type* array, size_t arrSize, void (*func)(const Type&))
{
    for (size_t i = 0; i < arrSize; i++)
        func(array[i]);
}

#endif
