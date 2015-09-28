/*
 * StackArray.hpp
 *
 *  Created on: Sep 7, 2015
 *      Author: Mahmoud Mheisen
 */

/*
 * Array based Stack, resizable array:
 * a collection that processes values in a last-in/first-out (LIFO) order.
 * Double the size when full, half the size when quarter full
 * Resizing operation has an amortized time of O(1)
 */

/*
 * TODO:
 * cin >> s; and s has zero length - Read data from command line:
 * Add const iterator
 * Work with STL sort
 */

#ifndef SRC_STACKARRAY_HPP_
#define SRC_STACKARRAY_HPP_

// Include C++ Libraries:
#include <iostream>
#include <sstream>
#include <string>

// Include project headers:
#include "Vector.hpp"
#include "utility.hpp"

// Default type is int:
template <class T = int>
class StackArray {
public:
	// Constructor:
	StackArray();

	// Copy Constructor:
	StackArray(const StackArray& other);

	// Destructor:
	virtual ~StackArray(void);

	// Assignment operator:
	StackArray<T>& operator=(const StackArray<T>& other);

	// Push element at the top of the stack:
	void push(const T& element);

	// Pop element from the top of the stack:
	T pop(void);

	// Return the top of the stack without removing it:
	T top(void) const;

	// toString method:
	std::string toString(void) const;

	// Operator <<: to quickly add elements to the stack:
	StackArray<T>& operator<<(const T& value);

	// Operator >>: to quickly remove elements from the stack:
	StackArray<T>& operator>>(T& value);

	// Clear the stack:
	void clear(void);

	// Return current number of elements in the stack:
	inline unsigned int size(void) const {
		return elements.size();
	}

	// isEmpty method:
	inline bool isEmpty(void) const {
		return elements.isEmpty();
	}

	// Random access iterator to loop through the stack:
	class iterator : public Vector<T>::iterator {
	public:
		iterator() : Vector<T>::iterator() {}
		iterator(const typename Vector<T>::iterator& it) : Vector<T>::iterator(it) {}
	};

    // Iterator that return the beginning of the stack:
    iterator begin(void) const {
        return iterator(elements.begin());
    }

    // Iterator that return the end of the stack:
    iterator end(void) const {
        return iterator(elements.end());
    }

private:
	// Member variables:
	Vector<T> elements;

	inline bool quarterFull(void) const {
		return elements.size() == elements.length() / 4;
	}

// Write data to command line:
template<class E>
friend std::ostream& operator<<(std::ostream& output, const StackArray<E>& other);

};

// Constructor:
template <class T>
StackArray<T>::StackArray()
:elements()
{
}

// Copy Constructor:
template <class T>
StackArray<T>::StackArray(const StackArray& other) {
	this->elements = other.elements;
}

// Destructor:
template <class T>
StackArray<T>::~StackArray(void) {
	clear();
}

// Assignment operator:
template <class T>
StackArray<T>& StackArray<T>::operator=(const StackArray<T>& other) {
	this->elements = other.elements;
}

// Push element at the top of the stack:
template <class T>
void StackArray<T>::push(const T& element) {
	// Add the element and increase the current size, vector will double its size automatically:
	elements << element;
}

// Pop element from the top of the stack:
template <class T>
T StackArray<T>::pop(void) {
	// If empty throw runtime error:
	Error(isEmpty(), "Stack Underflow");

	// Decrease the current size and return the element:
	T item = elements.popBack();

	// If the array is quarter full cut the length to half:
	if(quarterFull()) elements.resize(elements.length() / 2);

	return item;
}

// Return the top of the stack without removing it:
template <class T>
T StackArray<T>::top(void) const {
	// If empty throw runtime error:
	Error(isEmpty(), "Stack Underflow");

	return elements.back();
}

// toString method:
template <class T>
std::string StackArray<T>::toString(void) const {
	// Make an output string stream and insert this into it:
    std::ostringstream oss;
    oss << *this;

    // Transform the string stream to string:
    return oss.str();
}

// Operator <<: to quickly add elements to the stack:
template<class T>
StackArray<T>& StackArray<T>::operator<<(const T& value) {
	this->elements << value;
	return *this;
}

// Operator >>: to quickly remove elements from the stack:
template<class T>
StackArray<T>& StackArray<T>::operator>>(T& value) {
	value = pop();
	return *this;
}

// Clear the stack:
template<class T>
void StackArray<T>::clear(void) {
	elements.clear();
}

// Write data to command line:
template<class E>
std::ostream& operator<<(std::ostream& output, const StackArray<E>& other) {
	// Check if Empty:
	if(other.isEmpty()) {
		output << "The stack is empty" ;
		return output;
	}

	return output << other.elements;
}

#endif /* SRC_STACKARRAY_HPP_ */




