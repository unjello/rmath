#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <rmath/vector.hpp>

TEST_CASE("two uvec2's are added correctly") {
    rmath::uvec2 a{10, 20}, b{30, 10};

    auto c = a + b;

    CHECK(a.x == 10);
    CHECK(a.y == 20);
    CHECK(b.x == 30);
    CHECK(b.y == 10);
    CHECK(c.x == 40);
    CHECK(c.y == 30);
}
