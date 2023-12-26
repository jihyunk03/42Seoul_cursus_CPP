#include "./Contact.hpp"

static std::string	_getStrInRange(std::string str);

Contact::Contact()
{
	/* Constructor (default) */
	std::cout << "constructor" << std::endl;
}

Contact::~Contact()
{
	/* Destructor */
	std::cout << "destructor" << std::endl;
}

void	Contact::setContact(std::string *contact)
{
	this->_firstName = contact[0];
	this->_lastName = contact[1];
	this->_nickName = contact[2];
	this->_phoneNum = contact[3];
	this->_secret = contact[4];
}

void	Contact::previewContact(void)
{
	std::cout << "|" \
		<< std::setw(10) << _getStrInRange(_firstName) << "|" \
		<< std::setw(10) << _getStrInRange(_lastName) << "|" \
		<< std::setw(10) << _getStrInRange(_nickName) << "|" \
		<< std::setw(10) << _getStrInRange(_phoneNum) << "|" \
		<< std::setw(10) << _getStrInRange(_secret) << "|" \
		<< std::endl;
}

static std::string	_getStrInRange(std::string str)
{
	if (str.length() < 10)
		return str;
	return str.substr(0, 9) + ".";
}

void	Contact::showContact(void)
{
	std::cout << "First name:    \t" << _firstName << std::endl \
			  << "Last name:     \t" << _lastName << std::endl \
			  << "Nick-name:     \t" << _nickName << std::endl \
			  << "Phone num:     \t" << _phoneNum << std::endl \
			  << "Darkest secret:\t" << _secret << std::endl;
}
