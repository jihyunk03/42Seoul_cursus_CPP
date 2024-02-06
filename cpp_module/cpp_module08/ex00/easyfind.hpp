#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>

template<typename Type>
typename Type::iterator easyfind(Type& container, int value)
{
    typename Type::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        std::cerr << "'" << value << "' is not in this container" << std::endl;
    return it;
}

#endif
