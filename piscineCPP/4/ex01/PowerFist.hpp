#ifndef POWERFIST_HPP
#define POWERFIST_HPP

#include <iostream>
#include <string>
#include "AWeapon.hpp"

class	PowerFist : public AWeapon {
	public:
		PowerFist();
		PowerFist(PowerFist &obj);
		virtual ~PowerFist();
		PowerFist &operator=(PowerFist const &r);
		void	attack(void) const;
};

#endif