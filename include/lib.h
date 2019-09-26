#pragma once

#include<iostream>

class PidController {
    public:
        double compute(double actual, double set);
    private:
        double Kp, Kd, Ki;
};


