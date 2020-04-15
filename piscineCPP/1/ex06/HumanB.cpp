#include "HumanB.hpp"

HumanB::HumanB(std::string s): name(s) {
}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon& w) {
	this->_weapon = &w;
}

void HumanB::attack() {
	std::cout << this->name << " attacks with his " << this->_weapon->getType();
	std::cout << std::endl;
}
