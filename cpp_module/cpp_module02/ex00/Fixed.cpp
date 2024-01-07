#include "./Fixed.hpp"

/* constructor */
Fixed::Fixed()
	: _value(0)
{
	std::cout << "**\t[OCCF]: default constructor" << std::endl;
}

/* copy constructor */
Fixed::Fixed(const Fixed& origin)
{
	std::cout << "**\t[OCCF]: copy constructor" << std::endl;
	// std::cout << "!!\tthis address of copy constructor: " << this << std::endl;
	*this = origin;
}

/* operator overloading */
Fixed& Fixed::operator=(const Fixed &origin)
{
	std::cout << "**\t[OCCF]: operator overloading" << std::endl;
	// std::cout << "!!\tthis address of operator-overloading : " << this << std::endl;
	if (this != &origin)
		this->_value = origin.getRawBits();
	return (*this);
}

/* destructor */
Fixed::~Fixed()
{
	std::cout << "**\t[OCCF]: destructor" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "*\t[member-function]: getRawbits" << std::endl;
	return this->_value;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "*\t[member-function]: setRawbits" << std::endl;
	this->_value = raw;
}
