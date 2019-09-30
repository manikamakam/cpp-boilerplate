/** Copyright 2019 <Eashwar Sathyamurthy> <Sri Manika Makam> 
 */

/** @file main.cpp
 *  @brief This is the main application source file.
 *  @author Part 1: Sri Manika Makam(Driver) Eashwar Sathyamurthy(Navigator)
 *  @author Part 2: Andre Ferreira(Driver) Nakul Patel(Navigator)
 */

#include <iostream>
#include <memory>
#include "lib.hpp"

/**
 * @brief Main function
 * @param none
 * @return 0
 */
int main() {
  PidController pid;
  pid.set();
  double actualVelocity = 40.0;
  double desiredVelocity = 50.0;
  if (actualVelocity > 0 && desiredVelocity > 0) {
    /// Printing the velocities
    std::cout << "Current Velocity: " << actualVelocity << std::endl;
    std::cout << "Desired Velocity: " << desiredVelocity << std::endl;
    std::cout << "New Velocity using PID Controller is: "
              << pid.compute(actualVelocity, desiredVelocity) << std::endl;
  } else {
    std::cout << "Velocities cannot be negative.";
  }
  return 0;
}
