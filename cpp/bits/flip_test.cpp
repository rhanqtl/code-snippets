#include "flip.hpp"

#include <gtest/gtest.h>

TEST(FlipTest, Simple) {
  EXPECT_EQ(hq::bits::flip(0, 0), 1);
  EXPECT_EQ(hq::bits::flip(0, 1), 2);
  EXPECT_EQ(hq::bits::flip(0, 7), 128);
  EXPECT_EQ(hq::bits::flip(255, 7), 127);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}