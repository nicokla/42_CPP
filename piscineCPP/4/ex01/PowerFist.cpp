#include "PowerFist.hpp"

PowerFist::PowerFist(void) : AWeapon("Power Fist", 8, 50) { }

PowerFist::PowerFist(PowerFist &obj) : AWeapon(obj) {
	*this = obj;
}

PowerFist::~PowerFist() { }

PowerFist &PowerFist::operator=(PowerFist const &r) {
	AWeapon::operator=(r);
	return (*this);
}

void	PowerFist::attack(void) const {
	std::cout << "* pschhh... SBAM! *" << std::endl;
}