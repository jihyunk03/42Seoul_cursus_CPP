#include <iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRIAN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "memory address of str(string): " << &str << std::endl;
	std::cout << "memory address of stringPTR(string *): " << &stringPTR << std::endl;
	std::cout << "memory address of stringREF(string &): " << &stringREF << std::endl;

	std::cout << "value of str(string): " << str << std::endl;
	std::cout << "value of stringPTR(string *): " << stringPTR << std::endl;
	std::cout << "value of stringREF(string &): " << stringREF << std::endl;


	return (0);
}
