#ifndef FT_STACK_HPP
#define FT_STACK_HPP

#include <cstdlib>

// http://www.cplusplus.com/reference/stack/stack/
// https://en.cppreference.com/w/cpp/container/stack

namespace ft {

template <class T, class Container = list<T> >
class	stack {
public:
typedef T value_type;
typedef size_t size_type ;
typedef ptrdiff_t difference_type;
typedef value_type& reference;
typedef const value_type& const_reference;
typedef Container container_type;

private:
	Container list_;

public:
// --------------------------------------------------
// LABASE

explicit stack (const container_type& list2 = container_type()){
	list_ = list2;
}

stack(stack<T, Container> &o){
	list_ = o.list_;
}

~stack(){}

stack<T> &operator=(stack<T, Container> const &o){
	list_ = o.list_;
	return *this;
}

// --------------------------------------------------
// CAPACITY

bool empty() const{
	return list_.empty();
}

size_type size() const{
	return list_.size();
}

// --------------------------------------------------
// MODIFIERS

void pop(){
	list_.pop_back();
}

void push (const value_type& val){
	list_.push_back(val);
}

void swap (stack& o){
	o.list_.swap(list_);
}

value_type& top(){
	return list_.back();
}

const value_type& top() const{
	return list_.back();
}

}; 

// -------------------------------------------
// NON MEMBER FUNCTIONS 1

template <class T, class Container>
void swap (stack<T,Container>& x, stack<T,Container>& y) {
	x.swap(y);
}

// --------------------------------------------------
// NON MEMBER FUNCTIONS 2 : RELATIONAL OPERATORS
template <class T, class Container>
bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
	return (lhs.list_ == rhs.list_);
}

template <class T, class Container>
bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
	return (lhs.list_ != rhs.list_);
}

template <class T, class Container>
bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
	return (lhs.list_ < rhs.list_);
}

template <class T, class Container>
bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
	return (lhs.list_ <= rhs.list_);
}

template <class T, class Container>
bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
	return (lhs.list_ > rhs.list_);
}

template <class T, class Container>
bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
	return (lhs.list_ >= rhs.list_);
}


}

#endif