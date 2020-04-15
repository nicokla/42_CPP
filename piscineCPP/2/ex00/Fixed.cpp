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
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "Assignment operator called" << std::endl;
	this->value = raw;
}

int	const	Fixed::num = 8;
