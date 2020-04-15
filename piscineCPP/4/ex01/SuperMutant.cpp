#include "SuperMutant.hpp"

SuperMutant::SuperMutant(void) : Enemy(170, "Super Mutant") {
	std::cout << "Gaaah. Break everything!" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant &obj) : Enemy(obj) {
	*this = obj;
	std::cout << "Gaaah. Break everything!" << std::endl;
}

SuperMutant::~SuperMutant() {
	std::cout << "Aaargh ..." << std::endl;
}

SuperMutant &SuperMutant::operator=(SuperMutant const &r)  {
	Enemy::operator=(r);
	return (*this);
}

void SuperMutant::takeDamage(int amount) {
	Enemy::takeDamage(amount - 3);
}