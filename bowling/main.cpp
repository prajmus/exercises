/* Copyright (c) 2015, Jakub Borowski */
#include <gtest/gtest.h>

#include "bowling.hpp"

class BowlingTest : public ::testing::Test {
 public:
     Game g;

    void roll_many(int n, int pins) {
        for (int i = 0; i < n; i++)
            g.roll(pins);
    }
};

TEST_F(BowlingTest, test_game) {
    roll_many(20, 0);
    EXPECT_EQ(g.score(), 0);
}

TEST_F(BowlingTest, test_all_ones) {
    roll_many(20, 1);
    EXPECT_EQ(g.score(), 20);
}
