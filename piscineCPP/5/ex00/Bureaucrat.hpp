#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
class	Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat &obj);
		virtual ~Bureaucrat();
		Bureaucrat &operator=(Bureaucrat const &r);

		void incrementGrade();
		void decrementGrade();

		std::string			getName() const;
		int					getGrade() const;

		class GradeTooHighException : public std::exception {
			public:	
				GradeTooHighException();
				GradeTooHighException(GradeTooHighException const &obj);
				virtual ~GradeTooHighException(void) throw();
				GradeTooHighException &operator=(GradeTooHighException const &r);
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				GradeTooLowException();
				GradeTooLowException(GradeTooLowException const &obj);
				virtual ~GradeTooLowException(void) throw();
				GradeTooLowException &operator=(GradeTooLowException const &r);
				virtual const char* what() const throw();
		};

	private:
		std::string const	name;
		int					grade;
}; 

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &r); 

#endif