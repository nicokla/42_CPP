#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class	PresidentialPardonForm : public Form {
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &obj);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm &operator=(PresidentialPardonForm const &r);
		void	execute(Bureaucrat const &executor) const;
}; 

#endif
