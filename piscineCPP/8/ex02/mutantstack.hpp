#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <vector>
#include <list>

template<typename T>
class MutantStack : public std::stack<T> {
private:
	std::vector<T> 		 v;

public:
	MutantStack() {};

	MutantStack(MutantStack const& s) {
		*this = s;
	};

	MutantStack& operator=(MutantStack const& s) {
		v = s.v;
		return *this;
	};
	
	~MutantStack() {};

	typedef typename std::vector<T>::iterator iterator;
	
	iterator begin() {
		return v.begin();
	}
	
	iterator end(){
		return v.end();
	}
		
	void	 push(T x) {
		v.push_back(x);
	}

	void	 pop() {
		v.pop_back();
	}

	T		top() {
		return *(v.end() - 1);
	}

	T size() {
		return (v.size());
	}
};

#endif