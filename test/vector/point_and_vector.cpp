#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <rmath/generic/vector.hpp>

using namespace rmath::generic;

TEST_CASE("vector + vector = vector") {
    uvec2 v1 {1}, v2 {2};

    auto v = v1 + v2;

    CHECK(std::is_same<decltype(v), uvec2>::value);
}

TEST_CASE("vector - vector = vector") {
    uvec2 v1 {1}, v2 {2};

    auto v = v1 - v2;

    CHECK(std::is_same<decltype(v), uvec2>::value);
}

TEST_CASE("point + vector = point") {
    upt2  pt {1};
    uvec2 v {2};

    auto p = pt + v;

    CHECK(std::is_same<decltype(p), upt2>::value);
}

TEST_CASE("point - point = vector") {
    upt2 p1 {1}, p2 {2};

    auto p = p1 - p2;

    CHECK(std::is_same<decltype(p), uvec2>::value);
}
