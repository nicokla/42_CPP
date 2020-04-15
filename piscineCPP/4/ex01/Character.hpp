#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class	Character {
	public:
		Character();
		Character(std::string const &name);
		Character(Character &obj);
		virtual ~Character();
		Character &operator=(Character const &r);

		void			recoverAP();
		void			equip(AWeapon*);
		void			attack(Enemy*);

		std::string		getName(void) const;
		int				getAP(void) const;
		AWeapon			*getWeapon(void) const;

	private:
		std::string		name;
		AWeapon			*_weapon;
		int				ap;
};

std::ostream &operator<<(std::ostream &o, Character const &r);

#endif