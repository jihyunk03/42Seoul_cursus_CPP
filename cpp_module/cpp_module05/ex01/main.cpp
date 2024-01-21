#include "./Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat  jihyun("Jihyun", 1);
        std::cout << jihyun;

        // Bureaucrat  sohyun("Sohyun", 0);
        // std::cout << sohyun;

        Bureaucrat  gangme("Gangme", 150);
        std::cout << gangme;

        // Bureaucrat  gggg("Gggg", 180);
        // std::cout << gggg;

        std::cout << "===================================" << std::endl;

        // jihyun.increaseGrade();
        // gangme.decreaseGrade();

        std::cout << "jihyun -> downgrade, gangme -> upgrade" << std::endl;
        jihyun.decreaseGrade();
        std::cout << jihyun;
        gangme.increaseGrade();
        std::cout << gangme;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


    return 0;
}
