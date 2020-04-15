#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>

class	FragTrap {
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap &obj);
		virtual ~FragTrap();
		FragTrap &operator=(FragTrap const &r);

		void	rangedAttack(std::string const &target);
		void	meleeAttack(std::string const &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		void	rename(std::string input);
		void	displayStats();

		void	vaulthunter_dot_exe(std::string const &target);
		void	spoonAttack(std::string const &target);
		void	pillowAttack(std::string const &target);
		void	cheddarAttack(std::string const &target);
		void	rickrollAttack(std::string const &target);
		void	potatoAttack(std::string const &target);

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