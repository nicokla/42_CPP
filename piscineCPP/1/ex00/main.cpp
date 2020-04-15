#include "Pony.hpp"
#include <iostream>

static void ponyOnTheHeap() {
	Pony *fluttershy = new Pony("Fluttershy");
	std::cout << "Name  : " << fluttershy->getName() << std::endl;
	delete(fluttershy);
}

static void ponyOnTheStack() {
	Pony pinkiepie("Pinkiepie");
	std::cout << "Name  : " << pinkiepie.getName() << std::endl;
}

int main() {
	std::cout << "~~ Pony on the Heap ~~" << std::endl;
	ponyOnTheHeap();
	std::cout << std::endl;
	std::cout << "~~ Pony on the Stack ~~" << std::endl;
	ponyOnTheStack();
	return (0);
}
