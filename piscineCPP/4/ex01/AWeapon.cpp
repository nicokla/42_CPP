#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const &name, int apcost, int damage) :
name(name), dmg(damage), ap(apcost) { }

AWeapon::AWeapon(AWeapon &obj) {
	*this = obj;
}

AWeapon::~AWeapon(){
}

AWeapon &AWeapon::operator=(AWeapon const &r) {
	this->name = r.name;
	this->ap = r.ap;
	this->dmg = r.dmg;
	return (*this);
}

std::string		AWeapon::getName() const {
	return (this->name);
}

int	AWeapon::getDamage() const {
	return (this->dmg);
}

int	AWeapon::getAPCost() const {
	return (this->ap);
}
