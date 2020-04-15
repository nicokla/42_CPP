#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class	Form {
	public:
		class GradeTooLowException : public std::exception {
			public:
				GradeTooLowException();
				GradeTooLowException(const GradeTooLowException &src);
				virtual ~GradeTooLowException(void) throw();
				GradeTooLowException  &operator= (const GradeTooLowException &rhs);
				virtual const char *what() const throw();
		};

		class GradeTooHighException : public std::exception{
			public:
				GradeTooHighException();
				GradeTooHighException(const GradeTooHighException &src);
				virtual ~GradeTooHighException(void) throw();
				GradeTooHighException &operator= (const GradeTooHighException &rhs);
				virtual const char *what() const throw();
		};

		class NotSignedException : public std::exception{
			public:
				NotSignedException();
				NotSignedException(const NotSignedException &src);
				virtual ~NotSignedException(void) throw();
				NotSignedException &operator= (const NotSignedException &rhs);
				virtual const char *what() const throw();
		};

		Form();
		Form(std::string const name, int gradeToSign, 
			int gradeToExecute, std::string const target);
		Form(Form &obj);
		virtual ~Form();
		Form &operator=(Form const &f);

		std::string			getName(void) const;
		bool				getSigned(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;

		void				signForm();
		void				beSigned(Bureaucrat &b);

		void				setTarget(std::string target);
		std::string			getTarget(void) const;

		virtual void		execute(const Bureaucrat &executor) const = 0;

	private:
		std::string	const	name;
		bool				isSigned;
		int	const			gradeToSign;
		int	const			gradeToExecute;
		std::string			target;
}; 

std::ostream	&operator<<(std::ostream &o, Form const &f); 

#endif