#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class Form;

class	Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat &obj);
		virtual ~Bureaucrat();
		Bureaucrat &operator=(Bureaucrat const &b);

		std::string			getName() const;
		int					getGrade() const;

		void incrementGrade();
		void decrementGrade();
		void setGrade(int grade);
		void signForm(Form &form);
		void executeForm(Form const& form);

		class GradeTooHighException : public std::exception {
			public:	
				GradeTooHighException();
				GradeTooHighException(GradeTooHighException const &obj);
				virtual ~GradeTooHighException(void) throw();
				GradeTooHighException &operator=(GradeTooHighException const &e);
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				GradeTooLowException();
				GradeTooLowException(GradeTooLowException const &obj);
				virtual ~GradeTooLowException(void) throw();
				GradeTooLowException &operator=(GradeTooLowException const &e);
				virtual const char* what() const throw();
		};

	private:
		std::string const	name;
		int					grade;
}; 

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &b); 

#endif