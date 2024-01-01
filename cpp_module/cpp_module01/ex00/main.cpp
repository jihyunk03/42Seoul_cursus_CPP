#include "./Zombie.hpp"

int	main(void)
{
	Zombie	jihyun("Jihyun");
	jihyun.announce();

	std::cout << std::endl;

	Zombie	*gangme = newZombie("Gangme");
	gangme->announce();
	delete gangme;

	std::cout << std::endl;

	randomChump("Sohyun");

	return (0);
}
