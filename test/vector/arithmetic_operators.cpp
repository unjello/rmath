#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <rmath/generic/vector.hpp>

using namespace rmath::generic;

TEST_CASE("arithmetic operations on two uvec2's are performed correctly") {
    uvec2 a {10, 20}, b {30, 10};

    auto c = a + b;
    auto d = a - b;

    CHECK(x(a) == 10);
    CHECK(y(a) == 20);
    CHECK(x(b) == 30);
    CHECK(y(b) == 10);

    CHECK(x(c) == 40);
    CHECK(y(c) == 30);

    CHECK(x(d) == 4294967276); /* 2's complement -20 */
    CHECK(y(d) == 10);
}

TEST_CASE("arithmetic operations on two ivec3's are performed correctly") {
    ivec3 a {10, 20, -30}, b {30, 10, 40};

    auto c = a + b;
    auto d = a - b;

    CHECK(x(a) == 10);
    CHECK(y(a) == 20);
    CHECK(z(a) == -30);
    CHECK(x(b) == 30);
    CHECK(y(b) == 10);
    CHECK(z(b) == 40);

    CHECK(x(c) == 40);
    CHECK(y(c) == 30);
    CHECK(z(c) == 10);

    CHECK(x(d) == -20);
    CHECK(y(d) == 10);
    CHECK(z(d) == -70);
}

TEST_CASE("arithmetic operations on two vec4's are performed correctly") {
    vec4 a {10, 20, -10.5, -20}, b {30, 10, -10.5, 10.88};

    auto c = a + b;
    auto d = a - b;

    CHECK(x(a) == doctest::Approx(10));
    CHECK(y(a) == doctest::Approx(20));
    CHECK(z(a) == doctest::Approx(-10.5));
    CHECK(w(a) == doctest::Approx(-20));
    CHECK(x(b) == doctest::Approx(30));
    CHECK(y(b) == doctest::Approx(10));
    CHECK(z(b) == doctest::Approx(-10.5));
    CHECK(w(b) == doctest::Approx(10.88));

    CHECK(x(c) == doctest::Approx(40));
    CHECK(y(c) == doctest::Approx(30));
    CHECK(z(c) == doctest::Approx(-21));
    CHECK(w(c) == doctest::Approx(-9.12));

    CHECK(x(d) == doctest::Approx(-20));
    CHECK(y(d) == doctest::Approx(10));
    CHECK(z(d) == doctest::Approx(0));
    CHECK(w(d) == doctest::Approx(-30.88));
}
