#include "./PhoneBook.hpp"

static void	_clear_buffer(void);

PhoneBook::PhoneBook()
	: _currIndex(0), _contactCount(0)
{
	/* Constructor */
	this->_question[0] = "1. Enter your first name: ";
	this->_question[1] = "2. Enter your last name: ";
	this->_question[2] = "3. Enter your nickname: ";
	this->_question[3] = "4. Enter your phone number: ";
	this->_question[4] = "5. Enter your darkest secret: ";
}

PhoneBook::~PhoneBook()
{
	/* Destructor */
}

void	PhoneBook::add(void)
{
	std::string	answer[5];

	std::cout << "--- [ADD CONTACT] ---" << std::endl;
	for (int answer_idx = 0; answer_idx < 5; answer_idx++)
	{
		do {
			std::cout << this->_question[answer_idx];
			std::getline(std::cin, answer[answer_idx]);
			if (std::cin.fail() == true)
				_clear_buffer();
		} while (answer[answer_idx] == "" || std::cin.fail() == true);
	}
	this->_contacts[this->_currIndex].setContact(answer);

	if (++(this->_currIndex) == 8)
		this->_currIndex = 0;
	if (this->_contactCount < 8)
		this->_contactCount++;

	std::cout << "---------------------" << std::endl;
}

void	PhoneBook::search(void)
{
	std::string	answer;

	std::cout << "--- [SEARCH CONTACT] ---" << std::endl;
	std::cout << "---------------------------------------------" \
			  << std::endl \
			  << "|Index     |First-name|Last-name |Nick-name |" \
			  << std::endl \
			  << "---------------------------------------------" \
			  << std::endl;
	for (int preview_index = 0; preview_index < this->_contactCount; preview_index++)
		this->_contacts[preview_index].previewContact(preview_index);
	std::cout << "---------------------------------------------" << std::endl;

	do {
		std::cout << "⚡\tEnter the index to search: ";
		std::getline(std::cin, answer);
		if (std::cin.fail() == true)
			_clear_buffer();
	} while (answer == "" || std::cin.fail() == true);

	if (answer.length() != 1)
		std::cout << "X\tContact does not exist" << std::endl;
	else
	{
		int	answer_index = answer[0] - '0';
		if (answer_index < 0 || answer_index + 1 > this->_contactCount)
			std::cout << "X\tContact does not exist" << std::endl;
		else
			this->_contacts[answer_index].showContact();
	}
}

static void	_clear_buffer(void)
{
	clearerr(stdin);
	std::cin.clear();
	std::cout << std::endl;
}
