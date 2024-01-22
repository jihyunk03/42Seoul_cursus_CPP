#include "./Bureaucrat.hpp"
#include "./Form.hpp"

static void _newSingleLine(void);
static void _newDoubleLine(void);

int main(void)
{
    try
    {
        Bureaucrat  jihyun("Jihyun", 130);
        Bureaucrat  evaluator00("Evaluator00", 2);
        Bureaucrat  evaluator01("Evaluator01", 2);
        _newSingleLine();

        std::cout << jihyun << std::endl;
        std::cout << evaluator00 << std::endl;
        std::cout << evaluator01 << std::endl;
        _newSingleLine();

        Form        cpp05("CPP05", 2, 150);
        Form        cpp06("CPP06", 1, 1);
        _newSingleLine();

        std::cout << cpp05 << std::endl;
        std::cout << cpp06 << std::endl;
        _newSingleLine();

        _newDoubleLine();
        jihyun.signForm(cpp05);
        evaluator00.signForm(cpp05);
        evaluator01.signForm(cpp05);
        _newSingleLine();

        jihyun.signForm(cpp06);
        evaluator00.signForm(cpp06);
        evaluator01.signForm(cpp06);
        _newDoubleLine();
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
