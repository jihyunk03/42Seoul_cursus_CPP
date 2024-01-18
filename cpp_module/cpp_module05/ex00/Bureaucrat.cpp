#include "./Bureaucrat.hpp"

/* OCCF: constructor */
Bureaucrat::Bureaucrat()
    : _name("noname"), _grade(150)
{
    std::cout << "[Bureaucrat]: default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : _name(name)
{
    // check grade and throw the exceptions
    std::cout << "[Bureaucrat]: name & grade initialize constructor" << std::endl;
}

/* OCCF: copy constructor */
Bureaucrat::Bureaucrat(const Bureaucrat& origin)
    : _name(origin._name), _grade(origin._grade)
{
    std::cout << "[Bureaucrat]: copy constructor" << std::endl;
}

/* OCCF: copy assignment operator overloading */
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& origin)
{
    std::cout << "[Bureaucrat]: copy assignment operator overloading" << std::endl;
    if (this != &origin)
    {
        const_cast<std::string&>(this->_name) = origin._name;
        this->_grade = origin._grade;
    }
    return *this;
}

/* OCCF: destructor */
Bureaucrat::~Bureaucrat()
{
    std::cout << "[Bureaucrat]: destructor" << std::endl;
}


/* member functions */
const std::string& Bureaucrat::getName(void)
{
    return this->_name;
}

int Bureaucrat::getGrade(void)
{
    return this->_grade;
}

void


/* inner-class for exceptions */
const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return "(↑↑↑) grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return "(↓↓↓) grade is too low";
}
