#include "./Point.hpp"

static Fixed	crossProductXY(const Point& a, const Point& b, const Point& c);

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	crossAB = crossProductXY(a, b, point);
	Fixed	crossBC = crossProductXY(b, c, point);
	Fixed	crossCA = crossProductXY(c, a, point);

	if ((crossAB > 0.0f && crossBC > 0.0f && crossCA > 0.0f) \
		|| (crossAB < 0.0f && crossBC < 0.0f && crossCA < 0.0f))
		return true;
	return false;
}

static Fixed	crossProductXY(const Point& a, const Point& b, const Point& c)
{
	return (a.getX() - c.getX()) * (b.getY() - c.getY()) - (a.getY() - c.getY()) * (b.getX() - c.getX());
}
