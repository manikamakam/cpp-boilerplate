#include <gtest/gtest.h>
#include <memory>
#include <iostream>
#include "lib.h"

<<<<<<< HEAD
TEST(PidControllerTest, justForFun) {
    std::shared_ptr<PidController> velocityFinal (new PidController); 
    ASSERT_NEAR(10.0, velocityFinal->compute(8.0,100.0),0.2);
=======
TEST(PidControllerTest, shouldPass) {
    std::shared_ptr<PidController> velocityFinal (new PidController); 
    ASSERT_NEAR(9.0, velocityFinal-> compute(8.0,9.0),1.0);
    ASSERT_NEAR(9.0, velocityFinal-> compute(-6.0,9.0),1.0);
>>>>>>> 5fda9da5953fdc10d4aa759cb63489fbbaeaca70
}


TEST(PidControllerTest, shouldPass1) {
    std::shared_ptr<PidController> velocityFinal (new PidController); 
    ASSERT_NEAR(10.0, velocityFinal-> compute(-6.0,10.0),0.5);
}

