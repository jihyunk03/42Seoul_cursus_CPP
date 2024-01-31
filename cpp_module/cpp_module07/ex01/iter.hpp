#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename TArray, typename TFunc>
void iter(TArray array, size_t arrSize, TFunc func)
{
    for (size_t i = 0; i < arrSize; i++)
        func(array[i]);
}

#endif
