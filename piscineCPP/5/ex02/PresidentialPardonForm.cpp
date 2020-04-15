#include "PresidentialPardonForm.hpp"

#define gradeToSignPresidential 25
#define gradeToExecutePresidential 5
#define namePresidential "PresidentialPardon"

PresidentialPardonForm::PresidentialPardonForm(void) :
	Form(namePresidential,
		gradeToSignPresidential,
		gradeToExecutePresidential,
		"Anonymous") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	Form(namePresidential,
		gradeToSignPresidential,
		gradeToExecutePresidential,
		target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &s) {
	*this = s;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm 
	&PresidentialPardonForm::operator= (const PresidentialPardonForm &a) {
	Form::operator=(a);
	return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	Form::execute(executor);
	std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox." \
		<< std::endl;
}
