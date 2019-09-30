# PID-controller

[![Build Status](https://travis-ci.org/manikamakam/PID-controller.svg?branch=master)](https://travis-ci.org/manikamakam/PID-controller)
[![Coverage Status](https://coveralls.io/repos/github/manikamakam/PID-controller/badge.svg?branch=master)](https://coveralls.io/github/manikamakam/PID-controller?branch=master)


## Overview
Part 1: Driver: Sri Manika Makam
        Navigator: Eashwar Sathyamurthy
	
Part 2: Driver: Andre Luiz Gomes Ferreira
	Navigator: Nakul Patel 

## Standard install via command-line

git clone --recursive https://github.com/manikamakam/PID-controller.git
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app

## Summary

Learning the tools Travis and Coveralls was very important for the development of this project. 

When the compute method was implemented, the code coverage was 100% but after the implementation of the main function and adding a constraint where the velocities could not be negative, our code coverage became 96% because there were no unit tests to check this kind of approach. 

One problem that we had in the implementation is that it was not being able to pass the first test. So, we had to tune the values of the gains to achieve the desired result.

The implementation of the project was able to satisfy the class design and to successfully pass all the unit tests.
