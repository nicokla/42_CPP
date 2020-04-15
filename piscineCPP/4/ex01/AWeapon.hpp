#ifndef AWEAPON_HPP
#define AWEAPON_HPP

#include <iostream>
#include <string>

class AWeapon {
	public:
		AWeapon();
		AWeapon(std::string const &name, int apcost, int damage);
		AWeapon(AWeapon &obj);
		virtual ~AWeapon();
		AWeapon &operator=(AWeapon const &r);

		virtual void attack() const = 0;

		std::string	getName() const;
		int	getDamage() const;
		int getAPCost() const;

	private:
		std::string name;
		int	dmg;
		int	ap;
};

#endif