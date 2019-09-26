#include <gtest/gtest.h>
#include <memory>
#include <iostream>
#include "lib.h"

TEST(compute, justForFun) {
    //std::shared_ptr<PidController> velocityFinal = std::make_shared_ptr<PidController>(); 
    //std::unique_ptr<PidController> velocityFinal (new PidController);
    PidController velocityFinal;
    EXPECT_EQ(17.0, compute(8.0,9.0));
}
