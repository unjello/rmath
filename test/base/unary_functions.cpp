#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <rmath/generic/vector.hpp>

using namespace rmath::generic;

TEST_CASE("unary plus is computer correctly") {
    ivec2 v1 {1, -2};
    vec3  v2 {1.1, -3.5, -4.99};
    uvec4 v3 {1, 2, 3, 4};

    auto r1 = +v1;
    auto r2 = +v2;
    auto r3 = +v3;

    CHECK(x(r1) == 1);
    CHECK(y(r1) == -2);

    CHECK(x(r2) == doctest::Approx(1.1));
    CHECK(y(r2) == doctest::Approx(-3.5));
    CHECK(z(r2) == doctest::Approx(-4.99));

    CHECK(x(r3) == 1);
    CHECK(y(r3) == 2);
    CHECK(z(r3) == 3);
    CHECK(w(r3) == 4);
}

TEST_CASE("negation is computer correctly") {
    ivec2 v1 {1, -2};
    vec3  v2 {1.1, -3.5, -4.99};

    auto r1 = -v1;
    auto r2 = -v2;

    CHECK(x(r1) == -1);
    CHECK(y(r1) == 2);

    CHECK(x(r2) == doctest::Approx(-1.1));
    CHECK(y(r2) == doctest::Approx(3.5));
    CHECK(z(r2) == doctest::Approx(4.99));
}

TEST_CASE("abs is computer correctly") {
    ivec2 v1 {1, -2};
    vec3  v2 {1.1, -3.5, -4.99};

    auto r1 = abs(v1);
    auto r2 = abs(v2);

    CHECK(x(r1) == 1);
    CHECK(y(r1) == 2);

    CHECK(x(r2) == doctest::Approx(1.1));
    CHECK(y(r2) == doctest::Approx(3.5));
    CHECK(z(r2) == doctest::Approx(4.99));
}

TEST_CASE("floor is computer correctly") {
    ivec2 v1 {1, -2};
    vec3  v2 {1.1, -3.5, -4.99};

    auto r1 = floor(v1);
    auto r2 = floor(v2);

    CHECK(x(r1) == 1);
    CHECK(y(r1) == -2);

    CHECK(x(r2) == doctest::Approx(1.0));
    CHECK(y(r2) == doctest::Approx(-4.0));
    CHECK(z(r2) == doctest::Approx(-5.0));
}

TEST_CASE("fract is computer correctly") {
    ivec2 v1 {1, -2};
    vec3  v2 {1.1, -3.5, -4.99};

    auto r1 = floor(v1);
    auto r2 = floor(v2);

    CHECK(x(r1) == 0);
    CHECK(y(r1) == 0);

    CHECK(x(r2) == doctest::Approx(0.1));
    CHECK(y(r2) == doctest::Approx(-0.5));
    CHECK(z(r2) == doctest::Approx(-0.99));
}