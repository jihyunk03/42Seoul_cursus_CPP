#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <cstdlib>
# include <algorithm>

/**
 * size_t, unsigned int -> 혼란 해결하기, current size를 추가?
 * range of iterators: 설마 resize?
*/

class Span
{
    private:
        /* member variable */
        unsigned int        _maxSize;
        std::vector<int>    _vec;

        /* OCCF */
        Span();

    public:
        /* OCCF */
        Span(unsigned int maxSize);
        Span(const Span& origin);
        Span& operator=(const Span& origin);
        ~Span();

        /* member functions */
        void            addNumber(int value);
        void            addManyRandNumber(unsigned int size);     // size_t
        unsigned int    shortestSpan(void);
        unsigned int    longestSpan(void);
        void            printNumber(void);
};

#endif
