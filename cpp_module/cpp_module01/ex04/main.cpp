#include "./Replace.hpp"

static bool	_check_argument(int ac, char **av);

int	main(int ac, char **av)
{
	if (_check_argument(ac, av) == false)
		return 1;

	std::string	outfile = av[1];
	Replace		r(av, outfile.append(".replace"));

	r.replace();

	return 0;
}

static bool	_check_argument(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "The number of arguments is not 4" << std::endl;
		return false;
	}

	if (std::strlen(av[1]) == 0 || std::strlen(av[2]) == 0 || std::strlen(av[3]) == 0)
	{
		std::cout << "The argument is not valid" << std::endl;
		return false;
	}

	return true;
}

/*
$> ./ex04 a.txt '
' b
*/
