/** Copyright 2019 <Eashwar Sathyamurthy> <Sri Manika Makam> 
 */

/** @file PID-controller.cpp
 *  @brief This file provides the implementation of the compute method
 *  @author Part 1: Sri Manika Makam(Driver) Eashwar Sathyamurthy(Navigator)
 */

#include "lib.hpp"
#include <math.h>

void PidController::set() {
  Kp = 0.01;
  Kd = 0.2;
  Ki = 0.1;
  dt = 0.1;
}

double PidController::compute(double actual, double set) {
	double error;
	double previousError = 0;
	double derivePart = 0;
	double accumulatedError = 0;
	error = set - actual;
	int count = 0;

	while (fabs(error)>0.1){
					double kpPart = error* Kp;

					accumulatedError+=error * dt;
					double kiPart= accumulatedError*Ki;




		}

  return 0;
}

