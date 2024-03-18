#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
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
        void            addNumber(int value);
        unsigned int    shortestSpan(void);
        unsigned int    longestSpan(void);
        void            printNumber(void);

        /* additional function impl by template */
        template<typename T>
        void addManyNumbers(const T& iterableCont)
        {
            if (std::distance(iterableCont.begin(), iterableCont.end()) + this->_vec.size() > this->_maxSize)
                throw std::out_of_range("❌ cannot add numbers: out of range of this Span");

            typename T::const_iterator it;
            for (it = iterableCont.begin(); it != iterableCont.end(); ++it)
                this->_vec.push_back(*it);
        }
};

#endif
