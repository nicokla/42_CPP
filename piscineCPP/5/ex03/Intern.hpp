#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class	Intern {
	public:
		Intern() {};
		Intern(Intern const &obj);
		virtual ~Intern() {};
		Intern &operator=(Intern const &f);
		Form* makeForm(std::string name, std::string target);

		class InvalidFormException : public std::exception {
			public:
				InvalidFormException() {};
				InvalidFormException(InvalidFormException const& rhs);
				InvalidFormException& operator=(InvalidFormException const& rhs);
				virtual ~InvalidFormException() throw() {};
				virtual const char* what() const throw();
		};
}; 


#endif