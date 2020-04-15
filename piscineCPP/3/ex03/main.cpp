#include <iostream>
#include <fstream>
#include <string>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"

int	main() {
	srand(time(NULL));

	FragTrap frag1;
	ScavTrap scav1;

	frag1.rangedAttack("Zombie");
	frag1.meleeAttack("LeGrosMechant");
	frag1.takeDamage(20);
	frag1.beRepaired(10);
	frag1.displayStats();
	frag1.vaulthunter_dot_exe("Sauron");

	scav1.rangedAttack("Dark Vador");
	scav1.meleeAttack("Empereur Zorg");
	scav1.takeDamage(20);
	scav1.beRepaired(5);
	scav1.displayStats();
	scav1.challengeNewcomer();

	FragTrap frag2(frag1);
	frag2.rename("TrapiTrapo");

	ScavTrap scav2(scav1);
	scav2.rename("ScaviScavo");

	NinjaTrap ninja1("NinjiNinjo");
	ninja1.ninjaShoeBox(frag2);
	ninja1.ninjaShoeBox(scav2);

	NinjaTrap ninja2;
	ninja2.ninjaShoeBox(ninja1);

	ClapTrap clap1("ClapiClapo", 1, 87, 87, 38, 38, 30, 20, 5);
	ninja2.ninjaShoeBox(clap1);

	return (0);
}