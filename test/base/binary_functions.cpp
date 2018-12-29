#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <rmath/generic/vector.hpp>

using namespace rmath::generic;

TEST_CASE("scalar mod is computer correctly") {
    ivec2 v1 {1, -3};
    vec3  v2 {1.1, -3.5, -4.99};
    uvec4 v3 {1, 2, 3, 4};

    auto r1 = mod(v1, 2);
    auto r2 = mod(v2, 2.0f);
    auto r3 = mod(v3, 2u);

    CHECK(x(r1) == 1);
    CHECK(y(r1) == -1);

    CHECK(x(r2) == doctest::Approx(1.1));
    CHECK(y(r2) == doctest::Approx(-1.5));
    CHECK(z(r2) == doctest::Approx(-0.99));

    CHECK(x(r3) == 1);
    CHECK(y(r3) == 0);
    CHECK(z(r3) == 1);
    CHECK(w(r3) == 0);
}