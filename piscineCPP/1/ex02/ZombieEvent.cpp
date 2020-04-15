#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent() {
	this->type = "";
}

ZombieEvent::~ZombieEvent() {
}

void ZombieEvent::setZombieType(std::string type) {
	this->type = type;
}

std::string ZombieEvent::getZombieType() {
	return (this->type);
}

Zombie* ZombieEvent::newZombie(std::string name) {
	return (new Zombie(name, type));
}

Zombie *ZombieEvent::randomChump() {
	Zombie  *zombie;
	std::string names[] = 
	{"Glurp", "Gronf", "Ztroupf", "Gzurg", "Shmurf", "Burpz", "Groups", "Gzirg"};

	if (this->type == "")
		this->setZombieType("ex-human zombie");
	zombie = this->newZombie(names[rand() % 8]);
	return (zombie);
}
