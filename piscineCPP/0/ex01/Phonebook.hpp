#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include "Contact.hpp"

#define MAX 8

class	Phonebook {
	public:
		Phonebook(); 
		~Phonebook();
		void interactLoop();
		void add();
		void search();

	private:
		Contact		contacts[MAX];
		int			size;
		int			processInput(std::string input);
		int			areYouSure();
		void		tryDisplayContact(std::string response);
		std::string shortenIfNeeded(std::string input);
}; 

#endif