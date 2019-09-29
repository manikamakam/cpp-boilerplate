/** Copyright 2019 <Eashwar Sathyamurthy> <Sri Manika Makam> 
 */

/** @file PID-controller.cpp
 *  @brief This file provides the implementation of the compute method
 *  @author Part 1: Sri Manika Makam(Driver) Eashwar Sathyamurthy(Navigator)
 *  @author Part 2: Andre Ferreira(Driver) Nakul Patel(Navigator)
 *
 */

#include <math.h>
#include "lib.hpp"



/**
 * @brief implementation of set() function
 * @param none
 * @return none
 */
void PidController::set() {
    Kp = 0.5;
    Kd = 0.01;
    Ki = 0.02;
    dt = 0.1;
}


/**
 * @brief implementation of compute() function
 * @param actual- the actual velocity
 * @param set-   the set point velocity
 * @return newVelocity
 */
double PidController::compute(double actual, double set) {
    double error;

    /// Calculates the error in velocities
    error = set - actual;

    if (actual > 0 && set > 0) {
      double previousError = 0;
      double accumulatedError = 0;

      while (fabs(error) > 0.5) {
        /// proportional part
        double kpPart = error * Kp;

        accumulatedError += error * dt;
        /// integral part
        double kiPart = accumulatedError * Ki;

        double derivePart = (error - previousError) / dt;
        /// derivative part
        double kdPart = derivePart * Kd;

        /// storing the error to use in next iteration
        previousError = error;

        /// calculating the new velocity
        actual = kdPart + kiPart + kpPart;

        error = set - actual;
      }
      return actual;
    } else {
       return -1;
    }
}

