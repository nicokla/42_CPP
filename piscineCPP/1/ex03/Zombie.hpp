#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {
	private:
		std::string name;
		std::string type;
	public:
		Zombie(std::string, std::string);
		Zombie();
		~Zombie();
		void announce();

		std::string getName()
		{
			return this->name;
		}

	
		void setName(std::string name)
		{
			this->name = name;
		}

	
		std::string getType()
		{
			return this->type;
		}

	
		void setType(std::string type)
		{
			this->type = type;
		}
};

#endif
