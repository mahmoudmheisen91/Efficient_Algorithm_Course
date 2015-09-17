/*
 * Vector.hpp
 *
 *  Created on: Sep 15, 2015
 *      Author: Mahmoud Mheisen
 */

/*
 * Vector generic class stores list of values in an array.
 * Has an iterator to loop through its content.
 */

/*
 * TODO:
 * Add constant iterator
 * Modify >> operator to take values until it hits enter
 * checkIndex method
 * Work with STL sort
 */

#ifndef SRC_VECTOR_HPP_
#define SRC_VECTOR_HPP_

// Include C++ libraries:
#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
#include <stdexcept>
#include <iterator>

// Include project headers:
#include "utility.hpp"

// Default type is int:
template<class T = int>
class Vector {
public:
	// Default constructor:
	Vector(void);

	// Initialize the vector with predefined size and value:
	Vector(const unsigned int& length, const T& value = T());

	// Copy constructor:
	Vector(const Vector<T>& other);

	// Destructor:
	virtual ~Vector(void);

	// Push back method:
	void pushBack(const T& value);

	// Pop back method:
	T popBack(void);

	// Insert method:
	void insert(const unsigned int& index, const T& value);

	// Remove an element at index and shift to the left:
	T remove(const unsigned int& index);

	// Return the beginning of vector:
	T& front(void) const;

	// Return the end of vector:
	T& back(void) const;

	// Clear method:
	void clear(void);

	// Resize the vector to new size:
	void resize(const unsigned int& capacity);

	// toString method:
	std::string toString(void) const;

	// Synonym for non const []:
	T& at(const unsigned int& index);

	// Synonym for const []:
	const T& at(const unsigned int& index) const;

	// Array access operator [] for non const type:
	T& operator[](const unsigned int& index);

	// Array access operator [] for const type:
	const T& operator[](const unsigned int& index) const;

	// Assignment operator:
	Vector<T>& operator=(const Vector<T>& other);

	// Operator <<: to quickly add elements to the vector:
	Vector<T>& operator<<(const T& value);

	// Return the current number of elements inside the vector:
	inline unsigned int size(void) const {
		return this->count;
	}

	// Return the length of vector:
	inline unsigned int length(void) const {
		return this->capacity;
	}

	// isEmpty method:
	inline bool isEmpty(void) const {
		return size() == 0;
	}

	// Random access iterator to loop through the vector:
    class iterator : public std::iterator<std::random_access_iterator_tag, T> {

    public:
    	// Constructor:
        iterator() {
            this->container = NULL;
            this->index = 0;
        }

        // Copy constructor:
        iterator(const iterator& it) {
            this->container = it.container;
            this->index = it.index;
        }

        // Assignment constructor:
        iterator(const Vector* vp, int index) {
            this->container = vp;
            this->index = index;
        }

        // Destructor:
        virtual ~iterator() {
        	// TODO: Why:
        	// Empty:
        }

        // Pre ++ advance to next element:
        iterator& operator ++() {
            index++;
            return *this;
        }

        // Post ++ advance to next element:
        iterator operator ++(int) {
            iterator copy(*this);
            operator++();
            return copy;
        }

        // Pre -- advance to previous element:
        iterator& operator --() {
            index--;
            return *this;
        }

        // Post -- advance to previous element:
        iterator operator --(int) {
            iterator copy(*this);
            operator--();
            return copy;
        }

        // Compare operators:
        bool operator ==(const iterator& rhs) {
            return container == rhs.container && index == rhs.index;
        }

        bool operator !=(const iterator& rhs) {
            return !(*this == rhs);
        }

        bool operator <(const iterator& rhs) {
        	Error(container != rhs.container, "Vector Iterator::operator <: Iterators are in different vectors");
            return index < rhs.index;
        }

        bool operator <=(const iterator& rhs) {
        	Error(container != rhs.container, "Vector Iterator::operator <=: Iterators are in different vectors");
            return index <= rhs.index;
        }

        bool operator >(const iterator& rhs) {
        	Error(container != rhs.container, "Vector Iterator::operator >: Iterators are in different vectors");
            return index > rhs.index;
        }

        bool operator >=(const iterator& rhs) {
        	Error(container != rhs.container, "Vector Iterator::operator >=: Iterators are in different vectors");
            return index >= rhs.index;
        }

        // Advance to next:
        iterator operator +(const int& rhs) {
            return iterator(container, index + rhs);
        }

        iterator operator +=(const int& rhs) {
            index += rhs;
            return *this;
        }

        iterator operator -(const int& rhs) {
            return iterator(container, index - rhs);
        }

        // Advance to previous:
        iterator operator -=(const int& rhs) {
            index -= rhs;
            return *this;
        }

        // Dereference:
        T operator *() {
            return container->elements[index];
        }

        // Access:
        T* operator ->() {
            return &container->elements[index];
        }

        // index:
        T operator [](int k) {
            return container->elements[index + k];
        }

        int operator -(const iterator& rhs) {

            return index - rhs.index;
        }

    private:
        const Vector* container;
        int index;

    };

    // Iterator that return the beginning of vector:
    iterator begin() const {
        return iterator(this, 0);
    }

    // Iterator that return the end of vector:
    iterator end() const {
        return iterator(this, count);
    }

private:
	// Inner array:
	T* elements;

	// Length of inner array:
	unsigned int capacity;

	// Current number of elements inside the vector:
	unsigned int count;

	// Clone method:
	void clone(const Vector<T>& other);

	// isFull method:
	inline bool isFull(void) const {
		return size() == this->capacity;
	}

// Write data to command line:
template<class E>
friend std::ostream& operator<<(std::ostream& output, const Vector<E>& other);

// Read data from command line:
template<class E>
friend std::istream& operator>>(std::istream& input, Vector<E> & other);

};

// Default constructor:
template<class T>
Vector<T>::Vector(void) {
	// Initialization:
	this->count = 0;
	this->capacity = 1;
	this->elements = new T[this->capacity];
}

// Initialize the vector with predefined size and value:
template<class T>
Vector<T>::Vector(const unsigned int& length, const T& value) {
	// Check length:
	assert(length > 0);

	// Initialization:
	this->count = length;
	this->capacity = length;
	this->elements = new T[this->capacity];

	// Fill:
	std::fill(this->elements, this->elements + this->capacity, value);
}

// Copy constructor:
template<class T>
Vector<T>::Vector(const Vector<T>& other) {
	// Copy:
	clone(other);
}

// Destructor:
template<class T>
Vector<T>::~Vector(void) {
	if(this->elements != NULL) {
		delete[] this->elements;
		this->elements = NULL;
	}
}

// Push back method:
template<class T>
void Vector<T>::pushBack(const T& value) {
	insert(count, value);
}

// Pop back method:
template<class T>
T Vector<T>::popBack(void) {
	return remove(count-1);
}

// Insert method:
template<class T>
void Vector<T>::insert(const unsigned int& index, const T& value) {
	// Check:
	if(this->capacity == 0) resize(1);
	else if(isFull()) resize(2 * this->count);

	for(int i = count; i > index; --i) {
		this->elements[i] = this->elements[i - 1];
	}
	this->elements[index] = value;
	this->count++;
}

// Remove an element at index and shift to the left:
template <class T>
T Vector<T>::remove(const unsigned int& index) {
	// Check the index:
	assert(index >= 0 && index < this->count);
    Error(isEmpty(), "The vector is Empty");

	T temp = this->elements[index];
	for(int i = index; i < count; i++) {
		this->elements[i] = this->elements[i + 1];
	}

	this->count--;
	return temp;
}

// Return the beginning of vector:
template<class T>
T& Vector<T>::front(void) const {
	// Test if empty:
	Error(isEmpty(), "The vector is Empty");

	return this->elements[0];
}

// Return the end of vector:
template<class T>
T& Vector<T>::back(void) const {
	// Test if empty:
	Error(isEmpty(), "The vector is Empty");

	return this->elements[count-1];
}

// Clear method:
template<class T>
void Vector<T>::clear(void) {
	// Call destructor:
	this->~Vector();

	// Initialize:
	this->count = 0;
	this->capacity = 1;
	this->elements = new T[this->capacity];
}

// Resize the vector to new size:
template<class T>
void Vector<T>::resize(const unsigned int& capacity) {
	// Check capacity:
	assert(capacity > 0);

	// Update capacity:
	this->capacity = capacity;

	// Make a pointer that points to the old array:
	T* temp = this->elements;

	// Allocate new chunk to this array:
	this->elements = new T[this->capacity];

	// Copy from the old array to the new array:
	for(int i = 0; i < this->count; i++)
		this->elements[i] = temp[i];

	// Delete temp pointer:
	delete[] temp;
	temp = NULL;
}

// toString method:
template<class T>
std::string Vector<T>::toString(void) const {
	// Make an output string stream and insert this into it:
    std::ostringstream oss;
    oss << *this;

    // Transform the string stream to string:
    return oss.str();
}

// Acronym for non const []:
template<class T>
T& Vector<T>::at(const unsigned int& index) {
	return this->operator [](index);
}

// Acronym for const []:
template<class T>
const T& Vector<T>::at(const unsigned int& index) const {
	return this->operator [](index);
}

// Array access operator [] for non const type:
template<class T>
T& Vector<T>::operator[](const unsigned int& index) {
	// Check the index:
	assert(index >= 0 && index < this->count);

	// Return:
	return this->elements[index];
}

// Array access operator [] for const type:
template<class T>
const T& Vector<T>::operator[](const unsigned int& index) const {
	// Check the index:
	assert(index >= 0 && index < this->count);

	// Return:
	return this->elements[index];
}

// Assignment operator:
template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
	// Delete this before:
	this->~Vector();

	// Copy:
	clone(other);
	return *this;
}

// Operator <<: to quickly add elements to the vector:
template <class T>
Vector<T>& Vector<T>::operator<<(const T& value) {
	pushBack(value);

	return *this;
}

// Clone method:
template<class T>
void Vector<T>::clone(const Vector<T>& other) {
	// Copy count and capacity:
	this->count = other.count;
	this->capacity = other.capacity;

	// Allocate element before copying: (Very Important):
	this->elements = new T[this->capacity];
	std::copy(other.elements, other.elements + this->count, this->elements);
}

// Write data to command line:
template<class E>
std::ostream& operator<<(std::ostream& output, const Vector<E>& other) {
	// Check if Empty:
	if(other.isEmpty()) {
		output << "NULL";
		return output;
	}

	// Insert the vector in output stream:
	for(int i = 0; i < other.size(); i++) {
		output << other.elements[i] << " ";
	}
	return output;
}

// Read data from command line:
template<class E>
std::istream& operator>>(std::istream& input, Vector<E> & other) {

	// Read from command line:
	for(int i = 0; i < other.length(); i++) {
		input >> other.elements[i];
	}

	other.count = other.capacity;

	return input;
}

#endif /* SRC_VECTOR_HPP_ */





