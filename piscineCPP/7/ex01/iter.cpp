#include <iostream>

template<typename T>
void iter(T* arr, int len, void (*myFunction)(T const&)) {
	if (arr != nullptr) {
		for (int i = 0; i < len; i++) {
			myFunction(arr[i]);
		}
	}
}

template<typename T>
void print(T const& x) {
	std::cout << x << std::endl;
}

int main() {
	int numbers[] = {0, 1, 3, 7, 12, 42};
	std::string words[] = {"apple", "banana", "orange", "pear", "strawberry"};

	iter(numbers, 6, print);
	std::cout << std::endl;

	iter(words, 5, print);

	return 0;
}
