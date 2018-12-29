#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <rmath/generic/point.hpp>

using namespace rmath::generic;

struct tag {};

TEST_CASE_TEMPLATE("unsigned base can be constructed from scalar",
                   T,
                   base<2, uint32_t, tag>,
                   base<3, uint32_t, tag>,
                   base<4, uint32_t, tag>) {
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
                   base<2, int32_t, tag>,
                   base<3, int32_t, tag>,
                   base<4, int32_t, tag>) {
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
                   base<2, float, tag>,
                   base<3, float, tag>,
                   base<4, float, tag>) {
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
    auto pt = base<2, uint32_t, tag>(1, 2);

    CHECK(x(pt) == 1);
    CHECK(y(pt) == 2);
}
TEST_CASE("unsigned base of 3 can be constructed from coordinates") {
    auto pt = base<3, uint32_t, tag>(1, 2, 87);

    CHECK(x(pt) == 1);
    CHECK(y(pt) == 2);
    CHECK(z(pt) == 87);
}
TEST_CASE("unsigned base of 4 can be constructed from coordinates") {
    auto pt = base<4, uint32_t, tag>(1, 2, 3, 99);

    CHECK(x(pt) == 1);
    CHECK(y(pt) == 2);
    CHECK(z(pt) == 3);
    CHECK(w(pt) == 99);
}

TEST_CASE("signed base of 2 can be constructed from coordinates") {
    auto pt = base<2, int32_t, tag>(-1, 2);

    CHECK(x(pt) == -1);
    CHECK(y(pt) == 2);
}
TEST_CASE("signed base of 3 can be constructed from coordinates") {
    auto pt = base<3, int32_t, tag>(1, -2, 87);

    CHECK(x(pt) == 1);
    CHECK(y(pt) == -2);
    CHECK(z(pt) == 87);
}
TEST_CASE("signed base of 4 can be constructed from coordinates") {
    auto pt = base<4, int32_t, tag>(1, -2, 3, -99);

    CHECK(x(pt) == 1);
    CHECK(y(pt) == -2);
    CHECK(z(pt) == 3);
    CHECK(w(pt) == -99);
}

TEST_CASE("float base of 2 can be constructed from coordinates") {
    auto pt = base<2, float, tag>(-1.7f, 2.2f);

    CHECK(x(pt) == doctest::Approx(-1.7f));
    CHECK(y(pt) == doctest::Approx(2.2f));
}
TEST_CASE("float base of 3 can be constructed from coordinates") {
    auto pt = base<3, float, tag>(1.7f, -2.2f, 87.005f);

    CHECK(x(pt) == doctest::Approx(1.7f));
    CHECK(y(pt) == doctest::Approx(-2.2f));
    CHECK(z(pt) == doctest::Approx(87.005f));
}
TEST_CASE("float base of 4 can be constructed from coordinates") {
    auto pt = base<4, float, tag>(1.3f, -2.1f, 3.1f, -99.00099f);

    CHECK(x(pt) == doctest::Approx(1.3f));
    CHECK(y(pt) == doctest::Approx(-2.1f));
    CHECK(z(pt) == doctest::Approx(3.1f));
    CHECK(w(pt) == doctest::Approx(-99.00099f));
}
