#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("Clapy"), healthPoints(100), maxHealthPoints(100), energyPoints(100), maxEnergyPoints(100), level(1), meleeAttackDamage(30), rangeAttackDamage(20), armor(5) {
	std::cout << "Clap_Trap " << this->name << " was created." << std::endl;
}

ClapTrap::ClapTrap(std::string name, int level, 
							int healthPoints, int maxHealthPoints,
							int energyPoints, int maxEnergyPoints,
							int meleeAttackDamage,
							int rangeAttackDamage, int armor) :
	name(name), healthPoints(healthPoints), maxHealthPoints(maxHealthPoints),
	energyPoints(energyPoints), maxEnergyPoints(maxEnergyPoints), level(level),
	meleeAttackDamage(meleeAttackDamage), rangeAttackDamage(rangeAttackDamage), 
	armor(armor) {}

ClapTrap::ClapTrap(ClapTrap &obj) {
	*this = obj;
	std::cout << "Clap_Trap " << this->name << " was created." << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "Clap_Trap " << this->name << " was destructed." << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &r) {
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

void	ClapTrap::meleeAttack(std::string const &target) {
	std::cout << "Clap_Trap " << this->name << " attacks " << target << 
		" at melee, causing " << this->meleeAttackDamage << " points of damage !" 
		<< std::endl;
}

void	ClapTrap::rangedAttack(std::string const &target) {
	std::cout << "ClapTrap " << this->name << " attacks " << target << 
		" at range, causing " << this->rangeAttackDamage << " points of damage !" << std::endl;
}

void	ClapTrap::rename(std::string input) {
	std::cout << this->name << " is being renamed, meet " << input << "!" << std::endl << std::endl;
	this->name = input;
}

void	ClapTrap::displayStats() {
	std::cout << this->name << " stats:" << std::endl <<
		"Level: " << this->level << std::endl <<
		"Health: " << this->healthPoints << "/" << this->maxHealthPoints << std::endl <<
		"Energy: " << this->energyPoints << "/" << this->maxEnergyPoints << std::endl <<
		"Melee Attack: " << this->meleeAttackDamage << std::endl <<
		"Ranged Attack: " << this->rangeAttackDamage << std::endl <<
		"Armor: " << this->armor << std::endl << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount_) {
	int amount = amount_;
	int amount_old = amount;
	amount = std::max(0, amount - armor);
	healthPoints = std::max(0, healthPoints - amount);
	std::cout << "Clap_Trap " << this->name << " took " << amount << " of damage, armor blocked " 
	<< amount_old - amount << " points of damage. Its current health is " << this->healthPoints << "/" << this->maxHealthPoints << std::endl;
	if (this->healthPoints == 0)
		std::cout << this->name << ": I guess I am dead then." << std::endl << std::endl;
	else
		std::cout << this->name << ": It hurts... but I am still alive :D" << std::endl << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
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
