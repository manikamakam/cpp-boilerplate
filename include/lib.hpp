/** Copyright 2019 <Eashwar Sathyamurthy> <Sri Manika Makam> 
 */

/** @file lib.hpp
 *  @brief This file includes all the required headers and class definitions.
 *  @author Part 1: Sri Manika Makam(Driver) Eashwar Sathyamurthy(Navigator)
 *  @author Part 2: Andre Ferreira(Driver) Nakul Patel(Navigator)
 *
 */

#pragma once

#include<iostream>

/**
 * @brief PidController - Class to implement the PID Controller
 */

class PidController {
 public:
   /**
   * @brief set - Function which sets the values of kp,kd,ki,dt
   * @param none
   * @return none
   */
  void set();
  /**
   * @brief compute - Function which calculates the new velocity which is closer to the set point velocity
   * @param actual, a double that stores the actual velocity of the robot
   * @param set, a double that stores the set point
   * @return newVelocity
   */
  double compute(double actual, double set);
 private:
  double Kp, Kd, Ki, dt;
};


