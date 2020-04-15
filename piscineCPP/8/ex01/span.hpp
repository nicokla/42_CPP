#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span {
private:
	unsigned int     size;
	std::vector<int> array;

public:
	Span() {};
	Span(unsigned int size);
	Span(Span const& s);
	~Span() {};
	Span& operator=(Span const& s);
	
	void 		 addNumber(int n);

	template<typename InputIterator>
	void  addNumber(InputIterator first, InputIterator last){
		// while(first != last){
		// 	addNumber(*first);
		// 	++first;
		// }
		if ((this->array.size() + std::distance(first, last)) > this->size)
			throw std::length_error("Error: container can't add so many elements");
		this->array.insert(array.end(), first, last);
	};

	unsigned int shortestSpan();
	unsigned int longestSpan();
};

#endif