# PID-controller: Gmock Implementation

[![Build Status](https://travis-ci.org/manikamakam/PID-controller.svg?branch=GMock_Extra_Credit)](https://travis-ci.org/manikamakam/PID-controller?branch=GMock_Extra_Credit)
[![Coverage Status](https://coveralls.io/repos/github/manikamakam/PID-controller/badge.svg?branch=GMock_Extra_Credit)](https://coveralls.io/github/manikamakam/PID-controller?branch=GMock_Extra_Credit)

## Overview

This repository is an illustration of gmock testing using PID classes. Dependecies are as follows:

1. cmake
2. gtest
3. gmock

## cmake updates 

To use gmock make the following changes:

1. In the base CMakeLists.txt, add the following line:

    ```
    add_subdirectory(vendor/googletest)
    
    ```
2. In test/CMakeLists.txt, add the following lines at the end:

```
target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include PUBLIC ../vendor/googletest/googlemock/include ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(cpp-test PUBLIC gtest PUBLIC gmock)
```

## Google Mock Testing

A virtual 'virtualPID' class is created to test the mocking framework in C++ using gmock. The virtual methods are inherited by the 'PidController' class where virtual 'compute' function is re-defined.

In the test/mockvirtualPID.h file, all the methods used in gmock are defined and are given below:

```
class mockvirtualPID : public virtualPID {
 public:
  MOCK_METHOD2(compute, double(double,double));
  
  MOCK_METHOD1(setKP, bool(double kp));
  
  MOCK_METHOD1(setKI, bool(double ki));
  
  MOCK_METHOD1(setKD, bool(double kd));
};
```

## Standard install via command-line
```
git clone -b GMock_Extra_Credit --single-branch https://github.com/manikamakam/PID-controller.git
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/Pid-app
```

## Working with Eclipse IDE

Installation

In your Eclipse workspace directory (or create a new one), checkout the repo (and submodules)

```
mkdir -p ~/workspace
cd ~/workspace
git clone -b GMock_Extra_Credit --single-branch https://github.com/manikamakam/PID-controller.git
```

In your work directory, use cmake to create an Eclipse project for an [out-of-source build] of cpp-boilerplate

```
cd ~/workspace
mkdir -p PID-eclipse
cd PID-eclipse
cmake -G "Eclipse CDT4 - Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug -D CMAKE_ECLIPSE_VERSION=4.7.0 -D CMAKE_CXX_COMPILER_ARG1=-std=c++14 ../PID-controller/
```

Import

Open Eclipse, go to File -> Import -> General -> Existing Projects into Workspace -> Select "PID-eclipse" directory created previously as root directory -> Finish

Edit

Source files may be edited under the "[Source Directory]" label in the Project Explorer.

Build

To build the project, in Eclipse, unfold PID-eclipse project in Project Explorer, unfold Build Targets, double click on "all" to build all projects.

Run

In Eclipse, right click on the PID-eclipse in Project Explorer, select Run As -> Local C/C++ Application

Choose the binaries to run (e.g. shell-app, cpp-test for unit testing)
