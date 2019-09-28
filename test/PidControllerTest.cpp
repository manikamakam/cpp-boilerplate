#include <gtest/gtest.h>
#include <memory>
#include <iostream>
#include "lib.h"

TEST(PidControllerTest, shouldPass) {
    std::shared_ptr<PidController> velocityFinal (new PidController); 
    ASSERT_NEAR(9.0, velocityFinal-> compute(8.0,9.0),1.0);
}
