#include <list>
#include <map>
#include <queue>
#include <stack>
#include <vector>

#include "list.hpp"
#include "map.hpp"
#include "queue.hpp"
#include "stack.hpp"
#include "vector.hpp"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <assert.h>
#include <stdexcept>


// -----------------------------------------
//                  UTILS
// -----------------------------------------

std::ofstream ft_output, std_output;

void debutNewTest(std::string testName){
	std::string sep =  "\n-------------------------\n";
	std::string spaces = "       ";
	std_output << std::endl << sep << spaces << testName << sep << std::endl;
	ft_output  << std::endl << sep << spaces << testName << sep << std::endl;
}

// ft::list<int> *l2
template<typename T>
void print_iterator(T &l2, std::ofstream &o){
	typename T::iterator it2;
	o << std::endl << "size: " << l2.size() << std::endl;
	it2 = l2.begin();
	o << "[";
	while(it2 != l2.end()){
		o << *it2;
		++it2;
		if(it2 != l2.end())
			o << ", ";
	}
	o << "]" << std::endl;
}


template<typename T, typename U>
bool are_equals(T &l1, U &l2){
	typename T::iterator it1 = l1.begin() ;
	typename T::iterator end1 = l1.end() ;
	typename U::iterator it2 = l2.begin();
	typename U::iterator end2 = l2.end();
	while((it1 != end1) && (it2 != end2)){
		if(*it1 != *it2)
			return false;
		++it1;
		++it2;
	}
	return ((it1 == end1) && (it2 == end2));
	// if(! ((it1 == end1) && (it2 == end2)) )
	//     throw std::exception("lists are not equal");
}



// -----------------------------------------
//                  LIST
// -----------------------------------------

bool test_list_1(){
	// http://www.cplusplus.com/reference/list/list/insert/
	debutNewTest("test_list_1");

//-----------------------------
	std::list<int> mylist;
	std::list<int>::iterator it;
	// set some initial values:
	for (int i=1; i<=5; ++i) mylist.push_back(i); // 1 2 3 4 5
	it = mylist.begin();
	++it;       // it points now to number 2           ^
	mylist.insert (it,10);                        // 1 10 2 3 4 5
	// "it" still points to number 2                      ^
	mylist.insert (it,2,20);                      // 1 10 20 20 2 3 4 5
	--it;       // it points now to the second 20            ^
	std::vector<int> myvector (2,30);
	mylist.insert (it,myvector.begin(),myvector.end());
										// 1 10 20 30 30 20 2 3 4 5
										//               ^
	std_output << "mylist contains:";
	for (it=mylist.begin(); it!=mylist.end(); ++it)
		std_output << ' ' << *it;
	std_output << '\n';

	//-----------------------------
	ft::list<int> mylist_ft;
	ft::list<int>::iterator it2;
	// set some initial values:
	for (int i=1; i<=5; ++i) mylist_ft.push_back(i); // 1 2 3 4 5
	it2 = mylist_ft.begin();
	++it2;       // it2 points now to number 2           ^
	mylist_ft.insert (it2,10);                        // 1 10 2 3 4 5
	// "it2" still points to number 2                      ^
	mylist_ft.insert (it2,(size_t)2,20);                      // 1 10 20 20 2 3 4 5
	--it2;       // it2 points now to the second 20            ^
	ft::vector<int> myvector2 ((size_t)2,30);
	mylist_ft.insert (it2,myvector.begin(),myvector.end());
										// 1 10 20 30 30 20 2 3 4 5
										//               ^
	ft_output << "mylist contains:";
	for (it2=mylist_ft.begin(); it2!=mylist_ft.end(); ++it2)
		ft_output << ' ' << *it2;
	ft_output << '\n';
	
	// mylist.pop_back();
	return are_equals(mylist_ft, mylist);
}


bool test_list_2(){
	// http://www.cplusplus.com/reference/list/list/erase/
	debutNewTest("test_list_2");

	std::list<int> mylist;
	std::list<int>::iterator it1,it2;
	// set some values:
	for (int i=1; i<10; ++i)
		mylist.push_back(i*10);
								// 10 20 30 40 50 60 70 80 90
	it1 = it2 = mylist.begin(); // ^^
	advance (it2,6);            // ^                 ^
	++it1;                      //    ^              ^
	it1 = mylist.erase (it1);   // 10 30 40 50 60 70 80 90
								//    ^           ^
	it2 = mylist.erase (it2);   // 10 30 40 50 60 80 90
								//    ^           ^
	++it1;                      //       ^        ^
	--it2;                      //       ^     ^
	mylist.erase (it1,it2);     // 10 30 60 80 90
								//        ^
	std_output << "mylist contains:";
	for (it1=mylist.begin(); it1!=mylist.end(); ++it1)
		std_output << ' ' << *it1;
	std_output << '\n';
	
	// ------------------------------------

	ft::list<int> mylistft;
	ft::list<int>::iterator it1ft,it2ft;
	for (int i=1; i<10; ++i)
		mylistft.push_back(i*10);
	it1ft = it2ft = mylistft.begin(); 
	// advance (it2ft,6);
	it2ft = it2ft + 6;
	++it1ft;
	it1ft = mylistft.erase (it1ft);
	it2ft = mylistft.erase (it2ft);
	++it1ft; 
	--it2ft;
	mylistft.erase (it1ft,it2ft);
	ft_output << "mylist contains:";
	for (it1ft=mylistft.begin(); it1ft!=mylistft.end(); ++it1ft)
		ft_output << ' ' << *it1ft;
	ft_output << '\n';

	return true;
}


bool compare_nocase (const std::string& first, const std::string& second) {
	unsigned int i=0;
	while ( (i<first.length()) && (i<second.length()) ){
		if (tolower(first[i])<tolower(second[i]))
			return true;
		else if (tolower(first[i])>tolower(second[i]))
			return false;
		++i;
	}
	return ( first.length() < second.length() );
}

bool test_list_3(){
	// http://www.cplusplus.com/reference/list/list/erase/
	debutNewTest("test_list_3");
	{
		std::list<std::string> mylist;
		mylist.push_back ("one");
		mylist.push_back ("two");
		mylist.push_back ("Three");
		mylist.sort();
		print_iterator(mylist, std_output);
		mylist.sort(compare_nocase);
		print_iterator(mylist, std_output);
	}
	{
		ft::list<std::string> mylist;
		mylist.push_back ("one");
		mylist.push_back ("two");
		mylist.push_back ("Three");
		mylist.sort();
		print_iterator(mylist, ft_output);
		mylist.sort(compare_nocase);
		print_iterator(mylist, ft_output);
	}
	return true;
}


bool test_list_4(){
	debutNewTest("test_list_4");
	int tab[6]={45, 3, 18, 11, -10, -8};
	ft::list<int> mylistft;
	std::list<int> mylist;
	mylist.insert(mylist.begin(), tab, tab + (sizeof(tab)/sizeof(*tab)));
	mylistft.insert(mylistft.begin(), tab, tab + (sizeof(tab)/sizeof(*tab)));
	mylist.sort();
	mylistft.sort();
	print_iterator(mylist, std_output);
	print_iterator(mylistft, ft_output);
	return are_equals(mylist, mylistft);
}

bool test_list_5(){
	debutNewTest("test_list_5");
	{
		std::list<int> mylist;
		for (int i=1; i<=5; ++i)
			mylist.push_back(i);
		std_output << "mylist backwards:";
		for (std::list<int>::reverse_iterator rit=mylist.rbegin(); rit!=mylist.rend(); ++rit)
			std_output << ' ' << *rit;
		std_output << '\n';
	}
	{
		ft::list<int> mylist;
		for (int i=1; i<=5; ++i)
			mylist.push_back(i);
		ft_output << "mylist backwards:";
		for (ft::list<int>::reverse_iterator rit=mylist.rbegin(); rit!=mylist.rend(); ++rit)
			ft_output << ' ' << *rit;
		ft_output << '\n';
	}
	return true;
}

bool tests_list(){
	// try{
	// 	test_list_1();
	// } catch (std::exception& e){
	// 	std::cout << e.what() << std::endl;
	// }
	assert(test_list_1());
	assert(test_list_2());
	assert(test_list_3());
	assert(test_list_4());
	assert(test_list_5());
	return true;
}


// -----------------------------------------
//                  MAP
// -----------------------------------------

bool test_map_1(){
	debutNewTest("test_map_1");
	// http://www.cplusplus.com/reference/map/map/operator[]/
	std::map<char,std::string> mymap;
	mymap['a']="an element";
	mymap['b']="another element";
	mymap['c']=mymap['b'];
	std_output << "mymap now contains " << mymap.size() << " elements.\n";
	std_output << "mymap['a'] is " << mymap['a'] << '\n';
	std_output << "mymap['b'] is " << mymap['b'] << '\n';
	std_output << "mymap['c'] is " << mymap['c'] << '\n';
	std_output << "mymap['d'] is " << mymap['d'] << '\n';
	std_output << "mymap now contains " << mymap.size() << " elements.\n";

	//-----------------------------
	ft::map<char,std::string> mymap_ft;
	mymap_ft['a']="an element";
	mymap_ft['b']="another element";
	mymap_ft['c']=mymap['b'];
	ft_output << "mymap now contains " << mymap_ft.size() << " elements.\n";
	ft_output << "mymap['a'] is " << mymap_ft['a'] << '\n';
	ft_output << "mymap['b'] is " << mymap_ft['b'] << '\n';
	ft_output << "mymap['c'] is " << mymap_ft['c'] << '\n';
	ft_output << "mymap['d'] is " << mymap_ft['d'] << '\n';
	ft_output << "mymap now contains " << mymap_ft.size() << " elements.\n";
	return true;
}

bool test_map_2(){
	debutNewTest("test_map_2");
	std::map<char,int> mymap;
	// first insert function version (single parameter):
	mymap.insert ( std::pair<char,int>('a',100) );
	mymap.insert ( std::pair<char,int>('z',200) );
	std::pair<std::map<char,int>::iterator,bool> ret;
	ret = mymap.insert ( std::pair<char,int>('z',500) );
	if (ret.second==false) {
		std_output << "element 'z' already existed";
		std_output << " with a value of " << ret.first->second << '\n';
	}
	// second insert function version (with hint position):
	std::map<char,int>::iterator it = mymap.begin();
	mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
	mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting
	// third insert function version (range insertion):
	std::map<char,int> anothermap;
	anothermap.insert(mymap.begin(),mymap.find('c'));
	// showing contents:
	std_output << "mymap contains:\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std_output << it->first << " => " << it->second << '\n';
	std_output << "anothermap contains:\n";
	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
		std_output << it->first << " => " << it->second << '\n';

	//-----------------------------
	ft::map<char,int> mymapft;
	// first insert function version (single parameter):
	mymapft.insert ( ft::pair<char,int>('a',100) );
	mymapft.insert ( ft::pair<char,int>('z',200) );
	ft::pair<ft::map<char,int>::iterator,bool> retft;
	retft = mymapft.insert ( ft::pair<char,int>('z',500) );
	if (retft.second==false) {
		ft_output << "element 'z' already existed";
		ft_output << " with a value of " << (*(retft.first)).second << '\n';
	}
	// second insert function version (with hint position):
	ft::map<char,int>::iterator itft = mymapft.begin();
	mymapft.insert (itft, ft::pair<char,int>('b',300));  // max efficiency inserting
	mymapft.insert (itft, ft::pair<char,int>('c',400));  // no max efficiency inserting
	// third insert function version (range insertion):
	ft::map<char,int> anothermapft;
	anothermapft.insert(mymapft.begin(),mymapft.find('c'));
	// showing contents:
	ft_output << "mymap contains:\n";
	for (itft=mymapft.begin(); itft!=mymapft.end(); ++itft)
		ft_output << (*itft).first << " => " << (*itft).second << '\n';
	ft_output << "anothermap contains:\n";
	for (itft=anothermapft.begin(); itft!=anothermapft.end(); ++itft)
		ft_output << (*itft).first << " => " << (*itft).second << '\n';

	return true;
}

bool test_map_3(){
	debutNewTest("test_map_3");
	std::map<char,int> mymap;
	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;
	// show content:
	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std_output << it->first << " => " << it->second << '\n';

	// --------------------------------------
	ft::map<char,int> mymap2;
	mymap2['b'] = 100;
	mymap2['a'] = 200;
	mymap2['c'] = 300;
	// show content:
	for (ft::map<char,int>::iterator it2=mymap2.begin(); it2!=mymap2.end(); ++it2)
		ft_output << it2->first << " => " << it2->second << '\n';

	return true;
}

bool test_map_4(){
	debutNewTest("test_map_4");
	{
		std::map<char,int> mymap;
		std::map<char,int>::iterator itlow,itup;
		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;
		itlow=mymap.lower_bound ('b');  // itlow points to b
		itup=mymap.upper_bound ('d');   // itup points to e (not d!)
		mymap.erase(itlow,itup);        // erases [itlow,itup)
		for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std_output << it->first << " => " << it->second << '\n';
	}
	{
		ft::map<char,int> mymap;
		ft::map<char,int>::iterator itlow,itup;
		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;
		itlow=mymap.lower_bound ('b');  // itlow points to b
		itup=mymap.upper_bound ('d');   // itup points to e (not d!)
		mymap.erase(itlow,itup);        // erases [itlow,itup)
		for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			ft_output << it->first << " => " << it->second << '\n';
	}
	return true;
}

bool test_map_5(){
	debutNewTest("test_map_5");
	{
		std::map<char,int> mymap;
		mymap['x'] = 100;
		mymap['y'] = 200;
		mymap['z'] = 300;
		std::map<char,int>::reverse_iterator rit;
		for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
			std_output << rit->first << " => " << rit->second << '\n';
	}
	{
		ft::map<char,int> mymap;
		mymap['x'] = 100;
		mymap['y'] = 200;
		mymap['z'] = 300;
		ft::map<char,int>::reverse_iterator rit;
		for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
			ft_output << rit->first << " => " << rit->second << '\n';
	}
	return true;
}

void test_map_last(){
	ft::map<int,int> mymap;
	for(int i=0; i<10; i++){
		std::cout << "\n--------------------\n";
		std::cout << "size: " << mymap.size();
		std::cout << "\n--------------------\n";
		mymap[i] = i;
		mymap.print();
		std::cout << "\n--------------------\n";
	}
	mymap.clear();
	std::cout << "size after clear: " << mymap.size();
}

bool tests_map(){
	assert(test_map_1());
	assert(test_map_2());
	assert(test_map_3());
	assert(test_map_4());
	assert(test_map_5());
	test_map_last();
	return true;
}


// -----------------------------------------
//                  QUEUE
// -----------------------------------------

bool test_queue_1(){
	debutNewTest("test_queue_1");
	std::queue<int> myqueue;
	myqueue.push(77);
	myqueue.push(16);
	myqueue.front() -= myqueue.back();    // 77-16=61
	std_output << "myqueue.front() is now " << myqueue.front() << '\n';
	// ----------------
	ft::queue<int> myqueue2;
	myqueue2.push(77);
	myqueue2.push(16);
	myqueue2.front() -= myqueue2.back();    // 77-16=61
	ft_output << "myqueue.front() is now " << myqueue2.front() << '\n';
	return true;
}


bool test_queue_2(){
	debutNewTest("test_queue_2");
	std::queue<int> myqueue;
	ft::queue<int> myqueue2;
	int myint;
	std::cout << "Please enter some integers (finish with 0):\n";
	do {
		std::cin >> myint;
		myqueue.push (myint);
		myqueue2.push (myint);
	} while (myint);

	std_output << "myqueue contains: ";
	while (!myqueue.empty()){
		std_output << ' ' << myqueue.front();
		myqueue.pop();
	}
	std_output << '\n';

	ft_output << "myqueue contains: ";
	while (!myqueue2.empty()){
		ft_output << ' ' << myqueue2.front();
		myqueue2.pop();
	}
	ft_output << '\n';
	return true;
}

bool tests_queue(){
	assert(test_queue_1());
	assert(test_queue_2());
	return true;
}



// -----------------------------------------
//                  STACK
// -----------------------------------------

bool test_stack_1(){
	debutNewTest("test_stack_1");
	std::stack<int> mystack;
	for (int i=0; i<5; ++i) mystack.push(i);
	std_output << "Popping out elements...";
	while (!mystack.empty()){
		std_output << ' ' << mystack.top();
		mystack.pop();
	}
	std_output << '\n';
	// ------------------
	ft::stack<int> mystack2;
	for (int i=0; i<5; ++i) mystack2.push(i);
	ft_output << "Popping out elements...";
	while (!mystack2.empty()){
		ft_output << ' ' << mystack2.top();
		mystack2.pop();
	}
	ft_output << '\n';
	return true;
}

bool test_stack_2(){
	debutNewTest("test_stack_2");
	std::stack<int> myints;
	std_output << "0. size: " << myints.size() << '\n';
	for (int i=0; i<5; i++) myints.push(i);
		std_output << "1. size: " << myints.size() << '\n';
	myints.pop();
	std_output << "2. size: " << myints.size() << '\n';
	// -----------------
	ft::stack<int> myints2;
	ft_output << "0. size: " << myints2.size() << '\n';
	for (int i=0; i<5; i++) myints2.push(i);
		ft_output << "1. size: " << myints2.size() << '\n';
	myints2.pop();
	ft_output << "2. size: " << myints2.size() << '\n';
	return true;
}

bool tests_stack(){
	assert(test_stack_1());
	assert(test_stack_2());
	return true;
}


// -----------------------------------------
//                  VECTOR
// -----------------------------------------

bool test_vector_1(){
	debutNewTest("test_vector_1");
	{
		std::vector<int>::size_type sz;
		std::vector<int> foo;
		sz = foo.capacity();
		std_output << "making foo grow:\n";
		for (int i=0; i<100; ++i) {
			foo.push_back(i);
			if (sz!=foo.capacity()) {
				sz = foo.capacity();
				std_output << "capacity changed: " << sz << '\n';
			}
		}
		std::vector<int> bar;
		sz = bar.capacity();
		bar.reserve(100);   // this is the only difference with foo above
		std_output << "making bar grow:\n";
		for (int i=0; i<100; ++i) {
			bar.push_back(i);
			if (sz!=bar.capacity()) {
				sz = bar.capacity();
				std_output << "capacity changed: " << sz << '\n';
			}
		}
	}
	// ----------------------------------
	{
		ft::vector<int>::size_type sz;
		ft::vector<int> foo;
		sz = foo.capacity();
		ft_output << "making foo grow:\n";
		for (int i=0; i<100; ++i) {
			foo.push_back(i);
			if (sz!=foo.capacity()) {
				sz = foo.capacity();
				ft_output << "capacity changed: " << sz << '\n';
			}
		}
		ft::vector<int> bar;
		sz = bar.capacity();
		bar.reserve(100);   // this is the only difference with foo above
		ft_output << "making bar grow:\n";
		for (int i=0; i<100; ++i) {
			bar.push_back(i);
			if (sz!=bar.capacity()) {
				sz = bar.capacity();
				ft_output << "capacity changed: " << sz << '\n';
			}
		}
	}
	return true;
}

bool test_vector_2(){
	debutNewTest("test_vector_2");
	{
		std::vector<int> myvector;
		for (int i=1; i<=10; i++)
			myvector.push_back(i);
		print_iterator(myvector, std_output);
		myvector.erase (myvector.begin()+5);
		print_iterator(myvector, std_output);
		myvector.erase (myvector.begin(),myvector.begin()+3);
		print_iterator(myvector, std_output);
	}
	{
		ft::vector<int> myvector;
		for (int i=1; i<=10; i++)
			myvector.push_back(i);
		print_iterator(myvector, ft_output);
		myvector.erase (myvector.begin()+5);
		print_iterator(myvector, ft_output);
		myvector.erase (myvector.begin(),myvector.begin()+3);
		print_iterator(myvector, ft_output);
	}
	return true;
}


bool test_vector_3(){
	debutNewTest("test_vector_3");
	{
		std::vector<int> myvector;
		for (int i=1;i<10;i++) myvector.push_back(i);
		myvector.resize(5);
		myvector.resize(8,100);
		myvector.resize(12);
		print_iterator(myvector, std_output);
	}
	{
		ft::vector<int> myvector;
		for (int i=1;i<10;i++) myvector.push_back(i);
		myvector.resize(5);
		myvector.resize(8,100);
		myvector.resize(12);
		print_iterator(myvector, ft_output);
	}
	return true;
}


bool test_vector_4(){
	debutNewTest("test_vector_4");
	{
		std::vector<int> myvector (5);  // 5 default-constructed ints
		int i=0;
		std::vector<int>::reverse_iterator rit = myvector.rbegin();
		for (; rit!= myvector.rend(); ++rit)
			*rit = ++i;
		print_iterator(myvector, std_output);
	}
	{
		ft::vector<int> myvector (5);  // 5 default-constructed ints
		int i=0;
		ft::vector<int>::reverse_iterator rit = myvector.rbegin();
		for (; rit!= myvector.rend(); ++rit)
			*rit = ++i;
		print_iterator(myvector, ft_output);
	}
	return true;
}

bool tests_vector(){
	assert(test_vector_1());
	assert(test_vector_2());
	assert(test_vector_3());
	assert(test_vector_4());
	return true;
}

// -----------------------------------------
//                  MAIN
// -----------------------------------------

int main(int ac, char**av) {
	if (ac != 2){
		std::cout <<
		"Usage: ./a.out className (among list, map, queue, stack, vector)\n";
		return 1;
	}

	ft_output.open("list.ft.res");
	std_output.open("list.std.res");

	if (strcmp(av[1], "list") == 0)
		tests_list();
	else if (strcmp(av[1], "map") == 0)
		tests_map();
	else if (strcmp(av[1], "queue") == 0)
		tests_queue();
	else if (strcmp(av[1], "stack") == 0)
		tests_stack();
	else if (strcmp(av[1], "vector") == 0)
		tests_vector();

	ft_output.close();
	std_output.close();

	return 0;
}
