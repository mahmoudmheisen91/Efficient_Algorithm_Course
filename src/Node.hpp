/*
 * Node.hpp
 *
 *  Created on: Sep 8, 2015
 *      Author: Mahmoud Mheisen
 */

/*
 * Generic Node class that contain data and two pointers to next and previous nodes
 */

#ifndef SRC_NODE_HPP_
#define SRC_NODE_HPP_

// Include C++ Libraries:
#include <iostream>

// Default type is int:
template <class T = int>
class Node {
public:
	// Constructors:
	Node();
	Node(const T& data);

	// Copy Constructors:
	Node(const Node& other);
	Node(const Node* other);

	// Destructor:
	virtual ~Node(void);

	// Equal operator:
	Node<T>& operator=(const Node<T>& other);

	// Member variables:
	T data;
	Node<T>* next;
	Node<T>* previous;

private:
	// Clone method:
	void clone(const Node<T>& other);
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
Node<T>::Node(const T& data) {
	// Initialize:
	this->data = data;
	this->next = NULL;
	this->previous = NULL;
}

// Copy Constructors:
template <class T>
Node<T>::Node(const Node& other) {
	// Copy:
	clone(other);
}

template <class T>
Node<T>::Node(const Node* other) {
	// Copy:
	clone(*other);
}

// Destructor:
template <class T>
Node<T>::~Node(void) {
	// No Delete because if we deleted next we will have infinite recursive loop
}

// Equal operator:
template<class T>
Node<T>& Node<T>::operator=(const Node<T>& other) {
	// Delete this:
	this->~Node();

	// Copy:
	clone(other);
	return *this;
}

// Clone method:
template<class T>
void Node<T>::clone(const Node<T>& other) {
	// Copy:
	this->data = other.data;
	this->next = other.next;
	this->previous = other.previous;
}


#endif /* SRC_NODE_HPP_ */











