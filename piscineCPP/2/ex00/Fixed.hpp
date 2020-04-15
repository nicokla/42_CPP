#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>

class	Fixed  {
	public:
		Fixed();
		Fixed(Fixed const &input);
		~Fixed();

		Fixed	&operator=(Fixed const &r);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int					value;
		static	int	const	num;
}; 

#endif