#include "./Contact.hpp"

Contact::Contact()
{
	// 생성자 호출 확인용 메시지(지워)
	std::cout << "constructor" << std::endl;
}

Contact::~Contact()
{
	// 소멸자 호출 확인용 메시지(지워라^^)
	std::cout << "destructor" << std::endl;
}
