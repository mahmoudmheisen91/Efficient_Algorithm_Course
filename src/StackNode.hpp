/*
 * StackNode.hpp
 *
 *  Created on: Sep 8, 2015
 *      Author: Mahmoud Mheisen
 */

/*
 * Linked List based Stack:
 * a collection that processes values in a last-in/first-out (LIFO) order.
 */

/*
 * TODO:
 * Add >> operator to read data from command line
 * Add iterator
 * Add const iterator
 * Work with STL sort
 */

#ifndef SRC_STACKNODE_HPP_
#define SRC_STACKNODE_HPP_

// Include C++ Libraries:
#include <iostream>
#include <string>
#include <sstream>

// Include project headers:
#include "LinkedList.hpp"
#include "utility.hpp"

template <class T = int>
class StackNode {
public:
	// Constructor:
	StackNode();

	// Copy Constructor:
	StackNode(const StackNode<T>& other);

	// Destructor:
	virtual ~StackNode();

	// Copy assignment:
	const StackNode<T>& operator=(const StackNode<T>& other);

	// Push element at the top of the stack:
	void push(const T& element);

	// Pop element from the top of the stack:
	T pop(void);

	// Return the top of the stack without removing it:
	T top(void) const;

	// Operator <<: to quickly add elements to the stack:
	StackNode<T>& operator<<(const T& value);

	// Operator >>: to quickly remove elements from the stack:
	StackNode<T>& operator>>(T& value);

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

	// toString method:
	std::string toString(void) const;

private:
	// Member variables:
	LinkedList<T> elements;

// Write data to command line:
template<class E>
friend std::ostream& operator<<(std::ostream& output, const StackNode<E>& other);
};

// Constructor:
template <class T>
StackNode<T>::StackNode()
:elements()
{
}

// Copy Constructor:
template <class T>
StackNode<T>::StackNode(const StackNode<T>& other) {
	// Deep copy:
	this->elements = other.elements;
}

// Destructor:
template <class T>
StackNode<T>::~StackNode() {
	clear();
}

// Copy assignment:
template <class T>
const StackNode<T>& StackNode<T>::operator=(const StackNode<T>& other) {
	// Deep copy:
	this->elements = other.elements;
	return *this;
}

// Push element at the top of the stack:
template <class T>
void StackNode<T>::push(const T& element) {
	elements << element;
}

// Pop element from the top of the stack:
template <class T>
T StackNode<T>::pop(void) {
	// Check:
	Error(isEmpty(), "Stack underflow");

	return elements.popBack();
}

// Return the top of the stack without removing it:
template <class T>
T StackNode<T>::top(void) const {
	// Check:
	Error(isEmpty(), "Stack underflow");

	return elements.back();
}

// Operator <<: to quickly add elements to the stack:
template<class T>
StackNode<T>& StackNode<T>::operator<<(const T& value) {
	this->elements << value;
	return *this;
}

// Operator >>: to quickly remove elements from the stack:
template<class T>
StackNode<T>& StackNode<T>::operator>>(T& value) {
	value = pop();
	return *this;
}

// Clear the stack:
template<class T>
void StackNode<T>::clear(void) {
	elements.clear();
}

// toString method:
template<class T>
std::string StackNode<T>::toString(void) const {
	// Make an output string stream and insert this into it:
	std::ostringstream oss;
	oss << *this;

	// Transform the string stream to string:
	return oss.str();
}

// Write date to command line:
template<class E>
std::ostream& operator<<(std::ostream& output, const StackNode<E>& other) {
	// Check if empty:
	if(other.isEmpty()) {
		output << "Stack is Empty";
		return output;
	}

	return output << other.elements;
}

#endif /* SRC_STACKNODE_HPP_ */







