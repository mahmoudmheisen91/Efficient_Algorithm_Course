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
#include "StackNode.hpp"
#include "QueueArray.hpp"
#include "QueueNode.hpp"
#include "MaxHeapArray.hpp"

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

	//s.pop();
}

void test_node_class(void) {
	Node<int>* n1 = new Node<int>;
	Node<int>* n2 = new Node<int>(10);
	Node<int>* n3 = new Node<int>(*n2);

	n3->next = n1;
	n3->previous = n2;

	delete n3;
	delete n2;
	delete n1;
}

void test_stack_node(void) {
	StackNode<int> s;
	cout << "Size = " << s.size() << endl << endl;

	s.push(1);
	s.toString();
	cout << "Size = " << s.size() << endl << endl;

	s.push(2);
	s.toString();
	cout << "Size = " << s.size() << endl << endl;

	s.push(3);
	s.toString();
	cout << "Size = " << s.size() << endl << endl;

	s.push(4);
	s.toString();
	cout << "Size = " << s.size() << endl << endl;

	s.push(5);
	s.toString();
	cout << "Size = " << s.size() << endl << endl;

	StackNode<int> s2(s);

	int b = s.pop(); // 5
	cout << "pop = " << b << endl;
	s.toString();
	cout << "Size = " << s.size() << endl << endl;

	b = s.top(); // 4
	cout << "top = " << b << endl;
	s.toString();
	cout << "Size = " << s.size() << endl << endl;

	b = s.pop(); // 4
	cout << "pop = " << b << endl;
	s.toString();
	cout << "Size = " << s.size() << endl << endl; // 3

	StackNode<int> s4 = s;

	b = s.pop(); // 3
	cout << "pop = " << b << endl;
	s.toString();
	cout << "Size = " << s.size() << endl << endl; // 2

	b = s.pop(); // 2
	cout << "pop = " << b << endl;
	s.toString();
	cout << "Size = " << s.size() << endl << endl; // 1

	b = s.pop(); // 1
	cout << "pop = " << b << endl;
	s.toString();
	cout << "Size = " << s.size() << endl << endl; // 0

 	s2.toString();
 	cout << "S2 - Size = " << s2.size() << endl << endl;

 	StackNode<int>* s3 = new StackNode<int>(s2);
 	cout << "S3 - Size = " << s3->size() << endl << endl;
 	delete s3;
 	//cout << "S3 - Size = " << s3->size() << endl << endl;

 	s4.toString();
 	cout << "S4 - Size = " << s4.size() << endl << endl;

 	s4 = s;
 	s4.toString();
 	cout << "S4 - Size = " << s4.size() << endl << endl;

	//s.pop();
}

void test_queue_array(void) {
	QueueArray<int> s;
	cout << "Size = " << s.size() << endl << endl;

	s.enqueue(1);
	s.toString();
	cout << "Size = " << s.size() << endl << endl;

	s.enqueue(2);
	s.toString();
	cout << "Size = " << s.size() << endl << endl;

	s.enqueue(3);
	s.toString();
	cout << "Size = " << s.size() << endl << endl;

	s.enqueue(4);
	s.toString();
	cout << "Size = " << s.size() << endl << endl;

	s.enqueue(5);
	QueueArray<int> s2(s);
	s.toString();
	cout << "Size = " << s.size() << endl << endl;

	int b = s.dequeue();
	cout << "dequeue = " << b << endl;
	s.toString();
	cout << "Size = " << s.size() << endl << endl;

	b = s.top();
	cout << "top = " << b << endl;
	s.toString();
	cout << "Size = " << s.size() << endl << endl;

	b = s.dequeue();
	cout << "dequeue = " << b << endl;
	s.toString();
	cout << "Size = " << s.size() << endl << endl;

	QueueArray<int> s3 = s;
	s3.toString();
	cout << "S3 - Size = " << s3.size() << endl << endl;

	b = s.dequeue();
	cout << "dequeue = " << b << endl;
	s.toString();
	cout << "Size = " << s.size() << endl << endl;

	b = s.dequeue();
	cout << "dequeue = " << b << endl;
	s.toString();
	cout << "Size = " << s.size() << endl << endl;

	b = s.dequeue();
	cout << "dequeue = " << b << endl;
	s.toString();
	cout << "Size = " << s.size() << endl << endl;

 	s2.toString();
	cout << "S2 - Size = " << s2.size() << endl << endl;
}

void test_queue_node(void) {
	QueueNode<int> s;
	cout << "Size = " << s.size() << endl << endl;

	s.enqueue(1);
	s.toString();
	cout << "Size = " << s.size() << endl << endl;

	s.enqueue(2);
	s.toString();
	cout << "Size = " << s.size() << endl << endl;

	s.enqueue(3);
	s.toString();
	cout << "Size = " << s.size() << endl << endl;

	s.enqueue(4);
	s.toString();
	cout << "Size = " << s.size() << endl << endl;

	s.enqueue(5);
	s.toString();
	cout << "Size = " << s.size() << endl << endl;

	//QueueNode<int> s2(s);

	int b = s.dequeue(); // 5
	cout << "dequeue = " << b << endl;
	s.toString();
	cout << "Size = " << s.size() << endl << endl;

	b = s.top(); // 4
	cout << "top = " << b << endl;
	s.toString();
	cout << "Size = " << s.size() << endl << endl;

	b = s.dequeue(); // 4
	cout << "dequeue = " << b << endl;
	s.toString();
	cout << "Size = " << s.size() << endl << endl; // 3

	//QueueNode<int> s4 = s;

	b = s.dequeue(); // 3
	cout << "dequeue = " << b << endl;
	s.toString();
	cout << "Size = " << s.size() << endl << endl; // 2

	b = s.dequeue(); // 2
	cout << "dequeue = " << b << endl;
	s.toString();
	cout << "Size = " << s.size() << endl << endl; // 1

	b = s.dequeue(); // 1
	cout << "dequeue = " << b << endl;
	s.toString();
	cout << "Size = " << s.size() << endl << endl; // 0

 	//s2.toString();
 	//cout << "S2 - Size = " << s2.size() << endl << endl;

 	//StackNode<int>* s3 = new StackNode<int>(s2);
 	//cout << "Size = " << s3->size() << endl << endl;
 	//delete s3;
 	//cout << "Size = " << s3->size() << endl << endl;

 	//s4.toString();
 	//cout << "Size = " << s4.size() << endl << endl;

 	//s4 = s;
 	//s4.toString();
 	//cout << "Size = " << s4.size() << endl << endl;

	//s.pop();
}

void test_max_heap_array(void) {
	MaxHeapArray<int> h1(8);
	cout << "h1 - Size = " << h1.size() << ", Length = " << h1.length() << endl << endl;

	h1.insert(1);
	h1.toString();
	cout << "h1 - Size = " << h1.size() << ", Length = " << h1.length() << endl << endl;

	h1.insert(2);
	h1.toString();
	cout << "h1 - Size = " << h1.size() << ", Length = " << h1.length() << endl << endl;

	h1.insert(3);
	h1.toString();
	cout << "h1 - Size = " << h1.size() << ", Length = " << h1.length() << endl << endl;

	h1.insert(4);
	h1.toString();
	cout << "h1 - Size = " << h1.size() << ", Length = " << h1.length() << endl << endl;

	h1.insert(5);
	h1.toString();
	cout << "h1 - Size = " << h1.size() << ", Length = " << h1.length() << endl << endl;

	int b = h1.deleteMax();
	cout << "h1- deleteMax = " << b << endl;
	h1.toString();
	cout << "h1 - Size = " << h1.size() << ", Length = " << h1.length() << endl << endl;

	b = h1.max();
	cout << "h1- max = " << b << endl;
	h1.toString();
	cout << "h1 - Size = " << h1.size() << ", Length = " << h1.length() << endl << endl;

	MaxHeapArray<int> h2(h1);

	b = h1.deleteMax();
	cout << "h1- deleteMax = " << b << endl;
	h1.toString();
	cout << "h1 - Size = " << h1.size() << ", Length = " << h1.length() << endl << endl;

	b = h1.deleteMax();
	cout << "h1- deleteMax = " << b << endl;
	h1.toString();
	cout << "h1 - Size = " << h1.size() << ", Length = " << h1.length() << endl << endl;

	b = h1.deleteMax();
	cout << "h1- deleteMax = " << b << endl;
	h1.toString();
	cout << "h1 - Size = " << h1.size() << ", Length = " << h1.length() << endl << endl;

	b = h1.deleteMax();
	cout << "h1- deleteMax = " << b << endl;
	h1.toString();
	cout << "h1 - Size = " << h1.size() << ", Length = " << h1.length() << endl << endl;

	Array<int> a(5);
	a[0] = 0;
	a[1] = 5;
	a[2] = -4;
	a[3] = 2;
	a[4] = 2;

	h2.toString();
	cout << "h2 - Size = " << h2.size() << ", Length = " << h2.length() << endl << endl;

	b = h2.deleteMax();
	cout << "h2- deleteMax = " << b << endl;
	h2.toString();
	cout << "h2 - Size = " << h2.size() << ", Length = " << h2.length() << endl << endl;

	h2.insert(0);
	h2.toString();
	cout << "h2 - Size = " << h2.size() << ", Length = " << h2.length() << endl << endl;

	MaxHeapArray<int> h3(a);
	h3.toString();
	cout << "h3 - Size = " << h3.size() << ", Length = " << h3.length() << endl << endl;

	b = h3.deleteMax();
	cout << "h3- deleteMax = " << b << endl;
	h3.toString();
	cout << "h3 - Size = " << h3.size() << ", Length = " << h3.length() << endl << endl;

	MaxHeapArray<int> h4 = h2;
	h4.toString();
	cout << "h4 - Size = " << h4.size() << ", Length = " << h4.length() << endl << endl;

	b = h4.deleteMax();
	cout << "h4- deleteMax = " << b << endl;
	h4.toString();
	cout << "h4 - Size = " << h4.size() << ", Length = " << h4.length() << endl << endl;

	//b = h1.deleteMax(); // will throw run time error because the heap is empty
}


















