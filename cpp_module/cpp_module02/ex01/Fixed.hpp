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

		Fixed(const int value);
		Fixed(const float value);

		/* member functions */
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		int		toInt(void) const;
		float	toFloat(void) const;
};

std::ostream&	operator<<(std::ostream &out, const Fixed &print);

#endif
