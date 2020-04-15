#include <iostream>
#include <string>
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(Intern const& i) {
	*this = i;
}

Intern& Intern::operator=(Intern const& i) {
	(void)i;
	return *this;
}

Form*   Intern::makeForm(std::string name, std::string target) {
	try {
		if (name == "shrubbery creation") {
			std::cout << "Intern creates " << name << std::endl;
			return new ShrubberyCreationForm(target);
		} else if (name == "robotomy request") {
			std::cout << "Intern creates " << name << std::endl;
			return new RobotomyRequestForm(target);
		} else if (name == "presidential pardon") {
			std::cout << "Intern creates " << name << std::endl;
			return new PresidentialPardonForm(target);
		} else {
			throw InvalidFormException();
		}
	} catch(std::exception& e) {
		std::cerr << "Intern could not create form with name '" 
		<< name << "'." << std::endl
		<< e.what() << std::endl;
	}
	return nullptr;
};


Intern::InvalidFormException::InvalidFormException(InvalidFormException const& e) {
	*this = e;
};

Intern::InvalidFormException& Intern::InvalidFormException::operator=(InvalidFormException const& e) {
	(void)e;
	return *this;
};

const char* Intern::InvalidFormException::what() const throw() {
	return "Exception: Invalid Form Type";
}