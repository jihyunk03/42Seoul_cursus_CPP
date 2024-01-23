#include "./Bureaucrat.hpp"
#include "./AForm.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm.hpp"

static void _newSingleLine(void);
static void _newDoubleLine(void);

int main(void)
{
    try
    {
        Bureaucrat  jihyun("Jihyun", 1);
        Bureaucrat  sohyun("sohyun", 50);
        AForm*      shrubbery = new ShrubberyCreationForm("shrushru");
        AForm*      roboto = new RobotomyRequestForm("roborobo");
        AForm*      presidential = new PresidentialPardonForm("presidential");
        _newSingleLine();

        jihyun.executeForm(*shrubbery);
        _newSingleLine();

        jihyun.signAform(*shrubbery);
        sohyun.signAform(*roboto);
        sohyun.signAform(*presidential);
        jihyun.signAform(*presidential);
        _newDoubleLine();

        jihyun.executeForm(*shrubbery);
        jihyun.executeForm(*roboto);
        jihyun.executeForm(*presidential);
        _newDoubleLine();

        sohyun.executeForm(*shrubbery);
        sohyun.executeForm(*roboto);
        sohyun.executeForm(*presidential);
        _newDoubleLine();

        delete shrubbery;
        delete roboto;
        delete presidential;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

static void _newSingleLine(void)
{
    std::cout << "-------------------------------------------------------" << std::endl;
}

static void _newDoubleLine(void)
{
    std::cout << "=======================================================" << std::endl;
}
