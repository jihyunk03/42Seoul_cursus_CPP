#include "./ScavTrap.hpp"
#include "./FragTrap.hpp"

int main(void)
{
    std::cout << "\n============[ScavTrap]=============" << std::endl;
    {
        ScavTrap    jihyun("Jihyun");

        jihyun.attack("sohyun");

        jihyun.takeDamage(5);
        jihyun.takeDamage(5);
        jihyun.takeDamage(5);

        jihyun.beRepaired(100);

        jihyun.guardGate();

        std::cout << "\n----------------------------------\n" << std::endl;

        ClapTrap*   jiji = new ScavTrap("Jiji");

        jiji->attack("sohyun");

        jiji->takeDamage(5);
        jiji->takeDamage(5);
        jiji->takeDamage(5);

        jiji->beRepaired(100);

        // jiji->guardGate();

        delete jiji;

        std::cout << "\n----------------------------------\n" << std::endl;

        // ClapTrap sohyun("sohyun");
        // ScavTrap soso(sohyun);
        ScavTrap soso(jihyun);

        soso.attack("sohyun");

        soso.takeDamage(5);

        soso.guardGate();

    }

    std::cout << "\n============[FragTrap]=============" << std::endl;
    {
        FragTrap    jihyun("Jihyun");

        jihyun.attack("sohyun");

        jihyun.takeDamage(5);
        jihyun.takeDamage(5);
        jihyun.takeDamage(5);

        jihyun.beRepaired(100);

        jihyun.highFivesGuys();

        std::cout << "\n----------------------------------\n" << std::endl;

        ClapTrap*   jiji = new FragTrap("Jiji");

        jiji->attack("sohyun");

        jiji->takeDamage(5);
        jiji->takeDamage(5);
        jiji->takeDamage(5);

        jiji->beRepaired(100);

        // jiji->highFivesGuys();

        delete jiji;

        std::cout << "\n----------------------------------\n" << std::endl;

        // ClapTrap sohyun("sohyun");
        // FragTrap soso(sohyun);
        FragTrap soso(jihyun);

        soso.attack("sohyun");

        soso.takeDamage(5);

        soso.highFivesGuys();

    }

    return 0;
}
