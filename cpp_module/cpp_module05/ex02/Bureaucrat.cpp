#include "./Bureaucrat.hpp"
#include "./AForm.hpp"

/* OCCF: constructor */
Bureaucrat::Bureaucrat()
    : _name("noname"), _grade(150)
{
    std::cout << "[Bureaucrat]: default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : _name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
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
    std::cout << "[Bureaucrat]: destructor(" << this->_name << ")" << std::endl;
}


/* member functions */
const std::string& Bureaucrat::getName(void) const
{
    return this->_name;
}

int Bureaucrat::getGrade(void) const
{
    return this->_grade;
}

void Bureaucrat::increaseGrade(void)
{
    if (this->_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decreaseGrade(void)
{
    if (this->_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

void Bureaucrat::signAform(AForm& aform)
{
    try
    {
        aform.beSigned(*this);
        std::cout << "👤 " << this->_name << " signed " << aform.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "👤 " << this->_name << " couldn't sign " << aform.getName() << " because " << e.what() << std::endl;
    }
}


/* inner-class for exceptions: class-member functions overriding */
const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return "grade is too high (↑↑↑)";
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return "grade is too low (↓↓↓)";
}


/* ostream: operator overloading */
std::ostream& operator<<(std::ostream& out, const Bureaucrat& print)
{
    out << "👤 name(" << print.getName() << ")'s grade is " << print.getGrade();
    return out;
}
