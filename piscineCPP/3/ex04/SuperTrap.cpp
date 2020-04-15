#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "SuperTrap.hpp"
#include "ClapTrap.hpp"

SuperTrap::SuperTrap(void) : 
ClapTrap("Supy", 1, 100, 100, 120, 120, 60, 20, 5) {
	std::cout << "Super_Trap " << this->name << " was created." << std::endl;
}

SuperTrap::SuperTrap(std::string name) :
ClapTrap(name, 1, 100, 100, 120, 120, 60, 20, 5) {
	std::cout << "Super_Trap " << this->name << " was created." << std::endl;
}

SuperTrap::SuperTrap(SuperTrap &obj) {
	*this = obj;
	std::cout << "Super_Trap " << this->name << " was created." << std::endl;
}

SuperTrap::~SuperTrap() {
	std::cout << "Super_Trap " << this->name << " was destructed." << std::endl;
}

SuperTrap &SuperTrap::operator=(SuperTrap const &r) {
	ClapTrap::operator=(r);
	return (*this);
}

