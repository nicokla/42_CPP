#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <string>
# include <iostream>

class HumanB {
	public:
		HumanB(std::string);
		~HumanB();
		void attack();
		void setWeapon(Weapon&);

	private:
		Weapon* _weapon;
		std::string name;
};

#endif
