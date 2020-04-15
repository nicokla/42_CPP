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

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &b) {
	this->grade = b.grade;
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

std::ostream &operator<<(std::ostream &o, Bureaucrat const &b) {
	o << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return (o);
}


void Bureaucrat::setGrade(int grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade = grade;
}

void Bureaucrat::signForm(Form &form) {
	try {
		form.beSigned(*this);
		// std::cout << this->name << " signs " << form.getName() << std::endl;
	} catch (std::exception& e) {
		// std::cout << this->name << " cannot sign " << form.getName()
		// 	<< " because " << e.what() << std::endl;
	}
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
