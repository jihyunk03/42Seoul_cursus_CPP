#include "./Contact.hpp"

static std::string	_get_str_in_range(std::string str);

Contact::Contact()
{
	/* Constructor (default) */
}

Contact::~Contact()
{
	/* Destructor */
}

void	Contact::setContact(std::string *contact)
{
	this->_firstName = contact[0];
	this->_lastName = contact[1];
	this->_nickName = contact[2];
	this->_phoneNum = contact[3];
	this->_secret = contact[4];
}

void	Contact::previewContact(int contact_index)
{
	std::cout << "|" \
		<< std::setw(10) << contact_index << "|" \
		<< std::setw(10) << _get_str_in_range(this->_firstName) << "|" \
		<< std::setw(10) << _get_str_in_range(this->_lastName) << "|" \
		<< std::setw(10) << _get_str_in_range(this->_nickName) << "|" \
		<< std::endl;
}

void	Contact::showContact(void)
{
	std::cout << "--- [SHOW CONTACT] ---" << std::endl;
	std::cout << "First name:    \t" << this->_firstName << std::endl \
			  << "Last name:     \t" << this->_lastName << std::endl \
			  << "Nick-name:     \t" << this->_nickName << std::endl \
			  << "Phone num:     \t" << this->_phoneNum << std::endl \
			  << "Darkest secret:\t" << this->_secret << std::endl;
	std::cout << "----------------------" << std::endl;
}

static std::string	_get_str_in_range(std::string str)
{
	if (str.length() <= 10)
		return str;
	return (str.substr(0, 9) + ".");
}
