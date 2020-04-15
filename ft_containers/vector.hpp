#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include <cstdlib>
#include <string>
#include <iostream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include "reverse_iterator.hpp"

// http://www.cplusplus.com/reference/vector/vector/
// https://en.cppreference.com/w/cpp/container/vector

namespace ft {

template <typename T>
class VectorIterator : public std::iterator<std::input_iterator_tag, T>
{
public:
typedef T value_type;
typedef T* pointer;
typedef T& reference;

private:
	T *e;

public:
	VectorIterator(){e = NULL;}
	VectorIterator(T *e2) {e = e2;}
	VectorIterator(const VectorIterator& a) {e = a.e;}
	~VectorIterator() {}
	VectorIterator &operator=(const VectorIterator&c) {e = c.e; return *this;}
	bool operator==(const VectorIterator& a) const {return e == a.e;}
	bool operator!=(const VectorIterator& a) const {return e != a.e;}
	T& operator*() const {return (*e);}
	T* operator->() const {return e;}
	VectorIterator& operator++() {++e; return *this;}
	VectorIterator operator++(int input) {
		VectorIterator tmp(*this);
		(void)input;
		++(*this);
		return (tmp);
	}
	VectorIterator& operator--() {if(e) --e; return *this;}
	VectorIterator operator--(int input) {
		VectorIterator tmp(*this);
		(void)input;
		--(*this);
		return (tmp);
	}
	T *ptr(){return e;}
};
template <class T>
VectorIterator<T> operator+(VectorIterator<T> a, int n) {
	return VectorIterator<T>(a.ptr() + n);
}
template <class T>
VectorIterator<T> operator+(int n, VectorIterator<T> a) {
	return VectorIterator<T>(a.ptr() + n);
}
template <class T>
VectorIterator<T> operator-(VectorIterator<T> a, int n) {
	return VectorIterator<T>(a.ptr() - n);
}
template <class T>
std::ptrdiff_t operator-(const VectorIterator<T>& lhs, const VectorIterator<T>& rhs){
	return lhs.ptr() - rhs.ptr();
}



template <class T>
class	vector {

public:


// --------------------------------------------------
// --------------------------------------------------
// CLASS VARIABLES
typedef T value_type;
typedef size_t size_type ;
typedef ptrdiff_t difference_type;
typedef value_type& reference;
typedef VectorIterator<T> iterator;
typedef const value_type& const_reference;
typedef VectorIterator<const T> const_iterator;
typedef ft::reverse_iterator<iterator> reverse_iterator;
typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

private:
	T* v;
	size_t len;
	size_t cap;

// --------------------------------------------------
// --------------------------------------------------
// CLASS FUNCTIONS

public:
// --------------------------------------------------
// LABASE
explicit vector(){
	v = NULL;
	len = 0;
	cap = 0;
}

explicit vector(size_type n, const value_type& val = value_type()){
	v = NULL;
	len = 0;
	cap = 0;
	assign(n, val);
}

template <class InputIterator>
vector (InputIterator first, InputIterator last){
	v = NULL;
	len = 0;
	cap = 0;
	assign(first, last);
}

vector (const vector& x){
	v = NULL;
	len = 0;
	cap = 0;
	*this = x;
}

~vector<T>() {
	if(v)
		delete[] v;
}

vector<T>& operator=(vector<T> const& a) {
	clear();
	len = a.len;
	cap = a.cap;
	v = new T[cap];

	for (int i = 0; i < len; i++) {
		v[i] = a.v[i];
	}
}

template <class InputIterator>
void assign (InputIterator first, InputIterator last){
	clear();
	size_t n = last - first;
	len = n;
	cap = n;
	v = new T[n];
	T* v2 = v;
	InputIterator i;
	for(i=first; i!=last; ++i){
		*v2 = *i;
		++v2;
	}
}

void assign (size_type n, const value_type& val){
	clear();
	size_t i;
	len = n;
	cap = n;
	v = new T[cap];
	for(i=0; i<len; i++){
		v[i] = val;
	}
}

// --------------------------------------------------
// ELEMENT ACCESS
reference at (size_type n){
	if (n >= size()) {
		std::stringstream s;
		s << "index " << n
			<< " out of bound (size() is " << size()
			<< ")";
		throw std::out_of_range(s.str());
	}
	return v[n];
}

const_reference at (size_type n) const{
	if (n >= size()) {
		std::stringstream s;
		s << "index " << n
			<< " out of bound (size() is " << size()
			<< ")";
		throw std::out_of_range(s.str());
	}
	return v[n];
}

T& operator[](unsigned int i) {
	return v[i];
}

reference front(){
	return v[0];
}

const_reference front() const{
	return v[0];
}

reference back(){
	return v[len - 1];
}

const_reference back() const{
	return v[len - 1];
}

// --------------------------------------------------
// ITERATORS

iterator begin(){
	return iterator(v);
}

const_iterator begin() const{
	return const_iterator(v);
}

iterator end(){
	return iterator(v + len);
}

const_iterator end() const{
	return const_iterator(v + len);
}

reverse_iterator rbegin(){
	return reverse_iterator(--end());
}

const_reverse_iterator rbegin() const{
	return const_reverse_iterator(--end());
}


reverse_iterator rend(){
	return reverse_iterator(--begin());
}

const_reverse_iterator rend() const{
	return const_reverse_iterator(--begin());
}

// --------------------------------------------------
// CAPACITY

bool empty() const{
	return (len == 0);
}

size_t size() const {
	return len;
};

size_type max_size() const{
	return 2305843009213693951;
}

void reserve (size_type n){
	if(n <= cap)
		return;
	cap = n;
	T* new_v = new T[n];
	size_t i = 0;
	while(i < len){
		new_v[i] = v[i];
		i++;
	}
	if (v)
		delete[] v;
	v = new_v;
}

size_type capacity() const{
	return cap;
}

// --------------------------------------------------
// MODIFIERS

void clear(){
	if (v)
		delete[] v;
	v = NULL;
	len = 0;
	cap = 0;
}

iterator insert (iterator position, const value_type& val){
	size_t j = position.ptr() - v;
	insert(position, (size_type)1, val);
	return iterator(&v[j]);
}

void insert (iterator position, size_type n, const value_type& val){
	size_t j = position.ptr() - v;
	if(cap < (n + len)){
		size_t tmp = 1;
		while(tmp < (n + len))
			tmp *= 2;
		reserve(tmp);
	}
	len += n;
	size_t i = 0;
	while((j + n + i) < len){
		v[j + n + i] = v[j + i];
		++i;
	}
	i = 0;
	while(i < n){
		v[j + i] = val;
		++i;
	}
}

template <class InputIterator>
void insert (iterator position, InputIterator first, InputIterator last){
	size_t n = std::distance(first, last);
	size_t j = position.ptr() - v;
	if(cap < (n + len)){
		size_t tmp = 1;
		while(tmp < (n + len))
			tmp *= 2;
		reserve(tmp);
	}
	len += n;
	size_t i = 0;
	while((j + n + i) < len){
		v[j + n + i] = v[j + i];
		++i;
	}
	i = 0;
	while(first != last){ //i < n
		v[j + i] = *first;
		++first;
		++i;
	}
}

iterator erase (iterator position){
	return erase(position, position + 1);
}

iterator erase (iterator first, iterator last){
	size_t count = (size_t)(last.ptr() - first.ptr());
	if (count <= 0)
		return last;
	size_t index = first.ptr() - v;
	for (size_t i = index + count; i < len; i++) {
		v[i - count] = v[i];
	}
	len -= count;
	return first;
}

void push_back (const value_type& val){
	insert(end(), val);
}

void pop_back(){
	if(len != 0)
		len--;
}

void resize (size_type n, value_type val = value_type()){
	reserve(n);
	if(n <= len)
		len = n;
	else{
		size_t i;
		for(i = len; i < n; i++){
			v[i] = val;
		}
		len = n;
	}
}

void swap (vector& other){
	std::swap(v, other.v);
	std::swap(len, other.len);
	std::swap(cap, other.cap);
}


}; 

// -------------------------------------------
// NON MEMBER FUNCTIONS 1
template <class T>
void swap (ft::vector<T>& x, ft::vector<T>& y){
	x.swap(y);
}

// --------------------------------------------------
// NON MEMBER FUNCTIONS 2 : RELATIONAL OPERATORS

template <class T>
bool operator== ( ft::vector<T>& a,  ft::vector<T>& b){
	typename ft::vector<T>::iterator it = a.begin();
	typename ft::vector<T>::iterator it2 = b.begin();
	while(it != a.end() && it2 != b.end()){
		if(*it != *it2)
			return false;
		++it;
		++it2;
	}
	return (it == a.end() && it2 == b.end());
}


template <class T>
bool operator!= ( ft::vector<T>& a,  ft::vector<T>& b){
	return !(a == b);
}

template <class T>
bool operator< ( ft::vector<T>& a,  ft::vector<T>& b){
	typename ft::vector<T>::iterator it = a.begin();
	typename ft::vector<T>::iterator it2 = b.begin();
	while(it != a.end() && it2 != b.end()){
		if(*it < *it2)
			return true;
		else if (*it == *it2){
			++it;
			++it2;
		}
		else
			return false;
	}
	return (it == a.end() && it2 != b.end());
	// return (a.size() < b.size());
}

template <class T>
bool operator<= ( ft::vector<T>& a,  ft::vector<T>& b){
	return (!(a > b));
}

template <class T>
bool operator> ( ft::vector<T>& a,  ft::vector<T>& b){
	return (b < a);
}

template <class T>
bool operator>= ( ft::vector<T>& a,  ft::vector<T>& b){
	return (!(a < b));
}


}

#endif