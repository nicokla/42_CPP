#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "NinjaTrap.hpp"
#include "ClapTrap.hpp"

NinjaTrap::NinjaTrap(void) :
ClapTrap("Ninjy", 1, 60, 60, 120, 120, 60, 5, 0) {
	std::cout << "Ninja_Trap " << this->name << " was created." << std::endl;
}

NinjaTrap::NinjaTrap(std::string name) :
ClapTrap(name, 1, 60, 60, 120, 120, 60, 5, 0) {
	std::cout << "Ninja_Trap " << this->name << " was created." << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap &obj) {
	*this = obj;
	std::cout << "Ninja_Trap " << this->name << " was created." << std::endl;
}

NinjaTrap::~NinjaTrap() {
	std::cout << "Ninja_Trap " << this->name << " was destructed." << std::endl;
}

NinjaTrap &NinjaTrap::operator=(NinjaTrap const &r) {
	ClapTrap::operator=(r);
	return (*this);
}

void	NinjaTrap::ninjaShoeBox(ClapTrap &obj) {
	std::cout << this->name << " sent a shoe on Clap_Trap " << obj.name << "." << std::endl;
	obj.takeDamage(10);
}

void	NinjaTrap::ninjaShoeBox(FragTrap &obj) {
	std::cout << this->name << " sent a banana on Frag_Trap " << obj.name << "." << std::endl;
	obj.takeDamage(3);
}

void	NinjaTrap::ninjaShoeBox(NinjaTrap &obj) {
	std::cout << this->name << " sent an orange on Ninja_Trap " << obj.name << "." << std::endl;
	obj.takeDamage(8);
}

void	NinjaTrap::ninjaShoeBox(ScavTrap &obj) {
	std::cout << this->name << " sent a tomatoe on Scav_Trap " << obj.name << "." << std::endl;
	obj.takeDamage(9);
}