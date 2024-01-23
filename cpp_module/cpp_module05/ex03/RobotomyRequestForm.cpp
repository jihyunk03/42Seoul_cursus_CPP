#include "./RobotomyRequestForm.hpp"
#include "./Bureaucrat.hpp"

#include <cstdlib>

/* OCCF: constructor */
RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RR_default", RR_SIGN, RR_EXEC)
{
    std::cout << "[RobotomyRequestForm]: default constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& name)
    : AForm(name, RR_SIGN, RR_EXEC)
{
    std::cout << "[RobotomyRequestForm]: name & grades initialize constructor" << std::endl;
}

/* OCCF: copy constructor */
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& origin)
    : AForm(origin)
{
    std::cout << "[RobotomyRequestForm]: copy constructor" << std::endl;
}

/* OCCF: copy assignment operator overloading */
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& origin)
{
    std::cout << "[RobotomyRequestForm]: copy assignment operator overloading" << std::endl;
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
RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "[RobotomyRequestForm]: destructor(" << this->getName() << ")" << std::endl;
}

/* pure-virtual functions(override) */
void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    int exec_grade = executor.getGrade();

    if (this->getSigned() == false)
        throw AForm::AFormNeedSignedException();
    if (exec_grade > RR_EXEC)
        throw AForm::GradeTooLowException();

    std::cout << "🔩 Drrrrrrriiiiiiilll-------!!! whill-whill---!! 🔩" << std::endl;
    srand(time(0));
    if (std::rand() % 2 == 0)
        std::cout << "🤖 " << this->getName() << " has been robotomized SUCCESSFULLY 🤖" << std::endl;
    else
        std::cout << "🤖 " << this->getName() << " has FAILED to robotomized... 🤖" << std::endl;
}
