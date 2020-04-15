#ifndef SUPERMUTANT_HPP
#define SUPERMUTANT_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "Enemy.hpp"

class	SuperMutant : public Enemy {
	public:
		SuperMutant();
		SuperMutant(SuperMutant &obj);
		~SuperMutant();
		SuperMutant &operator=(SuperMutant const &r);

		virtual void		takeDamage(int damage);
};

#endif