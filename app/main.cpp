/**
 * @file      main.cpp
 * @author    Sri Manika Makam
 * @copyright MIT License
 * @brief     This is the main application source file
 */

/**
 *  MIT License
 *
 *  Copyright (c) 2019 Sri Manika Makam
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a
 *  copy of this software and associated documentation files (the "Software"),
 *  to deal in the Software without restriction, including without
 *  limitation the rights to use, copy, modify, merge, publish, distribute,
 *  sublicense, and/or sell copies of the Software, and to permit persons to
 *  whom the Software is furnished to do so, subject to the following
 *  conditions:
 *
 *  The above copyright notice and this permission notice shall be included
 *  in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 *  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *  DEALINGS IN THE SOFTWARE.
 */

#include <iostream>
#include "PidController.h"
#include "virtualPID.h"
#include "memory"

/**
 * @brief Main function
 * @param none
 * @return 0
 */
int main() {
  // Creating object for PidController class
  PidController pid;
  // Point the virtual class object to the PidController class
  std::unique_ptr<virtualPID> vpid = std::make_unique<PidController>();

  // Variables to store user input
  double actualVelocity, desiredVelocity;

  // Input desired velocity
  std::cout << "Enter the desired velocity" << std::endl;
  std::cin >> desiredVelocity;

  // Input current velocity
  std::cout << "Enter the current velocity" << std::endl;
  std::cin >> actualVelocity;

  // Set the PID gains
  vpid->setKP(2);
  vpid->setKI(0.1);
  vpid->setKD(1);

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
