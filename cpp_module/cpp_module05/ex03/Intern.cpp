#include "./Intern.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm.hpp"

/* OCCF: constructor */
Intern::Intern()
{
    std::cout << "[Intern]: default constructor" << std::endl;
}

/* OCCF: copy constructor */
Intern::Intern(const Intern& origin)
{
    (void) origin;
    std::cout << "[Intern]: copy constructor" << std::endl;
}

/* OCCF: copy assignment operator overloading */
Intern& Intern::operator=(const Intern& origin)
{
    (void) origin;
    std::cout << "[Intern]: copy assignment operator overloading" << std::endl;
    return *this;
}

/* OCCF: destructor */
Intern::~Intern()
{
    std::cout << "[Intern]: destructor" << std::endl;
}


/* member functions */
AForm* Intern::makeForm(const std::string& formName, const std::string& targetName)
{
    typedef     AForm*  (Intern::*funcPtr)(const std::string& name);

    funcPtr     func_arr[] = {&Intern::_makeShrubberyForm, &Intern::_makeRobotoForm, &Intern::_makePresidentialForm};
    std::string form_type[] = {"ShrubberyCreation", "RobotomyRequest", "PresidentialPardon"};
    AForm*      resForm = NULL;

    for (int index = 0; index < 3; index++)
    {
        if (formName == form_type[index])
        {
            resForm = (this->*func_arr[index])(targetName);
            std::cout << "🙆 Intern creates " << formName << "(" << targetName << ")" << std::endl;
            return resForm;
        }
    }
    throw Intern::AFormNameIsWrongException();
    return NULL;
}

AForm* Intern::_makeShrubberyForm(const std::string& name)
{
    return new ShrubberyCreationForm(name);
}

AForm* Intern::_makeRobotoForm(const std::string& name)
{
    return new RobotomyRequestForm(name);
}

AForm* Intern::_makePresidentialForm(const std::string& name)
{
    return new PresidentialPardonForm(name);
}


/* inner-class for exceptions: class-member functions overriding */
const char* Intern::AFormNameIsWrongException::what(void) const throw()
{
    return "doesn't exist!!";
}
