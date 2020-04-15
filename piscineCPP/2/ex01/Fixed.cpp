#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "Fixed.hpp"

Fixed::Fixed(void) : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &input) {
	std::cout << "Copy constructor called" << std::endl;
	*this = input;
}

Fixed::Fixed(int const input) {
	std::cout << "Int constructor called" << std::endl;
	setRawBits(input << this->num);
}

Fixed::Fixed(float const input) {
	std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(input * (1 << this->num)));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(Fixed const &r) {
	std::cout << "Assignment operator called" << std::endl;

	if (this != &r)
		this->value = r.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const {
	return (this->value);
}

void	Fixed::setRawBits(int const raw) {
	this->value = raw;
}

int		Fixed::toInt(void) const {
	return (getRawBits() >> this->num);
}

float	Fixed::toFloat(void) const {
	return ((float)getRawBits() / (1 << this->num));
}

std::ostream	&operator<<(std::ostream &o, Fixed const &r) {
	o << r.toFloat();
	return (o);
}

int	const	Fixed::num = 8;