#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <algorithm>
# include <stack>
# include <deque>

template<typename T>
class MutantStack
    : public std::stack<T>
{
    public:
        /* OCCF */
        MutantStack() : std::stack<T>() {}
        MutantStack(const MutantStack& origin) :std::stack<T>(origin) {}
        MutantStack& operator=(const MutantStack& origin)
        {
            if (this != &origin)
                *this = std::stack<T>::operator=(origin);
            return *this;
        }
        ~MutantStack() {}

        /* type-define for iterators */
        typedef typename std::stack<T>::container_type::iterator            iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator    reverse_iterator;

        /* member functions */
        iterator            begin(void) { return std::stack<T>::c.begin(); }
        iterator            end(void) { return std::stack<T>::c.end(); }
        reverse_iterator    rbegin(void) { return std::stack<T>::c.rbegin(); }
        reverse_iterator    rend(void) { return std::stack<T>::c.rend(); }
};

#endif
