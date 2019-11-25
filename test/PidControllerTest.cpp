/**
 * @file      PidControllerTest.cpp
 * @author    Sri Manika Makam
 * @copyright MIT License
 * @brief     Implementation of gmock and unit tests
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
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "mockvirtualPID.h"
#include "gmockStatic.h"
#include "virtualPID.h"
#include "PidController.h"

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

/**
 *@brief Cases to test the setting of kP gain by the mocked class and the derived class
 *@param none
 *@return none
 */
TEST(gmockStatic, settingKPTest) {
  PidController pid;
  std::unique_ptr<mockvirtualPID> vpid(new mockvirtualPID);
  std::unique_ptr<gmockStatic> gmock;

  // Expect a call of the mocked class and true should be returned
  EXPECT_CALL(*vpid, setKP(0.5)).Times(1).WillOnce(Return(true));
  gmock->set_KP(std::move(vpid));

  // Check if the expected return is equal to the actual output
  EXPECT_EQ(1, pid.setKP(0.5));
}

/**
 *@brief Cases to test the setting of kD gain by the mocked class and the derived class
 *@param none
 *@return none
 */
TEST(gmockStatic, settingKDTest) {
  PidController pid;
  std::unique_ptr<mockvirtualPID> vpid(new mockvirtualPID);
  std::unique_ptr<gmockStatic> gmock;

  EXPECT_CALL(*vpid, setKD(0.01)).Times(1).WillOnce(Return(true));
  gmock->set_KD(std::move(vpid));

  EXPECT_EQ(1, pid.setKD(0.01));
}

/**
 *@brief Cases to test the setting of kI gain by the mocked class and the derived class
 *@param none
 *@return none
 */
TEST(gmockStatic, settingKITest) {
  PidController pid;
  std::unique_ptr<mockvirtualPID> vpid(new mockvirtualPID);
  std::unique_ptr<gmockStatic> gmock;

  EXPECT_CALL(*vpid, setKI(0.02)).Times(1).WillOnce(Return(true));
  gmock->set_KI(std::move(vpid));

  EXPECT_EQ(1, pid.setKI(0.02));
}

/**
 *@brief Cases to test the setting of compute method by the mocked class and the derived class
 *@param none
 *@return none
 */
TEST(gmockStatic, computeTest) {
  PidController pid;
  std::unique_ptr<mockvirtualPID> vpid(new mockvirtualPID);
  std::unique_ptr<gmockStatic> gmock;

  EXPECT_CALL(*vpid , compute(145.0, 177.9)).Times(1).WillOnce(Return(0.0));
  gmock->compute_PID(std::move(vpid));

  ASSERT_NEAR(177.9, pid.compute(145.0, 177.9), 0.5);
}

/**
 *@brief Unit test to check if the returned gains are the initialized gains
 *@param none
 *@return none
 */
TEST(PIDtest, getGainsTest) {
  // KP, KD, KI, dT
  PidController pid(0.5, 0.01, 0.02, 0.1);

  // Checking if the gains are properly set by setkP, setkD and setkI  methods
  EXPECT_EQ(0.5, pid.getKP());
  EXPECT_EQ(0.01, pid.getKD());
  EXPECT_EQ(0.02, pid.getKI());
}
