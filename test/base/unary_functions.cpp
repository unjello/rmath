#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <rmath/vector.hpp>

TEST_CASE("unary plus is computer correctly") {
    rmath::ivec2 v1 {1, -2};
    rmath::vec3  v2 {1.1, -3.5, -4.99};
    rmath::uvec4 v3 {1, 2, 3, 4};

    auto r1 = +v1;
    auto r2 = +v2;
    auto r3 = +v3;

    CHECK(rmath::x(r1) == 1);
    CHECK(rmath::y(r1) == -2);

    CHECK(rmath::x(r2) == doctest::Approx(1.1));
    CHECK(rmath::y(r2) == doctest::Approx(-3.5));
    CHECK(rmath::z(r2) == doctest::Approx(-4.99));

    CHECK(rmath::x(r3) == 1);
    CHECK(rmath::y(r3) == 2);
    CHECK(rmath::z(r3) == 3);
    CHECK(rmath::w(r3) == 4);
}

TEST_CASE("negation is computer correctly") {
    rmath::ivec2 v1 {1, -2};
    rmath::vec3  v2 {1.1, -3.5, -4.99};

    auto r1 = -v1;
    auto r2 = -v2;

    CHECK(rmath::x(r1) == -1);
    CHECK(rmath::y(r1) == 2);

    CHECK(rmath::x(r2) == doctest::Approx(-1.1));
    CHECK(rmath::y(r2) == doctest::Approx(3.5));
    CHECK(rmath::z(r2) == doctest::Approx(4.99));
}

TEST_CASE("abs is computer correctly") {
    rmath::ivec2 v1 {1, -2};
    rmath::vec3  v2 {1.1, -3.5, -4.99};

    auto r1 = abs(v1);
    auto r2 = abs(v2);

    CHECK(rmath::x(r1) == 1);
    CHECK(rmath::y(r1) == 2);

    CHECK(rmath::x(r2) == doctest::Approx(1.1));
    CHECK(rmath::y(r2) == doctest::Approx(3.5));
    CHECK(rmath::z(r2) == doctest::Approx(4.99));
}

TEST_CASE("floor is computer correctly") {
    rmath::ivec2 v1 {1, -2};
    rmath::vec3  v2 {1.1, -3.5, -4.99};

    auto r1 = floor(v1);
    auto r2 = floor(v2);

    CHECK(rmath::x(r1) == 1);
    CHECK(rmath::y(r1) == -2);

    CHECK(rmath::x(r2) == doctest::Approx(1.0));
    CHECK(rmath::y(r2) == doctest::Approx(3.0));
    CHECK(rmath::z(r2) == doctest::Approx(4.0));
}