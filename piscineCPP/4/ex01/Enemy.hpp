#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>

class	Enemy {
	public:
		Enemy();
		Enemy(int hp, std::string const &type);
		Enemy(Enemy &obj);
		virtual ~Enemy();
		Enemy &operator=(Enemy const &r);

		std::string		getType(void) const;
		int				getHP(void) const;
		void			setHP(int i);

		virtual void	takeDamage(int);

	private:
		int				hp;
		std::string		type;
};

#endif