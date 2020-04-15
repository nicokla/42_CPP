#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>

class	ScavTrap {
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap &obj);
		virtual ~ScavTrap();
		ScavTrap &operator=(ScavTrap const &r);

		void	rangedAttack(std::string const &target);
		void	meleeAttack(std::string const &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		void	rename(std::string input);
		void	displayStats();

		void	challengeNewcomer();

	private:
		int					healthPoints;
		int					maxHealthPoints;
		int					energyPoints;
		int					maxEnergyPoints;
		int					level;
		std::string			name;
		int					meleeAttackDamage;
		int					rangeAttackDamage;
		int					armor;
}; 

#endif