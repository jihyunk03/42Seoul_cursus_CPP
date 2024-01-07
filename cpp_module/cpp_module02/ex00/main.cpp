#include "./Fixed.hpp"

int	main(void)
{
	Fixed	A;
	Fixed	B(A);
	Fixed	C = B;
	// C = B;

	// std::cout << "address of A: " << &A << std::endl;
	// std::cout << "address of B: " << &B << std::endl;
	// std::cout << "address of C: " << &C << std::endl;

	std::cout << A.getRawBits() << std::endl;
	std::cout << B.getRawBits() << std::endl;
	std::cout << C.getRawBits() << std::endl;

	return 0;
}
