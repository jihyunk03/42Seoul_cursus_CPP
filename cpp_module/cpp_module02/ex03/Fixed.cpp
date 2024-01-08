#include "./Fixed.hpp"

/* OCCF: constructor */
Fixed::Fixed()
	: _value(0)
{
	// std::cout << "**\t[OCCF]: default constructor" << std::endl;
}

Fixed::Fixed(const int value)
{
	// std::cout << "**\t[OCCF]: int constructor(" << value << ")" << std::endl;
	this->_value = value << 8;
}

Fixed::Fixed(const float value)
{
	// std::cout << "**\t[OCCF]: float constructor(" << value << ")" << std::endl;
	this->_value = roundf(value * 256);
}

/* OCCF: copy constructor */
Fixed::Fixed(const Fixed& origin)
{
	// std::cout << "**\t[OCCF]: copy constructor" << std::endl;
	*this = origin;
}

/* OCCF: operator overloading */
Fixed& Fixed::operator=(const Fixed& origin)
{
	// std::cout << "**\t[OCCF]: operator overloading" << std::endl;
	if (this != &origin)
		this->_value = origin.getRawBits();
	return (*this);
}

/* OCCF: destructor */
Fixed::~Fixed()
{
	// std::cout << "**\t[OCCF]: destructor" << std::endl;
}

/* member functions */
int	Fixed::getRawBits(void) const
{
	// std::cout << "*\t[member-function]: getRawbits" << std::endl;
	return this->_value;
}

void	Fixed::setRawBits(int const raw)
{
	// std::cout << "*\t[member-function]: setRawbits" << std::endl;
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

/* comparison operator overloading */
bool	Fixed::operator>(const Fixed& cmp)
{
	return this->toFloat() > cmp.toFloat();
}

bool	Fixed::operator<(const Fixed& cmp)
{
	return this->toFloat() < cmp.toFloat();
}

bool	Fixed::operator>=(const Fixed& cmp)
{
	return this->toFloat() >= cmp.toFloat();
}

bool	Fixed::operator<=(const Fixed& cmp)
{
	return this->toFloat() <= cmp.toFloat();
}

bool	Fixed::operator==(const Fixed& cmp)
{
	return this->toFloat() == cmp.toFloat();
}

bool	Fixed::operator!=(const Fixed& cmp)
{
	return this->toFloat() != cmp.toFloat();
}

/* arithmetic operator overloading */
float	Fixed::operator+(const Fixed& arth)
{
	return this->toFloat() + arth.toFloat();
}

float	Fixed::operator-(const Fixed& arth)
{
	return this->toFloat() - arth.toFloat();
}

float	Fixed::operator*(const Fixed& arth)
{
	return this->toFloat() * arth.toFloat();
}

float	Fixed::operator/(const Fixed& arth)
{
	return this->toFloat() / arth.toFloat();
}

/* incre/decre-ment(pre & post) operator overloading */
Fixed&	Fixed::operator++(void)		// pre
{
	this->_value++;
	return *this;
}

Fixed	Fixed::operator++(int)		// post
{
	Fixed	tempFixed = *this;

	this->_value++;
	return tempFixed;
}

Fixed&	Fixed::operator--(void)		// pre
{
	this->_value--;
	return *this;
}

Fixed	Fixed::operator--(int)		// post
{
	Fixed	tempFixed = *this;

	this->_value--;
	return tempFixed;
}

/* min, max function overloading */
Fixed&	Fixed::min(Fixed& fir, Fixed& sec)
{
	if (fir.toFloat() < sec.toFloat())
		return fir;
	return sec;
}

const Fixed&	Fixed::min(const Fixed& fir, const Fixed& sec)
{
	if (fir.toFloat() < sec.toFloat())
		return fir;
	return sec;
}

Fixed&	Fixed::max(Fixed& fir, Fixed& sec)
{
	if (fir.toFloat() > sec.toFloat())
		return fir;
	return sec;
}

const Fixed&	Fixed::max(const Fixed& fir, const Fixed& sec)
{
	if (fir.toFloat() > sec.toFloat())
		return fir;
	return sec;
}
