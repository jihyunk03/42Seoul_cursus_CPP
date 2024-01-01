#include "./PhoneBook.hpp"

static void	_clear_buffer(void);

int	main(void)
{
	PhoneBook	phonebook;
	std::string	command = "";

	std::cout << "==== [Welcome to PhoneBook World] ====" << std::endl;

	while (command != "EXIT")
	{
		std::cout << "Enter a command for using phonebook: ";
		std::getline(std::cin, command);

		if (command == "ADD")
			phonebook.add();
		else if (command == "SEARCH")
			phonebook.search();
		else if (command == "EXIT")
			std::cout << "==== EXIT PROGRAM ====" << std::endl;
		else if (std::cin.fail() == true)
			_clear_buffer();
		else
			std::cout << "X\tCommand does not exist" << std::endl;
	}

	return (0);
}

static void	_clear_buffer(void)
{
	clearerr(stdin);
	std::cin.clear();
	std::cout << std::endl;
}
