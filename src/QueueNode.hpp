/*
 * QueueNode.hpp
 *
 *  Created on: Sep 11, 2015
 *      Author: Mahmoud Mheisen
 */

/*
 * Linked List based Stack:
 * a collection that processes values in a first-in/first-out (FIFO) order.
 */

/*
 * TODO:
 * Add >> operator to read data from command line
 * Add iterator
 * Add const iterator
 * Work with STL sort
 * implement it as a ring
 */

#ifndef SRC_QUEUENODE_HPP_
#define SRC_QUEUENODE_HPP_

// Include C++ Libraries:
#include <iostream>
#include <string>
#include <sstream>

// Include project headers:
#include "LinkedList.hpp"
#include "utility.hpp"

template <class T>
class QueueNode {
public:
	// Constructor:
	QueueNode();

	// Copy Constructor:
	QueueNode(const QueueNode& other);

	// Destructor:
	virtual ~QueueNode();

	// Copy assignment:
	QueueNode<T>& operator=(const QueueNode<T>& other);

	// Add element at the top of the queue:
	void enqueue(const T& element);

	// Remove element from the end of the queue:
	T dequeue(void);

	// Return the top of the queue without removing it:
	T top(void) const;

	// Operator <<: to quickly add elements to the queue:
	QueueNode<T>& operator<<(const T& value);

	// Operator >>: to quickly remove elements from the queue:
	QueueNode<T>& operator>>(T& value);

	// Clear the queue:
	void clear(void);

	// Return current number of elements in the queue:
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

// Write date to command line:
template<class E>
friend std::ostream& operator<<(std::ostream& output, const QueueNode<E>& other);
};

// Constructor:
template <class T>
QueueNode<T>::QueueNode()
:elements()
{
}

// Copy Constructor:
template <class T>
QueueNode<T>::QueueNode(const QueueNode& other) {
	// Deep copy:
	this->elements = other.elements;
}

// Destructor:
template <class T>
QueueNode<T>::~QueueNode() {
	clear();
}

// Copy assignment:
template <class T>
QueueNode<T>& QueueNode<T>::operator=(const QueueNode<T>& other) {
	// Clear this first:
	clear();

	// Deep copy:
	this->elements = other.elements;

	return *this;
}

// Add element at the top of the queue:
template <class T>
void QueueNode<T>::enqueue(const T& element) {
	elements << element;
}

// Remove element from the end of the queue:
template <class T>
T QueueNode<T>::dequeue(void) {
	// Check:
	Error(isEmpty(), "Queue is Empty");

	return elements.popFront();
}

// Return the top of the queue without removing it:
template <class T>
T QueueNode<T>::top(void) const {
	// Check:
	Error(isEmpty(), "Queue is Empty");

	return elements.front();
}

// Operator <<: to quickly add elements to the queue:
template<class T>
QueueNode<T>& QueueNode<T>::operator<<(const T& value) {
	this->elements << value;
	return *this;
}

// Operator >>: to quickly remove elements from the queue:
template<class T>
QueueNode<T>& QueueNode<T>::operator>>(T& value) {
	value = dequeue();
	return *this;
}

// Clear the queue:
template<class T>
void QueueNode<T>::clear(void) {
	elements.clear();
}

// toString method:
template <class T>
std::string QueueNode<T>::toString() const {
	// Make an output string stream and insert this into it:
	std::ostringstream oss;
	oss << *this;

	// Transform the string stream to string:
	return oss.str();
}

// Write date to command line:
template<class E>
std::ostream& operator<<(std::ostream& output, const QueueNode<E>& other) {
	// Check if empty:
	if(other.isEmpty()) {
		output << "Queue is Empty";
		return output;
	}

	return output << other.elements;
}

#endif /* SRC_QUEUENODE_HPP_ */

















