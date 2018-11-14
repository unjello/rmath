#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <rmath/vector.hpp>

TEST_CASE("vector + vector = vector") {
    rmath::uvec2 v1 {1}, v2 {2};

    auto v = v1 + v2;

    CHECK(std::is_same<decltype(v), rmath::uvec2>::value);
}

TEST_CASE("vector - vector = vector") {
    rmath::uvec2 v1 {1}, v2 {2};

    auto v = v1 - v2;

    CHECK(std::is_same<decltype(v), rmath::uvec2>::value);
}

TEST_CASE("point + vector = point") {
    rmath::upt2  pt {1};
    rmath::uvec2 v {2};

    auto p = pt + v;

    CHECK(std::is_same<decltype(p), rmath::upt2>::value);
}

TEST_CASE("point - point = vector") {
    rmath::upt2 p1 {1}, p2 {2};

    auto p = p1 - p2;

    CHECK(std::is_same<decltype(p), rmath::uvec2>::value);
}
