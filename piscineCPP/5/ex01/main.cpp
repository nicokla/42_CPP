#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	Bureaucrat	b("Albert", 50);
	Form		f1("EasyForm", 100, 100);
	Form		f2("HardForm", 1, 1);

	std::cout << b << std::endl;
	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;

	b.signForm(f1);
	b.signForm(f2);
}