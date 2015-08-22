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

namespace Insertion {

	// Sort array in ascending order:
	template <class T>
	void sortAscend(Array<T> &array);

	// Sort array in descending order:
	template <class T>
	void sortDescend(Array<T> &array);

	// Generic Sort:
	template <bool isAscend, class T>
	void sort(Array<T> &array);

	// Test if the array it is sorted:
	template <bool isAscend, class T>
	bool isSorted(Array<T> &array);
}

// Include template file:
#include "Insertion.tpp"

#endif /* INSERTION_HPP_ */
