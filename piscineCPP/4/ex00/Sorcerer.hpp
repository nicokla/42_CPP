#ifndef SORCERER_HPP
#define SORCERER_HPP

#include <string>
#include <iostream>
#include "Victim.hpp"

class Sorcerer {
	public:
		Sorcerer();
		Sorcerer(const Sorcerer &src);
		Sorcerer(std::string name, std::string title);
		virtual ~Sorcerer();
		Sorcerer &operator= (const Sorcerer &rhs);
		void			setName(std::string name);
		void			setTitle(std::string title);
		void			polymorph(Victim const &victim) const;
		std::string		getName(void) const;
		std::string		getTitle(void) const;

	private:
		std::string  name;
		std::string  title;
};

std::ostream &operator<< (std::ostream &out, const Sorcerer &rhs);

#endif
