#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <rmath/base.hpp>

struct tag {};

TEST_CASE("base data can be accessed") {
    auto pt = rmath::base<2, uint32_t, tag>();
    pt.x    = 99;
    pt.y    = 98;

    CHECK(pt.data[0] == 99);
    CHECK(pt.data[1] == 98);
}

TEST_CASE("base data can be accessed") {
    auto pt = rmath::base<3, uint32_t, tag>();
    pt.x    = 99;
    pt.y    = 98;
    pt.z    = 99;

    CHECK(pt.data[0] == 99);
    CHECK(pt.data[1] == 98);
    CHECK(pt.data[2] == 99);
    CHECK(pt.r == 99);
    CHECK(pt.g == 98);
    CHECK(pt.b == 99);
}

TEST_CASE("base data can be accessed") {
    auto pt = rmath::base<4, uint32_t, tag>();
    pt.x    = 99;
    pt.y    = 98;
    pt.z    = 99;
    pt.w    = 97;

    CHECK(pt.data[0] == 99);
    CHECK(pt.data[1] == 98);
    CHECK(pt.data[2] == 99);
    CHECK(pt.data[3] == 97);
    CHECK(pt.r == 99);
    CHECK(pt.g == 98);
    CHECK(pt.b == 99);
    CHECK(pt.a == 97);
}

TEST_CASE("base data length matches") {
    CHECK(rmath::base<2, uint32_t, tag>::size() == 2);
    CHECK(rmath::base<3, uint32_t, tag>::size() == 3);
    CHECK(rmath::base<4, uint32_t, tag>::size() == 4);
}