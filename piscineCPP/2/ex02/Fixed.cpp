#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "Fixed.hpp"

Fixed::Fixed(void) : value(0) {
}

Fixed::Fixed(Fixed const &input) {
	*this = input;
}

Fixed::Fixed(int const input) {
	setRawBits(input << this->num);
}

Fixed::Fixed(float const input) {
	setRawBits(roundf(input * (1 << this->num)));
}

Fixed::~Fixed() {
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


// ----------------------
// Math operators

Fixed	&Fixed::operator=(Fixed const &r) {
	if (this != &r)
		this->value = r.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(Fixed const &r) {
	return (Fixed(this->value + r.getRawBits()));
}

Fixed	Fixed::operator-(Fixed const &r) {
	return (Fixed(this->value - r.getRawBits()));
}

Fixed	Fixed::operator*(Fixed const &r) {
	return (Fixed(this->toFloat() * r.toFloat()));
}

Fixed	Fixed::operator/(Fixed const &r) {
	if (r.toFloat() != 0)
		return (Fixed(this->toFloat() / r.toFloat()));
	else
	{
		std::cout << "Cannot divide by 0, resolving results to 0." << std::endl;
		return (Fixed(0));
	}
}

// ++x
Fixed	&Fixed::operator++() {
	this->value++;
	return (*this);
}

// x++
Fixed	Fixed::operator++(int input) {
	Fixed fplus(*this);
	(void)input;

	this->value++;
	return (fplus);
}

Fixed	&Fixed::operator--() {
	this->value--;
	return (*this);
}

Fixed	Fixed::operator--(int input) {
	Fixed fminus(*this);
	(void)input;
	
	this->value--;
	return (fminus);
}

Fixed	&Fixed::min(Fixed &l, Fixed &r) {
	return ((l.toFloat() < r.toFloat()) ? l : r);
}

Fixed 	&Fixed::max(Fixed &l, Fixed &r) {
	return ((l.toFloat() > r.toFloat()) ? l : r);
}

Fixed const		&Fixed::min(Fixed const &l, Fixed const &r) {
	return ((l.toFloat() < r.toFloat()) ? l : r);
}

Fixed const		&Fixed::max(Fixed const &l, Fixed const &r) {
	return ((l.toFloat() > r.toFloat()) ? l : r);
}


// ----------------------
// Booleans operators

bool	Fixed::operator>(Fixed const &r) {
	return (this->toFloat() > r.toFloat());
}

bool	Fixed::operator<(Fixed const &r) {
	return (this->toFloat() < r.toFloat());
}

bool	Fixed::operator>=(Fixed const &r) {
	return (this->toFloat() >= r.toFloat());
}

bool	Fixed::operator<=(Fixed const &r) {
	return (this->toFloat() <= r.toFloat());
}

bool	Fixed::operator==(Fixed const &r) {
	return (this->toFloat() == r.toFloat());
}

bool	Fixed::operator!=(Fixed const &r) {
	return (this->toFloat() != r.toFloat());
}


// ------------------
// Printing

std::ostream	&operator<<(std::ostream &o, Fixed const &r) {
	o << r.toFloat();
	return (o);
}

int	const	Fixed::num = 8;
