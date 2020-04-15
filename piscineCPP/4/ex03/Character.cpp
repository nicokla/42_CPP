#include "Character.hpp"

Character::Character() {}

Character::Character(const std::string name):
    name(name) {
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

Character::~Character() {
    for (int i = 0; i < 4; i++)
        delete inventory[i];
}

Character::Character(const Character &c):
    name(c.name) {
    for (int i = 0; i < 4; i++)
        inventory[i] = c.inventory[i]->clone();
}

Character &Character::operator=(const Character &c) {
    for (int i = 0; i < 4; i++)
        delete inventory[i];
    for (int i = 0; i < 4; i++)
        inventory[i] = c.inventory[i]->clone();
    name = c.name;
    return *this;
}

const std::string &Character::getName() const {
    return name;
}

void Character::equip(AMateria *m) {
    int i = 0;
    while(inventory[i] != NULL
			&& i < 4
			&& inventory[i] != m)
        i++;
	if (i < 4)
   		inventory[i] = m;
}

void Character::unequip(int i) {
    if (i < 0 || i > 3 || !inventory[i])
        return;
    inventory[i] = NULL;
}

void Character::use(int i, ICharacter &target) {
    if (i < 0 || i > 3 || !inventory[i])
        return;
    inventory[i]->use(target);
}
