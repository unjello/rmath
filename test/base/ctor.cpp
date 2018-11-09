#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <rmath/point.hpp>

struct tag {};

TEST_CASE_TEMPLATE("unsigned base can be constructed from scalar",
                   T,
                   rmath::base<2, uint32_t, tag>,
                   rmath::base<3, uint32_t, tag>,
                   rmath::base<4, uint32_t, tag>) {
    std::vector<uint32_t> data {0, 1, 2, 30, 199};

    for (auto& d : data) {
        CAPTURE(d);

        auto pt = T(d);
        for (size_t i = 0; i < T::size(); ++i) {
            CHECK(pt.data[i] == d);
        }
    }
}

TEST_CASE_TEMPLATE("signed base can be constructed from scalar",
                   T,
                   rmath::base<2, int32_t, tag>,
                   rmath::base<3, int32_t, tag>,
                   rmath::base<4, int32_t, tag>) {
    std::vector<int32_t> data {0, 1, -2, 30, -199};

    for (auto& d : data) {
        CAPTURE(d);

        auto pt = T(d);
        for (size_t i = 0; i < T::size(); ++i) {
            CHECK(pt.data[i] == d);
        }
    }
}

TEST_CASE_TEMPLATE("float base can be constructed from scalar",
                   T,
                   rmath::base<2, float, tag>,
                   rmath::base<3, float, tag>,
                   rmath::base<4, float, tag>) {
    std::vector<float> data {0.0f, 1.33f, -2.5f, 30.0f, -199.005f};

    for (auto& d : data) {
        CAPTURE(d);

        auto pt = T(d);
        for (size_t i = 0; i < T::size(); ++i) {
            CHECK(pt.data[i] == doctest::Approx(d));
        }
    }
}

TEST_CASE("unsigned base of 2 can be constructed from coordinates") {
    auto pt = rmath::base<2, uint32_t, tag>(1, 2);

    CHECK(pt.x == 1);
    CHECK(pt.y == 2);
}
TEST_CASE("unsigned base of 3 can be constructed from coordinates") {
    auto pt = rmath::base<3, uint32_t, tag>(1, 2, 87);

    CHECK(pt.x == 1);
    CHECK(pt.y == 2);
    CHECK(pt.z == 87);
}
TEST_CASE("unsigned base of 4 can be constructed from coordinates") {
    auto pt = rmath::base<4, uint32_t, tag>(1, 2, 3, 99);

    CHECK(pt.x == 1);
    CHECK(pt.y == 2);
    CHECK(pt.z == 3);
    CHECK(pt.w == 99);
}

TEST_CASE("signed base of 2 can be constructed from coordinates") {
    auto pt = rmath::base<2, int32_t, tag>(-1, 2);

    CHECK(pt.x == -1);
    CHECK(pt.y == 2);
}
TEST_CASE("signed base of 3 can be constructed from coordinates") {
    auto pt = rmath::base<3, int32_t, tag>(1, -2, 87);

    CHECK(pt.x == 1);
    CHECK(pt.y == -2);
    CHECK(pt.z == 87);
}
TEST_CASE("signed base of 4 can be constructed from coordinates") {
    auto pt = rmath::base<4, int32_t, tag>(1, -2, 3, -99);

    CHECK(pt.x == 1);
    CHECK(pt.y == -2);
    CHECK(pt.z == 3);
    CHECK(pt.w == -99);
}

TEST_CASE("float base of 2 can be constructed from coordinates") {
    auto pt = rmath::base<2, float, tag>(-1.7f, 2.2f);

    CHECK(pt.x == doctest::Approx(-1.7f));
    CHECK(pt.y == doctest::Approx(2.2f));
}
TEST_CASE("float base of 3 can be constructed from coordinates") {
    auto pt = rmath::base<3, float, tag>(1.7f, -2.2f, 87.005f);

    CHECK(pt.x == doctest::Approx(1.7f));
    CHECK(pt.y == doctest::Approx(-2.2f));
    CHECK(pt.z == doctest::Approx(87.005f));
}
TEST_CASE("float base of 4 can be constructed from coordinates") {
    auto pt = rmath::base<4, float, tag>(1.3f, -2.1f, 3.1f, -99.00099f);

    CHECK(pt.x == doctest::Approx(1.3f));
    CHECK(pt.y == doctest::Approx(-2.1f));
    CHECK(pt.z == doctest::Approx(3.1f));
    CHECK(pt.w == doctest::Approx(-99.00099f));
}
