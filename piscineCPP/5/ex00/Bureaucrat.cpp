#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat &obj) {
	*this = obj;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &r) {
	this->grade = r.grade;
	return (*this);
}

std::string Bureaucrat::getName(void) const {
	return (this->name);
}

int Bureaucrat::getGrade(void) const {
	return (this->grade);
}

void Bureaucrat::incrementGrade() {
	if (this->grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade++;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &r) {
	o << r.getName() << ", bureaucrat grade " << r.getGrade() << std::endl;
	return (o);
}

//-------------------------
// Grade too high exception

Bureaucrat::GradeTooHighException::GradeTooHighException() {}

Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const &obj) {
	*this = obj;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw() {}

Bureaucrat::GradeTooHighException &Bureaucrat::GradeTooHighException::operator=(GradeTooHighException const &r)  {
	(void)r;
	return (*this);
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Error: Grade too high (<1)");
}


//-------------------------
// Grade too low exception

Bureaucrat::GradeTooLowException::GradeTooLowException() {}

Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const &obj) {
	*this = obj;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw() {}

Bureaucrat::GradeTooLowException &Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const &r)  {
	(void)r;
	return (*this);
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Error: Grade too low (>150)");
}
