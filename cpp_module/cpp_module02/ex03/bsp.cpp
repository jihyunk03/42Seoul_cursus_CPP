#include "./Point.hpp"

static Fixed	getArea(const Point& a, const Point& b, const Point& c);

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	areaTotal = getArea(a, b, c);
	Fixed	areaA = getArea(a, b, point);
	Fixed	areaB = getArea(b, c, point);
	Fixed	areaC = getArea(c, a, point);

	if (areaA > 0.0f && areaB > 0.0f && areaC > 0.0f \
		&& areaTotal.toFloat() == areaA.toFloat() + areaB.toFloat() + areaC.toFloat())
		return true;
	return false;
}

static Fixed	getArea(const Point& a, const Point& b, const Point& c)
{
	return (a.getX() - c.getX()) * (b.getY() - c.getY()) - (a.getY() - c.getY()) * (b.getX() - c.getX());
}

// static float	crossProductXY(Point const vectorA, Point const vectorB)
// {
// 	return vectorA.getX() * vectorB.getY() - vectorA.getY() * vectorB.getX();
// }
