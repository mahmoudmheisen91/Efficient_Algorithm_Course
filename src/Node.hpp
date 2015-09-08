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

		// Assignment operator overloading:
		const Node<T>& operator=(const Node<T>& other);

		// Setters:
		void setData(const T data);
		void setNext(const Node<T>& next);
		void setPrevious(const Node<T>& previous);

		// Getters:
		T getData() const;
		T* getNext() const;
		T* getPrevious() const;

	private:
		// Member variables:
		T data;
		Node<T>* next;
		Node<T>* previous;

		// Clone method - to be called inside copy constructor and assignment operator:
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
Node<T>::Node(const T data) {
	// Initialize:
	this->data = data;
	this->next = new Node<T>;
	this->previous = new Node<T>;
}

// Copy Constructor:
template <class T>
Node<T>::Node(const Node& other) {
	// Copy:
	clone(other);
}

// Destructor:
template <class T>
Node<T>::~Node() {
	// Delete next pointer:
	if(this->next != NULL) {
		delete next;
		next = NULL;
	}

	// Delete previous pointer:
	if(this->previous != NULL) {
		delete previous;
		previous = NULL;
	}
}

// Assignment operator overloading:
template <class T>
const Node<T>& Node<T>::operator=(const Node<T>& other) {
	// Free just in case if it is preassigned:
	this->~Node();

	// Copy:
	clone(other);

	return *this;
}

// Setters:
template <class T>
void Node<T>::setData(const T data) {
	this->data = data;
}

template <class T>
void Node<T>::setNext(const Node<T>& next) {
	*(this->next) = next;
}

template <class T>
void Node<T>::setPrevious(const Node<T>& previous) {
	*(this->previous) = previous;
}

// Getters:
template <class T>
T Node<T>::getData() const {
	return this->data;
}

template <class T>
T* Node<T>::getNext() const {
	return this->next;
}

template <class T>
T* Node<T>::getPrevious() const {
	return this->previous;
}

// Clone method - to be called inside copy constructor and assignment operator:
template <class T>
void Node<T>::clone(const Node<T>& other) {
	this->data = other.data;
	this->next = other.next;
	this->previous = other.previous;
}

#endif /* SRC_NODE_HPP_ */











