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

// Enum Constants:
enum Order {ASCEND, DESCEND};

class Insertion {

	public:
		// Generic Sort:
		template <class E = int>
		static void sort(Array<E> &array, Order isAscend = ASCEND);

		// Test if the array it is sorted:
		template <class E = int>
		static bool isSorted(const Array<E> &array, Order isAscend = ASCEND);

	private:
		// Sort array in ascending order:
		template <class E = int>
		static void sortAscend(Array<E> &array);

		// Sort array in descending order:
		template <class E = int>
		static void sortDescend(Array<E> &array);

};

// Generic Sort:
template <class E>
void Insertion::sort(Array<E> &array, Order isAscend) {
	(isAscend == ASCEND) ? sortAscend(array) : sortDescend(array);
}

// Test if the array it is sorted:
template <class E>
bool Insertion::isSorted(const Array<E> &array, Order isAscend) {
	for(int i = 0; i < array.length()-1; i++) {

		if(isAscend == ASCEND && array[i] > array[i+1]) {
			return false;
		}

		if(isAscend == DESCEND && array[i] < array[i+1]) {
			return false;
		}

	}
	return true;
}

// Sort array in ascending order:
template <class E>
void Insertion::sortAscend(Array<E> &array) {
	// first element is considered to be sorted:
	for(int i = 1; i < array.length(); i++) {
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
	for(int i = 1; i < array.length(); i++) {
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











