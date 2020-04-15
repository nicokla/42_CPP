#include "Form.hpp"

Form::Form(void) :
	name("Undefined"), isSigned(false), gradeToSign(1),
	gradeToExecute(1), target("Undefined") {}

Form::Form(std::string const name,
			int gradeToSign,
			int gradeToExecute,
			std::string const target) :
	name(name), isSigned(false), gradeToSign(gradeToSign),
	gradeToExecute(gradeToExecute), target(target) 
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form &obj) :
	name(obj.name), isSigned(obj.isSigned),
	gradeToSign(obj.gradeToSign), 
	gradeToExecute(obj.gradeToExecute),
	target(obj.target) {
	*this = obj;
}

Form::~Form() {}

Form &Form::operator=(Form const &f)  {
	this->isSigned = f.isSigned;
	// name and grades are constant so commented out -->
	// this->name = f.name;
	// this->gradeToSign = f.gradeToSign;
	// this->gradeToExecute = f.gradeToExecute;
	this->target = f.target;
	return (*this);
}

void Form::signForm(void)  {
	this->isSigned = true;
}

void Form::beSigned(Bureaucrat &b) {
	if (gradeToSign < b.getGrade()) {
		throw Form::GradeTooLowException();
	}
	isSigned = true;
}

std::string	Form::getName(void) const {
	return (this->name);
}

bool Form::getSigned(void) const {
	return (this->isSigned);
}

int	Form::getGradeToSign(void) const {
	return (this->gradeToSign);
}

int	Form::getGradeToExecute(void) const {
	return	(this->gradeToExecute);
}

std::ostream &operator<<(std::ostream &o, Form const &f) {
	o << "Form Details:" << std::endl
			<< "Name: " << f.getName() << std::endl
			<< "Signing Grade Requirement: " << f.getGradeToSign() << std::endl
			<< "Execution Grade Requirement: " << f.getGradeToExecute() << std::endl;
	if(f.getSigned())
			o << "Form has been signed." << std::endl;
	else
			o << "Form has not been signed yet." << std::endl;
	o << "Form target: " << f.getTarget() << std::endl;
	return (o);
}


void Form::setTarget(std::string target) {
	this->target = target;
	return ;
}

std::string Form::getTarget(void) const {
	return (this->target);
}


void Form::execute(const Bureaucrat& executor) const {
	if (executor.getGrade() > gradeToExecute)
		throw Form::GradeTooLowException();
	else if (!isSigned) 
		throw Form::NotSignedException();
}

//-------------------------
// Grade too high exception

Form::GradeTooHighException::GradeTooHighException() {}

Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const &obj) {
	*this = obj;
}

Form::GradeTooHighException::~GradeTooHighException(void) throw() {}

Form::GradeTooHighException &Form::GradeTooHighException::operator=(GradeTooHighException const &r)  {
	(void)r;
	return (*this);
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Error: Grade too high (<1)");
}


//-------------------------
// Grade too low exception

Form::GradeTooLowException::GradeTooLowException() {}

Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const &obj) {
	*this = obj;
}

Form::GradeTooLowException::~GradeTooLowException(void) throw() {}

Form::GradeTooLowException &Form::GradeTooLowException::operator=(GradeTooLowException const &r)  {
	(void)r;
	return (*this);
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Error: Grade too low (>150)");
}


//-------------------------
// Form not signed exception

Form::NotSignedException::NotSignedException() {}

Form::NotSignedException::NotSignedException(NotSignedException const &obj) {
	*this = obj;
}

Form::NotSignedException::~NotSignedException(void) throw() {}

Form::NotSignedException &Form::NotSignedException::operator=(NotSignedException const &r)  {
	(void)r;
	return (*this);
}

const char* Form::NotSignedException::what() const throw() {
	return ("The form is not signed yet.");
}


