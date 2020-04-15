
#ifndef RADSCORPION_HPP
#define RADSCORPION_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "Enemy.hpp"

class	RadScorpion : public Enemy {
	public:
		RadScorpion();
		RadScorpion(RadScorpion &obj);
		~RadScorpion();
		RadScorpion &operator=(RadScorpion const &r);
};

#endif