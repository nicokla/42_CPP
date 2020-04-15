#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(std::string n, std::string t): name(n), type(t) {
	announce();
}

Zombie::~Zombie() {
	std::cout << this->getName() << " has returned back to the underworld and disappeared." << std::endl;
}

void Zombie::announce() {
	std::string format;
	std::string message;

	format = "<" + this->getName() + " (" + this->type + ")> ";
	message = "Braiiiiiiinnnssss...";
	std::cout << (format + message) << std::endl;
}
