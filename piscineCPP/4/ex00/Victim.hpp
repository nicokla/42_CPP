#ifndef VICTIM_HPP
#define VICTIM_HPP

#include <string>
#include <iostream>

class Victim {
	public:
		Victim();
		Victim(const Victim &src);
		Victim(std::string name);
		virtual ~Victim();
		Victim		&operator= (const Victim &rhs);
		void		setName(std::string name);
		std::string	getName(void) const;
		virtual void		getPolymorphed(void) const;

	private:
		std::string   name;
};

std::ostream &operator<< (std::ostream &out, const Victim &rhs);

#endif
