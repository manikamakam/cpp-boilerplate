/** Copyright 2019 <Eashwar Sathyamurthy> <Sri Manika Makam> 
 */

/** @file PID-controller.cpp
 *  @brief This file provides the implementation of the compute method
 *  @author Part 1: Sri Manika Makam(Driver) Eashwar Sathyamurthy(Navigator)
 *  @author Part 2: Andre Ferreira(Driver) Nakul Patel(Navigator)
 */

#include <math.h>
#include "lib.hpp"

PidController::PidController()
    : kp(0),
      kd(0),
      ki(0),
      dt(0) {
}

PidController::~PidController() {
}

void PidController::set() {
  /// Initializing the values of Kp,Kd,ki,dt
  kp = 0.5;
  kd = 0.01;
  ki = 0.02;
  dt = 0.1;
}

double PidController::compute(double actual, double set) {
  double error;

  /// Calculates the difference in velocities
  error = set - actual;

  if (actual > 0 && set > 0) {
    double previousError = 0;
    double accumulatedError = 0;

    while (fabs(error) > 0.5) {
      /// Calculating output from proportional part
      double kpPart = error * kp;

      accumulatedError += error * dt;
      /// Calculating output from integral part
      double kiPart = accumulatedError * ki;

      double derivePart = (error - previousError) / dt;
      /// Calculating output from derivative part
      double kdPart = derivePart * kd;

      /// Storing the error to use in next iteration
      previousError = error;

      /// Calculating the new velocity
      actual = kdPart + kiPart + kpPart;

      error = set - actual;
    }
    return actual;
  } else {
    return -1;
  }
}

