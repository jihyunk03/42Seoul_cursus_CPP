#include "./Fixed.hpp"

int	main(void)
{
	{
		Fixed		a;
		const Fixed	b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << "==[ incre/decre-ment(pre & post) operator overloading ]==" << std::endl;
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;

		std::cout << Fixed::max(a, b) << std::endl;
	}

	std::cout << "=========================================================" << std::endl;

	{
		Fixed	a(5);
		Fixed	b(3.14f);

		std::cout << "==[ comparison operator overloading ]==" << std::endl;
		std::cout << "a > b: " << (a > b) << std::endl;
		std::cout << "a < b: " << (a < b) << std::endl;
		std::cout << "a >= b: " << (a >= b) << std::endl;
		std::cout << "a <= b: " << (a <= b) << std::endl;
		std::cout << "a == b: " << (a == b) << std::endl;
		std::cout << "a != b: " << (a != b) << std::endl;

		std::cout << std::endl;

		std::cout << "==[ arithmetic operator overloading ]==" << std::endl;
		std::cout << "a + b: " << (a + b) << std::endl;
		std::cout << "a - b: " << (a - b) << std::endl;
		std::cout << "a * b: " << (a * b) << std::endl;
		std::cout << "a / b: " << (a / b) << std::endl;

		std::cout << std::endl;

		std::cout << "==[ min, max function overloading ]==" << std::endl;
		std::cout << "min(a, b): ";
		if (Fixed::min(a, b) == a)
			std::cout << "a !!" << std::endl;
		else
			std::cout << "b !!" << std::endl;
		std::cout << "max(a, b): ";
		if (Fixed::max(a, b) == a)
			std::cout << "a !!" << std::endl;
		else
			std::cout << "b !!" << std::endl;
	}

	return 0;
}
