#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <rmath/vector.hpp>

TEST_CASE("arithmetic operations on two uvec2's are performed correctly") {
    rmath::uvec2 a {10, 20}, b {30, 10};

    auto c = a + b;
    auto d = a - b;

    CHECK(a.x == 10);
    CHECK(a.y == 20);
    CHECK(b.x == 30);
    CHECK(b.y == 10);

    CHECK(c.x == 40);
    CHECK(c.y == 30);

    CHECK(d.x == 4294967276); /* 2's complement -20 */
    CHECK(d.y == 10);
}

TEST_CASE("two ivec3's are added correctly") {
    rmath::ivec3 a {10, 20, -30}, b {30, 10, 40};

    auto c = a + b;

    CHECK(a.x == 10);
    CHECK(a.y == 20);
    CHECK(a.z == -30);
    CHECK(b.x == 30);
    CHECK(b.y == 10);
    CHECK(b.z == 40);
    CHECK(c.x == 40);
    CHECK(c.y == 30);
    CHECK(c.z == 10);
}

TEST_CASE("two vec4's are added correctly") {
    rmath::vec4 a {10, 20, -10.5, -20}, b {30, 10, -10.5, 10.88};

    auto c = a + b;

    CHECK(a.x == doctest::Approx(10));
    CHECK(a.y == doctest::Approx(20));
    CHECK(a.z == doctest::Approx(-10.5));
    CHECK(a.w == doctest::Approx(-20));
    CHECK(b.x == doctest::Approx(30));
    CHECK(b.y == doctest::Approx(10));
    CHECK(b.z == doctest::Approx(-10.5));
    CHECK(b.w == doctest::Approx(10.88));
    CHECK(c.x == doctest::Approx(40));
    CHECK(c.y == doctest::Approx(30));
    CHECK(c.z == doctest::Approx(-21));
    CHECK(c.w == doctest::Approx(-9.12));
}
