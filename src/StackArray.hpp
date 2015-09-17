/*
 * StackArray.hpp
 *
 *  Created on: Sep 7, 2015
 *      Author: Mahmoud Mheisen
 */

/*
 * Array based Stack, resizable array:
 * Double the size when full, half the size when quarter full
 * Resizing operation has an amortized time of O(1)
 */

/*
 * TODO:
 * cin >> s; and s has zero length - Read data from command line:
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
	virtual ~StackArray();

	// Push element at the top of the stack:
	void push(const T& element);

	// Pop element from the top of the stack:
	T pop();

	// Return the top of the stack without removing it:
	T top() const;

	// toString method:
	std::string toString() const;

	// Operator <<: to quickly add elements to the stack:
	StackArray<T>& operator<<(const T& value);

	// Operator >>: to quickly remove elements from the stack:
	StackArray<T>& operator>>(T& value);

	// Return current number of elements in the stack:
	inline unsigned int size() const {
		return elements.size();
	}

	// isEmpty method:
	inline bool isEmpty() const {
		return elements.isEmpty();
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
StackArray<T>::StackArray() {
}

// Copy Constructor:
template <class T>
StackArray<T>::StackArray(const StackArray& other) {
	this->elements = other.elements;
}

// Destructor:
template <class T>
StackArray<T>::~StackArray() {
}

// Push element at the top of the stack:
template <class T>
void StackArray<T>::push(const T& element) {
	// Add the element and increase the current size, vector will double its size automatically:
	elements << element;
}

// Pop element from the top of the stack:
template <class T>
T StackArray<T>::pop() {
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
T StackArray<T>::top() const {
	// If empty throw runtime error:
	Error(isEmpty(), "Stack Underflow");

	return elements.back();
}

// toString method:
template <class T>
std::string StackArray<T>::toString() const {
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

// Write data to command line:
template<class E>
std::ostream& operator<<(std::ostream& output, const StackArray<E>& other) {
	// Check if Empty:
	if(other.isEmpty()) {
		output << "The stack is empty" ;
		return output;
	}

	output << other.elements;
	return output;
}

#endif /* SRC_STACKARRAY_HPP_ */




