#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "FragTrap.hpp"

FragTrap::FragTrap() {
	ClapTrap::setStats("Fragy", 1, 100, 100, 100, 100, 30, 20, 5);
	std::cout << "Frag_Trap " << this->name << " was created." << std::endl;
}

FragTrap::FragTrap(std::string name) {
	ClapTrap::setStats(name, 1, 100, 100, 100, 100, 30, 20, 5);
	std::cout << "Frag_Trap " << this->name << " was created." << std::endl;
}

FragTrap::FragTrap(FragTrap &obj) {
	*this = obj;
	std::cout << "Frag_Trap " << this->name << " was created." << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "Frag_Trap " << this->name << " was destructed." << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &r)  {
	ClapTrap::operator=(r);
	return (*this);
}

void	FragTrap::vaulthunter_dot_exe(std::string const &target) {
	void (FragTrap::*ptr[])(std::string const &) = {
		&FragTrap::spoonAttack,
		&FragTrap::pillowAttack,
		&FragTrap::cheddarAttack,
		&FragTrap::rickrollAttack,
		&FragTrap::potatoAttack
	};

	if (this->energyPoints < 25) {
		std::cout << "Frag_Trap " << this->name << " does not have enough energy points! Current energy " <<
			this->energyPoints << "/" << this->maxEnergyPoints << std::endl << std::endl;
	} else {
		this->energyPoints = this->energyPoints - 25;
		std::cout << "Frag_Trap " << this->name << " uses VaultHunter.Exe!!!" << std::endl;
		(this->*ptr[rand() % 5])(target);
	}
}

void	FragTrap::spoonAttack(std::string const &target) {
	std::cout << "Frag_Trap " << this->name << " attacks " << target << " with a spoon." <<
		std::endl;
}

void	FragTrap::pillowAttack(std::string const &target) {
	std::cout << "Frag_Trap " << this->name << " attacks " << target << " with a pillow." <<
		std::endl;
}

void	FragTrap::cheddarAttack(std::string const &target) {
	std::cout << "Frag_Trap " << this->name << " attacks " << target << " with a slice of cheddar." <<
		std::endl;
}

void	FragTrap::rickrollAttack(std::string const &target) {
	std::cout << "Frag_Trap " << this->name << " attacks " << target << " using a rickroll." <<
		std::endl;
}

void	FragTrap::potatoAttack(std::string const &target) {
	std::cout << "Frag_Trap " << this->name << " attacks " << target << " with a potato." <<
		std::endl;
}