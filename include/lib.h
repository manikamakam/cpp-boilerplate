/** Copyright 2019 <Eashwar> <Sri Manika> 
 */

/** @file lib.h
 *  @brief This file includes all the required headers and class definitions.
 *  @author Part 1: Sri Manika(Driver) Eashwar(Navigator)
 */

#pragma once

#include<iostream>

/**
 * @brief PidController - Class to implement the PID Controller
 */

class PidController {
 public:
  /**
   * @brief compute - Function which calculates the new velocity which is closer to the set point velocity
   * @param actual, a double that stores the actual velocity of the robot
   * @param set, a double that stores the set point
   * @return newVelocity
   */
  double compute(double actual, double set);
 private:
  double Kp, Kd, Ki;
  double error, prevError, integral, derivative, newVelocity, dt;
};


