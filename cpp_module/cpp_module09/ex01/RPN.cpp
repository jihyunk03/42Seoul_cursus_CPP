#include "./RPN.hpp"

/* OCCF: constructor */
RPN::RPN() {}

/* OCCF: destructor */
RPN::~RPN() {}

/* member function: public */
void RPN::calculate(const std::string& args)
{
    std::istringstream  iss(args);
    std::string         token;

    this->_clearStack();
    try {
        while (std::getline(iss, token, ' ')) {
            if (token.size() == 0)                  // row of blanks
                continue;
            int type = this->_checkType(token);     // operator or valid number
            if (type == OPERATOR)
                this->_calculateInStack(token);
            else
                this->_stack.push(type);
        }
        if (this->_stack.size() != 1)
            throw std::logic_error("Error: not enough operators for calculating");
        std::cout << "[result]: " << this->_stack.top() << std::endl;
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

/* member function: private */
int RPN::_checkType(const std::string& token)
{
    char*   pos;
    int     res;

    if (token.size() != 1)
        throw std::logic_error("Error: invalid token(only 0 ~ 9) => " + token);
    if (token == "+" || token == "-" || token == "*" || token == "/")
        return OPERATOR;
    res = strtod(token.c_str(), &pos);
    if (*pos != '\0')
        throw std::logic_error("Error: not a number => " + token);
    return res;
}

void RPN::_calculateInStack(const std::string& op)
{
    int firstNum;
    int secondNum;

    if (this->_stack.size() < 2)
        throw std::logic_error("Error: not enough numbers for calculating");
    secondNum = this->_stack.top();
    this->_stack.pop();
    firstNum = this->_stack.top();
    this->_stack.pop();
    this->_stack.push(this->_calculateNumbers(firstNum, secondNum, op));
}

int RPN::_calculateNumbers(int fn, int sn, const std::string& op)
{
    if (op == "+")
        return fn + sn;
    else if (op == "-")
        return fn - sn;
    else if (op == "*")
        return fn * sn;
    else {
        if (sn == 0)
            throw std::logic_error("Error: zero denominator in division calculating");
        return fn / sn;
    }
}

void RPN::_clearStack(void)
{
    while (this->_stack.empty() == false)
        this->_stack.pop();
}