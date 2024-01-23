#include "./PresidentialPardonForm.hpp"
#include "./Bureaucrat.hpp"

/* OCCF: constructor */
PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PP_default", PP_SIGN, PP_EXEC)
{
    std::cout << "[PresidentialPardonForm]: default constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& name)
    : AForm(name, PP_SIGN, PP_EXEC)
{
    std::cout << "[PresidentialPardonForm]: name & grades initialize constructor" << std::endl;
}

/* OCCF: copy constructor */
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& origin)
    : AForm(origin)
{
    std::cout << "[PresidentialPardonForm]: copy constructor" << std::endl;
}

/* OCCF: copy assignment operator overloading */
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& origin)
{
    std::cout << "[PresidentialPardonForm]: copy assignment operator overloading" << std::endl;
    if (this != &origin)
    {
        this->setName(origin.getName());
        this->setSigned(origin.getSigned());
        this->setSignGrade(origin.getSignGrade());
        this->setExecuteGrade(origin.getExecuteGrade());
    }
    return *this;
}

/* OCCF: destructor */
PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "[PresidentialPardonForm]: destructor(" << this->getName() << ")" << std::endl;
}

/* pure-virtual functions(override) */
void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    int exec_grade = executor.getGrade();

    if (this->getSigned() == false)
        throw AForm::AFormNeedSignedException();
    if (exec_grade > PP_EXEC)
        throw AForm::GradeTooLowException();

    std::cout << "🧑‍💼 " << this->getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
