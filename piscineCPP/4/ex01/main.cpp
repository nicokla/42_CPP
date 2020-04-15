#include <iostream>
#include <fstream>
#include <string>
#include "AWeapon.hpp"
#include "Enemy.hpp"
#include "Character.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"

int main() {
	Character* moi = new Character("moi");
	Enemy* scorpion = new RadScorpion();
	Enemy* mutant = new SuperMutant();
	AWeapon* rifle = new PlasmaRifle();
	AWeapon* fist = new PowerFist();

	std::cout << *moi;
	moi->equip(rifle);
	std::cout << *moi;
	moi->equip(fist);
	std::cout << *moi;
	moi->attack(scorpion);
	std::cout << *moi;
	moi->equip(rifle);
	std::cout << *moi;
	moi->attack(scorpion);
	std::cout << *moi;
	moi->attack(scorpion);
	std::cout << *moi;

	moi->recoverAP();
	moi->equip(fist);
	std::cout << *moi;

	moi->attack(mutant);
	moi->attack(mutant);
	moi->attack(mutant);
	moi->attack(mutant);
	std::cout << *moi;

	return 0;
}