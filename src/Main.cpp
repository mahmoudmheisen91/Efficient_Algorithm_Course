/*
 * Main.cpp
 *
 *  Created on: Aug 22, 2015
 *      Author: Mahmoud Mheisens
 */

// Include Standard C+ Libraries:
#include <iostream>
#include <string>
using namespace std;

// Include Header Files:
#include "Insertion.hpp"

// Test Insertion sort:
int main(void) {

	Array<int> a(4);
	a[0] = 1;
	a[1] = 2;
	a[2] = 9;
	a[3] = 4;
	a.print();

	Insertion::sort<ASCEND>(a);
	a.print();
	cout << Insertion::isSorted<ASCEND>(a) << endl;
	cout << Insertion::isSorted<DESCEND>(a) << endl;

	Insertion::sort<DESCEND>(a);
	a.print();
	cout << Insertion::isSorted<ASCEND>(a) << endl;
	cout << Insertion::isSorted<DESCEND>(a) << endl;

	return 0;
}




