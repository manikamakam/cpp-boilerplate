/**
 *  @file      gmockStatic.h
 *  @author    Sri Manika Makam
 *  @copyright MIT License
 *  @brief     Definition and implementation of the gmockStatic class
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

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "virtualPID.h"

/**
 * @brief gmockStatic class
 * Class to call functions of virtualPID mock class
 */
class gmockStatic : public ::testing::Test {
 public:
  /**
   * @brief set_KP function
   * @param Instance of std::unique_ptr<virtualPID>
   * @return none
   * Initializes the object and calls the setKP in the virtualPID class
   */
  void set_KP(std::unique_ptr<virtualPID> instance) {
    instance->setKP(0.5);
  }

  /**
   * @brief set_KD function
   * @param Instance of std::unique_ptr<virtuallPID>
   * @return none
   * Initializes the object and calls the setKD in the virtualPID class
   */
  void set_KD(std::unique_ptr<virtualPID> instance) {
    instance->setKD(0.01);
  }

  /**
   * @brief set_KI function
   * @param Instance of std::unique_ptr<virtualPID>
   * @return none
   * Initializes the object and calls the setKI in the virtualPID class
   */
  void set_KI(std::unique_ptr<virtualPID> instance) {
    instance->setKI(0.02);
  }

  /**
   * @brief compute_PID function
   * @param Instance of std::unique_ptr<virtualPID>
   * @return none
   * Initializes the object and calls the compute method in the virtualPID class
   */
  void compute_PID(std::unique_ptr<virtualPID> instance) {
    instance->compute(145.0, 177.9);
  }
};
