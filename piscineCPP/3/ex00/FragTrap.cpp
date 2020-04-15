#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "FragTrap.hpp"

FragTrap::FragTrap(void) : healthPoints(100), maxHealthPoints(100), energyPoints(100), maxEnergyPoints(100), level(1), name("Fragy"), meleeAttackDamage(30), rangeAttackDamage(20), armor(5) {
	std::cout << "Frag_Trap " << this->name << " was created." << std::endl;
}

FragTrap::FragTrap(std::string name) : healthPoints(100), maxHealthPoints(100), energyPoints(100), maxEnergyPoints(100), level(1), name(name), meleeAttackDamage(30), rangeAttackDamage(20), armor(5) {
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
	this->name = r.name;
	this->level = r.level;
	this->healthPoints = r.healthPoints;
	this->maxHealthPoints = r.maxHealthPoints;
	this->energyPoints = r.energyPoints;
	this->maxEnergyPoints = r.maxEnergyPoints;
	this->meleeAttackDamage = r.meleeAttackDamage;
	this->rangeAttackDamage = r.rangeAttackDamage;
	this->armor = r.armor;
	return (*this);
}

void	FragTrap::meleeAttack(std::string const &target) {
	std::cout << "Frag_Trap " << this->name << " attacks " << target << 
		" at melee, causing " << this->meleeAttackDamage << " points of damage !" 
		<< std::endl;
}

void	FragTrap::rangedAttack(std::string const &target) {
	std::cout << "Frag_Trap " << this->name << " attacks " << target << 
		" at range, causing " << this->rangeAttackDamage << " points of damage !" << std::endl;
}

void	FragTrap::rename(std::string input) {
	std::cout << this->name << " is being renamed, meet " << input << "!" << std::endl << std::endl;
	this->name = input;
}

void	FragTrap::displayStats() {
	std::cout << this->name << " stats:" << std::endl <<
		"Level: " << this->level << std::endl <<
		"Health: " << this->healthPoints << "/" << this->maxHealthPoints << std::endl <<
		"Energy: " << this->energyPoints << "/" << this->maxEnergyPoints << std::endl <<
		"Melee Attack: " << this->meleeAttackDamage << std::endl <<
		"Ranged Attack: " << this->rangeAttackDamage << std::endl <<
		"Armor: " << this->armor << std::endl << std::endl;
}

void	FragTrap::takeDamage(unsigned int amount_) {
	int amount = amount_;
	int amount_old = amount;
	amount = std::max(0, amount - armor);
	healthPoints = std::max(0, healthPoints - amount);
	std::cout << "Frag_Trap " << this->name << " took " << amount << " of damage, armor blocked " 
	<< amount_old - amount << " points of damage. Its current health is " << this->healthPoints << "/" << this->maxHealthPoints << std::endl;
	if (this->healthPoints == 0)
		std::cout << this->name << ": I guess I am dead then." << std::endl << std::endl;
	else
		std::cout << this->name << ": It hurts... but I am still alive :D" << std::endl << std::endl;
}


void	FragTrap::beRepaired(unsigned int amount) {
	int old_health = this->healthPoints;
	int healed = 0;

	this->healthPoints += amount;
	if (this->healthPoints > this->maxHealthPoints)
		this->healthPoints = this->maxHealthPoints;
	healed = this->healthPoints - old_health;
	std::cout << "Frag_Trap " << this->name << " recovers " << healed << " health back. Current health is " <<
		this->healthPoints << "/" << this->maxHealthPoints << std::endl;
	if (healed > 0)
		std::cout << "[" << this->name << "] Feels so good :D!" << std::endl << std::endl;
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