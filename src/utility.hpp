/*
 * utility.hpp
 *
 *  Created on: Sep 17, 2015
 *      Author: Mahmoud Mheisen
 */

#ifndef SRC_UTILITY_HPP_
#define SRC_UTILITY_HPP_

// Include C++ libraries:
#include <stdexcept>
#include <string>

// Function that throw an error when condition is true:
void Error(bool condition, const std::string& message);

#endif /* SRC_UTILITY_HPP_ */
