/* Copyright (c) 2015, Jakub Borowski */
#include <boost/test/unit_test.hpp>
#include <stdexcept>

#include "calculator.hpp"

using boost::unit_test_framework::test_suite;

void no_number() {
    BOOST_CHECK_EQUAL(add(""), 0);
}

void one_number() {
    BOOST_CHECK_EQUAL(add("1"), 1);
}

void many_single_numbers() {
    BOOST_CHECK_EQUAL(add("3"), 3);
    BOOST_CHECK_EQUAL(add("134"), 134);
    // BOOST_CHECK_EQUAL(add("9456"), 9456); --> invalid after step 6
    BOOST_CHECK_EQUAL(add("9456"), 0);  // after step 6
}

void two_numbers() {
    BOOST_CHECK_EQUAL(add("1,2"), 3);
}

void two_numbers2() {
    BOOST_CHECK_EQUAL(add("1,"), 1);
}

void many_numbers() {
    BOOST_CHECK_EQUAL(add("1,2,3"), 6);
    BOOST_CHECK_EQUAL(add("2,3,4,5,6"), 20);
}

void new_line_and_comma() {
    BOOST_CHECK_EQUAL(add("1\n2,3"), 6);
}

void different_delimiter() {
    BOOST_CHECK_EQUAL(add("//;\n1;2;3"), 6);
    BOOST_CHECK_EQUAL(add("//-\n1-4-5"), 10);
}

void test_negative() {
    BOOST_CHECK_THROW(add("-1,2"), std::logic_error);
    try {
        add("-1,-2,-3");
    } catch (std::logic_error &e) {
        BOOST_CHECK_EQUAL(e.what(), "negatives not allowed: -1-2-3");
    }
}

void check_thousand() {
    BOOST_CHECK_EQUAL(add("1001,2"), 2);
}

void longer_delimeter() {
    BOOST_CHECK_EQUAL(add("//[***]\n1***2***3"), 6);
}

void many_delimeters() {
    BOOST_CHECK_EQUAL(add("//[*][%]\n1*2%3"), 6);
    BOOST_CHECK_EQUAL(add("//[*][%][^]\n1*2%3^4"), 10);
}

void many_long_delimeters() {
    BOOST_CHECK_EQUAL(add("//[**][%%]\n1**2%%3"), 6);
}

test_suite *init_unit_test_suite(int argc, char *argv[]) {
    test_suite *t = BOOST_TEST_SUITE("String Calculator");
    t->add(BOOST_TEST_CASE(&no_number));
    t->add(BOOST_TEST_CASE(&one_number));
    t->add(BOOST_TEST_CASE(&many_single_numbers));
    t->add(BOOST_TEST_CASE(&two_numbers));
    t->add(BOOST_TEST_CASE(&two_numbers2));
    t->add(BOOST_TEST_CASE(&many_numbers));
    t->add(BOOST_TEST_CASE(&new_line_and_comma));
    t->add(BOOST_TEST_CASE(&different_delimiter));
    t->add(BOOST_TEST_CASE(&test_negative));
    t->add(BOOST_TEST_CASE(&check_thousand));
    t->add(BOOST_TEST_CASE(&longer_delimeter));
    t->add(BOOST_TEST_CASE(&many_delimeters));
    t->add(BOOST_TEST_CASE(&many_long_delimeters));
    return t;
}
