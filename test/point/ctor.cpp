#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <rmath/point.hpp>

TEST_CASE("upoint2 can be constructed from scalar") {
    std::vector<unsigned int> data {0, 1, 2, 30, 199};

    for (auto& d : data) {
        CAPTURE(d);

        auto pt = rmath::upt2(d);

        CHECK(pt.x == d);
        CHECK(pt.y == d);
    }
}

TEST_CASE("upoint3 can be constructed from scalar") {
    std::vector<unsigned int> data {0, 1, 2, 30, 199};

    for (auto& d : data) {
        CAPTURE(d);

        auto pt = rmath::upt3(d);

        CHECK(pt.x == d);
        CHECK(pt.y == d);
        CHECK(pt.z == d);
    }
}

TEST_CASE("upoint4 can be constructed from scalar") {
    std::vector<unsigned int> data {0, 1, 2, 30, 199};

    for (auto& d : data) {
        CAPTURE(d);

        auto pt = rmath::upt4(d);

        CHECK(pt.x == d);
        CHECK(pt.y == d);
        CHECK(pt.z == d);
        CHECK(pt.w == d);
    }
}