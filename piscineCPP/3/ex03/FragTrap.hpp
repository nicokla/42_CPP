#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "ClapTrap.hpp"

class	FragTrap : public ClapTrap {
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap &obj);
		virtual ~FragTrap();
		FragTrap &operator=(FragTrap const &r);

		void	vaulthunter_dot_exe(std::string const &target);
		void	spoonAttack(std::string const &target);
		void	pillowAttack(std::string const &target);
		void	cheddarAttack(std::string const &target);
		void	rickrollAttack(std::string const &target);
		void	potatoAttack(std::string const &target);

	// private:
}; 

#endif