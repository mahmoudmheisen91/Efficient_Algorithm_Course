/*
 * Person.cpp
 *
 *  Created on: Aug 23, 2015
 *      Author: Mahmoud Mheisen
 */

#include "Person.hpp"

// constructors:
Person::Person() {
	// TODO Auto-generated constructor stub
	this->name = "";
	this->age = 0;
}

Person::Person(string name, int age) {
	this->name = name;
	this->age = age;
}

// destructor:
Person::~Person() {
	// TODO Auto-generated destructor stub
}

// overloaded compare method methods:
bool Person::operator>(const Person& other) {
	return this->compareTo(other) > 0;
}

bool Person::operator<(const Person& other) {
	return this->compareTo(other) < 0;
}

bool Person::operator==(const Person& other) {
	return this->compareTo(other) == 0;
}

// interface implementation:
int Person::compareTo(const Person& item) {
	if (this->age > item.age) return 1;
	if (this->age < item.age) return -1;
	return 0;
}

// setters and getters:
int Person::getAge() const {
	return age;
}

void Person::setAge(int age) {
	this->age = age;
}

const string& Person::getName() const {
	return name;
}

void Person::setName(const string& name) {
	this->name = name;
}

// overloaded output stream: friend function
ostream& operator<<(ostream& os, const Person& that) {
	os << "Name: " << that.name << ", Age: " << that.age << ".";

	return os;
}

















