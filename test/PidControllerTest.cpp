/** Copyright 2019 <Eashwar> <Sri Manika> 
 */

/** @file PidControllerTest.cpp
 *  @brief This file has all the unit tests  to be implemented by the compute method.
 *  @author Part 1: Sri Manika(Driver) Eashwar(Navigator)
 */

#include <gtest/gtest.h>
#include <memory>
#include <iostream>
#include "lib.h"

/** @brief This unit test checks the returned new velocity to be in the desired range.
  *        Actual Velocity = 145.0 and Set point velocity = 177.9
 */        
TEST(PidControllerTest, shouldPass) {  
    std::shared_ptr<PidController> velocityFinal (new PidController);
    ASSERT_NEAR(177.9, velocityFinal-> compute(145.0,177.9),0.5);
}

/** @brief This unit test checks that the retured new velocity is never zero.
  *        Actual Velocity = 3.85 and Set point velocity = 14.98
 */
TEST(PidControllerTest, shouldPass2) {
    std::shared_ptr<PidController> velocityFinal (new PidController);
    ASSERT_TRUE(velocityFinal-> compute(3.85,14.98)); 
}



