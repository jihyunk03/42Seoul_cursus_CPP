#include "./Harl.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "[X]\tinput argument error!!" << std::endl;
		return 1;
	}

	Harl	harl;

	harl.complain(av[1]);
	return 0;
}
