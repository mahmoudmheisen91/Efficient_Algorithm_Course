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

// Include Standard Libraries:
#include <cassert>
#include <algorithm>

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
		
	this->length = length;
	internalArray = new T[length];
	this->fill(value);
}

// clear array:
template <class T>
Array<T>::~Array() {
	// To protect from doubl free:
	if (internalArray != NULL) {
		delete[] internalArray;
	}
}

// overload [] so that the array will keep track of it's size:
template <class T>
T& Array<T>::operator[](int i) {
	assert(i >= 0 && i < length);
	return internalArray[i];
}

// when one array is assigned to another, this is just a pointer manipulation
// that takes constant time:
template <class T>
Array<T>& Array<T>::operator=(Array<T> &other) {
	// Free just in case sizes are not identical:
	if (internalArray != NULL) {
		delete[] internalArray;
	}

	// pointer manipulation:
	internalArray = other.internalArray;
	other.internalArray = NULL;
	length = other.length;

	return *this;
}

// Print array in one line:
template <class T>
void Array<T>::print(void) {
	for(int i = 0; i < length; i++) {
		std::cout << internalArray[i] << " ";
	}
	std::cout << std::endl;
}

// Fill array with predefined value:
template <class T>
void Array<T>::fill(T value) {
	std::fill(internalArray, internalArray+length, value);
}

// Swap two entries:
template <class T>
void Array<T>::swap(int i, int j) {
	// Checking:
	assert(i >= 0 && i < length);
	assert(j >= 0 && j < length);
	
	// Swaping:
	T temp = internalArray[i]; 
	internalArray[i] = internalArray[j];
	internalArray[j] = temp;
}

