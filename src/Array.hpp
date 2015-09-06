/*
 * Array.cpp
 *
 *  Created on: Aug 22, 2015
 *      Author: Mahmoud Mheisen
 */

/*
 * In this chapter, and throughout this book, it will be convenient to have
 * arrays that keep track of their size. The usual C++ arrays do not do this,
 * so we have defined a class, Array, that keeps track of its length. The
 * implementation of this class is straightforward. It is implemented as a
 * standard C++ array, array, and an integer, length.
 */

#ifndef ARRAY_HPP_
#define ARRAY_HPP_

// Include standard I/O streams:
#include <iostream>
#include <algorithm>
#include <cassert>

template <class T = int>
class Array {

	public:
		// Default constructor:
		Array();

		// Declare array with a specific length:
		Array(int length);

		// Initialize the array with predefined value:
		Array(int length, T value);

		// Copy constructor:
		Array(const Array<T>& other);

		// clear array:
		virtual ~Array();

		// Copy assignment:
		Array<T>& operator=(const Array<T>& other);

		// overload [] so that the array will keep track of it's size:
		T& operator[](int i) const;

		// Print array in one line:
		void toString(void) const;

		// length of the array:
		int length;

	private:
		// Dynamic array:
		T* internalArray;

		// Clone method - to be called inside copy constructor and operator:
		void clone(const Array& other);

	// Template friend function that implements the toString() method with << operator:
	template <class E>
	friend std::ostream& operator<<(std::ostream& output, const Array<E>& other);

};

// Default constructor:
template <class T>
Array<T>::Array() {
	this->length = 0;
	this->internalArray = NULL;
}

// Declare array with a specific length:
template <class T>
Array<T>::Array(int length) {
	// check size:
	assert(length > 0);

	// The size of an array is specified at the time of creation:
	this->length = length;
	internalArray = new T[length];
}

// Initialize the array with predefined value:
template <class T>
Array<T>::Array(int length, T value) {
	// check size:
	assert(length > 0);

	// Initialize member variables:
	this->length = length;
	this->internalArray = new T[length];

	// Fill:
	std::fill(this->internalArray, this->internalArray + this->length, value);
}

// Copy constructor:
template <class T>
Array<T>::Array(const Array<T>& other) {
	// Clone other:
	clone(other);
}

// clear array:
template <class T>
Array<T>::~Array() {
	// To protect from double free:
	if (internalArray != NULL) {
		// Delete content of internalArray:
		delete[] this->internalArray;

		// Delete the pointer itself:
		this->internalArray = NULL;
	}
}

// Copy assignment:
template <class T>
Array<T>& Array<T>::operator=(const Array<T> &other) {
	// Free just in case sizes are not identical:
	this->~Array();

	// Clone other:
	clone(other);

	return *this;
}

// overload [] so that the array will keep track of it's size:
template <class T>
T& Array<T>::operator[](int i) const {
	assert(i >= 0 && i < length);
	return internalArray[i];
}

// Print array in one line:
template <class T>
void Array<T>::toString(void) const {
	for(int i = 0; i < length; i++) {
		std::cout << internalArray[i] << " ";
	}
	std::cout << std::endl;
}

// Clone method - to be called inside copy constructor and operator:
template <class T>
void Array<T>::clone(const Array& other) {
	// Copy length value:
	this->length = other.length;

	// Allocate internalArray before copying: (Very Important):
	this->internalArray = new T[this->length];

	// Start copying:
	for(int i = 0; i < this->length; i++)
		this->internalArray[i] = other.internalArray[i];
}

// Friend function that implements the toString() method with << operator:
template <class E>
std::ostream& operator<<(std::ostream& output, const Array<E>& other) {
	for(int i = 0; i < other.length; i++) {
		output << other.internalArray[i] << " ";
	}
	output << std::endl;
	return output;
}

#endif /* ARRAY_HPP_ */



