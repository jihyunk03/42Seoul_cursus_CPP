#include "./Point.hpp"

/* OCCF: constructor */
Point::Point()
	: _x(0), _y(0)
{
	// std::cout << "**\t[OCCF]: default constructor" << std::endl;
}

Point::Point(const float x, const float y)
	: _x(x), _y(y)
{
	// std::cout << "**\t[OCCF]: float constructor(" << this->_x << ", " << this->_y << ")" << std::endl;
}

/* OCCF: copy constructor */
Point::Point(const Point& origin)
	: _x(origin.getX()), _y(origin.getY())
{
	// std::cout << "**\t[OCCF]: copy constructor" << std::endl;
}

/* OCCF: operator overloading */
Point& Point::operator=(const Point& origin)
{
	// std::cout << "**\t[OCCF]: operator overloading" << std::endl;
	if (this != &origin)
	{
		const_cast<Fixed&>(this->_x) = origin.getX();
		const_cast<Fixed&>(this->_y) = origin.getY();
	}
	return *this;
}

/* OCCF: destructor */
Point::~Point()
{
	// std::cout << "**\t[OCCF]: destructor" << std::endl;
}

/* member functions */
Fixed	Point::getX(void) const
{
	return this->_x;
}

Fixed	Point::getY(void) const
{
	return this->_y;
}
