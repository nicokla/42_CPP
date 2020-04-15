#include <iostream>
#include <list>
#include <set>
#include "easyfind.hpp"

int main() {
	std::list<int> list;
	std::set<int> set;

	list.push_front(2);
	list.push_front(3);

	try {
		std::cout << easyfind(list, 2) << std::endl;
		std::cout << easyfind(list, 3) << std::endl;
		std::cout << easyfind(list, 4) << std::endl;
	} catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---------------" << std::endl;

	set.insert(2);
	set.insert(3);

	try {
		std::cout << easyfind(set, 2) << std::endl;
		std::cout << easyfind(set, 3) << std::endl;
		std::cout << easyfind(set, 4) << std::endl;
	} catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}