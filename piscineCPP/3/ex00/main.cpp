#include <iostream>
#include <fstream>
#include <string>
#include "FragTrap.hpp"

// https://borderlands.fandom.com/wiki/Claptrap/Quotes
int	main() {
	srand(time(NULL));
	FragTrap fragOne;
	fragOne.meleeAttack("Bandits");
	fragOne.rangedAttack("Raiders");
	fragOne.takeDamage(50);
	fragOne.beRepaired(20);
	fragOne.beRepaired(50);
	fragOne.takeDamage(120);
	fragOne.beRepaired(500);
	fragOne.rename("Toto");
	fragOne.beRepaired(20);

	FragTrap fragTwo(fragOne);
	fragTwo.rename("Titi");
	fragTwo.meleeAttack("Toto");
	fragOne.takeDamage(30);

	fragOne.vaulthunter_dot_exe("Darth Vador");
	fragTwo.vaulthunter_dot_exe("Freezer");
	fragOne.vaulthunter_dot_exe("Voldemort");
	fragTwo.vaulthunter_dot_exe("");

	FragTrap fragThree("Toutou");
	std::cout << std::endl;

	fragOne.displayStats();
	fragTwo.displayStats();
	fragThree.displayStats();
	
	return (0);
}