#include "./ClapTrap.hpp"

int main(void)
{
    ClapTrap    jihyun("Jihyun");

    jihyun.attack("sohyun");

    jihyun.takeDamage(5);
    jihyun.takeDamage(5);
    jihyun.takeDamage(5);

    jihyun.beRepaired(100);

    return 0;
}
