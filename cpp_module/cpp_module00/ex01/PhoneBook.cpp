#include "./PhoneBook.hpp"

PhoneBook::PhoneBook()
	: _currIndex(0), _contactCount(0)
{
	/* Constructor */
	std::cout << "\nPhoneBook Constructor\n" << std::endl;

	_question[0] = "1. Enter your first name: ";
	_question[1] = "2. Enter your last name: ";
	_question[2] = "3. Enter your nickname: ";
	_question[3] = "4. Enter your phone number: ";
	_question[4] = "5. Enter your darkest secret: ";
}

PhoneBook::~PhoneBook()
{
	/* Destructor */
	std::cout << "\nPhoneBook destructor\n" << std::endl;
}

void	PhoneBook::add(void)
{
	std::string	answer[5];

	std::cout << "--- [ADD CONTACT] ---" << std::endl;
	for (int answer_idx = 0; answer_idx < 5; answer_idx++)
	{
		do {
			std::cout << _question[answer_idx];
			std::getline(std::cin, answer[answer_idx]);
		} while (answer[answer_idx] == "" && std::cin.eof() == true);
	}
	_contacts[_currIndex].setContact(answer);

	if (++_currIndex == 8)
		_currIndex = 0;
	if (_contactCount < 8)
		_contactCount++;
}

void	PhoneBook::search(void)
{
	std::string	answer;

	std::cout << "--- [SEARCH CONTACT] ---" << std::endl;
	std::cout << " ------------------------------------------- " \
			  << std::endl \
			  << "|Index     |First-name|Last-name |Nick-name |" \
			  << std::endl \
			  << " ------------------------------------------- " \
			  << std::endl;
	for (int preview_index = 0; preview_index < _contactCount; preview_index++)
		_contacts[preview_index].previewContact();
	std::cout << " ------------------------------------------- " << std::endl;

	do {
		std::cout << "Enter the index to search: ";
		std::getline(std::cin, answer);
	} while (answer == "" || std::cin.eof() == true);
	if (answer.length() != 1)
		std::cout << "Contact does not exist" << std::endl;
	else
	{
		int	answer_index = answer[0] - '0';
		if (answer_index < 0 || answer_index > _contactCount)
			std::cout << "Contact does not exist" << std::endl;
		else
			_contacts[answer_index].showContact();
	}
}
