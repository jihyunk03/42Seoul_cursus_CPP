#include <iostream>

static std::string	_toUpper(char *av);

int	main(int ac, char **av)
{
	std::string	str;

	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

	while (*(++av))
	{
		str = _toUpper(*av);
		std::cout << str;
	}
	std::cout << std::endl;

	return (0);
}

static std::string	_toUpper(char *av)
{
	std::string	str;

	str = av;
	for (unsigned int i = 0; i < str.length(); i++)
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	return (str);
}
