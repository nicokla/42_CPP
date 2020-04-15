#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cmath>

class	Fixed {
	public:
		Fixed();
		Fixed(Fixed const &input);
		Fixed(int const input);
		Fixed(float const input);
		~Fixed();

		int			getRawBits(void) const;
		void		setRawBits(int const raw);

		float		toFloat(void) const;
		int			toInt(void) const;

		Fixed 		&operator=(Fixed const &r);

		bool		operator>(Fixed const &r);
		bool		operator<(Fixed const &r);
		bool		operator>=(Fixed const &r);
		bool		operator<=(Fixed const &r);
		bool		operator==(Fixed const &r);
		bool		operator!=(Fixed const &r);

		Fixed 		operator+(Fixed const &r);
		Fixed 		operator-(Fixed const &r);
		Fixed 		operator*(Fixed const &r);
		Fixed 		operator/(Fixed const &r);

		Fixed 		&operator++();
		Fixed		operator++(int input);
		Fixed 		&operator--();
		Fixed		operator--(int input);

		static Fixed		&min(Fixed 	 	 &l, Fixed 		 &r);
		static Fixed		&max(Fixed 	 	 &l, Fixed 		 &r);
		static Fixed const	&min(Fixed const &l, Fixed const &r);
		static Fixed const	&max(Fixed const &l, Fixed const &r);

	private:
		int					value;
		static	int	const	num;
}; 

std::ostream	&operator<<(std::ostream &o, Fixed const &r);

#endif