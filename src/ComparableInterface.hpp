/*
 * ComparableInterface.hpp
 *
 *  Created on: Aug 23, 2015
 *      Author: Mahmoud Mheisen
 */

#ifndef SRC_COMPARABLEINTERFACE_HPP_
#define SRC_COMPARABLEINTERFACE_HPP_

template <class T>
class ComparableInterface {
	public:
		// Default constructor:
		// must be implemented, because we are inheriting from this class: ( {} must exists )
		ComparableInterface() {};

		// Destructor:
		// must be defined, because we have virtual method inside this class:
		// must be implemented, because we are inheriting from this class: ( {} must exists )
		virtual ~ComparableInterface() {};

		// Interface API:
		virtual int compareTo(const T& item) = 0;

};

#endif /* SRC_COMPARABLEINTERFACE_HPP_ */
