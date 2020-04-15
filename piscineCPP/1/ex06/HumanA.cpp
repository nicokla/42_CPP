#include "HumanA.hpp"

HumanA::HumanA(std::string s, Weapon& w): name(s), _weapon(w) {}

HumanA::~HumanA() {}

void HumanA::attack() {
	std::cout << this->name << " attacks with his " << this->_weapon.getType();
	std::cout << std::endl;
}
