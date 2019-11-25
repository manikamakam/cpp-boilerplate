/**
 *  @file      virtualPID.cpp
 *  @author    Sri Manika Makam
 *  @copyright MIT License
 *  @brief     Implementation of the virtual PID class
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

#include "virtualPID.h"

virtualPID::virtualPID()
    : kP(0),
      kD(0),
      kI(0),
      dT(0) {
}

virtualPID::~virtualPID() {
}

bool virtualPID::setKD(double kd) {
  // Set the kD value
  kD = kd;
  // Return true
  return true;
}

bool virtualPID::setKP(double kp) {
  // Set the kP value
  kP = kp;
  // Return true
  return true;
}

bool virtualPID::setKI(double ki) {
  // Set the kI value
  kI = ki;
  // Return true
  return true;
}



