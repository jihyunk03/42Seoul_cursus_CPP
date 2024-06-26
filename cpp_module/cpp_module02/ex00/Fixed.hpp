#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					_value;
		static const int	_bits = 8;

	public:
		/* OCCF */
		Fixed();
		Fixed(const Fixed& origin);
		Fixed&	operator=(const Fixed& origin);
		~Fixed();

		/* member functions */
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
