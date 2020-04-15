#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <stdexcept>

template<typename T>
int easyfind(T& container, int n) {
	typename T::iterator it;
	try {
		it = std::find(container.begin(), container.end(), n);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	if (it == container.end())
		throw std::logic_error("Item not found in container");
	return *it;
}

#endif
