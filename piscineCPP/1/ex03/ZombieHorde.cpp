#include "Zombie.hpp"
#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n): number(n) {
	this->horde = new Zombie[n];
	for (int i = 0; i < this->number; i++) {
		this->horde[i].setType("Horde Zombie");
		this->horde[i].setName(randomName());
	}
}

ZombieHorde::~ZombieHorde() {
	delete [] this->horde;
}

std::string ZombieHorde::randomName() {
	std::string names[] = 
	{"Glurp", "Gronf", "Ztroupf", "Gzurg", "Shmurf", "Burpz", "Groups", "Gzirg"};
	return (names[rand() % 8]);
}

void ZombieHorde::announce() {
	for (int i = 0; i < this->number; i++) {
		this->horde[i].announce();
	}
}
