/*
 * Node.hpp
 *
 *  Created on: Sep 8, 2015
 *      Author: Mahmoud Mheisen
 */

#ifndef SRC_NODE_HPP_
#define SRC_NODE_HPP_

// Include C++ Libraries:
#include <iostream>

template <class T>
class Node {
	public:
		// Constructors:
		Node();
		Node(const T data);

		// Copy Constructor:
		Node(const Node& other);

		// Destructor:
		virtual ~Node();

		// Member variables:
		T data;
		Node<T>* next;
		Node<T>* previous;
};

// Constructors:
template <class T>
Node<T>::Node() {
	// Initialize data to the default T: (important):
	this->data = T();
	this->next = NULL;
	this->previous = NULL;
}

template <class T>
Node<T>::Node(const T data) {
	// Initialize:
	this->data = data;
	this->next = NULL;
	this->previous = NULL;
}

// Copy Constructor:
template <class T>
Node<T>::Node(const Node& other) {
	// Copy:
	this->data = other.data;
	this->next = other.next;
	this->previous = other.previous;
}

// Destructor:
template <class T>
Node<T>::~Node() {
	// TODO: is correct?
	// no Delete because if we deleted next we will have infinite recursive loop
}

#endif /* SRC_NODE_HPP_ */











