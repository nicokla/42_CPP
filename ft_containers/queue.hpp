#ifndef FT_QUEUE_HPP
#define FT_QUEUE_HPP

#include <cstdlib>

// http://www.cplusplus.com/reference/queue/queue/
// https://en.cppreference.com/w/cpp/container/queue

namespace ft {

template <class T > // , class Container = list<T>
class	queue {
public:
typedef T value_type;
typedef size_t size_type ;
typedef ptrdiff_t difference_type;
typedef value_type& reference;
typedef const value_type& const_reference;
typedef list<T> container_type;  // Container container_type

private:
	list<T> list_;  // Container list;

public:
// --------------------------------------------------
// LABASE

explicit queue (const container_type& list2 = container_type()){
	list_ = list2;
}

queue(queue<T> &o){
	list_ = o.list_;
}

~queue(){}

queue<T> &operator=(queue<T> const &o){
	list_ = o.list_;
	return *this;
}

// --------------------------------------------------
// ELEMENT ACCESS

value_type& front(){
	return list_.front();
}

const value_type& front() const{
	return list_.front();
}

value_type& back(){
	return list_.back();
}

const value_type& back() const{
	return list_.back();
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
	list_.pop_front();
}

void push (const value_type& val){
	list_.push_back(val);
}

void swap (queue& o){
	o.list_.swap(list_);
}

}; 

// -------------------------------------------
// NON MEMBER FUNCTIONS 1

template <class T>
void swap (queue<T>& x, queue<T>& y) {
	x.swap(y);
}

// --------------------------------------------------
// NON MEMBER FUNCTIONS 2 : RELATIONAL OPERATORS
template <class T>//, class Container
bool operator== (const queue<T>& lhs, const queue<T>& rhs){
	return (lhs.list_ == rhs.list_);
}

template <class T>
bool operator!= (const queue<T>& lhs, const queue<T>& rhs){
	return (lhs.list_ != rhs.list_);
}

template <class T>
bool operator<  (const queue<T>& lhs, const queue<T>& rhs){
	return (lhs.list_ < rhs.list_);
}

template <class T>
bool operator<= (const queue<T>& lhs, const queue<T>& rhs){
	return (lhs.list_ <= rhs.list_);
}

template <class T>
bool operator>  (const queue<T>& lhs, const queue<T>& rhs){
	return (lhs.list_ > rhs.list_);
}

template <class T>
bool operator>= (const queue<T>& lhs, const queue<T>& rhs){
	return (lhs.list_ >= rhs.list_);
}


}

#endif