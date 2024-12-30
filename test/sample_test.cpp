#include <gtest/gtest.h>

// A simple test case
TEST(SampleTest, BasicAssertions) {
    EXPECT_EQ(1, 1);  // Passes
    EXPECT_TRUE(true); // Passes
}

// Main function for GoogleTest
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
