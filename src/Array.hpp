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
#include <string>
#include <sstream>

// Class template, with default type equal to int:
template <class T = int>
class Array {

	public:
		// Default constructor:
		Array();

		// Declare array with a specific length:
		Array(unsigned int length);

		// Initialize the array with predefined value:
		Array(unsigned int length, T value);

		// Copy constructor:
		Array(const Array<T>& other);

		// Clear array:
		virtual ~Array();

		// Copy assignment:
		const Array<T>& operator=(const Array<T>& other);

		// Overload [] so that the array will check the index before accessing:
		T& operator[](unsigned int index);

		// Overload [] for constant arrays:
		const T& operator[](unsigned int index) const;

		// Is equal operator:
		bool operator==(const Array<T>& other) const;

		// Not equal operator:
		bool operator!=(const Array<T>& other) const;

		// Set the length of the array, to be used with the default constructor:
		void setLength(unsigned int length);

		// Resize array to new capacity:
		void resize(unsigned int capacity);

		// Convert array to string:
		std::string toString(void) const;

		// Length method:
		inline unsigned int length() const {
			return this->size;
		}

	private:
		// Length of the array:
		unsigned int size;

		// Dynamic array:
		T* internalArray;

		// Clone method - to be called inside copy constructor and assignment operator:
		void clone(const Array<T>& other);

	// TODO: E type:
	// Template friend function that implements the toString() method with << operator:
	template <class E>
	friend std::ostream& operator<<(std::ostream& output, const Array<E>& other);

	// Read data from command line:
	template <class E>
	friend std::istream& operator>>(std::istream& input, Array<E>& other);

};

// Default constructor:
template <class T>
Array<T>::Array() {
	this->size = 0;
	this->internalArray = NULL;
}

// Declare array with a specific length:
template <class T>
Array<T>::Array(unsigned int size) {
	// check size:
	assert(size > 0);

	// The size of an array is specified at the time of creation:
	this->size = size;
	this->internalArray = new T[this->size];

	// Fill with default values, just in case if print without initialization:
	std::fill(this->internalArray, this->internalArray + this->size, T());
}

// Initialize the array with predefined value:
template <class T>
Array<T>::Array(unsigned int size, T value) {
	// check size:
	assert(size > 0);

	// Initialize member variables:
	this->size = size;
	this->internalArray = new T[this->size];

	// Fill:
	std::fill(this->internalArray, this->internalArray + this->size, value);
}

// Copy constructor:
template <class T>
Array<T>::Array(const Array<T>& other) {
	// Clone other:
	clone(other);
}

// Clear array:
template <class T>
Array<T>::~Array() {
	// To protect from double free:
	if (this->internalArray != NULL) {
		// Delete content of internalArray:
		delete[] this->internalArray;

		// Make the pointer points to NULL, instead of unknown place:
		this->internalArray = NULL;
	}
}

// Copy assignment:
template <class T>
const Array<T>& Array<T>::operator=(const Array<T> &other) {
	// Free just in case sizes are not identical:
	this->~Array();

	// Clone other:
	clone(other);

	return *this;
}

// Overload [] so that the array will check the index before accessing:
template <class T>
T& Array<T>::operator[](unsigned int index) {
	assert(index >= 0 && index < this->size);
	return this->internalArray[index];
}

// Overload [] for constant arrays:
template <class T>
const T& Array<T>::operator[](unsigned int index) const {
	assert(index >= 0 && index < this->size);
	return this->internalArray[index];
}

// Is equal operator:
template <class T>
bool Array<T>::operator==(const Array<T>& other) const {
	// Check sizes first:
	if(this->size != other.size)
		return false;

	// Check array:
	for(int i = 0; i < this->size; i++) {
		if(this->internalArray[i] != other.internalArray[i])
			return false;
	}

	// If all passed;
	return true;
}

// Not equal operator:
template <class T>
bool Array<T>::operator!=(const Array<T>& other) const {
	return !(*this == other);
}

// Set the length of the array, to be used with the default constructor:
template <class T>
void Array<T>::setLength(unsigned int size) {
	// check size:
	assert(size > 0);

	// Free just in case if it is not used with the default constructor:
	this->~Array();

	// The size of an array is specified at the time of creation:
	this->size = size;
	this->internalArray = new T[this->size];

	// Fill with default values, just in case if print without initialization:
	std::fill(this->internalArray, this->internalArray + this->size, T());
}

// Resize array to new capacity:
template <class T>
void Array<T>::resize(unsigned int capacity) {
	// If it is length equal to zero:
	if(this->size == 0) {
		setLength(capacity);
		return;
	}

	// Save old length then update it:
	unsigned int oldSize = this->size;
	this->size = capacity;

	// Make a pointer that points to the old array:
	T* temp = this->internalArray;

	// Allocate new chunk to this array:
	this->internalArray = new T[this->size];

	// Copy from the old array to the new array:
	for(int i = 0; i < oldSize; i++)
		this->internalArray[i] = temp[i];

	// Delete temp pointer:
	delete[] temp;
	temp = NULL;

	// Initialize remainder values in the new array with the default value:
	for(int i = oldSize; i < this->size; i++)
		this->internalArray[i] = T();
}

// Convert array to string:
template <class T>
std::string Array<T>::toString(void) const {
	// Make an output string stream and insert this into it:
    std::ostringstream oss;

    // std::ostringstream is inherited from std::ostream:
    oss << *this;	// will call the friend function operator <<

    // Transform the string stream to string:
    return oss.str();
}

// Clone method - to be called inside copy constructor and assignment operator:
template <class T>
void Array<T>::clone(const Array<T>& other) {
	// Copy length value:
	this->size = other.size;

	// Allocate internalArray before copying: (Very Important):
	this->internalArray = new T[this->size];

	// Start copying:
	std::copy(other.internalArray, other.internalArray + size, this->internalArray);
}

// Friend function that implements the toString() method with << operator:
template <class E>
std::ostream& operator<<(std::ostream& output, const Array<E>& other) {
	// Check if the array is NULL:
	if(other.internalArray == NULL) {
		output << "NULL";
		return output;
	}

	// Insert the array in output stream:
	for(int i = 0; i < other.size; i++) {
		output << other.internalArray[i] << " ";
	}
	return output;
}

// Read data from command line:
template <class E>
std::istream& operator>>(std::istream& input, Array<E>& other) {

	// Read from command line:
	for(int i = 0; i < other.size; i++) {
		input >> other.internalArray[i];
	}

	return input;
}

#endif /* ARRAY_HPP_ */






















