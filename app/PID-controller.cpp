/** Copyright 2019 <Eashwar Sathyamurthy> <Sri Manika Makam> 
 */

/** @file PID-controller.cpp
 *  @brief This file provides the implementation of the compute method
 *  @author Part 1: Sri Manika Makam(Driver) Eashwar Sathyamurthy(Navigator)
 */

#include "lib.hpp"
#include <math.h>

void PidController::set() {
  Kp = 0.5;
  Kd = 0.01;
  Ki = 0.02;
  dt = 0.1;
}

double PidController::compute(double actual, double set) {
	double error;
	double previousError = 0;
	double derivePart = 0;
	double accumulatedError = 0;
	error = set - actual;
	int count = 0;

	while (fabs(error)>0.5){
		double kpPart = error * Kp;

		accumulatedError += error * dt;
		double kiPart = accumulatedError * Ki;

		derivePart = (error - previousError) / dt;
		double kdPart = derivePart * Kd;

		previousError = error;
		actual = kdPart + kiPart + kpPart;
		error = set-actual;


		}


  return actual ;
}

