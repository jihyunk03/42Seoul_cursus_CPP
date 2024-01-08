#include "./Fixed.hpp"

int	main(void)
{
	Fixed	a;
	Fixed	b( 10 );
	Fixed	c( 42.42f );
	Fixed	d( b );

	a = Fixed( 1234.4321f );

	std::cout << "====show: as fixed-point type variable====" << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "====show: as integer type variable====" << std::endl;
	std::cout << "a is " << a.toInt() << std::endl;
	std::cout << "b is " << b.toInt() << std::endl;
	std::cout << "c is " << c.toInt() << std::endl;
	std::cout << "d is " << d.toInt() << std::endl;

	return 0;
}
