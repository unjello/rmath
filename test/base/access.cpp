#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <rmath/generic/base.hpp>

using namespace rmath::generic;

struct tag {};

TEST_CASE("base data can be accessed") {
    auto pt = base<2, uint32_t, tag>();
    x(pt)   = 99;
    y(pt)   = 98;

    CHECK(pt.data[0] == 99);
    CHECK(pt.data[1] == 98);
}

TEST_CASE("base data can be accessed") {
    auto pt = base<3, uint32_t, tag>();
    x(pt)   = 99;
    y(pt)   = 98;
    z(pt)   = 99;

    CHECK(pt.data[0] == 99);
    CHECK(pt.data[1] == 98);
    CHECK(pt.data[2] == 99);
    CHECK(x(pt) == 99);
    CHECK(y(pt) == 98);
    CHECK(z(pt) == 99);
}

TEST_CASE("base data can be accessed") {
    auto pt = base<4, uint32_t, tag>();
    x(pt)   = 99;
    y(pt)   = 98;
    z(pt)   = 99;
    w(pt)   = 97;

    CHECK(pt.data[0] == 99);
    CHECK(pt.data[1] == 98);
    CHECK(pt.data[2] == 99);
    CHECK(pt.data[3] == 97);
    CHECK(x(pt) == 99);
    CHECK(y(pt) == 98);
    CHECK(z(pt) == 99);
    CHECK(w(pt) == 97);
}

TEST_CASE("base data length matches") {
    CHECK(base<2, uint32_t, tag>::size() == 2);
    CHECK(base<3, uint32_t, tag>::size() == 3);
    CHECK(base<4, uint32_t, tag>::size() == 4);
}