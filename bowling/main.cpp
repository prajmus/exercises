/* Copyright (c) 2015, Jakub Borowski */
#include <boost/test/unit_test.hpp>

#include "bowling.hpp"

using boost::unit_test_framework::test_suite;

void test_game() {
    Game g;
}


test_suite *init_unit_test_suite(int argc, char *argv[]) {
    test_suite *t = BOOST_TEST_SUITE("String Calculator");
    t->add(BOOST_TEST_CASE(&test_game));
    return t;
}
