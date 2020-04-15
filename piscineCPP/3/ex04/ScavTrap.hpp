#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap &obj);
		virtual ~ScavTrap();
		ScavTrap &operator=(ScavTrap const &r);

		void	challengeNewcomer();

	// private:
}; 

#endif