#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <cstdlib>
# include <algorithm>

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
        void    addNumber(int value);
        void    addManyNumber(size_t size);
        int     shortestSpan(void);
        int     longestSpan(void);
        void    printNumber(void);
};

#endif
