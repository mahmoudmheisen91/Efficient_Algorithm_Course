/*
 * LinkedList.hpp
 *
 *  Created on: Sep 27, 2015
 *      Author: Mahmoud Mheisen
 */

/*
 * LinkedList generic class stores list of values.
 * Has an iterator to loop through its content.
 */

/*
 * TODO:
 * Add iterator
 * Add constant iterator
 * Reverse iterators??
 * Add >> operator to take values until it hits enter
 * Add checkIndex method
 * Work with STL sort
 * Implement sublist Method
 * Make use of the tail
 * Double Linked List
 * Reduce the amount of code inside the insert and remove methods
 * Search??
 * []??
 * Add operators +, +=, etc ??
 * Advance ??
 * Traverse??
 * Visitor??
 */

// When declaring a new node, do not use new keyword, because we assign another pointer node
// to it and the allocated memory using new keyword is lost, the delete will remove the assigned
// pointer not the allocated chunk, just make a pointer:
// use this: Node<T>* current;
// not this: Node<T>* current = new Node<T>();

#ifndef SRC_LINKEDLIST_HPP_
#define SRC_LINKEDLIST_HPP_

// Include C++ libraries:
#include <iostream>
#include <string>
#include <sstream>

// Include Project headers:
#include "Node.hpp"
#include "utility.hpp"

template <class T = int>
class LinkedList {
public:
	// Default constructor:
	LinkedList();

	// Copy constructor:
	LinkedList(LinkedList<T>& other);

	// Destructor:
	virtual ~LinkedList();

	// Assignment operator:
	LinkedList<T>& operator=(const LinkedList<T>& other);

	// Push at the end of the list:
	void pushBack(const T& value);

	// Push at the beginning of the list:
	void pushFront(const T& value);

	// Operator <<: to add elements quickly to the end of the list:
	LinkedList<T>& operator<<(const T& value);

	// Operator >>: to pop elements quickly from the end of the list:
	LinkedList<T>& operator>>(T& value);

	// Pop from the end of the list:
	T popBack(void);

	// Pop from the beginning of the list:
	T popFront(void);

	// Insert before specified index:
	void insert(const unsigned int& index, const T& value);

	// Remove the node at the specified index:
	T remove(const unsigned int& index);

	// Return the beginning of list:
	T front(void) const;

	// Return the end of list:
	T back(void) const;

	// Get the element at specified index:
	T get(const unsigned int& index) const;

	// Set the element at specified index:
	void set(const unsigned int& index, const T& value);

	// Returns new list containing subset range of elements:
	LinkedList<T> sublist(const unsigned int& start, const unsigned int& length) const;

	// Clear list:
	void clear(void);

	// toString method:
	std::string toString(void) const;

	// isEmpty method:
	inline bool isEmpty(void) const {
		return (this->head == NULL);
	}

	// Return the current number of elements inside the list:
	inline unsigned int size(void) const {
		return this->count;
	}

private:
	// Member variables:
	Node<T>* head;		// beginning
	Node<T>* tail;		// end		(head------------tail)
	unsigned int count;	// current size

	// Clone method:
	void clone(const LinkedList<T>& other);

// Write date to command line:
template<class E>
friend std::ostream& operator<<(std::ostream& output, const LinkedList<E>& other);
};

// Default constructor:
template<class T>
LinkedList<T>::LinkedList() {
	// Init:
	this->head = NULL;
	this->tail = NULL;
	this->count = 0;
}

// Copy constructor:
template<class T>
LinkedList<T>::LinkedList(LinkedList<T>& other) {
	// Copy:
	clone(other);
}

// Destructor:
template<class T>
LinkedList<T>::~LinkedList() {
	// Clear this:
	clear();
}

// Assignment operator:
template<class T>
LinkedList<T>& LinkedList<T>::operator =(const LinkedList<T>& other) {
	// Clear this:
	clear();

	// Copy:
	clone(other);
	return *this;
}

// Push at the end of the list:
template<class T>
void LinkedList<T>::pushBack(const T& value) {
	insert(this->count, value);
}

// Push at the beginning of the list:
template<class T>
void LinkedList<T>::pushFront(const T& value) {
	insert(0, value);
}

// Operator <<: to add elements quickly to the end of the list:
template<class T>
LinkedList<T>& LinkedList<T>::operator<<(const T& value) {
	pushBack(value);
	return *this;
}

// Operator >>: to pop elements quickly from the end of the list:
template<class T>
LinkedList<T>& LinkedList<T>::operator>>(T& value) {
	value = popBack();
	return *this;
}

// Pop from the end of the list:
template<class T>
T LinkedList<T>::popBack(void) {
	return remove(count-1);
}

// Pop from the beginning of the list:
template<class T>
T LinkedList<T>::popFront(void) {
	return remove(0);
}

// Insert before specified index:
template<class T>
void LinkedList<T>::insert(const unsigned int& index, const T& value) {
	// Checking:
	Error(index < 0 || index > this->count, "Index out of Range");

	// Make new point that contain the value:
	Node<T>* newNode = new Node<T>(value);

	if (index == 0) {
		newNode->next = this->head;
		this->head = newNode;
		this->count++;
		return;
	}

	if (index == 1) {
		head->next = newNode;
		newNode->next = NULL;
		this->count++;
		return;
	}

	Node<T>* current = this->head;	// points to index
	Node<T>* prev = this->head;		// points before index

	// Advance the current and prev nodes:
	for(int i = 0; i < index - 1; i++) {
		current = current->next;
		prev = prev->next;
	}
	current = current->next;

	// Link and increase the size:
	newNode->next = current;
	prev->next = newNode;
	this->count++;
}

// Remove the node at the specified index:
template<class T>
T LinkedList<T>::remove(const unsigned int& index) {
	// Checking:
	Error(isEmpty(), "List is Empty");
	Error(index < 0 || index >= this->count, "Index out of Range");

	T temp;		// the return value

	Node<T>* old = this->head;
	if (index == 0) {
		this->head = head->next;
		temp = old->data;
		delete old;
		this->count--;
		return temp;
	}

	Node<T>* current = this->head;	// points to index
	Node<T>* prev = this->head;		// points before index

	// Advance to index:
	for(int i = 0; i < index-1; i++) {
		current = current->next;
		prev = prev->next;
	}
	current = current->next;

	// Link, delete and decrement the size:
	old = current;
	current = current->next;
	prev->next = current;
	temp = old->data;
	delete old;
	this->count--;
	return temp;
}

// Return the beginning of list:
template<class T>
T LinkedList<T>::front(void) const {
	return get(0);
}

// Return the end of list:
template<class T>
T LinkedList<T>::back(void) const {
	return get(count-1);
}

// Get the element at specified index:
template<class T>
T LinkedList<T>::get(const unsigned int& index) const {
	// Checking:
	Error(isEmpty(), "List is Empty");
	Error(index < 0 || index >= this->count, "Index out of Range");

	// Make new point that points to the head of the this list:
	Node<T>* current = this->head;

	// Advance to index:
	for(int i = 0; i < index; i++) {
		current = current->next;
	}

	return current->data;
}

// Get the element at specified index:
template<class T>
void LinkedList<T>::set(const unsigned int& index, const T& value) {
	// Checking:
	Error(isEmpty(), "List is Empty");
	Error(index < 0 || index >= this->count, "Index out of Range");

	// Make new point that points to the head of the this list:
	Node<T>* current = this->head;

	// Advance to index:
	for(int i = 0; i < index; i++) {
		current = current->next;
	}

	current->data = value;
}

// Clear list:
template<class T>
void LinkedList<T>::clear(void) {
	// Make new point that points to the head of the this list:
	Node<T>* current = NULL;

	// Delete head pointer and all other pointers:
	while(this->head != NULL) {
		// Assign current to head, move the head to next one, then remove the current,
		// do not delete the current before moving the head to the next one:
		current = head;
		head = head->next;
		delete current;
	}

	// Init:
	this->head = NULL;
	this->tail = NULL;
	this->count = 0;
}

// toString method:
template<class T>
std::string LinkedList<T>::toString(void) const {
	// Make an output string stream and insert this into it:
	std::ostringstream oss;
	oss << *this;

	// Transform the string stream to string:
	return oss.str();
}

// Clone method:
template<class T>
void LinkedList<T>::clone(const LinkedList<T>& other) {
	// Init:
	this->head = NULL;
	this->tail = NULL;
	this->count = 0;

	// Check if empty:
	if(other.isEmpty()) return;

	// Make new point that points to the head of the other list:
	Node<T>* current = other.head;

	// Deep copy:
	while(current != NULL) {
		pushBack(current->data);
		current = current->next;
	}
}

// Write date to command line:
template<class E>
std::ostream& operator<<(std::ostream& output, const LinkedList<E>& other) {
	// Check if empty:
	if(other.isEmpty()) {
		output << "List is Empty";
		return output;
	}

	// Make new point that points to the head of the other list:
	Node<E>* current = other.head;

	// Traverse:
	while(current != NULL) {
		output << current->data << " ";
		current = current->next;
	}

	return output;
}

#endif /* SRC_LINKEDLIST_HPP_ */
















