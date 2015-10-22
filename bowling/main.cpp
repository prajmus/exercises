/* Copyright (c) 2015, Jakub Borowski */
#include <gtest/gtest.h>

#include "bowling.hpp"

class BowlingTest : public ::testing::Test {
 public:
     Game g;
};

TEST_F(BowlingTest, test_game) {
    for (int i=0; i<20; i++)
        g.roll(0);
    EXPECT_EQ(g.score(), 0);
}

TEST_F(BowlingTest, test_all_ones) {
    for (int i = 0; i < 20; i++)
        g.roll(1);
    EXPECT_EQ(g.score(), 20);
}
