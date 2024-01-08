#ifndef POINT_HPP
# define POINT_HPP

# include "./Fixed.hpp"

class Point
{
	private:
		const Fixed	_x;
		const Fixed	_y;

	public:
		/* OCCF */
		Point();
		Point(const float x, const float y);
		Point(const Point& origin);
		Point&	operator=(const Point& origin);
		~Point();

		/* member functions */
		Fixed	getX(void) const;
		Fixed	getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
