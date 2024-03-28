#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <algorithm>
# include <stack>

class RPN
{
    private:

    public:
        /* OCCF */
        RPN();
        RPN(const RPN& origin);
        RPN& operator=(const RPN& origin);
        ~RPN();
};

#endif