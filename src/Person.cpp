/*
 * Person.cpp
 *
 *  Created on: Aug 23, 2015
 *      Author: redapple
 */

#include "Person.hpp"

Person::Person() {
	// TODO Auto-generated constructor stub
	this->name = "";
	this->age = 0;
}

Person::Person(string name, int age) {
	this->name = name;
	this->age = age;
}

Person::~Person() {
	// TODO Auto-generated destructor stub
}

bool Person::operator>(Person& other) {
	return this->compareTo(other) > 0;
}

bool Person::operator<(Person& other) {
	return this->compareTo(other) < 0;
}

bool Person::operator==(Person& other) {
	return this->compareTo(other) == 0;
}

int Person::compareTo(const Person& item) {
	if (this->age > item.age) return 1;
	if (this->age < item.age) return -1;
	return 0;
}

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

ostream& operator<<(ostream& os, const Person& that) {
	os << "Name: " << that.name << ", Age: " << that.age << ".";

	return os;
}

















