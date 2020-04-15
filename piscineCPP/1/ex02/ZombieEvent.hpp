#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include <string>
# include <cstdlib>
# include "Zombie.hpp"

class ZombieEvent {
	public:
		ZombieEvent();
		~ZombieEvent();
		void		setZombieType(std::string);
		std::string	getZombieType();
		Zombie		*newZombie(std::string);
		Zombie		*randomChump();

	private:
		std::string  type;
};

#endif
