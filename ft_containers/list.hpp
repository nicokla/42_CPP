#ifndef FT_LIST_HPP
#define FT_LIST_HPP

#include <cstdlib>
#include <cstring>
// #include <iterator>
#include "reverse_iterator.hpp"

// http://www.cplusplus.com/reference/list/list/
// https://en.cppreference.com/w/cpp/container/list
// http://www.cplusplus.com/reference/iterator/

namespace ft {

template <typename T>
class	list;


template <typename T>
class ListIterator // : public std::iterator<std::input_iterator_tag, T>
{
public:
typedef typename list<T>::Elt Elt;
typedef T value_type;
typedef T* pointer;
typedef T& reference;

private:
	Elt *e;
public:
	ListIterator(){e = NULL;}
	ListIterator(Elt *e2) {e = e2;}
	ListIterator(const ListIterator& a) {e = a.e;}
	~ListIterator() {}
	ListIterator &operator=(const ListIterator&c) {e = c.e; return *this;}
	bool operator==(const ListIterator& a) const {return e == a.e;}
	bool operator!=(const ListIterator& a) const {return e != a.e;}
	reference operator*() const {
		return (e->content);
	}
	pointer operator->() const {
		return &(e->content);
	}
	ListIterator& operator++() {if(e) e = e->next; return *this;}
	ListIterator operator++(int input) {
		ListIterator tmp(*this);
		(void)input;
		++(*this);
		return (tmp);
	}
	ListIterator& operator--() {if(e) e = e->previous; return *this;}
	ListIterator operator--(int input) {
		ListIterator tmp(*this);
		(void)input;
		--(*this);
		return (tmp);
	}
	ListIterator operator+(int n) {
		Elt *e2 = e;
		for(int i=0; i<n; i++) e2 = e2->next;
		return ListIterator(e2);
	}
	ListIterator operator-(int n) {
		Elt *e2 = e;
		for(int i=0; i<n; i++) e2 = e2->previous;
		return ListIterator(e2);
	}
	Elt *getElt(){return e;}
};

template <typename T>
class	list {
// friend bool operator== (const list<T>& a, const list<T>& b);

public:
typedef T value_type;
typedef T& reference;
typedef const T& const_reference;
typedef T* pointer;
typedef const T* const_pointer;
typedef std::ptrdiff_t difference_type;
typedef size_t size_type;
typedef ListIterator<T> iterator;
typedef ListIterator<const T> const_iterator;
typedef ft::reverse_iterator<iterator> reverse_iterator;
typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

// --------------------------------------------------
//                INTERNAL CLASSES
// --------------------------------------------------

class Elt{
public:
	T content;
	Elt *previous;
	Elt *next;
};


// --------------------------------------------------
//                   CLASS VARIABLES
// --------------------------------------------------
private:
	Elt origin;
	size_t size_;

// --------------------------------------------------
//                    CLASS FUNCTIONS
// --------------------------------------------------

public:

// --------------------------------------------------
// LABASE
// 1.1
list<T>(){
	origin.next = &origin;
	origin.previous = &origin;
	memset(&(origin.content), 0, sizeof(T));
	size_ = 0;
}

// 1.2
explicit list<T> (size_t n, const T& val = T()){
	origin.next = &origin;
	origin.previous = &origin;
	memset(&(origin.content), 0, sizeof(T));
	size_ = 0;
	assign(n, val);
}

// 1.3
template <class InputIterator>
list<T>(InputIterator first, InputIterator last){
	origin.next = &origin;
	origin.previous = &origin;
	memset(&(origin.content), 0, sizeof(T));
	size_ = 0;
	assign(first, last);
}

// 1.4
list<T>(list<T> const& a) {
	origin.next = &origin;
	origin.previous = &origin;
	memset(&(origin.content), 0, sizeof(T));
	size_ = 0;
	*this = a;
}

// 3 (should be 2 but mistake numbering functions)
~list<T>() {
	clear();
}

// 4
list<T>& operator=(list<T> const& a) {
	clear();
	Elt *e = a.origin.next;
	while(e != &(a.origin)){
		push_back(e->content);
		e = e->next;
	}
	return *this;
}

// 5.1
// assign
void assign(size_t count, const T& value){
	size_t i = 0;
	clear();
	for(i=0; i<count; i++){
		push_back(value);
	}
}

// 5.2
// assign
template <class InputIterator>
void assign(InputIterator first, InputIterator last){
	clear();
	while (first != last){
		push_back(*first);
		++first;
	}
}

// --------------------------------------------------
// ELEMENT ACCESS

// 6
// list::front
reference front(){
	return (origin.next->content);
}
const_reference front() const {
	return (origin.next->content);
}

// 7
// list::back
reference back(){
	return (origin.previous->content);
}
const_reference back() const{
	return (origin.previous->content);
}

// --------------------------------------------------
// ITERATORS

// 8
// list::begin
iterator begin(){
	return iterator(origin.next);
}
const_iterator begin() const{
	return const_iterator(origin.next);
}

// 9
// list::end
iterator end(){
	return iterator(&origin);
}
const_iterator end() const{
	return const_iterator(&origin);
}

// 10
// list::rbegin
reverse_iterator rbegin(){
	return reverse_iterator(origin.previous);
}
const_reverse_iterator rbegin() const {
	return const_reverse_iterator(origin.previous);
}

// 11
// list::rend
reverse_iterator rend(){
	return reverse_iterator(&origin);
}
const_reverse_iterator rend() const {
	return const_reverse_iterator(&origin);
}

// --------------------------------------------------
// CAPACITY

// 12
// list::empty
bool empty() const{
	return (size_ == 0);
}

// 13
// list::size
size_t size() const{
	return size_;
}

// 14
// list::max_size
size_t max_size(){
	return 768614336404564650;
}

// --------------------------------------------------
// MODIFIERS

// 15
// list::clear
void clear(){
	Elt *e = origin.next;
	Elt *tmp;
	while(e != &origin){
		tmp = e;
		e = e->next;
		delete tmp;
	}
	origin.next = &origin;
	origin.previous = &origin;
	size_ = 0;
}

// 16.1
// insert
iterator insert(iterator position, const value_type& val){
	Elt *e = new Elt;
	e->content = val;
	Elt *pos = position.getElt();
	Elt *prev = pos->previous;
	e->next = pos;
	e->previous = prev;
	prev->next = e;
	pos->previous = e;
	size_++;
	return iterator(e);
}

// 16.2
// insert
void insert (iterator position, size_type n, const value_type& val){
	for(size_type i=0; i<n; i++){
		position = insert(position, val);
	}
}

// 16.3
// insert
template <class InputIterator>
void insert (iterator position, InputIterator first,
			InputIterator last){
	while (first != last){
		insert(position, *first);
		++first;
	}
}

// 17.1
// list::erase
iterator erase(iterator position){
	Elt *e = position.getElt();
	if(e != &origin){
		e->previous->next = e->next;
		e->next->previous = e->previous;
		delete e;
		size_--;
		return iterator(e->next);
	}
	return iterator(&origin);
}

// 17.2
iterator erase(iterator first, iterator last){
	iterator i = first;
	while (i != last){
		i = erase(i);
	}
	return i;
}

// 18
// list::push_back
void push_back(const T& value){
	Elt *e = new Elt;
	e->content = value;
	e->next = &origin;
	e->previous = &origin;
	if(origin.previous == &origin){
		origin.next = e;
		origin.previous = e;
	}
	else {
		origin.previous->next = e;
		e->previous = origin.previous;
		origin.previous = e;
	}
	size_++;
}

// 19
// list::push_front
void push_front(const T &value){
	Elt *e = new Elt;
	e->content = value;
	e->next = &origin;
	e->previous = &origin;
	if(origin.next == &origin){
		origin.next = e;
		origin.previous = e;
	}
	else {
		origin.next->previous = e;
		e->next = origin.next;
		origin.next = e;
	}
	size_++;
}

// 20
// list::pop_back
void pop_back() {
	Elt *tmp;
	if(origin.previous != &origin){
		tmp = origin.previous;
		origin.previous = tmp->previous;
		if (!origin.previous)
			origin.next = &origin;
		if (origin.previous)
			origin.previous->next = &origin;
		delete tmp;
		this->size_--;
	}
}

// 21
// list::pop_front
void pop_front() {
	Elt *tmp;
	if(origin.next != &origin){
		tmp = origin.next;
		origin.next = tmp->next;
		if (!origin.next)
			origin.previous = &origin;
		if(origin.next)
			origin.next->previous = &origin;
		delete tmp;
		this->size_--;
	}
}

// 22
// list::resize
void resize (size_t n, T val = T()){ 
	if(n < size_){
		iterator i = begin();
		i = (i + n);
		erase(i, end());
	}
	else if(n > size_) {
		insert(end(), n, val);
	}
}

// 23
// list::swap
void swap (list& x){
	Elt origin_tmp = origin;
	size_t size_tmp = size_;
	origin = x.origin;
	size_ = x.size_;
	origin.next->previous = &origin;
	origin.previous->next = &origin;
	x.origin = origin_tmp;
	x.size_ = size_tmp;
	x.origin.next->previous = &(x.origin);
	x.origin.previous->next = &(x.origin);
}

// --------------------------------------------------
// OPERATIONS

// 24.1
// list::merge
void merge (list& x){
	iterator i1 = begin();
	// iterator i2 = x.begin();
	T t1, t2;
	while(!x.empty()){
		t1 = *i1;
		t2 = x.front();
		if(t2 <= t1 || i1 == end()){
			insert(i1, t2);
			x.pop_front();
		}
		else if (i1 != end())
			++i1;
	}
}

// 24.2
// merge
template <class Compare>
void merge (list& x, Compare comp){
	iterator i1 = begin();
	// iterator i2 = x.begin();
	T t1, t2;
	while(!x.empty() && i1 != end()){
		t1 = *i1;
		t2 = x.front();
		if(comp(t2, t1) || i1 == end()){
			insert(i1, t2);
			x.pop_front();
		}
		else if (i1 != end())
			++i1;
	}
}


// 25.2
// splice
void splice (iterator position, list& x, iterator i){
	insert(position, *i);
	x.erase(i);
}

// 25.3
// splice
void splice(iterator position, list& x, iterator first, iterator last){
	insert(position, first, last);
	x.erase(first, last);
}

// 25.1
// list::splice
void splice (iterator position, list& x){
	splice(position, x, x.begin(), x.end());
}

// 26
// list::remove
void remove (const T& val){
	iterator i = begin();
	while(i != end()){
		if(*i == val)
			i = erase(i);
		else
			++i;
	}
}

// 27
// list::remove_if
template <class Predicate>
void remove_if (Predicate pred) {
	iterator i = begin();
	while(i != end()){
		if(pred(*i))
			i = erase(i);
		else
			++i;
	}
}

// 28
// list::reverse
void reverse() {
	Elt *e = origin.next;
	Elt *tmp;
	while(e != &origin) {
		tmp = e->next;
		e->next = e->previous;
		e->previous = tmp;
		e = tmp;
	};
	tmp = e->next;
	e->next = e->previous;
	e->previous = tmp;
}

// 29.1
// list::unique
void unique() {
	iterator i = begin();
	T t1, t2;
	++i;
	while(i != end()){
		t1 = *i;
		t2 = *(i - 1);
		if(t1 == t2)
			i = erase(i);
		else
			++i;
	}
}

// 29.2
// unique
template <class BinaryPredicate>
void unique (BinaryPredicate binary_pred) {
	iterator i = begin();
	++i;
	while(i != end()){
		if(binary_pred(*i, *(i - 1)))
			i = erase(i);
		else
			++i;
	}
}


template <class Compare>
Elt	*merge_recur(Elt *a, Elt *b, Compare comp)
{
	Elt	*result;

	if (a == &origin)
		return (b);
	else if (b == &origin)
		return (a);
	if (comp(a->content, b->content))
	{
		result = a;
		result->next = merge_recur(a->next, b, comp);
	}
	else
	{
		result = b;
		result->next = merge_recur(a, b->next, comp);
	}
	return (result);
}

void	front_back_split(Elt *source,
						Elt **front_ref, Elt **back_ref)
{
	Elt	*fast;
	Elt	*slow;

	slow = source;
	fast = source->next;
	while (fast != &origin)
	{
		fast = fast->next;
		if (fast != &origin)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front_ref = source;
	*back_ref = slow->next;
	slow->next = &origin;
}

template <class Compare>
void	ft_list_sort(Elt **begin_list, Compare comp)
{
	Elt *head;
	Elt *a;
	Elt *b;

	head = *begin_list;
	if ((head == &origin) || (head->next == &origin))
		return ;
	front_back_split(head, &a, &b);
	ft_list_sort(&a, comp);
	ft_list_sort(&b, comp);
	*begin_list = merge_recur(a, b, comp);
}


// 30.2
// sort
template <class Compare>
void sort (Compare comp){
	ft_list_sort(&(origin.next), comp);
}

static bool defaultComp(const T& a, const T& b){
	return (a <= b);
}

// 30.1
// sort
void sort(){
	sort(defaultComp);
}

}; // end class


} // end namespace

// --------------------------------------------------
// --------------------------------------------------
// NON-MEMBER FUNCTIONS

// 31
template <class T>
void swap (ft::list<T>& x, ft::list<T>& y){
	x.swap(y);
}

// 32
template <class T>
bool operator== (const ft::list<T>& a, const ft::list<T>& b){
	typename ft::list<T>::iterator it = a.begin();
	typename ft::list<T>::iterator it2 = b.begin();
	while(it != a.end() && it2 != b.end()){
		if(*it != *it2)
			return false;
		++it;
		++it2;
	}
	return (it == a.end() && it2 == b.end());
}


// 33
// operator!=
template <class T>
bool operator!= (const ft::list<T>& a, const ft::list<T>& b){
	return !(a == b);
}

// 34
// operator<
template <class T>
bool operator< ( ft::list<T>& a, ft::list<T>& b){
	typename ft::list<T>::iterator it = a.begin();
	typename ft::list<T>::iterator it2 = b.begin();
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

// 35
// operator<=
template <class T>
bool operator<= (const ft::list<T>& a, const ft::list<T>& b){
	return (!(a > b));
}

// 36
// operator>
template <class T>
bool operator> (const ft::list<T>& a, const ft::list<T>& b){
	return (b < a);
}

// 37
// operator>=
template <class T>
bool operator>= (const ft::list<T>& a, const ft::list<T>& b){
	return (!(a < b));
}

#endif