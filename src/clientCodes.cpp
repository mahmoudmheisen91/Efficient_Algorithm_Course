/*
 * clientCodes.cpp
 *
 *  Created on: Aug 24, 2015
 *      Author: Mahmoud Mheisen
 */

// Include own header:
#include "clientCodes.hpp"

// Include Standard C+ Libraries:
#include <iostream>
#include <string>
using namespace std;

// Include project headers:
#include "Insertion.hpp"
#include "Person.hpp"

void test_comparable_objects(void) {
	Array<Person> arrayOfPersons(3);
	arrayOfPersons[0] = Person("A", 22);
	arrayOfPersons[1] = Person("B", 33);
	arrayOfPersons[2] = Person("C", 11);
	arrayOfPersons.toString();
	cout << Insertion::isSorted(arrayOfPersons) << endl;

	Insertion::sort(arrayOfPersons);
	arrayOfPersons.toString();
	cout << Insertion::isSorted(arrayOfPersons) << endl;

	Insertion::sort(arrayOfPersons, DESCEND);
	arrayOfPersons.toString();
	cout << Insertion::isSorted(arrayOfPersons, DESCEND) << endl;
}

void test_copy_operations(void) {
	const Array<int> a(3);
	a[0] = 0;
	a[1] = 1;
	a[2] = 2;

	Array<> b(a);
	Array<> c(3);
	c = b;

	a[1] = 5;
	cout << c << b << a;

}






























