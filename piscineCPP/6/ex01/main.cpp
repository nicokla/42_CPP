#include <ctime>
#include <iostream>
#include <string>

struct Data {
	std::string s1;
	int			n;
	std::string s2;
};

void* serialize() {
	char const chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

	Data *d = new Data();
	d->s1 = "";
	d->s2 = "";

	for (int i = 0; i < 8; i++) {
		d->s1 += chars[rand() % sizeof(chars)];
	}
	d->n = rand();
	for (int i = 0; i < 8; i++) {
		d->s2 += chars[rand() % sizeof(chars)];
	}
	return reinterpret_cast<void*>(d);
}

Data* deserialize(void* raw) {
	return reinterpret_cast<Data*>(raw);
}

int main() {
	srand(time(nullptr));

	void* v = serialize();
	std::cout << "Serialized: " << v << std::endl;

	Data* d = deserialize(v);
	std::cout << "Deserialized: " << d->s1 << ", " 
	<< d->n << ", "  << d->s2 << std::endl;

	delete d;
}