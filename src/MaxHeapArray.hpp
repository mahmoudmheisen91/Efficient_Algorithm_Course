/*
 * HeapArray.hpp
 *
 *  Created on: Sep 12, 2015
 *      Author: Mahmoud Mheisen
 */

#ifndef SRC_MAXHEAPARRAY_HPP_
#define SRC_MAXHEAPARRAY_HPP_

// Include C++ libraries:
#include <iostream>
#include <cassert>
#include <stdexcept>

// Include project libraries:
#include "Array.hpp"

// TODO: make it resizable array:
template <class T>
class MaxHeapArray {
	public:
		// Constructors:
		MaxHeapArray();
		MaxHeapArray(unsigned int size);

		// Build heap constructor:
		MaxHeapArray(const Array<T>& array);

		// Copy Constructor:
		MaxHeapArray(const MaxHeapArray<T>& other);

		// Destructor:
		~MaxHeapArray();

		// Assignment operator:
		MaxHeapArray<T>& operator=(const MaxHeapArray<T>& other);

		// Insert an element to the heap:
		void insert(T value);

		// Delete max number (root):
		T deleteMax(void) throw(std::runtime_error);

		// Return maximum (root):
		T max(void) const throw(std::runtime_error);

		// Size method:
		unsigned int size(void) const;

		// Length method:
		unsigned int length(void) const;

		// isEmpty method:
		bool isEmpty(void) const;

		// toString method:
		void toString(void) const;

	private:
		// Constant:
		unsigned int maxLength;

		// Member variables:
		Array<T> backingArray;
		unsigned int currentSize;

		// Clone method:
		void clone(const MaxHeapArray<T>& other);

		// Parent node:
		inline unsigned int parent(unsigned int index) const {
			assert(index > 1);
			return index / 2;
		}

		// Left node:
		inline unsigned int left(unsigned int index) const {
			assert(index > 0);
			return 2 * index;
		}

		// Right node:
		inline unsigned int right(unsigned int index) const {
			assert(index > 0);
			return 2 * index + 1;
		}

		// Conserve the max heap property:
		void maxHeapify(unsigned int index);

		// Build maximum heap:
		void buildMaxHeap(void);
};

// Constructors:
template<class T>
MaxHeapArray<T>::MaxHeapArray()
: maxLength(10), currentSize(0)
{
	// Initialize array:
	backingArray.setLength(this->maxLength + 1); // from 1 to 11

	// First value is dummy:
	this->backingArray[0] = T();
}

template<class T>
MaxHeapArray<T>::MaxHeapArray(unsigned int size)
: currentSize(0)
{
	// Check size:
	assert(size > 0);
	this->maxLength = size;

	// Initialize array:
	backingArray.setLength(this->maxLength + 1);

	// First value is dummy:
	this->backingArray[0] = T();
}

// Build heap constructor:
template<class T>
MaxHeapArray<T>::MaxHeapArray(const Array<T>& array) {
	// Check size:
	assert(array.length - 1 > 0);
	this->maxLength = array.length - 1;

	// Initialize member variables:
	this->currentSize = this->maxLength;
	backingArray.setLength(this->maxLength + 1);
	this->backingArray = array;

	// Build max heap:
	buildMaxHeap();
}

// Copy Constructor:
template<class T>
MaxHeapArray<T>::MaxHeapArray(const MaxHeapArray<T>& other) {
	// Copy:
	clone(other);
}

// Destructor:
template<class T>
MaxHeapArray<T>::~MaxHeapArray() {
	// TODO: is correct:
	this->currentSize = 0;
	this->maxLength = 0;

	// Delete backing array:
	backingArray.~Array();
}

// Assignment operator:
template<class T>
MaxHeapArray<T>& MaxHeapArray<T>::operator=(const MaxHeapArray<T>& other) {
	// Delete current:
	this->~MaxHeapArray();

	// Copy:
	clone(other);

	// Return:
	return *this;
}

// Insert an element to the heap:
template<class T>
void MaxHeapArray<T>::insert(T value) {
	// Increase the current size and add the element to the end:
	this->backingArray[++this->currentSize] = value;

	// Heapify:
	if(size() < 1)
		return;

	// Up Heap:
	int index = this->currentSize;
	while(index > 1 && (this->backingArray[index] > this->backingArray[parent(index)])) {
		// Swap:
		T temp = this->backingArray[index];
		this->backingArray[index] = this->backingArray[parent(index)];
		this->backingArray[parent(index)] = temp;

		index = parent(index);
	}

}

// Delete max number (root):
template<class T>
T MaxHeapArray<T>::deleteMax(void) throw(std::runtime_error) {
	// Check if Empty:
	if(isEmpty()) {
		throw std::runtime_error("Heap is Empty");
	}

	// Save the root before removing:
	T root = this->backingArray[1];

	// Swap the root with the last value in the heap and decrease the size:
	this->backingArray[1] = this->backingArray[this->currentSize--];

	// Down Heap from the root:
	maxHeapify(1);

	// Return:
	return root;
}

// Return maximum (root):
template<class T>
T MaxHeapArray<T>::max(void) const throw(std::runtime_error) {
	// Check if Empty:
	if(isEmpty()) {
		throw std::runtime_error("Heap is Empty");
	}

	// Return root:
	return this->backingArray[1];
}

// Size method:
template<class T>
unsigned int MaxHeapArray<T>::size(void) const {
	return this->currentSize;
}

// Length method:
template<class T>
unsigned int MaxHeapArray<T>::length(void) const {
	return this->maxLength;
}

// isEmpty method:
template<class T>
bool MaxHeapArray<T>::isEmpty(void) const {
	return size() == 0;
}

// toString method:
template<class T>
void MaxHeapArray<T>::toString(void) const {
	// Check if Empty:
	if(isEmpty()) {
		std::cout << "Heap is Empty" << std::endl;
		return;
	}

	for(int i = 1; i <= this->currentSize; i++) {
		std::cout << this->backingArray[i] << " ";
	}
	std::cout << std::endl;
}

// Clone method:
template<class T>
void MaxHeapArray<T>::clone(const MaxHeapArray<T>& other) {
	// Copy:
	this->maxLength = other.maxLength;
	this->currentSize = other.currentSize;
	this->backingArray = other.backingArray;
}

// Conserve the max heap property:
template<class T>
void MaxHeapArray<T>::maxHeapify(unsigned int index) {
	// Left and right indexes:
	unsigned int leftIndex = left(index);
	unsigned int rightIndex = right(index);

	// Index of the largest node:
	unsigned int largestIndex = index;

	// Decide the largest Index:
	if(leftIndex <= this->currentSize && this->backingArray[index] < this->backingArray[leftIndex]) {
		largestIndex = leftIndex;
	}
	if(rightIndex <= this->currentSize && this->backingArray[largestIndex] < this->backingArray[rightIndex]) {
		largestIndex = rightIndex;
	}

	// If not max heap, heapify it:
	if(largestIndex != index) {
		// Swap:
		T temp = this->backingArray[index];
		this->backingArray[index] = this->backingArray[largestIndex];
		this->backingArray[largestIndex] = temp;

		// Conserve the max heap property for the lower node:
		maxHeapify(largestIndex);
	}
}

// Build maximum heap:
template<class T>
void MaxHeapArray<T>::buildMaxHeap(void) {
	// Just from N/2 to 1, because N/2 + 1 to N are leafs:
	for(int i = this->currentSize / 2; i > 0; i--) {
		maxHeapify(i);
	}
}

#endif /* SRC_MAXHEAPARRAY_HPP_ */





















