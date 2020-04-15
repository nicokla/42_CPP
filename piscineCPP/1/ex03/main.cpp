#include "Zombie.hpp"
#include "ZombieHorde.hpp"
#include <iostream>

int main() {
	srand(time(NULL));
	ZombieHorde horde = ZombieHorde(10);
	horde.announce();
	return (0);
}
