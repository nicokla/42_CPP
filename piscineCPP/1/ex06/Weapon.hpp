#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon {
	public:
		Weapon(std::string);
		~Weapon();
		void setType(std::string);
		const std::string& getType();

	private:
		std::string type;
};

#endif
