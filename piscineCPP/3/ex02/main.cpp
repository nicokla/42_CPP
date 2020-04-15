#include <iostream>
#include <fstream>
#include <string>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int	main() {
	srand(time(NULL));
	
	FragTrap fragOne("titi");
	ScavTrap scavOne;

	std::cout << std::endl;

	fragOne.meleeAttack("Dark Sidious");
	scavOne.meleeAttack("Baby Zombie");

	fragOne.rangedAttack("Dog Zombie");
	scavOne.rangedAttack("Fat Zombie");

	fragOne.takeDamage(30);
	scavOne.takeDamage(30);

	fragOne.beRepaired(10);
	scavOne.beRepaired(10);

	fragOne.displayStats();
	scavOne.displayStats();

	fragOne.vaulthunter_dot_exe("NiarkNiarkMan");
	scavOne.challengeNewcomer();

	FragTrap fragTwo(fragOne);
	ScavTrap scavtwo(scavOne);
	
	return (0);
}