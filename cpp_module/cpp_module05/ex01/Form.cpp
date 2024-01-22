#include "./Form.hpp"
#include "./Bureaucrat.hpp"

/* OCCF: constructor */
Form::Form()
    : _name("noname"), _signed(false), _signGrade(75), _executeGrade(75)
{
    std::cout << "[Form]: default constructor" << std::endl;
}

Form::Form(const std::string name, const int signGrade, const int executeGrade)
    : _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
    if (signGrade < 1 || executeGrade < 1)
        throw Form::GradeTooHighException();
    else if (signGrade > 150 || executeGrade > 150)
        throw Form::GradeTooLowException();
    std::cout << "[Form]: name & grades initialize constructor" << std::endl;
}

/* OCCF: copy constructor */
Form::Form(const Form& origin)
    : _name(origin._name), _signed(origin._signed)
    , _signGrade(origin._signGrade), _executeGrade(origin._executeGrade)
{
    std::cout << "[Form]: copy constructor" << std::endl;
}

/* OCCF: copy assignment operator overloading */
Form& Form::operator=(const Form& origin)
{
    std::cout << "[Form]: copy assignment operator overloading" << std::endl;
    if (this != &origin)
    {
        const_cast<std::string&>(this->_name) = origin._name;
        this->_signed = origin._signed;
        const_cast<int&>(this->_signGrade) = origin._signGrade;
        const_cast<int&>(this->_executeGrade) = origin._executeGrade;
    }
    return *this;
}

/* OCCF: destructor */
Form::~Form()
{
    std::cout << "[Form]: destructor(" << this->_name << ")" << std::endl;
}


/* member functions */
const std::string& Form::getName(void) const
{
    return this->_name;
}

bool Form::getSigned(void) const
{
    return this->_signed;
}

int Form::getSignGrade(void) const
{
    return this->_signGrade;
}

int Form::getExecuteGrade(void) const
{
    return this->_executeGrade;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    int bur_grade = bureaucrat.getGrade();
    if (bur_grade > this->_signGrade)
        throw Form::GradeTooLowException();
    if (this->_signed == true)
        throw Form::FormAlreadySignedException();
    this->_signed = true;
}


/* inner-class for exceptions: class-member functions overriding */
const char* Form::GradeTooHighException::what(void) const throw()
{
    return "grade is too high (↑↑↑)";
}

const char* Form::GradeTooLowException::what(void) const throw()
{
    return "grade is too low (↓↓↓)";
}

const char* Form::FormAlreadySignedException::what(void) const throw()
{
    return "already signed!!";
}


/* ostream: operator overloading */
std::ostream& operator<<(std::ostream& out, const Form& print)
{
    out << "📕 name(" << print.getName() << ")'s informations: ";
    if (print.getSigned() == true)
        out << "signed(O), ";
    else
        out << "signed(X), ";
    out << "sign-grade(" << print.getSignGrade() << "), execute-grade(" << print.getExecuteGrade() << ")";
    return out;
}
