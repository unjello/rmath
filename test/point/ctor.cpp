#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <rmath/point.hpp>

TEST_CASE_TEMPLATE("unsigned point can be constructed from scalar",
                   T,
                   rmath::upt2,
                   rmath::upt3,
                   rmath::upt4) {
    std::vector<uint32_t> data {0, 1, 2, 30, 199};

    for (auto& d : data) {
        CAPTURE(d);

        auto pt = T(d);
        for (size_t i = 0; i < T::size(); ++i) {
            CHECK(pt.data[i] == d);
        }
    }
}

TEST_CASE_TEMPLATE("signed point can be constructed from scalar",
                   T,
                   rmath::ipt2,
                   rmath::ipt3,
                   rmath::ipt4) {
    std::vector<int32_t> data {0, 1, -2, 30, -199};

    for (auto& d : data) {
        CAPTURE(d);

        auto pt = T(d);
        for (size_t i = 0; i < T::size(); ++i) {
            CHECK(pt.data[i] == d);
        }
    }
}

TEST_CASE_TEMPLATE("float point can be constructed from scalar",
                   T,
                   rmath::pt2,
                   rmath::pt3,
                   rmath::pt4) {
    std::vector<float> data {0.0f, 1.33f, -2.5f, 30.0f, -199.005f};

    for (auto& d : data) {
        CAPTURE(d);

        auto pt = T(d);
        for (size_t i = 0; i < T::size(); ++i) {
            CHECK(pt.data[i] == doctest::Approx(d));
        }
    }
}

TEST_CASE("upoint2 can be constructed from coordinates") {
    auto pt = rmath::upt2(1, 2);

    CHECK(pt.x == 1);
    CHECK(pt.y == 2);
}
TEST_CASE("upoint3 can be constructed from coordinates") {
    auto pt = rmath::upt3(1, 2, 87);

    CHECK(pt.x == 1);
    CHECK(pt.y == 2);
    CHECK(pt.z == 87);
}
TEST_CASE("upoint4 can be constructed from coordinates") {
    auto pt = rmath::upt4(1, 2, 3, 99);

    CHECK(pt.x == 1);
    CHECK(pt.y == 2);
    CHECK(pt.z == 3);
    CHECK(pt.w == 99);
}

TEST_CASE("ipoint2 can be constructed from coordinates") {
    auto pt = rmath::ipt2(-1, 2);

    CHECK(pt.x == -1);
    CHECK(pt.y == 2);
}
TEST_CASE("ipoint3 can be constructed from coordinates") {
    auto pt = rmath::ipt3(1, -2, 87);

    CHECK(pt.x == 1);
    CHECK(pt.y == -2);
    CHECK(pt.z == 87);
}
TEST_CASE("ipoint4 can be constructed from coordinates") {
    auto pt = rmath::ipt4(1, -2, 3, -99);

    CHECK(pt.x == 1);
    CHECK(pt.y == -2);
    CHECK(pt.z == 3);
    CHECK(pt.w == -99);
}

TEST_CASE("point2 can be constructed from coordinates") {
    auto pt = rmath::pt2(-1.7f, 2.2f);

    CHECK(pt.x == doctest::Approx(-1.7f));
    CHECK(pt.y == doctest::Approx(2.2f));
}
TEST_CASE("point3 can be constructed from coordinates") {
    auto pt = rmath::pt3(1.7f, -2.2f, 87.005f);

    CHECK(pt.x == doctest::Approx(1.7f));
    CHECK(pt.y == doctest::Approx(-2.2f));
    CHECK(pt.z == doctest::Approx(87.005f));
}
TEST_CASE("point4 can be constructed from coordinates") {
    auto pt = rmath::pt4(1.3f, -2.1f, 3.1f, -99.00099f);

    CHECK(pt.x == doctest::Approx(1.3f));
    CHECK(pt.y == doctest::Approx(-2.1f));
    CHECK(pt.z == doctest::Approx(3.1f));
    CHECK(pt.w == doctest::Approx(-99.00099f));
}
