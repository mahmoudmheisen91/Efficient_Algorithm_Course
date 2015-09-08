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
#include "Array.hpp"
#include "Insertion.hpp"
#include "Person.hpp"
#include "StackArray.hpp"
#include "Node.hpp"

void test_array_class(void) {
	Array<int> a(4, 0);
	Array<int> c(4, 1);
	Array<int> b(a);
	b = c;
	b[2] = 3;
	cout << b << endl;
}

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

void test_stack_array(void) {
	StackArray<int> s;
	cout << "Size = " << s.size() << " ,Length " << s.length() << endl << endl;

	s.push(1);
	s.toString();
	cout << "Size = " << s.size() << " ,Length " << s.length() << endl << endl;

	s.push(2);
	s.toString();
	cout << "Size = " << s.size() << " ,Length " << s.length() << endl << endl;

	s.push(3);
	s.toString();
	cout << "Size = " << s.size() << " ,Length " << s.length() << endl << endl;

	s.push(4);
	s.toString();
	cout << "Size = " << s.size() << " ,Length " << s.length() << endl << endl;

	s.push(5);
	StackArray<int> s2(s);
	s.toString();
	cout << "Size = " << s.size() << " ,Length " << s.length() << endl << endl;

	s.pop();
	s.toString();
	cout << "Size = " << s.size() << " ,Length " << s.length() << endl << endl;

	int b = s.top();
	cout << "top = " << b << endl;
	s.toString();
	cout << "Size = " << s.size() << " ,Length " << s.length() << endl << endl;

	b = s.pop();
	cout << "pop = " << b << endl;
	s.toString();
	cout << "Size = " << s.size() << " ,Length " << s.length() << endl << endl;

	b = s.pop();
	cout << "pop = " << b << endl;
	s.toString();
	cout << "Size = " << s.size() << " ,Length " << s.length() << endl << endl;

	b = s.pop();
	cout << "pop = " << b << endl;
	s.toString();
	cout << "Size = " << s.size() << " ,Length " << s.length() << endl << endl;

	b = s.pop();
	cout << "pop = " << b << endl;
	s.toString();
	cout << "Size = " << s.size() << " ,Length " << s.length() << endl << endl;

	s2.toString();
	cout << "S2 - Size = " << s2.size() << " ,Length " << s2.length() << endl << endl;

	s.pop();
}

void test_node_class(void) {
	Node<int> n1, n2(10), n3(n2);

	n1.setData(3);
	n3.setNext(n1);
	n3.setNext(n1);
	n3.setPrevious(n2);
}


























