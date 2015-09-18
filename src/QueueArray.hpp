/*
 * QueueArray.hpp
 *
 *  Created on: Sep 10, 2015
 *      Author: Mahmoud Mheisen
 */

/*
 * Array based Queue, resizable array:
 * a collection that processes values in a first-in/first-out (FIFO) order.
 * Double the size when full, half the size when quarter full
 * Resizing operation has an amortized time of O(1)
 */

/*
 * TODO:
 * cin >> s; and s has zero length - Read data from command line:
 * Add const iterator
 * Work with STL sort
 * implement it as a ring
 * dequeue takes O(N)
 * Add clear method - also for stack
 * Add = operator - also for stack
 */

#ifndef SRC_QUEUEARRAY_HPP_
#define SRC_QUEUEARRAY_HPP_

// Include C++ Libraries:
#include <iostream>
#include <sstream>
#include <string>

// Include project headers:
#include "Vector.hpp"
#include "utility.hpp"

// Array based Queue, resizable array:
// Resizing operation has an amortized time of O(1)
template <class T>
class QueueArray {
public:
	// Constructor:
	QueueArray();

	// Copy Constructor:
	QueueArray(const QueueArray& other);

	// Destructor:
	virtual ~QueueArray(void);

	// Enqueue element at the top of the queue:
	void enqueue(T element);

	// Dequeue element from the end of the queue:
	T dequeue(void);

	// Return the top of the queue without removing it:
	T top(void);

	// Return the back of the queue without removing it:
	T back(void);

	// toString method:
	std::string toString(void) const;

	// Operator <<: to quickly add elements to the queue:
	QueueArray<T>& operator<<(const T& value);

	// Operator >>: to quickly remove elements from the queue:
	QueueArray<T>& operator>>(T& value);

	// Return current number of elements in the queue:
	unsigned int size(void) const {
		return elements.size();
	}

	// isEmpty method:
	bool isEmpty(void) const {
		return elements.isEmpty();
	}

	// Random access iterator to loop through the queue:
	class iterator : public Vector<T>::iterator {
	public:
		iterator() : Vector<T>::iterator() {}
		iterator(const typename Vector<T>::iterator& it) : Vector<T>::iterator(it) {}
	};

    // Iterator that return the beginning of the queue:
    iterator begin(void) const {
        return iterator(elements.begin());
    }

    // Iterator that return the end of the queue:
    iterator end(void) const {
        return iterator(elements.end());
    }

private:
	// Member variables:
	Vector<T> elements;

	// Quarter full method:
	inline bool quarterFull(void) const {
		return elements.size() == elements.length() / 4;
	}

// Write data to command line:
template<class E>
friend std::ostream& operator<<(std::ostream& output, const QueueArray<E>& other);

};

// Constructor:
template <class T>
QueueArray<T>::QueueArray() {
}

// Copy Constructor:
template <class T>
QueueArray<T>::QueueArray(const QueueArray& other) {
	this->elements = other.elements;
}

// Destructor:
template <class T>
QueueArray<T>::~QueueArray(void) {
}

// Enqueue element at the top of the queue:
template <class T>
void QueueArray<T>::enqueue(T element) {
	// Add the element and increase the current size, vector will double its size automatically:
	elements << element;
}

// Dequeue element from the end of the queue:
template <class T>
T QueueArray<T>::dequeue(void) {
	// If empty throw runtime error:
	Error(isEmpty(), "Queue is Empty");

	// Decrease the current size and return the element:
	T item = elements.remove(0);

	// If the array is quarter full cut the length to half:
	if(quarterFull()) elements.resize(elements.length() / 2);

	return item;
}

// Return the top of the queue without removing it:
template <class T>
T QueueArray<T>::top(void) {
	// If empty throw runtime error:
	Error(isEmpty(), "Queue is Empty");

	return elements.front();
}

// Return the back of the queue without removing it:
template <class T>
T QueueArray<T>::back(void) {
	// If empty throw runtime error:
	Error(isEmpty(), "Queue is Empty");

	return elements.back();
}

// toString method:
template <class T>
std::string QueueArray<T>::toString(void) const {
	// Make an output string stream and insert this into it:
    std::ostringstream oss;
    oss << *this;

    // Transform the string stream to string:
    return oss.str();
}

// Operator <<: to quickly add elements to the queue:
template<class T>
QueueArray<T>& QueueArray<T>::operator<<(const T& value) {
	this->elements << value;
	return *this;
}

// Operator >>: to quickly remove elements from the queue:
template<class T>
QueueArray<T>& QueueArray<T>::operator>>(T& value) {
	value = dequeue();
	return *this;
}

// Write data to command line:
template<class E>
std::ostream& operator<<(std::ostream& output, const QueueArray<E>& other) {
	// Check if Empty:
	if(other.isEmpty()) {
		output << "The queue is empty" ;
		return output;
	}

	return output << other.elements;
}

#endif /* SRC_QUEUEARRAY_HPP_ */













