#include "Weapon.hpp"

Weapon::Weapon(std::string t): type(t) {
}

Weapon::~Weapon() {
}

void Weapon::setType(std::string str) {
	this->type = str;
}

const std::string& Weapon::getType() {
	return (this->type);
}
