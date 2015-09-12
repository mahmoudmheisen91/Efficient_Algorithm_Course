/*
 * QueueNode.hpp
 *
 *  Created on: Sep 11, 2015
 *      Author: Mahmoud Mheisen
 */

#ifndef SRC_QUEUENODE_HPP_
#define SRC_QUEUENODE_HPP_

// Include C++ Libraries:
#include <iostream>
#include <stdexcept>

// Include project headers:
#include "Node.hpp"

template <class T>
class QueueNode {
	public:
		// Constructor:
		QueueNode();

		// TODO:
		// Copy Constructor:
		//QueueNode(const QueueNode& other);

		// Destructor:
		virtual ~QueueNode();

		// TODO:
		// Copy assignment:
		//const QueueNode<T>& operator=(const QueueNode<T>& other);

		// Add element at the top of the queue:
		void enqueue(T element);

		// Remove element from the end of the queue:
		T dequeue() throw(std::runtime_error);

		// Return the top of the queue without removing it:
		T top() const throw(std::runtime_error);

		// Return current number of elements in the queue:
		int size() const;

		// isEmpty method:
		bool isEmpty() const;

		// toString method:
		void toString() const;

	private:
		// Member variables:
		Node<T>* head;
		Node<T>* tail;
		int currentSize;

		// TODO:
		// Clone method:
		//void clone(const QueueNode& other);
};

// Constructor:
template <class T>
QueueNode<T>::QueueNode() {
	this->currentSize = 0;
	this->head = NULL;
	this->tail = NULL;
}

/*
// Copy Constructor:
template <class T>
QueueNode<T>::QueueNode(const QueueNode& other) {
	// Copy:
	clone(other);
}
*/

// Destructor:
template <class T>
QueueNode<T>::~QueueNode() {
	// TODO: is correct??
	// Set size to zero:
	this->currentSize = 0;

	// Delete head pointer and all other pointers:
	while(this->head != NULL) {
		// Make new node that point to head:
		Node<T>* current = new Node<T>;

		current = head;
		this->head = head->next;

		delete current;
	}

	this->tail = NULL;
}

/*
// Copy assignment:
template <class T>
const QueueNode<T>& QueueNode<T>::operator=(const QueueNode<T>& other) {
	// Delete this before copying:
	if(!this->isEmpty()) {
		this->~QueueNode();
	}

	// Copy:
	clone(other);

	return *this;
}
*/

// Add element at the top of the queue:
template <class T>
void QueueNode<T>::enqueue(T element) {

	// Add new node that contain the element:
	Node<T>* newNode = new Node<T>;
	newNode->data = element;
	newNode->next = NULL;

	// Link:
	if(isEmpty()) {
		this->head = newNode;
		this->tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}

	// Increase the size:
	currentSize++;
}

// Remove element from the end of the queue:
template <class T>
T QueueNode<T>::dequeue() throw(std::runtime_error) {
	// If the queue is empty throw run time error:
	if(isEmpty())
		throw std::runtime_error("The Queue is empty");

	// Save the item in the tail:
	T item = head->data;

	// Make new node that point to head, to delete it latter:
	Node<T>* old;
	old = head;

	// Make the head point to the next value in the queue:
	head = old->next;

	// Decrease the size:
	currentSize--;

	// Delete the old head:
	delete old;

	// Return the item:
	return item;
}

// Return the top of the queue without removing it:
template <class T>
T QueueNode<T>::top() const throw(std::runtime_error) {
	// If the stack is empty throw run time error:
	if(isEmpty())
		throw new std::runtime_error("The Queue is empty");

	// Return the item in the head:
	return head->data;
}

// Return current number of elements in the queue:
template <class T>
int QueueNode<T>::size() const {
	return this->currentSize;
}

// isEmpty method:
template <class T>
bool QueueNode<T>::isEmpty() const {
	return this->currentSize == 0;
}

// toString method:
template <class T>
void QueueNode<T>::toString() const {
	// If the queue is empty:
	if(isEmpty()) {
		std::cout << "The Queue is empty" << std::endl;
		return;
	}

	// Make new node that points to the head, to loop through the queue:
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

/*
// Clone method:
template <class T>
void QueueNode<T>::clone(QueueNode& other) {
	// Initialize this queue:
	this->currentSize = 0;
	this->head = NULL;
	this->tail = NULL;

	// If the queue is empty:
	if(other.isEmpty()) return;


}
*/


#endif /* SRC_QUEUENODE_HPP_ */
