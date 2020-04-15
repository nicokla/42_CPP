#include "Phonebook.hpp"

Phonebook::Phonebook() {
	this->size = 0;
}

Phonebook::~Phonebook() {
}

void Phonebook::add() {
	std::string response = " ";

	if (this->size >= MAX) {
		std::cout << "Sorry you have too many contacts, you cannot add more." << std::endl;
		return ;
	}
	std::cout << "Please enter the following details for contact:" << std::endl;
	
	std::cout << "> First Name: ";
	std::getline(std::cin, response);
	this->contacts[this->size].setFirstname(response);

	std::cout << "> Last Name: ";
	std::getline(std::cin, response);
	this->contacts[this->size].setLastname(response);

	std::cout << "> Nickname: ";
	std::getline(std::cin, response);
	this->contacts[this->size].setNickname(response);

	std::cout << "> Login: ";
	std::getline(std::cin, response);
	this->contacts[this->size].setLogin(response);

	std::cout << "> Postal Address: ";
	std::getline(std::cin, response);
	this->contacts[this->size].setAddress(response);

	std::cout << "> Email Address: ";
	std::getline(std::cin, response);
	this->contacts[this->size].setEmail(response);

	std::cout << "> Phone Number: ";
	std::getline(std::cin, response);
	this->contacts[this->size].setPhone(response);

	std::cout << "> Birthday Date: ";
	std::getline(std::cin, response);
	this->contacts[this->size].setBirthday(response);

	std::cout << "> Favorite Meal: ";
	std::getline(std::cin, response);
	this->contacts[this->size].setMeal(response);

	std::cout << "> Underwear Color: ";
	std::getline(std::cin, response);
	this->contacts[this->size].setUnderwearColor(response);

	std::cout << "> Darkest Secret: ";
	std::getline(std::cin, response);
	this->contacts[this->size].setDarkestSecret(response);

	std::cout << " * * * " << std::endl;
	std::cout << "You've successfully added " << this->contacts[this->size].getFirstname()
				<< " " << this->contacts[this->size].getLastname() << std::endl;
	std::cout << " * * * " << std::endl;

	this->size++;
}

void		Phonebook::tryDisplayContact(std::string response) {
	int a;

	try {
    	a = std::stoi(response);
		if (a >= 1 && a <= this->size)
			this->contacts[a-1].display_info();
		else
			std::cout << "Sorry, that index number is invalid." << std::endl;
	}
	catch (const std::invalid_argument& ia) {
		std::cout << "Could not parse the index number." << std::endl;
	}
}

std::string	Phonebook::shortenIfNeeded(std::string input) {
	int a = input.length();

	if (a > 10) {
		input.erase(9, a);
		return (input + ".");
	}
	while (a++ < 10)
		input += " ";
	return (input);
}

void Phonebook::search() {
	int i = 0;
	std::string output;
	std::string response;

	if (this->size == 0) {
		std::cout << "Sorry, there are no contacts here." << std::endl;
		return ;
	}
	std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
	while (i < this->size)
	{
		std::cout << "|         " << (i + 1) << "|";
		output = shortenIfNeeded(this->contacts[i].getFirstname());
		std::cout << output << "|";
		output = shortenIfNeeded(this->contacts[i].getLastname());
		std::cout << output << "|";
		output = shortenIfNeeded(this->contacts[i].getNickname());
		std::cout << output << "|" << std::endl;
		i++;
	}
	std::cout << std::endl;
	std::cout << "Which contact would you like to look at ? Please enter his index number." << std::endl;
	std::cout << "> ";
	std::getline(std::cin, response);
	tryDisplayContact(response);
}

int Phonebook::areYouSure() {
	std::string response = " ";

	std::cout << "Are you sure you want to exit? Nothing will be saved." << std::endl;
	std::cout << "Please enter YES to exit program, all other input will not quit." << std::endl;
	std::cout << "> ";
	std::getline(std::cin, response);
	if (response.compare("YES") == 0) {
		std::cout << "Goodbye :(" << std::endl;
		return 1;
	}
	return 0;
}

int Phonebook::processInput(std::string input) {
	if (input.compare("EXIT") == 0) {
		return this->areYouSure();
	} else if (input.compare("ADD") == 0) {
		this->add();
		return 0;
	} else if (input.compare("SEARCH") == 0) {
		this->search();
		return 0;
	}
	else
		return 0;
}

void Phonebook::interactLoop(){
	std::string input = " ";

	std::cout << "Welcome to your awesome phonebook!" << std::endl;
	while (1) {
		std::cout << "What would you like to do ?" << std::endl;
		std::cout << "Commands: ADD - SEARCH - EXIT" << std::endl;
		std::cout << "> ";
		std::getline(std::cin, input);
		if (std::cin.eof()) {
			std::cout << "CTRL + D pressed, ending program. Good bye." << std::endl;
			break ;
		}
		if (this->processInput(input))
			break ;
	}
}