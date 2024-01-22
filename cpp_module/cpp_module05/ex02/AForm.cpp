#include "./AForm.hpp"
#include "./Bureaucrat.hpp"

/* OCCF: constructor */
AForm::AForm()
    : _name("noname"), _signed(false), _signGrade(75), _executeGrade(75)
{
    std::cout << "[AForm]: default constructor" << std::endl;
}

AForm::AForm(const std::string name, const int signGrade, const int executeGrade)
    : _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
    if (signGrade < 1 || executeGrade < 1)
        throw AForm::GradeTooHighException();
    else if (signGrade > 150 || executeGrade > 150)
        throw AForm::GradeTooLowException();
    std::cout << "[AForm]: name & grades initialize constructor" << std::endl;
}

/* OCCF: copy constructor */
AForm::AForm(const AForm& origin)
    : _name(origin._name), _signed(origin._signed)
    , _signGrade(origin._signGrade), _executeGrade(origin._executeGrade)
{
    std::cout << "[AForm]: copy constructor" << std::endl;
}

/* OCCF: copy assignment operator overloading */
AForm& AForm::operator=(const AForm& origin)
{
    std::cout << "[AForm]: copy assignment operator overloading" << std::endl;
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
AForm::~AForm()
{
    std::cout << "[AForm]: destructor(" << this->_name << ")" << std::endl;
}


/* member functions */
const std::string& AForm::getName(void) const
{
    return this->_name;
}

bool AForm::getSigned(void) const
{
    return this->_signed;
}

int AForm::getSignGrade(void) const
{
    return this->_signGrade;
}

int AForm::getExecuteGrade(void) const
{
    return this->_executeGrade;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    int bur_grade = bureaucrat.getGrade();
    if (bur_grade > this->_signGrade)
        throw AForm::GradeTooLowException();
    if (this->_signed == true)
        throw AForm::AFormAlreadySignedException();
    this->_signed = true;
}


/* inner-class for exceptions: class-member functions overriding */
const char* AForm::GradeTooHighException::what(void) const throw()
{
    return "grade is too high (↑↑↑)";
}

const char* AForm::GradeTooLowException::what(void) const throw()
{
    return "grade is too low (↓↓↓)";
}

const char* AForm::AFormAlreadySignedException::what(void) const throw()
{
    return "already signed!!";
}


/* ostream: operator overloading */
std::ostream& operator<<(std::ostream& out, const AForm& print)
{
    out << "📕 name(" << print.getName() << ")'s inAformations: ";
    if (print.getSigned() == true)
        out << "signed(O), ";
    else
        out << "signed(X), ";
    out << "sign-grade(" << print.getSignGrade() << "), execute-grade(" << print.getExecuteGrade() << ")";
    return out;
}
