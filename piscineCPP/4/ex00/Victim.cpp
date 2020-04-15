#include "Victim.hpp"

Victim::Victim() {
	this->name = "Joe";
	std::cout << "Some random victim called " << this->name \
		<< " just popped !" << std::endl;
}

Victim::Victim(std::string name) {
	this->name = name;
	std::cout << "Some random victim called " << this->name \
		<< " just popped !" << std::endl;
}

Victim::Victim(const Victim &src) {
	*this = src;
}

Victim::~Victim() {
	std::cout << "Victim " << this->name \
		<< " just died for no apparent reason !" << std::endl;
}

Victim &Victim::operator= (const Victim &rhs) {
	if (this != &rhs) {
		this->name = rhs.name;
	}
	return (*this);
}

std::ostream &operator<< (std::ostream &out, const Victim &rhs) {
	out << "I am " << rhs.getName() << ", and I like otters ! " \
		<< std::endl;
	return (out);
}

std::string Victim::getName(void) const {
	return (this->name);
}

void Victim::getPolymorphed(void) const {
	std::cout << this->name << " has been turned into a cute little sheep !" \
		<< std::endl;
}

void Victim::setName(std::string name) {
	this->name = name;
}
