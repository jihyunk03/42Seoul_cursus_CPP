#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

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
		int					getRawBits(void) const;
		void				setRawBits(int const raw);

		int					toInt(void) const;
		float				toFloat(void) const;

		/* comparison operator overloading */
		bool				operator>(const Fixed& cmp);
		bool				operator<(const Fixed& cmp);
		bool				operator>=(const Fixed& cmp);
		bool				operator<=(const Fixed& cmp);
		bool				operator==(const Fixed& cmp);
		bool				operator!=(const Fixed& cmp);

		/* arithmetic operator overloading */
		Fixed				operator+(const Fixed& arth);
		Fixed				operator-(const Fixed& arth);
		Fixed				operator*(const Fixed& arth);
		Fixed				operator/(const Fixed& arth);

		/* incre/decre-ment(pre & post) operator overloading */
		Fixed&				operator++(void);	// pre
		Fixed				operator++(int);	// post
		Fixed&				operator--(void);	// pre
		Fixed				operator--(int);	// post

		/* min, max function overloading */
		static Fixed&		min(Fixed& fir, Fixed& sec);
		static const Fixed&	min(const Fixed& fir, const Fixed& sec);
		static Fixed&		max(Fixed& fir, Fixed& sec);
		static const Fixed&	max(const Fixed& fir, const Fixed& sec);
};

std::ostream&	operator<<(std::ostream &out, const Fixed &print);

#endif
