#include "Sorcerer.hpp"

Sorcerer::Sorcerer(const Sorcerer &src) {
	*this = src;
}

Sorcerer::Sorcerer(std::string name, std::string title) {
	this->name = name;
	this->title = title;
	std::cout << this->name << ", " << this->title << ", is born !" \
		<< std::endl;
}

Sorcerer::~Sorcerer() {
	std::cout << this->name << ", " << this->title \
		<< ", is dead. Consequences will never be the same !" \
		<< std::endl;
}

Sorcerer &Sorcerer::operator= (const Sorcerer &rhs) {
	if (this != &rhs) {
		this->name = rhs.name;
		this->title = rhs.title;
	}
	return (*this);
}

std::ostream &operator<< (std::ostream &out, const Sorcerer &rhs) {
	out << "I am " << rhs.getName() << ", " << rhs.getTitle() \
		<< ", and I like ponies ! " << std::endl;
	return (out);
}

void Sorcerer::setName(std::string name) {
	this->name = name;
}

void Sorcerer::setTitle(std::string title) {
	this->title = title;
}

void Sorcerer::polymorph(const Victim &victim) const {
	return (victim.getPolymorphed());
}

std::string Sorcerer::getName(void) const {
	return (this->name);
}

std::string Sorcerer::getTitle(void) const {
	return (this->title);
}
