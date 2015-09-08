/*
 * StackArray.hpp
 *
 *  Created on: Sep 7, 2015
 *      Author: Mahmoud Mheisen
 */

#ifndef SRC_STACKARRAY_HPP_
#define SRC_STACKARRAY_HPP_

// Include C++ Libraries:
#include <iostream>
#include <stdexcept>

// Include project headers:
#include "Array.hpp"

// Array based Stack, resizable array:
// Resizing operation has an amortized time of O(1)
template <class T>
class StackArray {
	public:
		// Constructor:
		StackArray();

		// Copy Constructor:
		StackArray(const StackArray& other);

		// Destructor:
		virtual ~StackArray();

		// Push element at the top of the stack:
		void push(T element);

		// Pop element from the top of the stack:
		T pop() throw(runtime_error);

		// Return the top of the stack without removing it:
		T top() const throw(runtime_error);

		// Return current number of elements in the stack:
		int size() const;

		// Return the length of the stack:
		int length() const;

		// isEmpty method:
		bool isEmpty() const;

		// isFull method:
		bool isFull() const;

		// toString method:
		void toString() const;

	private:
		// Member variables:
		Array<T> backingArray;
		int currentSize;

		// Resize method:
		void resize(int capacity);
};

// Constructor:
template <class T>
StackArray<T>::StackArray() {
	// Set current number of elements to zero:
	this->currentSize = 0;

	// Set array length to 1:
	backingArray.setLength(1);
}

// Copy Constructor:
template <class T>
StackArray<T>::StackArray(const StackArray& other)
:currentSize(other.currentSize)
{
	this->backingArray = other.backingArray;
}

// Destructor:
template <class T>
StackArray<T>::~StackArray() {
	// TODO: is this correct? no pointers!!!
	// Clear the stack:
	currentSize = 0;
	backingArray.~Array();
}

// Push element at the top of the stack:
template <class T>
void StackArray<T>::push(T element) {
	// If the array is full, double its size:
	if(isFull())
		resize(2 * backingArray.length);

	// Add the element and increase the current size:
	this->backingArray[currentSize++] = element;
}

// Pop element from the top of the stack:
template <class T>
T StackArray<T>::pop() throw(runtime_error) {
	// If empty throw runtime error:
	if(isEmpty())
		throw runtime_error("Stack underflow");

	// TODO: the last element is still their but we are not pointing to it:
	// Decrease the current size and return the element:
	T item = this->backingArray[--currentSize];

	// If the array is quarter full cut the size to half:
	if(this->currentSize == backingArray.length / 4)
		resize(backingArray.length / 2);

	// Return the element:
	return item;
}

// Return the top of the stack without removing it:
template <class T>
T StackArray<T>::top() const throw(runtime_error) {
	// If empty throw runtime error:
	if(isEmpty())
		throw runtime_error("Stack underflow");

	// Return the top of the stack:
	return this->backingArray[currentSize-1];
}

// Return current number of elements in the stack:
template <class T>
int StackArray<T>::size() const {
	return this->currentSize;
}

// Return the length of the stack:
template <class T>
int StackArray<T>::length() const {
	return backingArray.length;
}

// isEmpty method:
template <class T>
bool StackArray<T>::isEmpty() const {
	return this->currentSize == 0;
}

// isFull method:
template <class T>
bool StackArray<T>::isFull() const {
	return this->currentSize == backingArray.length;
}

// toString method:
template <class T>
void StackArray<T>::toString() const {
	// If the stack is empty:
	if(isEmpty()) {
		std::cout << "The stack is empty" << std::endl;
		return;
	}

	// Print:
	for(int i = 0; i < this->currentSize; i++) {
		std::cout << backingArray[i] << " ";
	}
	std::cout << std::endl;
}

// Resize method:
template <class T>
void StackArray<T>::resize(int capacity) {
	// New array with the new length:
	Array<T> copy(capacity);

	// Copying to new array:
	for(int i = 0; i < this->currentSize; i++)
		copy[i] = this->backingArray[i];

	// TODO: copying twice:
	// Copying back to the backing array:
	this->backingArray = copy;
}

#endif /* SRC_STACKARRAY_HPP_ */















