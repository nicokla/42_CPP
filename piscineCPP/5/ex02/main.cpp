#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
	Bureaucrat				b("Albert", 1);
	ShrubberyCreationForm	f1;
	RobotomyRequestForm		f2;
	PresidentialPardonForm	f3;

	std::cout << b << std::endl;
	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;
	std::cout << f3 << std::endl;

	b.signForm(f1);
	b.signForm(f2);
	b.signForm(f3);

	b.executeForm(f1);
	b.executeForm(f2);
	b.executeForm(f3);

	// -----------------------
	std::cout << std::endl;

	PresidentialPardonForm f4("Toto");
	Bureaucrat alpha("Alpha Bureaucrat", 1);
	Bureaucrat beta("Beta Bureaucrat", 150);
	
	std::cout << f4 << std::endl;
	std::cout << alpha << std::endl;
	std::cout << beta << std::endl;

	beta.signForm(f4);
	beta.executeForm(f4);
	alpha.signForm(f4);
	alpha.executeForm(f4);
}