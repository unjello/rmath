#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <rmath/base.hpp>

TEST_CASE("scalar mod is computer correctly") {
    rmath::ivec2 v1 {1, -3};
    rmath::vec3  v2 {1.1, -3.5, -4.99};
    rmath::uvec4 v3 {1, 2, 3, 4};

    auto r1 = mod(v1, 2);
    auto r2 = mod(v2, 2.0f);
    auto r3 = mod(v3, 2);

    CHECK(rmath::x(r1) == 1);
    CHECK(rmath::y(r1) == -1);

    CHECK(rmath::x(r2) == doctest::Approx(1.1));
    CHECK(rmath::y(r2) == doctest::Approx(-1.5));
    CHECK(rmath::z(r2) == doctest::Approx(-0.99));

    CHECK(rmath::x(r3) == 1);
    CHECK(rmath::y(r3) == 0);
    CHECK(rmath::z(r3) == 1);
    CHECK(rmath::w(r3) == 0);
}