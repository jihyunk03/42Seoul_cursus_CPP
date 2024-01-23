#include "./Bureaucrat.hpp"
#include "./Intern.hpp"

static void _newSingleLine(void);
static void _newDoubleLine(void);

int main(void)
{
    std::string formName, targetName;
    Bureaucrat  evaluator("Evaluator", 1);
    try
    {
        _newSingleLine();
        Intern someRandomIntern;
        _newDoubleLine();

        /* ex1) */
        formName = "ShrubberyCreation";
        targetName = "cpp05";
        AForm* form = someRandomIntern.makeForm(formName, targetName);
        std::cout << std::endl;

        evaluator.signAform(*form);
        evaluator.executeForm(*form);
        std::cout << std::endl;

        delete form;

        /* ex2) */
        // while (true)
        // {
        //     _newSingleLine();
        //     std::cout << "[write form-name] (ShrubberyCreation), (RobotomyRequest), (PresidentialPardon): ";
        //     std::cin >> formName;
        //     std::cout << std::endl;

        //     std::cout << "[write target-name]: ";
        //     std::cin >> targetName;
        //     std::cout << std::endl;

        //     AForm* form = someRandomIntern.makeForm(formName, targetName);

        //     evaluator.signAform(*form);
        //     evaluator.executeForm(*form);
        //     std::cout << std::endl;

        //     delete form;
        //     std::cout << std::endl;
        // }

        _newDoubleLine();
    }
    catch(const std::exception& e)
    {
        std::cerr << "🤦 '" << formName << "' " << e.what() << std::endl;
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
