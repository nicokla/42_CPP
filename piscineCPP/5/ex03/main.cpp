#include <iostream>
#include <string>
#include "Intern.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
	Intern i;
	Form* f;

	f = i.makeForm("robotomy request", "Albert");
	f = i.makeForm("shrubbery creation", "Toto");
	f = i.makeForm("presidential pardon", "Titi");
	f = i.makeForm("non existing form", "Toutou");
}