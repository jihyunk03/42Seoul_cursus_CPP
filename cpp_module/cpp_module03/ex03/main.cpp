#include "./DiamondTrap.hpp"

int main(void)
{
    std::cout << "\n============[DiamondTrap]=============" << std::endl;

    DiamondTrap jihyun("Jihyun");
    jihyun.printAll();

    jihyun.attack("sohyun");
    jihyun.whoAmI();
    jihyun.printAll();

    std::cout << "\n----------------------------------\n" << std::endl;

    ClapTrap*   jiji = new DiamondTrap("Jiji");

    jiji->attack("sohyun");
    // jiji->whoAmI();
    // jiji->printAll();

    delete jiji;

    std::cout << "\n----------------------------------\n" << std::endl;

    DiamondTrap *soso = new DiamondTrap("sohyun");
    soso->printAll();

    delete soso;

    std::cout << "\n----------------------------------\n" << std::endl;

    DiamondTrap jiso = jihyun;
    jiso.whoAmI();
    jiso.printAll();

    std::cout << "\n----------------------------------\n" << std::endl;

    return 0;
}
