/** Copyright 2019 <Eashwar Sathyamurthy> <Sri Manika Makam> 
 */

/** @file PID-controller.cpp
 *  @brief This file provides the implementation of the compute method
 *  @author Part 1: Sri Manika Makam(Driver) Eashwar Sathyamurthy(Navigator)
 */

#include "lib.hpp"

void PidController::set() {
  Kp = 0.01;
  Kd = 0.2;
  Ki = 0.1;
  dt = 0.1;
}

double PidController::compute(double actual, double set) {
  return newVelocity;
}

