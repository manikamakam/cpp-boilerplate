/**
 * @file      virtualPID.h
 * @author    Sri Manika Makam
 * @copyright MIT License
 * @brief     Header file for defining the virtual class used for abstraction and implementation of PID
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

#ifndef INCLUDE_VIRTUALPID_H_
#define INCLUDE_VIRTUALPID_H_

#include <iostream>

/**
 * @brief virtualPID Class
 * Base class from which PidController class is derived
 */

class virtualPID {
 protected:
  // Variable to store proportional gain
  double kP;
  // Variable to store derivative gain
  double kD;
  // Variable to store integral gain
  double kI;
  // Variable to store time interval
  double dT;

 public:
  /**
   * @brief constructor of virtualPID class
   * @param none
   * @return none
   * Initializes kp, kd, ki and dt to zero
   */
  virtualPID();

  /**
   * @brief Destructor of virtualPID class
   * @param none
   * @return none
   * Destroys class objects of base and derived class when program goes out of scope.
   */
  virtual ~virtualPID()=0;

  /**
   * @brief Virtual 'compute' method
   * @param actual
   * @param set
   * @return double
   * Virtual function which is derived by PidController class
   */
  virtual double compute(double actual, double set) =0;

  /**
   * @brief Virtual 'setKP' method
   * @param kp of type double
   * @return boolean
   * Function to set the kP value
   */
  virtual bool setKP(double kp);

  /**
   * @brief Virtual 'setKI' method
   * @param ki of type double
   * @return boolean
   * Function to set the kI value
   */
  virtual bool setKI(double ki);

  /**
   * @brief Virtual 'setKD' method
   * @param kd of type double
   * @return boolean
   * Function to set the kD value
   */
  virtual bool setKD(double kd);
};

#endif /* INCLUDE_VIRTUALPID_H_ */
