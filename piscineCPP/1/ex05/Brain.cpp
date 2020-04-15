#include "Brain.hpp"

Brain::Brain() {
	setAddress();
}

Brain::~Brain() {}

void Brain::setAddress() {
	std::stringstream   buff;

	buff << this;
	this->address = buff.str();
}

std::string Brain::identify() {
	return (this->address);
}
