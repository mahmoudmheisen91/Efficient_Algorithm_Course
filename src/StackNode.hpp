/*
 * StackNode.hpp
 *
 *  Created on: Sep 8, 2015
 *      Author: Mahmoud Mheisen
 */

#ifndef SRC_STACKNODE_HPP_
#define SRC_STACKNODE_HPP_

// Include C++ Libraries:
#include <iostream>
#include <stdexcept>

// Include project headers:
#include "Node.hpp"

// When declaring a new node, do not use new keyword, because we assign another pointer node
// to it and the allocated memory using new keyword is lost, the delete will remove the assigned
// pointer not the allocated chunk, just make a pointer:
// use this: Node<T>* current;
// not this: Node<T>* current = new Node<T>();

template <class T>
class StackNode {
	public:
		// Constructor:
		StackNode();

		// Copy Constructor:
		StackNode(const StackNode& other);

		// Destructor:
		virtual ~StackNode();

		// Copy assignment:
		const StackNode<T>& operator=(const StackNode<T>& other);

		// Push element at the top of the stack:
		void push(T element);

		// Pop element from the top of the stack:
		T pop() throw(std::runtime_error);

		// Return the top of the stack without removing it:
		T top() const throw(std::runtime_error);

		// Return current number of elements in the stack:
		int size() const;

		// isEmpty method:
		bool isEmpty() const;

		// toString method:
		void toString() const;

	private:
		// Member variables:
		Node<T>* head;
		int currentSize;

		// Clone method:
		void clone(const StackNode& other);
};

// Constructor:
template <class T>
StackNode<T>::StackNode() {
	this->currentSize = 0;
	this->head = NULL;
}

// Copy Constructor:
template <class T>
StackNode<T>::StackNode(const StackNode& other) {
	// Copy:
	clone(other);
}

// Destructor:
template <class T>
StackNode<T>::~StackNode() {
	// TODO: is correct??
	// Set size to zero:
	this->currentSize = 0;

	// Make new node that point to head:
	Node<T>* current;

	// Delete head pointer and all other pointers:
	while(head != NULL) {
		// Assign current to head, move the head to next one, then remove the current
		// do not delete the current before moving the head to the next one:
		current = head;
		head = head->next;

		delete current;
	}
}

// Copy assignment:
template <class T>
const StackNode<T>& StackNode<T>::operator=(const StackNode<T>& other) {
	// Delete this before copying:
	if(!this->isEmpty()) {
		this->~StackNode();
	}

	// Copy:
	clone(other);

	return *this;
}

// Push element at the top of the stack:
template <class T>
void StackNode<T>::push(T element) {

	// Add new node that contain the element:
	Node<T>* newNode = new Node<T>(element);

	// Make this new node point to the head:
	newNode->next = head;

	// Make the head point to this node:
	head = newNode;

	// Increase the size:
	currentSize++;
}

// Pop element from the top of the stack:
template <class T>
T StackNode<T>::pop() throw(std::runtime_error) {
	// If the stack is empty throw run time error:
	if(isEmpty())
		throw std::runtime_error("Stack underflow");

	// Save the item in the head:
	T item = head->data;

	// Make new node that point to head, to delete it latter:
	Node<T>* old;
	old = head;

	// Make the head point to the next value in the stack:
	head = old->next;

	// Decrease the size:
	currentSize--;

	// Delete the old head:
	delete old;

	// Return the item:
	return item;
}

// Return the top of the stack without removing it:
template <class T>
T StackNode<T>::top() const throw(std::runtime_error) {
	// If the stack is empty throw run time error:
	if(isEmpty())
		throw new std::runtime_error("Stack underflow");

	// Return the item in the head:
	return head->data;
}

// Return current number of elements in the stack:
template <class T>
int StackNode<T>::size() const {
	return this->currentSize;
}

// isEmpty method:
template <class T>
bool StackNode<T>::isEmpty() const {
	return this->currentSize == 0;
}

// toString method:
template <class T>
void StackNode<T>::toString() const {
	// If the stack is empty:
	if(isEmpty()) {
		std::cout << "The stack is empty" << std::endl;
		return;
	}

	// Make new node that points to the head, to loop through the stack:
	Node<T>* current;
	current = head;

	// Print:
	while(current != NULL) {
		std::cout << current->data << " ";
		current = current->next;
	}

	std::cout << std::endl;
	delete current;
}

// Clone method:
template <class T>
void StackNode<T>::clone(const StackNode& other) {
	// Initialize this stack:
	this->currentSize = 0;
	this->head = NULL;

	// If the stack is empty:
	if(other.isEmpty()) return;

	// Make new node that points to the head of the other stack, to loop through the stack:
	Node<T>* current;
	current = other.head;

	// TODO: two loops:
	// Make temp stack, to hold the data in other stack in reversed way:
	StackNode<T> tempStack;

	// Add data from the other stack to temp stack:
	while(current != NULL) {
		tempStack.push(current->data);
		current = current->next;
	} // in this loop, we moved through the other stack without removing any data from it

	// Make the new node points to the head of the temp stack:
	current = tempStack.head;

	// Add data from the temp stack to this stack:
	while(current != NULL) {
		this->push(tempStack.pop()); // inside pop the head is changed
		current = tempStack.head; 	 // no need to point to the next
	} // in this loop, we removed every data from temp stack, to reduce memory usage

	delete current;
}

#endif /* SRC_STACKNODE_HPP_ */







