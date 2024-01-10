#include "./ScavTrap.hpp"

int main(void)
{
    ScavTrap    jihyun("Jihyun");

    jihyun.attack("sohyun");

    jihyun.takeDamage(5);
    jihyun.takeDamage(5);
    jihyun.takeDamage(5);

    jihyun.beRepaired(100);

    jihyun.guardGate();

    std::cout << "\n=========================\n" << std::endl;

    ClapTrap*   jiji = new ScavTrap("Jiji");

    jiji->attack("sohyun");

    jiji->takeDamage(5);
    jiji->takeDamage(5);
    jiji->takeDamage(5);

    jiji->beRepaired(100);

    // jiji->guardGate();

    delete jiji;

    std::cout << "\n=========================\n" << std::endl;

    // ClapTrap sohyun("sohyun");
    // ScavTrap soso(sohyun);
    ScavTrap soso(jihyun);

    soso.attack("sohyun");

    soso.takeDamage(5);

    soso.guardGate();

    return 0;
}
