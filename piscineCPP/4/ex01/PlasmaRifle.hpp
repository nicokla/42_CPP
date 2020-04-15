#ifndef PLASMARIFLE_HPP
#define PLASMARIFLE_HPP

#include <iostream>
#include <string>
#include "AWeapon.hpp"

class	PlasmaRifle : public AWeapon {
	public:
		PlasmaRifle();
		PlasmaRifle(PlasmaRifle &obj);
		virtual ~PlasmaRifle();
		PlasmaRifle &operator=(PlasmaRifle const &r);
		void	attack(void) const;
};

#endif