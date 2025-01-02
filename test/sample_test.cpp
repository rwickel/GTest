#include "sample.h"
#include <gtest/gtest.h>

// Test case for the add function
TEST(AddTest, HandlesPositiveInput) {
    EXPECT_EQ(add(2, 3), 5);
    EXPECT_EQ(add(10, 15), 25);
}

TEST(AddTest, HandlesNegativeInput) {
    EXPECT_EQ(add(-1, 1), 0);
    EXPECT_EQ(add(-5, -7), -12);
}

TEST(AddTest, HandlesZeroInput) {
    EXPECT_EQ(add(0, 0), 0);
    EXPECT_EQ(add(0, 5), 5);
    EXPECT_EQ(add(5, 0), 5);
}