#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>
# include <algorithm>
# include <stack>

# define OPERATOR -1

/**
 * stack에 관련된 연산 시, empty로 확인하는 경우 거의 없어서.. (abort 주의하기)
*/

class RPN
{
    private:
        /* OCCF */
        RPN(const RPN& origin);
        RPN& operator=(const RPN& origin);

        /* member variable */
        std::stack<int> _stack;

        /* member function */
        int     _checkType(const std::string& token);
        void    _calculateInStack(const std::string& op);
        int     _calculateNumbers(int fn, int sn, const std::string& op);
        void    _clearStack(void);

    public:
        /* OCCF */
        RPN();
        ~RPN();

        /* member function */
        void    calculate(const std::string& args);
};

#endif