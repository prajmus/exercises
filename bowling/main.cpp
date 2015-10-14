/* Copyright (c) 2015, Jakub Borowski */
#include <boost/test/unit_test.hpp>

#include "bowling.hpp"

using boost::unit_test_framework::test_suite;

void test_game() {
    Game g;
    for (int i=0; i<20; i++)
        g.roll(0);
    BOOST_CHECK_EQUAL(g.score(), 0);
}

void test_all_ones() {
    Game g;
    for (int i = 0; i < 20; i++)
        g.roll(1);
    BOOST_CHECK_EQUAL(g.score(), 20);
}


test_suite *init_unit_test_suite(int argc, char *argv[]) {
    test_suite *t = BOOST_TEST_SUITE("String Calculator");
    t->add(BOOST_TEST_CASE(&test_game));
    t->add(BOOST_TEST_CASE(&test_all_ones));
    return t;
}
