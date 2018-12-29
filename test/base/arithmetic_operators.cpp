#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <rmath/generic/vector.hpp>

using namespace rmath::generic;

TEST_CASE("arithmetic operations on base2 of unsigneds and scalars are performed correctly") {
    uvec2 a {10, 20}, b {30, 10};

    auto e = a - 10;
    auto f = 10 - b;
    auto g = a * 10;
    auto h = 20 * b;
    auto i = a + 10;
    auto j = 20 + b;

    CHECK(x(a) == 10);
    CHECK(y(a) == 20);
    CHECK(x(b) == 30);
    CHECK(y(b) == 10);

    CHECK(x(e) == 0);
    CHECK(y(e) == 10);

    CHECK(x(f) == 4294967276);
    CHECK(y(f) == 0);

    CHECK(x(g) == 100);
    CHECK(y(g) == 200);

    CHECK(x(h) == 600);
    CHECK(y(h) == 200);

    CHECK(x(i) == 20);
    CHECK(y(i) == 30);
    CHECK(x(j) == 50);
    CHECK(y(j) == 30);
}

TEST_CASE("arithmetic operations on base3 of signed and scalars are performed correctly") {
    ivec3 a {10, 20, -30}, b {30, 10, 40};

    auto e = a - 10;
    auto f = 10 - b;
    auto g = a * 10;
    auto h = -20 * b;
    auto i = a + 10;
    auto j = -20 + b;

    CHECK(x(a) == 10);
    CHECK(y(a) == 20);
    CHECK(z(a) == -30);
    CHECK(x(b) == 30);
    CHECK(y(b) == 10);
    CHECK(z(b) == 40);

    CHECK(x(e) == 0);
    CHECK(y(e) == 10);
    CHECK(z(e) == -40);

    CHECK(x(f) == -20);
    CHECK(y(f) == 0);
    CHECK(z(f) == -30);

    CHECK(x(g) == 100);
    CHECK(y(g) == 200);
    CHECK(z(g) == -300);

    CHECK(x(h) == -600);
    CHECK(y(h) == -200);
    CHECK(z(h) == -800);

    CHECK(x(i) == 20);
    CHECK(y(i) == 30);
    CHECK(z(i) == -20);

    CHECK(x(j) == 10);
    CHECK(y(j) == -10);
    CHECK(z(j) == 20);
}

TEST_CASE("arithmetic operations on base4 of floats and scalars are performed correctly") {
    vec4 a {10, 20, -10.5, -20}, b {30, 10, -10.5, 10.88};

    auto e = a - 10;
    auto f = 10 - b;
    auto g = a * 10;
    auto h = 20.5f * b;
    auto i = a + 10;
    auto j = -20.5f + b;

    CHECK(x(a) == doctest::Approx(10));
    CHECK(y(a) == doctest::Approx(20));
    CHECK(z(a) == doctest::Approx(-10.5));
    CHECK(w(a) == doctest::Approx(-20));
    CHECK(x(b) == doctest::Approx(30));
    CHECK(y(b) == doctest::Approx(10));
    CHECK(z(b) == doctest::Approx(-10.5));
    CHECK(w(b) == doctest::Approx(10.88));

    CHECK(x(e) == doctest::Approx(0));
    CHECK(y(e) == doctest::Approx(10));
    CHECK(z(e) == doctest::Approx(-20.5));
    CHECK(w(e) == doctest::Approx(-30));

    CHECK(x(f) == doctest::Approx(-20));
    CHECK(y(f) == doctest::Approx(0));
    CHECK(z(f) == doctest::Approx(20.5));
    CHECK(w(f) == doctest::Approx(-0.88));

    CHECK(x(g) == doctest::Approx(100));
    CHECK(y(g) == doctest::Approx(200));
    CHECK(z(g) == doctest::Approx(-105));
    CHECK(w(g) == doctest::Approx(-200));

    CHECK(x(h) == doctest::Approx(615));
    CHECK(y(h) == doctest::Approx(205));
    CHECK(z(h) == doctest::Approx(-215.25));
    CHECK(w(h) == doctest::Approx(223.04));

    CHECK(x(i) == doctest::Approx(20));
    CHECK(y(i) == doctest::Approx(30));
    CHECK(z(i) == doctest::Approx(-0.5));
    CHECK(w(i) == doctest::Approx(-10));

    CHECK(x(j) == doctest::Approx(9.5));
    CHECK(y(j) == doctest::Approx(-10.5));
    CHECK(z(j) == doctest::Approx(-31));
    CHECK(w(j) == doctest::Approx(-9.62));
}
