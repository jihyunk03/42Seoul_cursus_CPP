#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template<typename T>
void swap(T& a, T& b)
{
    T   tmp(a);

    tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
const T& min(const T& a, const T& b)
{
    if (a < b)
        return a;
    return b;
}

template<typename T>
const T& max(const T& a, const T& b)
{
    if (a > b)
        return a;
    return b;
}

template<typename T>
void _printValue(const T& a, const T& b)
{
    std::cout << "a(" << a << "),\tb(" << b << ")" << std::endl;
}

#endif
