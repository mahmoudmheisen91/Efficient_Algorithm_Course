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

template <class T>
class Array {

	public:
		// Declare array with a specific length:
		Array(int length);

		// Initialize the array with predefined value:
		Array(int length, T value);

		// clear array:
		virtual ~Array();

		// overload [] so that the array will keep track of it's size:
		T& operator[](int i);

		// when one array is assigned to another, this is just a pointer manipulation
		// that takes constant time:
		Array<T>& operator=(Array<T> &b);

		// Print array in one line:
		void print(void);

		// Fill array with predefined value:
		void fill(T value);

		// Swap two entries:
		void swap(int i, int j);

		// length of the array:
		int length;

	private:
		// Dynamic array:
		T* internalArray;

};

// Include template file:
#include "Array.tpp"

#endif /* ARRAY_HPP_ */
