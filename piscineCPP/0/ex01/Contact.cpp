#include "Contact.hpp"

Contact::Contact() {
}

Contact::~Contact() {
}

void		Contact::display_info() {
	std::cout << "First Name: " << this->firstname << std::endl;
	std::cout << "Last Name: " << this->lastname << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Login: " << this->login << std::endl;
	std::cout << "Postal Address: " << this->address << std::endl;
	std::cout << "Email Address: " << this->email << std::endl;
	std::cout << "Phone Number: " << this->phone << std::endl;
	std::cout << "Birthday Date: " << this->birthday << std::endl;
	std::cout << "Favorite Meal: " << this->meal << std::endl;
	std::cout << "Underwear Color: " << this->underwearColor << std::endl;
	std::cout << "Darkest Secret: " << this->darkestSecret << std::endl;
}
