#include <gtest/gtest.h>
#include <memory>
#include <iostream>
#include "lib.h"

TEST(PidControllerTest, justForFun) {
    std::shared_ptr<PidController> velocityFinal (new PidController); 
    ASSERT_NEAR(10.0, velocityFinal->compute(8.0,100.0),0.2);
}
