#ifndef PONY_HPP
#define PONY_HPP

#include <string>

class Pony {
	private:
		std::string name;

	public:
		Pony(std::string name);
		~Pony();

		std::string getName()
		{
			return this->name;
		}

		void setName(std::string name)
		{
			this->name = name;
		}
};

#endif
