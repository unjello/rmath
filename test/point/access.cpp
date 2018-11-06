#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <rmath/point.hpp>

TEST_CASE("upoint2 data can be accessed") {
    auto pt = rmath::upt2();
    pt.x    = 99;
    pt.y    = 98;

    CHECK(pt.data[0] == 99);
    CHECK(pt.data[1] == 98);
}

TEST_CASE("upoint3 data can be accessed") {
    auto pt = rmath::upt3();
    pt.x    = 99;
    pt.y    = 98;
    pt.z    = 99;

    CHECK(pt.data[0] == 99);
    CHECK(pt.data[1] == 98);
    CHECK(pt.data[2] == 99);
}

TEST_CASE("upoint4 data can be accessed") {
    auto pt = rmath::upt4();
    pt.x    = 99;
    pt.y    = 98;
    pt.z    = 99;
    pt.w    = 97;

    CHECK(pt.data[0] == 99);
    CHECK(pt.data[1] == 98);
    CHECK(pt.data[2] == 99);
    CHECK(pt.data[3] == 97);
}

TEST_CASE("point data length matches") {
    CHECK(rmath::point<2, uint32_t>::size() == 2);
    CHECK(rmath::point<3, uint32_t>::size() == 3);
    CHECK(rmath::point<4, uint32_t>::size() == 4);
}