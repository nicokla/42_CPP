#include "Peon.hpp"

Peon::Peon() {
	this->name = "Bob";
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(std::string name) {
	this->name = name;
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(const Peon &src) {
	*this = src;
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon() {
	std::cout << "Bleuark..." << std::endl;
}

Peon &Peon::operator= (const Peon &rhs) {
	if (this != &rhs) {
		this->name = rhs.name;
	}
	return (*this);
}

void Peon::getPolymorphed(void) const {
	std::cout << this->name << " has been turned into a pink pony !" \
		<< std::endl;
}
