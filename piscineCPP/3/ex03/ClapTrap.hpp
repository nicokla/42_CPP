#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>

class	ClapTrap {
	public:
		ClapTrap();
		ClapTrap(std::string name, int level, 
				int healthPoints, int maxHealthPoints,
				int energyPoints, int maxEnergyPoints,
				int meleeAttackDamage,
				int rangeAttackDamage, int armor);
		ClapTrap(ClapTrap &obj);
		virtual ~ClapTrap();
		ClapTrap &operator=(ClapTrap const &r);

		std::string			name;

		void	rangedAttack(std::string const &target);
		void	meleeAttack(std::string const &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		void	rename(std::string input);
		void	displayStats();

		void setStats(std::string name, int level, 
							int healthPoints, int maxHealthPoints,
							int energyPoints, int maxEnergyPoints,
							int meleeAttackDamage,
							int rangeAttackDamage, int armor);

	protected:
		int					healthPoints;
		int					maxHealthPoints;
		int					energyPoints;
		int					maxEnergyPoints;
		int					level;
		int					meleeAttackDamage;
		int					rangeAttackDamage;
		int					armor;
}; 

#endif