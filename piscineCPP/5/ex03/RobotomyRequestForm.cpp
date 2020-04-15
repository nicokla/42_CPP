#include <ctime>
#include "RobotomyRequestForm.hpp"

#define gradeToSignRobotomy 72
#define gradeToExecuteRobotomy 45
#define nameRobotomy "RobotomyRequest"

bool RobotomyRequestForm::seeded = false;

RobotomyRequestForm::RobotomyRequestForm(void) :
	Form(nameRobotomy,
		gradeToSignRobotomy,
		gradeToExecuteRobotomy,
		"Anonymous") {
	if (!seeded) {
		seeded = true;
		srand(time(NULL));
	}
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	Form(nameRobotomy,
		gradeToSignRobotomy,
		gradeToExecuteRobotomy,
		target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &s) {
	*this = s;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator= (const RobotomyRequestForm &a) {
	Form::operator=(a);
	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	Form::execute(executor);
	if (rand() % 2) {
		std::cout << "* skrr skrr *" << std::endl;
	} else {
		std::cout << "Failing to Drill" << std::endl;
	}
}
