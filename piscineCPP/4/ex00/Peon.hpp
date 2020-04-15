#ifndef PEON_HPP
#define PEON_HPP

#include <string>
#include <iostream>
#include "Victim.hpp"

class Peon : public Victim {
	public:
		Peon();
		Peon(const Peon &src);
		Peon(std::string name);
		virtual ~Peon();
		Peon &operator= (const Peon &rhs);
		virtual void getPolymorphed(void) const;

	private:
		std::string name;
};

#endif
