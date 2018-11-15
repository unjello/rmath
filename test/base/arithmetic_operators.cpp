#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <rmath/vector.hpp>

TEST_CASE("arithmetic operations on base2 of unsigneds and scalars are performed correctly") {
    rmath::uvec2 a {10, 20}, b {30, 10};

    auto e = a - 10;
    auto f = 10 - b;
    auto g = a * 10;
    auto h = 20 * b;
    auto i = a + 10;
    auto j = 20 + b;

    CHECK(a.x == 10);
    CHECK(a.y == 20);
    CHECK(b.x == 30);
    CHECK(b.y == 10);

    CHECK(e.x == 0);
    CHECK(e.y == 10);

    CHECK(f.x == 4294967276);
    CHECK(f.y == 0);

    CHECK(g.x == 100);
    CHECK(g.y == 200);

    CHECK(h.x == 600);
    CHECK(h.y == 200);

    CHECK(i.x == 20);
    CHECK(i.y == 30);
    CHECK(j.x == 50);
    CHECK(j.y == 30);
}

TEST_CASE("arithmetic operations on base3 of signed and scalars are performed correctly") {
    rmath::ivec3 a {10, 20, -30}, b {30, 10, 40};

    auto e = a - 10;
    auto f = 10 - b;
    auto g = a * 10;
    auto h = -20 * b;
    auto i = a + 10;
    auto j = -20 + b;

    CHECK(a.x == 10);
    CHECK(a.y == 20);
    CHECK(a.z == -30);
    CHECK(b.x == 30);
    CHECK(b.y == 10);
    CHECK(b.z == 40);

    CHECK(e.x == 0);
    CHECK(e.y == 10);
    CHECK(e.z == -40);

    CHECK(f.x == -20);
    CHECK(f.y == 0);
    CHECK(f.z == -30);

    CHECK(g.x == 100);
    CHECK(g.y == 200);
    CHECK(g.z == -300);

    CHECK(h.x == -600);
    CHECK(h.y == -200);
    CHECK(h.z == -800);

    CHECK(i.x == 20);
    CHECK(i.y == 30);
    CHECK(i.z == -20);

    CHECK(j.x == 10);
    CHECK(j.y == -10);
    CHECK(j.z == 20);
}

TEST_CASE("arithmetic operations on base4 of floats and scalars are performed correctly") {
    rmath::vec4 a {10, 20, -10.5, -20}, b {30, 10, -10.5, 10.88};

    auto e = a - 10;
    auto f = 10 - b;
    auto g = a * 10;
    auto h = 20.5f * b;
    auto i = a + 10;
    auto j = -20.5f + b;

    CHECK(a.x == doctest::Approx(10));
    CHECK(a.y == doctest::Approx(20));
    CHECK(a.z == doctest::Approx(-10.5));
    CHECK(a.w == doctest::Approx(-20));
    CHECK(b.x == doctest::Approx(30));
    CHECK(b.y == doctest::Approx(10));
    CHECK(b.z == doctest::Approx(-10.5));
    CHECK(b.w == doctest::Approx(10.88));

    CHECK(e.x == doctest::Approx(0));
    CHECK(e.y == doctest::Approx(10));
    CHECK(e.z == doctest::Approx(-20.5));
    CHECK(e.w == doctest::Approx(-30));

    CHECK(f.x == doctest::Approx(-20));
    CHECK(f.y == doctest::Approx(0));
    CHECK(f.z == doctest::Approx(20.5));
    CHECK(f.w == doctest::Approx(-0.88));

    CHECK(g.x == doctest::Approx(100));
    CHECK(g.y == doctest::Approx(200));
    CHECK(g.z == doctest::Approx(-105));
    CHECK(g.w == doctest::Approx(-200));

    CHECK(h.x == doctest::Approx(615));
    CHECK(h.y == doctest::Approx(205));
    CHECK(h.z == doctest::Approx(-215.25));
    CHECK(h.w == doctest::Approx(223.04));

    CHECK(i.x == doctest::Approx(20));
    CHECK(i.y == doctest::Approx(30));
    CHECK(i.z == doctest::Approx(-0.5));
    CHECK(i.w == doctest::Approx(-10));

    CHECK(j.x == doctest::Approx(9.5));
    CHECK(j.y == doctest::Approx(-10.5));
    CHECK(j.z == doctest::Approx(-31));
    CHECK(j.w == doctest::Approx(-9.62));
}
