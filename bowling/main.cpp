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

    void roll_spare() {
        g.roll(5);
        g.roll(5);
    }

    void roll_strike() {
        g.roll(10);
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

TEST_F(BowlingTest, test_one_spare) {
    roll_spare();
    g.roll(3);
    roll_many(17, 0);
    EXPECT_EQ(g.score(), 16);
}

TEST_F(BowlingTest, test_one_strike) {
    roll_strike();
    g.roll(3);
    g.roll(4);
    roll_many(16, 0);
    EXPECT_EQ(g.score(), 24);
}

TEST_F(BowlingTest, test_perfect_game) {
    roll_many(12, 10);
    EXPECT_EQ(300, g.score());
}
