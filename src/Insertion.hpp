/*
 * Insertion.hpp
 *
 *  Created on: Aug 22, 2015
 *      Author: Mahmoud Mheisen
 */

// Worst case: O(N^2)
// Best case: O(N)

#ifndef INSERTION_HPP_
#define INSERTION_HPP_

// Include Header Files:
#include "Array.hpp"

// Macro types:
#define ASCEND true
#define DESCEND false

class Insertion {

	public:
		// Generic Sort:
		template <class E>
		static void sort(Array<E> &array, bool isAscend = ASCEND);

		// Test if the array it is sorted:
		template <class E>
		static bool isSorted(Array<E> &array, bool isAscend = ASCEND);

	private:
		// Sort array in ascending order:
		template <class E>
		static void sortAscend(Array<E> &array);

		// Sort array in descending order:
		template <class E>
		static void sortDescend(Array<E> &array);

};

// Generic Sort:
template <class E>
void Insertion::sort(Array<E> &array, bool isAscend) {
	isAscend? sortAscend(array) : sortDescend(array);
}

// Test if the array it is sorted:
template <class E>
bool Insertion::isSorted(Array<E> &array, bool isAscend) {
	for(int i = 0; i < array.length-1; i++) {

		if(isAscend && array[i] > array[i+1]) {
			return false;
		}

		if(!isAscend && array[i] < array[i+1]) {
			return false;
		}

	}
	return true;
}

// Sort array in ascending order:
template <class E>
void Insertion::sortAscend(Array<E> &array) {
	// first element is considered to be sorted:
	for(int i = 1; i < array.length; i++) {
		// every element before i is sorted:
		E key = array[i];

		int j = i - 1;
		while(j >= 0 && array[j] > key) {
			array[j + 1] = array[j];
			j--;
		}

		array[j+1] = key;
		// every element after i is not sorted:
	}
}

// Sort array in descending order:
template <class E>
void Insertion::sortDescend(Array<E> &array) {
	// first element is considered to be sorted:
	for(int i = 1; i < array.length; i++) {
		// every element before i is sorted:
		E key = array[i];

		int j = i - 1;

		// just flip array[j] > key to array[j] < key:
		while(j >= 0 && array[j] < key) {
			array[j + 1] = array[j];
			j--;
		}

		array[j+1] = key;
		// every element after i is not sorted:
	}
}

#endif /* INSERTION_HPP_ */











