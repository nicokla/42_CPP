#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include <iostream>

int main() {
	srand(time(NULL));

	Zombie *zombie0, *zombie1, *zombie2;
	ZombieEvent event;

	zombie0 = event.randomChump();

	event.setZombieType("ex-cat zombie");
	zombie1 = event.randomChump();

	event.setZombieType("ex-dog zombie");
	zombie2 = event.randomChump();

	delete zombie0;
	delete zombie1;
	delete zombie2;

	return (0);
}
