#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <rmath/generic/vector.hpp>

using namespace rmath::generic;

TEST_CASE("uvec2 length is correctly calculated") {
    uvec2 v {10, 20};

    CHECK(length(v) == 22);
}

TEST_CASE("ivec2 length is correctly calculated") {
    ivec2 v {10, -20};

    CHECK(length(v) == 22);
}

TEST_CASE("vec2 length is correctly calculated") {
    vec2 v {10.10f, -20.45f};

    CHECK(length(v) == doctest::Approx(22.808167f));
}

TEST_CASE("uvec3 length is correctly calculated") {
    uvec3 v {10, 20, 30};

    CHECK(length(v) == 37);
}

TEST_CASE("ivec3 length is correctly calculated") {
    ivec3 v {10, -20, 30};

    CHECK(length(v) == 37);
}

TEST_CASE("vec3 length is correctly calculated") {
    vec3 v {10.10f, -20.45f, 33.33f};

    CHECK(length(v) == doctest::Approx(40.386896f));
}

TEST_CASE("uvec4 length is correctly calculated") {
    uvec4 v {10, 20, 30, 53};

    CHECK(length(v) == 65);
}

TEST_CASE("ivec4 length is correctly calculated") {
    ivec4 v {10, -20, 30, -53};

    CHECK(length(v) == 65);
}

TEST_CASE("vec4 length is correctly calculated") {
    vec4 v {10.10f, -20.45f, 33.33f, 55.41f};

    CHECK(length(v) == doctest::Approx(68.566533f));
}
