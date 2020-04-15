#include "span.hpp"
#include <vector>
#include <stdexcept>
#include <limits>
#include <cmath>
#include <algorithm>

Span::Span(unsigned int size): size(size) {
	array.reserve(size);
}

Span::Span(Span const& s) {
	*this = s;
}

Span& Span::operator=(Span const& s) {
	array = s.array;
	return *this;
}

void 		 Span::addNumber(int n) {
	if (array.size() < size) {
		array.push_back(n);
	} else {
		throw std::length_error("Error: container is full");
	}
}

unsigned int Span::shortestSpan() {
	int min = INT_MAX;
	int diff;
	std::vector<int>		   tmp = array;
	std::vector<int>::iterator it;
	
	if (tmp.size() > 1) {
		std::sort(tmp.begin(), tmp.end());
		it  = tmp.begin();
		while ((it+1) != tmp.end()) {
			diff = (*(it+1) - *it);
			if (diff < min)
				min = diff;
			if (min == 0)
				return 0;
			it++;
		}
	} else {
		throw std::logic_error("Error: container 1 element or is empty");
	}
	return min;
}

unsigned int Span::longestSpan() {
	int max;
	int min;
	if (array.size() > 1) {
		min = *std::min_element(array.begin(), array.end());
		max = *std::max_element(array.begin(), array.end());
	} else {
		throw std::logic_error("Error: container 1 element or is empty");
	}
	return (max - min);
}