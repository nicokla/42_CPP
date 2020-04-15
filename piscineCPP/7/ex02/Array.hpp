#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <string>
#include <iostream>

template<typename T>
class Array {
private:
	T* 			 arr;
	unsigned int size;

public:
	Array<T>():
	arr(nullptr), size(0) {}

	Array<T>(unsigned int size):
	size(size) {
		arr = new T[size];
	}

	Array<T>(Array const& a) {
		*this = a;
	}

	Array& operator=(Array const& a) {
		size = a.size;
		arr = new T[size];

		for (int i = 0; i < size; i++) {
			arr[i] = a.arr[i];
		}
	}

	~Array<T>() {
		if (arr)
			delete arr;
	}

	unsigned int getSize() const {
		return size;
	};

	T& operator[](unsigned int i) {
		if (i >= size) {
			throw std::exception();
		}
		return arr[i];
	}
};

#endif