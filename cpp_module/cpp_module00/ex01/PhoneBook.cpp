#include "./PhoneBook.hpp"

PhoneBook::PhoneBook()
	: _question({"1. First name: ", "2. Last name: ", "3. Nickname: ", "4. Phone number: ", "5. Secret~?: "})
{
	_currIndex = 0;
}

PhoneBook::~PhoneBook()
{
	// 소멸자 호출 확인용 메시지(지워)
	std::cout << "PhoneBook destructor" << std::endl;
}

void	PhoneBook::add(void)
{
	std::string	answer[5];

	for (int answer_idx = 0; answer_idx < 5; answer_idx++)
	{
		do {
			std::cout << _question[answer_idx];
			std::getline(std::cin, answer[answer_idx]);
		} while (std::cin.eof() == true);
	}
}

void	PhoneBook::search(void)
{

}
