#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <rmath/point.hpp>

TEST_CASE("upoint2 can be default constructed") {
    auto pt = rmath::upt2();

    CHECK(pt.x == 0);
    CHECK(pt.y == 0);
}

TEST_CASE("upoint3 can be default constructed") {
    auto pt = rmath::upt3();

    CHECK(pt.x == 0);
    CHECK(pt.y == 0);
    CHECK(pt.z == 0);
}

TEST_CASE("upoint4 can be default constructed") {
    auto pt = rmath::upt4();

    CHECK(pt.x == 0);
    CHECK(pt.y == 0);
    CHECK(pt.z == 0);
    CHECK(pt.w == 0);
}