#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	private:
		int value;
		static const int fractionalBits = 8;

	public:
		Fixed();
		Fixed(const int nbr);
		Fixed(const float nbr);
		Fixed(const Fixed &src);
		~Fixed();

		Fixed &operator=(const Fixed &src);
		Fixed &operator*=(const Fixed &src);
		Fixed &operator++(void);
        Fixed operator+(const Fixed &src);
        Fixed &operator--(void);
        Fixed operator-(const Fixed &src);
        Fixed operator++(int);
        Fixed operator--(int);
        Fixed operator*(const Fixed &src);
        Fixed operator/(const Fixed &src);

		static Fixed min(const Fixed &a, const Fixed &b);
		static Fixed max(const Fixed &a, const Fixed &b);

		bool operator<(const Fixed &src);
		bool operator>(const Fixed &src);
		bool operator<=(const Fixed &src);
		bool operator>=(const Fixed &src);
		bool operator==(const Fixed &src);
		bool operator!=(const Fixed &src);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream    &operator<<(std::ostream& flux, const Fixed& f);

#endif