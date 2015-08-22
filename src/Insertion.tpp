/*
 * Insertion.cpp
 *
 *  Created on: Aug 22, 2015
 *      Author: Mahmoud Mheisen
 */

namespace Insertion {

	// Sort array in ascending order:
	template <class T>
	void sortAscend(Array<T> &array) {
		// first element is considered to be sorted:
		for(int i = 1; i < array.length; i++) {
			// every element before i is sorted:
			T key = array[i];
	
			int j = i - 1;
			while(j >= 0 && array[j] > key) {
				array[j + 1] = array[j];
				j--;
			}
	
			array[j+1] = key;
			// every elemnt after i is not sorted:
		}
	}
	
	// Sort array in descending order:
	template <class T>
	void sortDescend(Array<T> &array) {
		// first element is considered to be sorted:
		for(int i = 1; i < array.length; i++) {
			// every element before i is sorted:
			T key = array[i];
	
			int j = i - 1;
			
			// just flip array[j] > key to array[j] < key:
			while(j >= 0 && array[j] < key) {
				array[j + 1] = array[j];
				j--;
			}
	
			array[j+1] = key;
			// every elemnt after i is not sorted:
		}
	}
	
	// Generic Sort:
	template <bool isAscend, class T>
	void sort(Array<T> &array) {
		if(isAscend) { // Compile time decesion
			sortAscend(array);
		}
		else {
			sortDescend(array);
		}
	}
	
	// Test if the array it is sorted:
	template <bool isAscend, class T>
	bool isSorted(Array<T> &array) {
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
	
}
