#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nbr) {
	std::cout << "Int constructor called" << std::endl;
	value = nbr << fractionalBits;
}

Fixed::Fixed(const float nbr) {
	std::cout << "Float constructor called" << std::endl;
	value = ((int)roundf(nbr * (1 << fractionalBits)));
}

Fixed::Fixed(const Fixed &src) {
	std::cout << "Copy constructor called" << std::endl;
	if (this != &src)
		value = src.getRawBits();
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &src) {
	if (this != &src)
		value = src.getRawBits();
	std::cout << "Copy assigment operator called" << std::endl;
	return *this;
}

std::ostream    &operator<<(std::ostream& flux, const Fixed& f)
{
	return flux << f.toFloat();
}

int Fixed::getRawBits(void) const {
	return value;
}

void Fixed::setRawBits(int const raw) {
	value = raw;
}

float Fixed::toFloat(void) const {
	return (float)value / (1 << fractionalBits);
}

int Fixed::toInt(void) const {
	return value >> fractionalBits;
}