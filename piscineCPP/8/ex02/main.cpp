#include <iostream>
#include <stack>
#include <vector>
#include "mutantstack.hpp"

int main() {
	MutantStack<int> mstack;

	mstack.push(1);
	mstack.push(2);
	std::cout << "Top: " << mstack.top() << std::endl;
	std::cout << "Size: " << mstack.size() << std::endl;
	std::cout << std::endl;

	mstack.pop();
	std::cout << "Top: " << mstack.top() << std::endl;
	std::cout << "Size: " << mstack.size() << std::endl;
	std::cout << std::endl;

	mstack.push(3);
	mstack.push(4);
	mstack.push(5);
	mstack.push(6);
	std::cout << "Top: " << mstack.top() << std::endl;
	std::cout << "Size: " << mstack.size() << std::endl;
	std::cout << std::endl;

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << "Iter: " << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}
