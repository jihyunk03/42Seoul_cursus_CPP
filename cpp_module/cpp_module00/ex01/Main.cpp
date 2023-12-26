#include "./PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	command;

	std::cout << "Welcome to PhoneBook World" << std::endl;

	do {
		std::cout << "Enter a command for using phonebook: ";
		std::getline(std::cin, command);
		if (command == "ADD")
			phonebook.add();
		else if (command == "SEARCH")
			phonebook.search();
		else if (command == "EXIT")
			std::cout << "==== EXIT PROGRAM ====" << std::endl;
		else	// 이거 좀 이상한데 고치자
			std::cout << "--- Invalid Command ---" << std::endl;
	} while (command != "EXIT" || std::cin.eof() == true);

	return (0);
}
