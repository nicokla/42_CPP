#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class	NinjaTrap : public ClapTrap {
	public:
		NinjaTrap();
		NinjaTrap(std::string name);
		NinjaTrap(NinjaTrap &obj);
		virtual ~NinjaTrap();
		NinjaTrap &operator=(NinjaTrap const &r);

		void	ninjaShoeBox(ClapTrap &obj);
		void	ninjaShoeBox(FragTrap &obj);
		void	ninjaShoeBox(NinjaTrap &obj);
		void	ninjaShoeBox(ScavTrap &obj);
}; 

#endif