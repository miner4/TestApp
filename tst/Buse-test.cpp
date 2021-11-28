#include "gtest/gtest.h"
#include "Bus.h"

TEST(blaTest, test1) {
    //arrange
    //act
    //assert
    Bus b;
    EXPECT_EQ (b.getFuelCapacity(),  11);
}