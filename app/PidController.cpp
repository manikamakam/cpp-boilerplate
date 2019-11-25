/**
 * @file      PidController.cpp
 * @author    Sri Manika Makam
 * @copyright MIT License
 * @brief     This file provides the implementation of the methods of PidController class
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
#include "math.h"

PidController::PidController() {
  kP = 0.5;
  kD = 0.01;
  kI = 0.02;
  dT = 0.1;
}
PidController::PidController(double kp, double kd, double ki, double dt) {
  kP = kp;
  kD = kd;
  kI = ki;
  dT = dt;
}

PidController::~PidController() {
}

double PidController::getKD() {
  return kD;
}

double PidController::getKI() {
  return kI;
}

double PidController::getKP() {
  return kP;
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
      double kpPart = error * kP;

      accumulatedError += error * dT;
      /// Calculating output from integral part
      double kiPart = accumulatedError * kI;

      double derivePart = (error - previousError) / dT;
      /// Calculating output from derivative part
      double kdPart = derivePart * kD;

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
