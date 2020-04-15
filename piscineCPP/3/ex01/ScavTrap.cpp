#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : healthPoints(100), maxHealthPoints(100), energyPoints(50), maxEnergyPoints(50), level(1), name("Scavy"), meleeAttackDamage(20), rangeAttackDamage(15), armor(3) {
	std::cout << "Scav_Trap " << this->name << " was created." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : healthPoints(100), maxHealthPoints(100), energyPoints(50), maxEnergyPoints(50), level(1), name(name), meleeAttackDamage(20), rangeAttackDamage(15), armor(3) {
	std::cout << "Scav_Trap " << this->name << " was created." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &obj) {
	*this = obj;
	std::cout << "Scav_Trap " << this->name << " was created." << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "Scav_Trap " << this->name << " was destructed." << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &r)  {
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

void	ScavTrap::meleeAttack(std::string const &target) {
	std::cout << "Scav_Trap " << this->name << " attacks " << target << 
		" at melee, causing " << this->meleeAttackDamage << " points of damage !" 
		<< std::endl;
}

void	ScavTrap::rangedAttack(std::string const &target) {
	std::cout << "ScavTrap " << this->name << " attacks " << target << 
		" at range, causing " << this->rangeAttackDamage << " points of damage !" << std::endl;
}

void	ScavTrap::rename(std::string input) {
	std::cout << this->name << " is being renamed, meet " << input << "!" << std::endl << std::endl;
	this->name = input;
}

void	ScavTrap::displayStats() {
	std::cout << this->name << " stats:" << std::endl <<
		"Level: " << this->level << std::endl <<
		"Health: " << this->healthPoints << "/" << this->maxHealthPoints << std::endl <<
		"Energy: " << this->energyPoints << "/" << this->maxEnergyPoints << std::endl <<
		"Melee Attack: " << this->meleeAttackDamage << std::endl <<
		"Ranged Attack: " << this->rangeAttackDamage << std::endl <<
		"Armor: " << this->armor << std::endl << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount_) {
	int amount = amount_;
	int amount_old = amount;
	amount = std::max(0, amount - armor);
	healthPoints = std::max(0, healthPoints - amount);
	std::cout << "Scav_Trap " << this->name << " took " << amount << " of damage, armor blocked " 
	<< amount_old - amount << " points of damage. Its current health is " << this->healthPoints << "/" << this->maxHealthPoints << std::endl;
	if (this->healthPoints == 0)
		std::cout << this->name << ": I guess I am dead then." << std::endl << std::endl;
	else
		std::cout << this->name << ": It hurts... but I am still alive :D" << std::endl << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount) {
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
