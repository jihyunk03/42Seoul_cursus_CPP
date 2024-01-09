#include "./Point.hpp"

int	main(void)
{
	Point	a(0, 0);
	Point	b(5, 0);
	Point	c(0, 5);
	Point	point(10, 10);

	std::cout << "The point of (" << point.getX() << ", " << point.getY() << ") is ";
	if (bsp(a, b, c, point) == true)
		std::cout << "in the triangle 🙆" << std::endl;
	else
		std::cout << "out of the triangle 🙅" << std::endl;

	return 0;
}
