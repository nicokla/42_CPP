#ifndef FT_MAP_HPP
#define FT_MAP_HPP

#include <iostream>
#include <cstdlib>
#include "pair.hpp"
#include "triplet.hpp"
#include "reverse_iterator.hpp"

// http://www.cplusplus.com/reference/map/map/
// https://en.cppreference.com/w/cpp/container/map

namespace ft {

// -------------------------------
//				Less
// -------------------------------

template <typename key_type>
struct less {
	bool operator()(const key_type& a, const key_type& b) const {
		return a < b;
	}
};



// -------------------------------
//             MapIterator
// -------------------------------
template < typename Key, typename T, typename key_compare >
class	map;

template < typename key_type, typename mapped_type,
			typename key_compare > // typename typeConstOrNot
class MapIterator {
public:
	typedef map<key_type, mapped_type, key_compare> Map;
	typedef typename Map::Node Node;
	typedef pair<key_type, mapped_type> value_type; // <const
	typedef value_type& reference;
	typedef value_type* pointer;
	// typedef typeConstOrNot& reference;
	// typedef typeConstOrNot* pointer;

private:
	Map* myMap;
	Node* node;
	
public:
	MapIterator(): myMap(NULL), node(NULL){}
	// iterator(this, n);
	MapIterator(Map *myMap_, Node *node_):
		myMap(myMap_), node(node_) {}
	MapIterator(const MapIterator& a):
		myMap(a.myMap), node(a.node) {}
	~MapIterator() {}
	MapIterator &operator=(const MapIterator&c) {
		myMap = c.myMap;
		node = c.node;
		return *this;
	}
	// bool operator==(const MapIterator& a) const {return node == a.node;}
	// bool operator!=(const MapIterator& a) const {return node != a.node;}
	reference operator*() const {
		return node->value;
	}
	pointer operator->() const {
		return &(node->value);
	}
	MapIterator& operator++() {
		if (!node) {
			node = myMap->root;
			while (node && node->left)
				node = node->left;
		}
		if (node->right){
			node = node->right;
			while (node->left)
				node = node->left;
		}
		else {
			Node *tmp;
			do {
				tmp = node;
				node = node->parent;
			} while (node && (tmp == node->right));
		}
		return *this;
	}
	MapIterator operator++(int input) {
		MapIterator tmp(*this);
		(void)input;
		++(*this);
		return (tmp);
	}
	MapIterator& operator--() {
		if (!node) {
			node = myMap->root;
			while (node && node->right)
				node = node->right;
		}
		else if (node->left) {
			node = node->left;
			while (node && node->right)
				node = node->right;
		}
		else {
			Node *tmp;
			do {
				tmp = node;
				node = node->parent;
			} while (node && tmp == node->left);
		}
		return *this;
	}
	MapIterator operator--(int input) {
		MapIterator tmp(*this);
		(void)input;
		--(*this);
		return (tmp);
	}
	MapIterator operator+(int n) {
		Node *node2 = node;
		for(int i=0; i<n; i++)
			++node2;
		return MapIterator(myMap, node2);
	}
	MapIterator operator-(int n) {
		Node *node2 = node;
		for(int i=0; i<n; i++)
			--node2;
		return MapIterator(myMap, node2);
	}
	template <class A, class B, class C>
	friend bool operator==(	const MapIterator<A, B, C>& lhs,
							const MapIterator<A, B, C>& rhs);
	template <class A, class B, class C>
	friend class map;
};
template <typename A, typename B, typename C>
bool operator==(const MapIterator<A, B, C>& lhs,
				const MapIterator<A, B, C>& rhs) {
	return lhs.node == rhs.node;
}
template <typename A, typename B, typename C>
bool operator!=(const MapIterator<A, B, C>& lhs,
				const MapIterator<A, B, C>& rhs) {
	return !(lhs == rhs);
}



template < typename key_type, typename mapped_type,
			typename key_compare>
class ConstIterator {
private:
	typedef map<key_type, mapped_type, key_compare> Map;
	typedef typename Map::Node Node;
	typedef pair<key_type, mapped_type> value_type;
	typedef const value_type& reference;
	typedef const value_type* pointer;

	Map* myMap;
	Node* node;
public:
	ConstIterator(){}
	// iterator(this, n);
	ConstIterator(Map *myMap_, Node *node_):
		myMap(myMap_), node(node_) {}
	ConstIterator(const ConstIterator& a):
		myMap(a.myMap), node(a.node) {}
	~ConstIterator() {}
	ConstIterator &operator=(const ConstIterator&c) {
		myMap = c.myMap;
		node = c.node;
		return *this;
	}
	// bool operator==(const MapIterator& a) const {return node == a.node;}
	// bool operator!=(const MapIterator& a) const {return node != a.node;}
	reference operator*() const {
		return node->value;
	}
	pointer operator->() const {
		return &node->value;
	}
	ConstIterator& operator++() {
		if (!node) {
			node = myMap->root;
			while (node && node->left)
				node = node->left;
		}
		if (node->right){
			node = node->right;
			while (node->left)
				node = node->left;
		}
		else {
			Node *tmp;
			do {
				tmp = node;
				node = node->parent;
			} while (node && (tmp == node->right));
		}
		return *this;
	}
	ConstIterator operator++(int input) {
		ConstIterator tmp(*this);
		(void)input;
		++(*this);
		return (tmp);
	}
	ConstIterator& operator--() {
		if (!node) {
			node = myMap->root;
			while (node && node->right)
				node = node->right;
		}
		else if (node->left) {
			node = node->left;
			while (node && node->right)
				node = node->right;
		}
		else {
			Node *tmp;
			do {
				tmp = node;
				node = node->parent;
			} while (node && tmp == node->left);
		}
		return *this;
	}
	ConstIterator operator--(int input) {
		ConstIterator tmp(*this);
		(void)input;
		--(*this);
		return (tmp);
	}
	ConstIterator operator+(int n) {
		Node *node2 = node;
		for(int i=0; i<n; i++)
			++node2;
		return ConstIterator(myMap, node2);
	}
	ConstIterator operator-(int n) {
		Node *node2 = node;
		for(int i=0; i<n; i++)
			--node2;
		return ConstIterator(myMap, node2);
	}
	template <class A, class B, class C>
	friend bool operator==(	const ConstIterator<A, B, C>& lhs,
							const ConstIterator<A, B, C>& rhs);
	template <class A, class B, class C>
	friend class map;
};
template <typename A, typename B, typename C>
bool operator==(const ConstIterator<A, B, C>& lhs,
				const ConstIterator<A, B, C>& rhs) {
	return lhs.node == rhs.node;
}
template <typename A, typename B, typename C>
bool operator!=(const ConstIterator<A, B, C>& lhs,
				const ConstIterator<A, B, C>& rhs) {
	return !(lhs == rhs);
}

// -------------------------------
//             Map
// -------------------------------

template < typename Key, typename T, typename key_compare = less<Key> >
class	map {

// ----------------------
// typedefs
public:
typedef Key key_type;
typedef T mapped_type;
typedef pair<key_type, mapped_type> value_type;
// typedef pair<key_type, mapped_type> value_type;
typedef MapIterator<Key, T, key_compare> iterator; // value_type
typedef ConstIterator<Key, T, key_compare> const_iterator; // const value_type
typedef ft::reverse_iterator<iterator> reverse_iterator;
typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
typedef size_t size_type;

// -------------------------
// Internal classes

class value_compare {
	friend class map;
protected:
	key_compare comp;
public:
	value_compare (key_compare c) : comp(c) {}
	typedef bool result_type;
	typedef value_type first_argument_type;
	typedef value_type second_argument_type;
	bool operator() (const value_type& x, const value_type& y) const {
		return comp(x.first, y.first);
	}
};

public:
class Node {
public:
	Node *left;
	Node *right;
	Node *parent;
	size_t height;
	value_type value;
	Node(value_type value_, Node *parent_):
		left(NULL), right(NULL), parent(parent_), height(1), value(value_) {}
	int getHeight(Node *head){
		if(head==NULL) return 0;
		return head->height;
	}
	void setRightChild(Node *child){
		if(child)
			child->parent = this;
		this->right = child;
		this->height = 1 + std::max(getHeight(this->left), getHeight(this->right));
	}
	void setLeftChild(Node *child){
		if(child)
			child->parent = this;
		this->left = child;
		this->height = 1 + std::max(getHeight(this->left), getHeight(this->right));
	}
};


// --------------------------------------------------
// Class variables

private:
	Node *root;
	size_t len;
	value_compare comp;
	key_compare comp2;

// --------------------------------------------------
// Class functions

// --------------------------------------------------
// LABASE

public:

explicit map (const key_compare& comp_ = key_compare()):
	root(NULL), len(0), comp(value_compare(comp_))
{
	comp2 = comp_;
}

template <class InputIterator>
map (InputIterator first, InputIterator last,
	const key_compare& comp_ = key_compare()){
	comp = value_compare(comp_);
	comp2 = comp_;
	root = NULL;
	len = 0;
	while(first != last){
		insert(*first);
		++first;
	}
}

private:
void deep_copy(Node **node1, Node *node2, Node *parent){
	if(node2){
		*node1 = new Node(node2->value, parent);
		deep_copy(&((*node1)->left), node2->left, *node1);
		deep_copy(&((*node1)->right), node2->right, *node1);
	}
}

public:
map (const map& x){
	*this = x;
}

~map(){
	clear();
}

map& operator= (const map& x){
	clear();
	deep_copy(&root, x.root, NULL);
	len = x.len;
	comp = x.comp;
}

// --------------------------------------------------
// ELEMENT_ACCESS

mapped_type& operator[] (const key_type& k){
	pair<iterator, bool> res = 
		insert(value_type(k, mapped_type()));
	Node *node = res.first.node;
	return node->value.second;
}

// --------------------------------------------------
// ITERATORS

iterator begin(){
	Node *n = root;
	while (n && n->left)
		n = n->left;
	return iterator(this, n);
}
const_iterator begin() const{
	Node *n = root;
	while (n && n->left)
		n = n->left;
	return const_iterator(this, n);
}

iterator end(){
	return iterator(this, NULL);
}
const_iterator end() const{
	return const_iterator(this, NULL);
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

bool empty() const {
	return (len == 0);
}

size_type size() const{
	return len;
}

size_type max_size() const{
	return 461168601842738790;
}

// --------------------------------------------------
// MODIFIERS
private:
void clear(Node *n){
	if(n){
		clear(n->left);
		clear(n->right);
		delete n;
	}
}
public:
void clear(){
	clear(root);
	root = NULL;
	len = 0;
}

private:

int getHeight(Node *head){
	if(head==NULL) return 0;
	return head->height;
}

Node *rightRotation(Node *head){
	Node *newhead = head->left;
	head->setLeftChild(newhead->right);
	newhead->parent = head->parent;
	newhead->setRightChild(head);
	return newhead;
}

Node *leftRotation(Node *head){
	Node *newhead = head->right;
	head->setRightChild(newhead->left);
	newhead->parent = head->parent;
	newhead->setLeftChild(head);
	return newhead;
}

Node *balanceUtil(Node *head, bool afterInsert, key_type x){
	int bal = getHeight(head->left) - getHeight(head->right);
	bool afterDelete = !afterInsert;
	bool cond;
	if(bal > 1) {
		cond = (comp2(head->left->value.first, x));
		if (afterDelete)
			cond = (comp2(x, head->left->value.first));
		if (cond)
			head->setLeftChild(leftRotation(head->left));
		return rightRotation(head);
	}
	else if(bal < (-1)) {
		cond = (comp2(x, head->right->value.first));
		if (afterDelete)
			cond = (comp2(head->right->value.first, x));
		if (cond)
			head->setRightChild(rightRotation(head->right));
		return leftRotation(head);
	}
	return head;
}

// first is true if a node was actually added, ie if x not yet in there
// the second variable of the triplet is the pointer to the node containing x
// the third argument is the new root after balancing
triplet<bool,Node*,Node*> insertUtil(Node *head, 
								value_type val, Node *parent){
	triplet< bool, Node* , Node* > p;
	if(head == NULL){
		++len;
		Node *temp = new Node(val, parent);
		p.first = true;
		p.second = temp;
		p.third = temp;
		return p;
	}
	else if(comp(val, head->value)) {
		p = insertUtil(head->left, val, head);
		head->setLeftChild(p.third);
	}
	else if(comp(head->value, val)) {
		p = insertUtil(head->right, val, head);
		head->setRightChild(p.third);
	}
	else { // if (value.first == head->value.first)
		p.first = false;
		p.second = head;
		p.third = head;
		return p;
	}
	// head->height = 1 + max(getHeight(head->left), getHeight(head->right));
	head = balanceUtil(head, true, val.first);
	p.third = head;
	return p;
}

public:
pair<iterator,bool> insert (const value_type& val){
	triplet<bool, Node* , Node* > p = 
		insertUtil(root, val, NULL);
	root = p.third;
	iterator it = iterator(this, p.second);
	pair<iterator,bool> p2 = pair<iterator,bool>(it, p.first);
	return p2;
}

iterator insert (iterator hint, const value_type& val){
	// not using the hint (not optimized but the output is the same anyway)
	(void)hint;
	pair<iterator,bool> p = insert(val);
	return p.first; 
}

template <class InputIterator>
void insert (InputIterator first, InputIterator last){
	while (first != last){
		insert(*first);
		++first;
	}				
}

private:
Node *eraseUtil(Node *head, key_type x){
	if(head == NULL)
		return NULL;
	if(comp2(x, head->value.first)){
		head->setLeftChild(eraseUtil(head->left, x));
	}
	else if(comp2(head->value.first, x)){
		head->setRightChild(eraseUtil(head->right, x));
	}
	else{
		Node *r = head->right;
		if(head->right == NULL){
			Node *l = head->left;
			delete(head);
			head = l;
			--len;
		}
		else if(head->left == NULL){
			delete(head);
			head = r;
			--len;
		}
		else{
			while(r->left != NULL)
				r = r->left;
			head->value = r->value;
			head->setRightChild(eraseUtil(head->right, r->value.first));
		}
	}
	if(head == NULL)
		return head;
	// head->height = 1 + max(getHeight(head->left), getHeight(head->right));
	head = balanceUtil(head, false, x);
	return head;
}

public:
void erase (iterator position){
	Node *node = position.node;
	key_type k = node->value.first;
	root = eraseUtil(root, k);
}

size_type erase (const key_type& k){
	root = eraseUtil(root, k);
}

void erase (iterator first, iterator last){
	key_type tmp;
	while((*first) != (*last)){
		tmp = (*(first)).first;
		// std::cout <<"--------------" << std::endl;
		// std::cout << this->len << std::endl;
		// print();
		// std::cout <<"erasing "<< (*first).first << std::endl;
		erase(first);
		// std::cout <<"--------------" << std::endl;
		// std::cout << this->len << std::endl;
		// print();
		if((*(first)).first == tmp)
			++first; // = tmp;
	}
}

void swap (map& x){
	Node *root2 = root;
	size_t len2 = len;
	key_compare comp2_2 = comp2;
	value_compare comp_2 = comp;
	root = x.root;
	len = x.len;
	comp = x.comp;
	comp2 = x.comp2;
	x.root = root2;
	x.len = len2;
	x.comp = comp_2;
	x.comp2 = comp2_2;
}

// --------------------------------------------------
// LOOKUP

size_type count (const key_type& k) const{
	iterator it = find(k);
	if(it == end())
		return 0;
	else
		return 1;
}

private:
Node *findUtil(Node *head, key_type x){
	if(head == NULL)
		return NULL;
	key_type k = head->value.first;
	if(comp2(x, k))
		return findUtil(head->left, x);
	else if(comp2(k, x))
		return findUtil(head->right, x);
	else //if(k == x)
		return head;
}

public:
iterator find (const key_type& k){
	return iterator(this, findUtil(root, k));
}
const_iterator find (const key_type& k) const{
	return const_iterator(this, findUtil(root, k));
}

private:
Node *equalRangeUtil(Node *head, key_type x){
	if(head == NULL)
		return NULL;
	key_type k = head->value.first;
	if(comp2(x, k)){		
		if(head->left == NULL)
			return head;
		else
			return equalRangeUtil(head->left, x);
	}
	else if(comp2(k, x)){
		if(head->right == NULL){
			iterator it = iterator(this, head);
			++it;
			return it.node;
		}
		else
			return equalRangeUtil(head->right, x);
	}
	else //if(k == x)
		return head;
}

public:
pair<iterator,iterator> equal_range (const key_type& k){
	Node * node = equalRangeUtil(root, k);
	iterator it = iterator(this, node);
	if(node->value.first == k)
		return (pair<iterator,iterator>(it, (it + 1)));
	else
		return (pair<iterator,iterator>(it, it));
}
pair<const_iterator,const_iterator> equal_range (const key_type& k) const{
	Node * node = equalRangeUtil(root, k);
	const_iterator it = const_iterator(this, node);
	if(node->value.first == k)
		return (pair<const_iterator,const_iterator>(it, (it + 1)));
	else
		return (pair<const_iterator,const_iterator>(it, it));
}

iterator lower_bound (const key_type& k){
	Node * node = equalRangeUtil(root, k);
	iterator it = iterator(this, node);
	return it;
}
const_iterator lower_bound (const key_type& k) const{
	Node * node = equalRangeUtil(root, k);
	const_iterator it = const_iterator(this, node);
	return it;
}

iterator upper_bound (const key_type& k){
	Node * node = equalRangeUtil(root, k);
	iterator it = iterator(this, node);
	if(node->value.first == k)
		++it;
	return it;
}
const_iterator upper_bound (const key_type& k) const{
	const_iterator it = upper_bound(k);
	return it;
}

// --------------------------------------------------
// OBSERVERS

key_compare key_comp() const{
	return comp2;
}

value_compare value_comp() const{
	return comp;
}

template <typename A, typename B, typename C>
friend class MapIterator;
template <typename A, typename B, typename C>
friend class ConstIterator;

void print(Node *node, int tabs){
	if(node == NULL)
		return;
	int i;
	print(node->right, tabs + 1);
	for (i=0; i < tabs; ++i){
		std::cout << "\t";
	}
	std::cout << node->value.first;
	std::cout << std::endl;
	print(node->left, tabs + 1);
}

void print(){
	if(root)
		print(root, 0);
}

};


// --------------------------------------------------
// NON MEMBER FUNCTIONS 1 : RELATIONAL OPERATORS
template <class Key, class T, class key_compare>
bool operator== (	const map<Key,T,key_compare>& a,
					const map<Key,T,key_compare>& b) {
	if (a.size() != b.size())
		return false;
	else {
		typename map<Key,T,key_compare>::const_iterator it1(a.begin());
		typename map<Key,T,key_compare>::const_iterator it2(b.begin());
		while(it1 != a.end() && it2 != b.end()) {
			if(*it1 != *it2)
				return false;
			++it1;
			++it2;
		}
		return (it1 == a.end() && it2 == b.end());
	}
}

template <class Key, class T, class key_compare>
bool operator<  ( const map<Key,T,key_compare>& a,
				const map<Key,T,key_compare>& b ){
	typename map<Key,T,key_compare>::const_iterator it1 = a.begin();
	typename map<Key,T,key_compare>::const_iterator it2 = b.begin();
	while(it1 != a.end() && it2 != b.end()){
		if(*it1 != *it2)
			return (*it1 < *it2);
		++it1;
		++it2;
	}
	return (it1 == a.end() && it2 != b.end());
}

template <class Key, class T, class key_compare >
bool operator!= (	const map<Key,T,key_compare>& a,
					const map<Key,T,key_compare>& b ){
	return (!(a==b));
}

template <class Key, class T, class key_compare >
bool operator<= ( const map<Key,T,key_compare>& a,
				const map<Key,T,key_compare>& b ){
	return (!(b < a));
}

template <class Key, class T, class key_compare >
bool operator>  ( const map<Key,T,key_compare>& a,
				const map<Key,T,key_compare>& b ){
	return (b < a);
}

template <class Key, class T, class key_compare >
bool operator>= ( const map<Key,T,key_compare>& a,
				const map<Key,T,key_compare>& b ){
	return (!(a < b));
}

// -------------------------------------------
// NON MEMBER FUNCTIONS 2

template <class Key, class T, class key_compare >
void swap (map<Key,T,key_compare>& x, map<Key,T,key_compare>& y){
	x.swap(y);
}

}


#endif