#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

int main() {
	Bureaucrat albert("Albert", 6);

	albert.getName();
	albert.getGrade();
	std::cout << albert << std::endl;
	while (true) {
		try {
			albert.incrementGrade();
		} catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
			break;
		}
		std::cout << albert << std::endl;
	}
}