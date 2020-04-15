#include "Character.hpp"

Character::Character(std::string const &name) :
 name(name), _weapon(NULL), ap(40) {}

Character::Character(Character &obj) {
	*this = obj;
}

Character::~Character() {}

Character &Character::operator=(Character const &r) {
	this->name = r.name;
	this->_weapon = r._weapon;
	this->ap = r.ap;
	return (*this);
}

std::string Character::getName(void) const {
	return (this->name);
}

int Character::getAP(void) const {
	return (this->ap);
}

AWeapon *Character::getWeapon(void) const {
	return (this->_weapon);
}

void Character::recoverAP() {
	this->ap = this->ap + 10;
	if (this->ap > 40)
		this->ap = 40;
}

void Character::equip(AWeapon *weapon) {
	this->_weapon = weapon;
}

void Character::attack(Enemy *enemy) {
	if(!enemy->getHP())
		return;
	if (this->_weapon) {
		if (this->ap != 0 && (this->ap >= this->_weapon->getAPCost())) {
			std::cout << this->name << " attacks " << enemy->getType() << " with a " << this->_weapon->getName() << std::endl;
			this->_weapon->attack();
			enemy->takeDamage(this->_weapon->getDamage());
			this->ap = this->ap - this->_weapon->getAPCost();
			if (enemy->getHP() <= 0)
				delete enemy;
		}
	}
}

std::ostream &operator<<(std::ostream &o, Character const &r) {
	if (r.getWeapon())
		o << r.getName() << " has " << r.getAP() << " AP and wields a " << r.getWeapon()->getName() << std::endl;
	else
		o << r.getName() << " has " << r.getAP() << " AP and is unarmed" << std::endl;
	return (o);
}