#include <iostream>
#include <fstream>
#include <string>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main() {
	srand(time(NULL));

	FragTrap fragOne;
	ScavTrap scavOne;

	std::cout << std::endl;

	fragOne.meleeAttack("Darth Vaor");
	scavOne.meleeAttack("Voldemort");

	fragOne.rangedAttack("Sauron");
	scavOne.rangedAttack("BadGuy");

	fragOne.takeDamage(30);
	scavOne.takeDamage(30);

	fragOne.beRepaired(10);
	scavOne.beRepaired(10);

	fragOne.displayStats();
	scavOne.displayStats();

	fragOne.vaulthunter_dot_exe("GrosMechant");
	scavOne.challengeNewcomer();
	
	return (0);
}