#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cmath>

class	Fixed  {
	public:
		Fixed();
		Fixed(Fixed const &input);
		Fixed(int const input);
		Fixed(float const input);
		~Fixed();

		Fixed	&operator=(Fixed const &r);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int					value;
		static	int	const	num;
}; 

std::ostream	&operator<<(std::ostream &o, Fixed const &r);

#endif