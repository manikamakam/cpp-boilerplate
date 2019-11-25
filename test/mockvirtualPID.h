/**
 *  @file      mockvirtualPID.h
 *  @author    Sri Manika Makam
 *  @copyright MIT License
 *  @brief     Definition and implementation of the mockvirtualPID class
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

#ifndef INCLUDE_MOCKVIRTUALPID_H_
#define INCLUDE_MOCKVIRTUALPID_H_

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "virtualPID.h"

/**
 * @brief mockvirtualPID class
 * Class to initialize the mock methods that are yet to be tested using gmock
 */
class mockvirtualPID : public virtualPID {
 public:
  /**
   * @brief compute mock
   * @param double actual
   * @param double set
   * @return double
   * Initializes the compute mock
   */
  MOCK_METHOD2(compute, double(double,double));

  /**
   * @brief setKP mock
   * @param double kp
   * @return bool
   * Initializes the setKP mock
   */
  MOCK_METHOD1(setKP, bool(double kp));

  /**
   * @brief setKI mock
   * @param double ki
   * @return bool
   * Initializes the setKI mock
   */
  MOCK_METHOD1(setKI, bool(double ki));

  /**
   * @brief setKD mock
   * @param double kd
   * @return bool
   * Initializes the setKD mock
   */
  MOCK_METHOD1(setKD, bool(double kd));
};

#endif /* INCLUDE_MOCKVIRTUALPID_H_ */
