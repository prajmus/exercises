/* Copyright (c) 2015, Jakub Borowski */
#include <gtest/gtest.h>

#include "bowling.hpp"

TEST(bowling, test_game) {
    Game g;
    for (int i=0; i<20; i++)
        g.roll(0);
    EXPECT_EQ(g.score(), 0);
}

TEST(bowling, test_all_ones) {
    Game g;
    for (int i = 0; i < 20; i++)
        g.roll(1);
    EXPECT_EQ(g.score(), 20);
}
