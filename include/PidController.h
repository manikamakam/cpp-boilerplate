/**
 *  @file      PidController.h
 *  @author    Sri Manika Makam
 *  @copyright MIT License
 *  @brief     Header file for defining the PID class
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

#ifndef INCLUDE_PIDCONTROLLER_H_
#define INCLUDE_PIDCONTROLLER_H_

#include <iostream>
#include "virtualPID.h"

/**
 * @brief PidController class
 * This class is derived from virtualPID class
 */
class PidController : public virtualPID {
 public:
  /**
   * @brief Default constructor of PidController class
   * @param none
   * @return none
   * Initializes all gains and dt to zero
   */
  PidController();

  /**
   * @brief Constructor of PidController class
   * @param kp of type double
   * @param kd of type double
   * @param ki of type double
   * @param dt of type double
   * @return none
   * Initializes gains and dt to the values passed to the constructor
   */
  PidController(double kp, double kd, double ki, double dt);

  /**
   * @brief getKp function
   * @param none
   * @return kp gain of type double
   * Returns the kp gain upon request
   */
  double getKp();

  /**
   * @brief getKd function
   * @param none
   * @return kd gain of type double
   * Returns the kd gain upon request
   */
  double getKd();

  /**
   * @brief getKi function
   * @param none
   * @return ki gain of type double
   * Returns the ki gain upon request
   */
  double getKi();

  /**
   * @brief compute - Function which calculates the new velocity which is closer to the set point velocity
   * @param actual, a double that stores the actual velocity of the robot
   * @param set, a double that stores the set point
   * @return newVelocity of type double
   */
  double compute(double actual, double set);

  /**
   * @brief Destructor of PidController class
   * @param none
   * @return none
   * Destroys class objects when program goes out of scope
   */
  ~PidController();
};

#endif /* INCLUDE_PIDCONTROLLER_H_ */
