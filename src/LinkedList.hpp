/*
 * LinkedList.hpp
 *
 *  Created on: Sep 27, 2015
 *      Author: Mahmoud Mheisen
 */

#ifndef SRC_LINKEDLIST_HPP_
#define SRC_LINKEDLIST_HPP_

// Include C++ libraries:
#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

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
	LinkedList<T>& operator=(LinkedList<T>& other);

	// Push at the end of the list:
	void pushBack(const T& value);

	// Push at the beginning of the list:
	void pushFront(const T& value);

	// Operator <<: to add elements quickly to the end of the list:
	LinkedList<T>& operator<<(const T& value);

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
	void set(const unsigned int& index);

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
	Node<T>* head;
	Node<T>* current;
	unsigned int count;

	// Clone method:
	void clone(LinkedList<T>& other);

};

#endif /* SRC_LINKEDLIST_HPP_ */
















