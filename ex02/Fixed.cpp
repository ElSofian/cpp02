#include "Fixed.hpp"

Fixed::Fixed():value(0)
{
}

Fixed::Fixed(const Fixed &src)
{
  *this = src;
}

Fixed   &Fixed::operator=(const Fixed &src)
{
	if (this != &src)
		value = src.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
}

int	Fixed::getRawBits() const
{
	return (value);
}

void	Fixed::setRawBits(int const raw)
{
	value = raw;
}

int		Fixed::toInt(void) const
{
	return (value >> fractionalBits);
}

float	Fixed::toFloat(void) const
{
	return (float)(value) / (1 << fractionalBits);
}

Fixed::Fixed(const int num):value(num << fractionalBits)
{
}

Fixed::Fixed(const float num):value((int)(roundf(num * (1 << fractionalBits))))
{
}

Fixed Fixed::max(const Fixed &a, const Fixed &b)
{
	return(a.toFloat() > b.toFloat() ? a : b);
}

Fixed Fixed::min(const Fixed &a, const Fixed &b)
{
	return(a.toFloat() < b.toFloat() ? a : b);
}

Fixed max(Fixed &a, Fixed &b)
{
	return(a.toFloat() > b.toFloat() ? a : b);
}

Fixed min(Fixed &a, Fixed &b)
{
	return(a.toFloat() < b.toFloat() ? a : b);
}


// Operators

std::ostream& operator<<(std::ostream& flux, const Fixed& f)
{
	return flux << f.toFloat();
}

bool	Fixed::operator>(const Fixed& src)
{
	return (value > src.value);
}

bool	Fixed::operator<(const Fixed& src)
{
	return (value < src.value);
}

bool	Fixed::operator>=(const Fixed& src)
{
	return (value >= src.value);
}

bool	Fixed::operator<=(const Fixed& src)
{
	return (value <= src.value);
}

bool	Fixed::operator==(const Fixed& src)
{
	return (value == src.value);
}

bool	Fixed::operator!=(const Fixed& src)
{
	return (value != src.value);
}

Fixed	Fixed::operator+(const Fixed& src)
{
	return (toFloat() + src.toFloat());
}

Fixed	Fixed::operator-(const Fixed& src)
{
	return (toFloat() - src.toFloat());
}

Fixed	Fixed::operator*(const Fixed& src)
{
	return (toFloat() * src.toFloat());
}

Fixed	Fixed::operator/(const Fixed& src)
{
	return (toFloat() / src.toFloat());
}

Fixed& Fixed::operator++(void) {
  ++value;
  return *this;
}

Fixed& Fixed::operator--(void) {
  --value;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed tmp = *this;

  ++value;
  return tmp;
}

Fixed Fixed::operator--(int) {
  Fixed tmp = *this;

  --value;
  return tmp;
}