#include "lib.h"

double PidController::compute(double actual, double set) {
    return actual+set;
}
