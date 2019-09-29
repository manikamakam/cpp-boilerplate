/** Copyright 2019 <Eashwar Sathyamurthy> <Sri Manika Makam> 
 */

/** @file main.cpp
 *  @brief This is the main application source file.
 *  lib.hpp is included.
 *  @author Part 1: Sri Manika Makam(Driver) Eashwar Sathyamurthy(Navigator)
 *  @author Part 2: Andre Ferreira(Driver) Nakul Patel(Navigator)
 *
 */

#include "lib.hpp"
#include <iostream>
#include <memory>

int main() {
	std::shared_ptr<PidController> pid(new PidController);
	pid->set();
	double actualVelocity = 40.0;
	double desiredVelocity = 50.0;
	std::cout << "Current Velocity: " << actualVelocity << std::endl;
	std::cout << "Desired Velocity: " << desiredVelocity << std::endl;
	std::cout << "New Velocity using PID Controller is: "
			<< pid->compute(actualVelocity, desiredVelocity);
	return 0;
}

