#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <sstream>

class Brain {
	private:
		std::string address;

	public:
		Brain();
		~Brain();
		void setAddress();
		std::string getAddress();
		std::string identify();
};

#endif
