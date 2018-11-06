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