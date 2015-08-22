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
		template <bool isAscend, class T>
		static void sort(Array<T> &array);

		// Test if the array it is sorted:
		template <bool isAscend, class T>
		static bool isSorted(Array<T> &array);

	private:
		// Sort array in ascending order:
		template <class T>
		static void sortAscend(Array<T> &array);

		// Sort array in descending order:
		template <class T>
		static void sortDescend(Array<T> &array);

};

// Include template file:
#include "Insertion.tpp"

#endif /* INSERTION_HPP_ */
