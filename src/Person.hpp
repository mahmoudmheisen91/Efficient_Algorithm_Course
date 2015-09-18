/*
 * Person.hpp
 *
 *  Created on: Aug 23, 2015
 *      Author: Mahmoud Mheisen
 */

#ifndef SRC_PERSON_HPP_
#define SRC_PERSON_HPP_

// Include standard library:
#include <iostream>
using namespace std;

// Include Comparable interface:
#include "ComparableInterface.hpp"

// Virtual inheritance to avoid diamond problem:
class Person : virtual public ComparableInterface<Person> {
	public:
		// constructors:
		Person();
		Person(string name, int age);

		// destructor:
		virtual ~Person();

		// overloaded compare method methods:
		bool operator>(const Person& other) const;
		bool operator<(const Person& other) const;
		bool operator==(const Person& other) const;

		// getters and setters:
		int getAge() const;
		void setAge(int age);
		const string& getName() const;
		void setName(const string& name);

	private:
		// Member variables:
		int age;
		string name;

		// interface implementation:
		int compareTo(const Person& item) const;

	// overloaded output stream:
	friend ostream& operator<<(ostream& os, const Person& that);
};


#endif /* SRC_PERSON_HPP_ */











