#include "./ShrubberyCreationForm.hpp"
#include "./Bureaucrat.hpp"

/* OCCF: constructor */
ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("SH_default", SC_SIGN, SC_EXCE)
{
    std::cout << "[ShrubberyCreationForm]: default constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name)
    : AForm(name, SC_SIGN, SC_EXCE)
{
    std::cout << "[ShrubberyCreationForm]: name & grades initialize constructor" << std::endl;
}

/* OCCF: copy constructor */
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& origin)
    : AForm(origin)
{
    std::cout << "[ShrubberyCreationForm]: copy constructor" << std::endl;
}

/* OCCF: copy assignment operator overloading */
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& origin)
{
    std::cout << "[ShrubberyCreationForm]: copy assignment operator overloading" << std::endl;
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
ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "[ShrubberyCreationForm]: destructor(" << this->getName() << ")" << std::endl;
}

/* pure-virtual functions(override) */
void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    std::ofstream   ofs;
    std::string     filename = this->getName() + "_shrubbery";
    int             exec_grade = executor.getGrade();

    if (this->getSigned() == false)
        throw AForm::AFormNeedSignedException();
    if (exec_grade > SC_EXCE)
        throw AForm::GradeTooLowException();

    ofs.open((this->getName() + "_shrubbery").c_str());
    if (ofs.is_open() == false)
        std::cout << "Fail to open file" << std::endl;      // file open에 대한 내장된 exception 없나..?
    ofs << ASCII_TREE;
}
