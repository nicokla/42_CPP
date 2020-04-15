#include <iostream>
#include <ctime>
#include <iostream>
#include <string>
#include "span.hpp"

int main() {
	Span s1(3);
	try{
		std::cout << s1.longestSpan();
	} catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	
	// ----------------------
	int a[] = {4, 10, 12, 42};
	try {
		s1.addNumber(a, a+4);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	s1.addNumber(a, a+3);
	std::cout << "Longest Span: " << s1.longestSpan() << std::endl;
	std::cout << "Shortest Span: " << s1.shortestSpan() << std::endl;

	// ----------------------
	std::cout << "\n-----------\n" << std::endl;
	Span s2(10000);
	try {
		for (int i = 0; i < 10042; i++) {
			s2.addNumber(i);
		}
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Longest Span: " << s2.longestSpan() << std::endl;
	std::cout << "Shortest Span: " << s2.shortestSpan() << std::endl;

	return 0;
}