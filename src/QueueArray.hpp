/*
 * QueueArray.hpp
 *
 *  Created on: Sep 10, 2015
 *      Author: Mahmoud Mheisen
 */

#ifndef SRC_QUEUEARRAY_HPP_
#define SRC_QUEUEARRAY_HPP_

// Include C++ Libraries:
#include <iostream>
#include <stdexcept>

// Include project headers:
#include "Array.hpp"

// Array based Queue, resizable array:
// Resizing operation has an amortized time of O(1)
template <class T>
class QueueArray {
	public:
		// Constructor:
		QueueArray();

		// Copy Constructor:
		QueueArray(const QueueArray& other);

		// Destructor:
		virtual ~QueueArray();

		// Assignment operator:
		QueueArray<T>& operator=(const QueueArray<T>& other);

		// Enqueue element at the top of the queue:
		void enqueue(T element);

		// Dequeue element from the end of the queue:
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
		int begin, end;
		int currentSize;
		Array<T> backingArray;

		// Return the length of the queue:
		int length() const;

		// isFull method:
		bool isFull() const;

		// Resize method:
		void resize(int capacity);

		// Clone method:
		void clone(const QueueArray<T>& other);

		// TODO: overload <<
};

// Constructor:
template <class T>
QueueArray<T>::QueueArray() {
	// Set current number of elements to zero:
	this->currentSize = 0;

	// Pointers to the beginning and end of queue:
	this->end = 0;
	this->begin = 0;

	// Set array length to 1:
	backingArray.setLength(1);
}

// Copy Constructor:
template <class T>
QueueArray<T>::QueueArray(const QueueArray& other) {

	// Copy:
	clone(other);
}

// Destructor:
template <class T>
QueueArray<T>::~QueueArray() {
	// TODO: is this correct? no pointers!!!
	// Clear the stack:
	this->end = 0;
	this->begin = 0;
	this->currentSize = 0;
	this->backingArray.~Array();
}

// Assignment operator:
template <class T>
QueueArray<T>& QueueArray<T>::operator=(const QueueArray<T>& other) {
	// Delete previous queue:
	this->~QueueArray();

	// Copy:
	clone(other);

	// Return:
	return *this;
}

// Enqueue element at the top of the queue:
template <class T>
void QueueArray<T>::enqueue(T element) {
	// If the array is full, double its size:
	if(isFull())
		resize(2 * backingArray.length);

	// Add the element to the end and increment end:
	this->backingArray[this->end++] = element;

	// Increase the current size:
	this->currentSize++;
}

// Dequeue element from the end of the queue:
template <class T>
T QueueArray<T>::dequeue() throw(std::runtime_error) {
	// If empty throw runtime error:
	if(isEmpty())
		throw std::runtime_error("Queue is Empty");

	// TODO: the element is still their but we are not pointing to it:
	// Increment the begin pointer and save the element:
	T item = this->backingArray[begin++];

	// Decrease the current size:
	this->currentSize--;

	// If the array is quarter full cut the size to half:
	if(this->currentSize == backingArray.length / 4)
		resize(backingArray.length / 2);

	// Return the element:
	return item;
}

// Return the top of the queue without removing it:
template <class T>
T QueueArray<T>::top() const throw(std::runtime_error) {
	// If empty throw runtime error:
	if(isEmpty())
		throw std::runtime_error("Queue is Empty");

	// Return the top of the queue:
	return this->backingArray[begin];
}

// Return current number of elements in the queue:
template <class T>
int QueueArray<T>::size() const {
	return this->currentSize;
}

// isEmpty method:
template <class T>
bool QueueArray<T>::isEmpty() const {
	return this->currentSize == 0;
}

// toString method:
template <class T>
void QueueArray<T>::toString() const {
	// If the queue is empty:
	if(isEmpty()) {
		std::cout << "The Queue is empty" << std::endl;
		return;
	}

	// Print:
	for(int i = this->begin; i < this->end; i++) {
		std::cout << backingArray[i] << " ";
	}
	std::cout << std::endl;
}

// Return the length of the queue:
template <class T>
int QueueArray<T>::length() const {
	return backingArray.length;
}

// isFull method:
template <class T>
bool QueueArray<T>::isFull() const {
	return size() == length();
}

// Resize method:
template <class T>
void QueueArray<T>::resize(int capacity) {
	// New array with the new length:
	Array<T> copy(capacity);

	// Copying to new array:
	int j = 0;
	for(int i = this->begin; i < this->end; i++) {
		copy[j] = this->backingArray[i];
		j++;
	}

	// Set begin pointer back to zero:
	this->begin = 0;

	// If resizing to smaller size, set the end pointer to the current size:
	if(capacity <= end)
		this->end = currentSize;

	// TODO: copying twice:
	// Copying back to the backing array:
	this->backingArray = copy;
}

// Clone method:
template <class T>
void QueueArray<T>::clone(const QueueArray<T>& other) {
	// Copy member variables:
	this->begin = other.begin;
	this->end = other.end;
	this->currentSize = other.currentSize;
	this->backingArray = other.backingArray;
}

#endif /* SRC_QUEUEARRAY_HPP_ */













