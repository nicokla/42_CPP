#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class	Contact {
	private:
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string login;
		std::string address;
		std::string email;
		std::string phone;
		std::string birthday;
		std::string meal;
		std::string underwearColor;
		std::string darkestSecret;

	public:
		Contact(); 
		~Contact();
		void		display_info();

		std::string getFirstname()
		{
			return this->firstname;
		}

		void setFirstname(std::string firstname)
		{
			this->firstname = firstname;
		}

		std::string getLastname()
		{
			return this->lastname;
		}

		void setLastname(std::string lastname)
		{
			this->lastname = lastname;
		}

		std::string getNickname()
		{
			return this->nickname;
		}

		void setNickname(std::string nickname)
		{
			this->nickname = nickname;
		}

		std::string getLogin()
		{
			return this->login;
		}

		void setLogin(std::string login)
		{
			this->login = login;
		}

		std::string getAddress()
		{
			return this->address;
		}

		void setAddress(std::string address)
		{
			this->address = address;
		}

		std::string getEmail()
		{
			return this->email;
		}

		void setEmail(std::string email)
		{
			this->email = email;
		}

		std::string getPhone()
		{
			return this->phone;
		}

		void setPhone(std::string phone)
		{
			this->phone = phone;
		}

		std::string getBirthday()
		{
			return this->birthday;
		}

		void setBirthday(std::string birthday)
		{
			this->birthday = birthday;
		}

		std::string getMeal()
		{
			return this->meal;
		}

		void setMeal(std::string meal)
		{
			this->meal = meal;
		}

		std::string getUnderwearColor()
		{
			return this->underwearColor;
		}

		void setUnderwearColor(std::string underwearColor)
		{
			this->underwearColor = underwearColor;
		}

		std::string getDarkestSecret()
		{
			return this->darkestSecret;
		}

		void setDarkestSecret(std::string darkestSecret)
		{
			this->darkestSecret = darkestSecret;
		}
};

#endif