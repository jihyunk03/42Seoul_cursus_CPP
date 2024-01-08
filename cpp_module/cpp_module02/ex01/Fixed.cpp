#include "./Fixed.hpp"

/* constructor */
Fixed::Fixed()
	: _value(0)
{
	std::cout << "**\t[OCCF]: default constructor" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "**\t[OCCF]: int constructor(" << value << ")" << std::endl;
	this->_value = value << 8;
}

Fixed::Fixed(const float value)
{
	std::cout << "**\t[OCCF]: float constructor(" << value << ")" << std::endl;
	this->_value = roundf(value * 256);
}

/* copy constructor */
Fixed::Fixed(const Fixed& origin)
{
	std::cout << "**\t[OCCF]: copy constructor" << std::endl;
	*this = origin;
}

/* operator overloading */
Fixed& Fixed::operator=(const Fixed &origin)
{
	std::cout << "**\t[OCCF]: operator overloading" << std::endl;
	if (this != &origin)
		this->_value = origin.getRawBits();
	return (*this);
}

/* destructor */
Fixed::~Fixed()
{
	std::cout << "**\t[OCCF]: destructor" << std::endl;
}

/* member functions */
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

int	Fixed::toInt(void) const
{
	return this->_value >> 8;
}

float	Fixed::toFloat(void) const
{
	return float(this->_value) / float(256);
}

std::ostream&	operator<<(std::ostream &out, const Fixed &print)
{
	out << print.toFloat();
	return out;
}
