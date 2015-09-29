/*
 * DequeArray.hpp
 *
 *  Created on: Sep 28, 2015
 *      Author: Mahmoud Mheisen
 */

/*
 * Array based deque, resizable array:
 * a collection that acts as two sided stack
 * Double the size when full, half the size when quarter full
 * Resizing operation has an amortized time of O(1)
 */

/*
 * TODO:
 * cin >> s; and s has zero length - Read data from command line:
 * Dereferencing problem in iterator, also in other iterator
 * Add const iterator
 * Work with STL sort
 */

#ifndef SRC_DEQUEARRAY_HPP_
#define SRC_DEQUEARRAY_HPP_

// Include C++ libraries:
#include <iostream>
#include <string>
#include <sstream>

// Include project headers:
#include "Vector.hpp"
#include "utility.hpp"

template<class T = int>
class DequeArray {
public:
	// Default constructor:
	DequeArray();

	// Copy constructor:
	DequeArray(const DequeArray<T>& other);

	// Destructor:
	virtual ~DequeArray();

	// Assignment operator:
	const DequeArray<T>& operator=(const DequeArray<T>& other);

	// Add item to the end of the deque:
	void addBack(const T& item);

	// Add item to the start of the deque:
	void addFront(const T& item);

	// Remove item from the end of the deque:
	const T removeBack(void);

	// Remove item from the start of the deque:
	const T removeFront(void);

	// Peek at the end of the deque:
	const T back(void) const;

	// Peek at the start of the deque:
	const T front(void) const;

	// Operator <<: to quickly add elements to the deque:
	DequeArray<T>& operator<<(const T& item);

	// Operator >>: to quickly remove elements from the deque:
	DequeArray<T>& operator>>(T& item);

	// Clear the deque:
	void clear(void);

	// toString method:
	const std::string& toString(void) const;

	// Return the current number of elements inside the deque:
	inline unsigned int size(void) const {
		return elements.size();
	}

	// isEmpty method:
	inline bool isEmpty(void) const {
		return elements.isEmpty();
	}

	// Random access iterator to loop through the deque:
	class iterator : public Vector<T>::iterator {
	public:
		// Default constructor, will launch iterator constructor:
		iterator() : Vector<T>::iterator() {}

		// Constructor that lunch copy constructor of Vector iterator:
		iterator(const typename Vector<T>::iterator& iter) : Vector<T>::iterator(iter) {}
	};

	// Iterator that return the start of the deque:
	iterator begin(void) const {
		return iterator(elements.begin());
	}

	// Iterator that return the end of the deque:
	iterator end(void) const {
		return iterator(elements.end());
	}

private:
	// Member variables:
	Vector<T> elements;

	// Clone method for copying:
	void clone(const DequeArray<T>& other);

	// Test if the deque is quarter full:
	inline bool quarterFull(void) const {
		return elements.size() == elements.length() / 4;
	}

// Write data to command line:
template<class E>
friend std::ostream& operator<<(std::ostream& output, const DequeArray<E>& other);

};

// Default constructor:
template<class T>
DequeArray<T>::DequeArray()
:elements()
{
}

// Copy constructor:
template<class T>
DequeArray<T>::DequeArray(const DequeArray<T>& other) {
	// Deep copy:
	clone(other);
}

// Destructor:
template<class T>
DequeArray<T>::~DequeArray() {
	clear();
}

// Assignment operator:
template<class T>
const DequeArray<T>& DequeArray<T>::operator =(const DequeArray<T>& other) {
	// Clear this first:
	clear();

	// Deep copy and return:
	clone(other);
	return *this;
}

// Add item to the end of the deque:
template<class T>
void DequeArray<T>::addBack(const T& item) {
	elements.pushBack(item);
}

// Add item to the start of the deque:
template<class T>
void DequeArray<T>::addFront(const T& item) {
	elements.insert(0, item);
}

// Remove item from the end of the deque:
template<class T>
const T DequeArray<T>::removeBack(void) {
	// Checking:
	Error(isEmpty(), "Deque is Empty");

	// Decrease the current size and return the element:
	T item = elements.popBack();

	// If quarter full cut the length to half:
	if(quarterFull()) elements.resize(elements.length() / 2);

	return item;
}

// Remove item from the start of the deque:
template<class T>
const T DequeArray<T>::removeFront(void) {
	// Checking:
	Error(isEmpty(), "Deque is Empty");

	// Decrease the current size and return the element:
	T item = elements.remove(0);

	// If quarter full cut the length to half:
	if(quarterFull()) elements.resize(elements.length() / 2);

	return item;
}

// Peek at the end of the deque:
template<class T>
const T DequeArray<T>::back(void) const {
	// Checking:
	Error(isEmpty(), "Deque is Empty");

	return elements.back();
}

// Peek at the start of the deque:
template<class T>
const T DequeArray<T>::front(void) const {
	// Checking:
	Error(isEmpty(), "Deque is Empty");

	return elements.front();
}

// Operator <<: to quickly add elements to the deque:
template<class T>
DequeArray<T>& DequeArray<T>::operator <<(const T& item) {
	addBack(item);
	return *this;
}

// Operator >>: to quickly remove elements from the deque:
template<class T>
DequeArray<T>& DequeArray<T>::operator >>(T& item) {
	item = removeBack();
	return *this;
}

// Clear the deque:
template<class T>
void DequeArray<T>::clear(void) {
	elements.clear();
}

// toString method:
template<class T>
const std::string& DequeArray<T>::toString(void) const {
	std::ostringstream oss;
	oss << *this;
	return oss.str();
}

// Clone method for copying:
template<class T>
void DequeArray<T>::clone(const DequeArray<T>& other) {
	this->elements = other.elements;
}

// Write data to command line:
template<class E>
std::ostream& operator<<(std::ostream& output, const DequeArray<E>& other) {
	// Check:
	if(other.isEmpty())
		return output << "Deque is Empty";

	return output << other.elements;
}

#endif /* SRC_DEQUEARRAY_HPP_ */





















