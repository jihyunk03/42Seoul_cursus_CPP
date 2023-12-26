#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

class Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNum;
		std::string	_secret;

	public:
		Contact();
		~Contact();

		void	setContact(std::string *contact);
		void	previewContact(int index);
		void	showContact(void);
};

#endif
