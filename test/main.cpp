/** Copyright 2019 <Eashwar Sathyamurthy> <Sri Manika Makam> 
 */

/** @file main.cpp
 *  @brief This file will run all test cases.
 *  @author Part 1: Sri Manika Makam(Driver) Eashwar Sathyamurthy(Navigator)
 *  @author Part 2: Andre Ferreira(Driver) Nakul Patel(Navigator)
 */

#include <gtest/gtest.h>
#include "lib.hpp"

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

