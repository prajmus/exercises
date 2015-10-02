/* Copyright (c) 2015, Jakub Borowski */
#include <boost/test/unit_test.hpp>
#include <stdexcept>

#include "vector.hpp"

using boost::unit_test_framework::test_suite;

void size_test() {
    Vector<int> v;
    BOOST_CHECK_EQUAL(v.size(), 0);

    v.push_back(1);
    BOOST_CHECK_EQUAL(v.size(), 1);

    v.push_back(2);
    BOOST_CHECK_EQUAL(v.size(), 2);

    v.clear();
    BOOST_CHECK_EQUAL(v.size(), 0);
}

void constructors_test() {
    Vector<int> v;
    BOOST_CHECK_EQUAL(v.size(), 0);
    BOOST_CHECK_EQUAL(v.capacity(), 0);
    BOOST_CHECK(!v.data());

    Vector<int> x {1, 2, 3, 4};
    BOOST_CHECK_EQUAL(x.size(), 4);
    BOOST_CHECK_EQUAL(x[3], 4);

    Vector<int> y(x);
    BOOST_CHECK_EQUAL(y.size(), 4);
    BOOST_CHECK_EQUAL(x.size(), 4);
    BOOST_CHECK_EQUAL(y[3], 4);

    Vector<int> z(std::move(x));
    BOOST_CHECK_EQUAL(z.size(), 4);
    BOOST_CHECK_EQUAL(z[3], 4);
    BOOST_CHECK_EQUAL(x.size(), 0);
}

void basic_vector_operations() {
    Vector<int> v;
    BOOST_CHECK_EQUAL(v.empty(), true);

    v.push_back(1);
    BOOST_CHECK_EQUAL(v[0], 1);
    BOOST_CHECK_EQUAL(v.size(), 1);

    Vector<int> v2(2, 2);
    BOOST_CHECK_EQUAL(v2.size(), 2);
    v2.push_back(3);
    BOOST_CHECK_EQUAL(v2.size(), 3);
    BOOST_CHECK_EQUAL(v2[2], 3);
}

void iterators() {
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    Vector<int>::iterator tmp = v.begin();
    BOOST_CHECK_EQUAL(*tmp, 1);

    int counter = 0;
    for (; tmp != v.end(); ++tmp)
        counter++;
    BOOST_CHECK_EQUAL(counter, 5);

    // Check post and prefix incrementation
    Vector<int>::iterator x = v.begin();
    auto y = x++;
    BOOST_CHECK_EQUAL(*y, 1);
    x = v.begin();
    y = ++x;
    BOOST_CHECK_EQUAL(*y, 2);
}

void out_of_range_test() {
    Vector<int> v {1, 2, 3, 4, 5};
    BOOST_CHECK_EQUAL(v[0], 1);
    BOOST_CHECK_THROW(v.at(7), std::out_of_range);
}

void assign_repeat_value() {
    Vector<int> v;
    v.assign(10, 2);
    BOOST_CHECK_EQUAL(v.size(), 10);
    for (int i=0; i < v.size(); ++i)
        BOOST_CHECK_EQUAL(v[i], 2);
}

void assign_initializer_list() {
    Vector<int> v;
    v.assign({1,2,3,4,5,6});
    BOOST_CHECK_EQUAL(v.size(), 6);
    for (int i=0; i < v.size(); ++i)
        BOOST_CHECK_EQUAL(v[i], i+1);
}

test_suite *init_unit_test_suite(int argc, char *argv[]) {
    test_suite *t = BOOST_TEST_SUITE("Create a Vector class");
    t->add(BOOST_TEST_CASE(&size_test));
    t->add(BOOST_TEST_CASE(&constructors_test));
    t->add(BOOST_TEST_CASE(&basic_vector_operations));
    t->add(BOOST_TEST_CASE(&iterators));
    t->add(BOOST_TEST_CASE(&out_of_range_test));
    t->add(BOOST_TEST_CASE(&assign_repeat_value));
    t->add(BOOST_TEST_CASE(&assign_initializer_list));
    return t;
}
