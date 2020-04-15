#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	ClapTrap::setStats("Scavy", 1, 100, 100, 50, 50, 20, 15, 3);
	std::cout << "Scav_Trap " << this->name << " was created." << std::endl;
}

ScavTrap::ScavTrap(std::string name) {
	ClapTrap::setStats(name, 1, 100, 100, 50, 50, 20, 15, 3);
	std::cout << "Scav_Trap " << this->name << " was created." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &obj) {
	*this = obj;
	std::cout << "Scav_Trap " << this->name << " was created." << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "Scav_Trap " << this->name << " was destructed." << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &r) {
	ClapTrap::operator=(r);
	return (*this);
}

void	ScavTrap::challengeNewcomer() {
	std::string challenges[] = {
		"say hello to unknown people in the street.",
		"stay on one foot for 1 hour.",
		"drink 3 liters of water straight.",
		"beat me at chess.",
		"lick your elbow."
	};
	int i = rand() % 5;
	std::cout << this->name << " : I challenge you to " << challenges[i] << std::endl;;
}

