#include <iostream>

template<typename T>
void swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T const& min(T const& a, T const& b) {
	if (a < b)
		return a;
	return b;
}

template<typename T>
T const& max(T const& a, T const& b) {
	if (a > b)
		return a;
	return b;
}

int main() {
	{
		int a = 1, b = 2;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "Swaping..." << std::endl;
		::swap(a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	}
	std::cout << std::endl;
	{
		std::string a = "coucou", b = "salut";
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "Swaping..." << std::endl;
		::swap(a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	}
	return (0);
}
