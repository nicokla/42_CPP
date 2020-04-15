#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

# include <string>
# include <iostream>
# include "Zombie.hpp"

class ZombieHorde {
	private:
		Zombie *horde;
		int number;
	public:
		ZombieHorde(int);
		~ZombieHorde();
		void announce();
		std::string randomName();
};

#endif
