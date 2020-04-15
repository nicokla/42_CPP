#ifndef SUPERTRAP_HPP
#define SUPERTRAP_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class	SuperTrap : virtual public FragTrap, virtual public NinjaTrap {
	public:
		SuperTrap();
		SuperTrap(std::string name);
		SuperTrap(SuperTrap &obj);
		virtual ~SuperTrap();
		SuperTrap &operator=(SuperTrap const &r);
}; 

#endif