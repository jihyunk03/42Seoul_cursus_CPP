#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "./Contact.hpp"

class PhoneBook
{
	private:
		int			_currIndex;
		std::string	_question[5];
		Contact		_contacts[8];

	public:
		PhoneBook();
		~PhoneBook();

		void	add(void);
		void	search(void);
};


#endif
