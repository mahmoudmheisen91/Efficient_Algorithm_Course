/*
 * utility.cpp
 *
 *  Created on: Sep 17, 2015
 *      Author: Mahmoud Mheisen
 */

#include "utility.hpp"

void Error(bool condition, const std::string& message) {
	if(condition)
		throw std::runtime_error(message);
}
