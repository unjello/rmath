#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <rmath/vector.hpp>

TEST_CASE("uvec2 length is correctly calculated") {
    rmath::uvec2 v {10, 20};

    CHECK(rmath::length(v) == 22);
}

TEST_CASE("ivec2 length is correctly calculated") {
    rmath::ivec2 v {10, -20};

    CHECK(rmath::length(v) == 22);
}

TEST_CASE("vec2 length is correctly calculated") {
    rmath::vec2 v {10.10f, -20.45f};

    CHECK(rmath::length(v) == doctest::Approx(22.808167f));
}

TEST_CASE("uvec3 length is correctly calculated") {
    rmath::uvec3 v {10, 20, 30};

    CHECK(rmath::length(v) == 37);
}

TEST_CASE("ivec3 length is correctly calculated") {
    rmath::ivec3 v {10, -20, 30};

    CHECK(rmath::length(v) == 37);
}

TEST_CASE("vec3 length is correctly calculated") {
    rmath::vec3 v {10.10f, -20.45f, 33.33f};

    CHECK(rmath::length(v) == doctest::Approx(40.386896f));
}

TEST_CASE("uvec4 length is correctly calculated") {
    rmath::uvec4 v {10, 20, 30, 53};

    CHECK(rmath::length(v) == 65);
}

TEST_CASE("ivec4 length is correctly calculated") {
    rmath::ivec4 v {10, -20, 30, -53};

    CHECK(rmath::length(v) == 65);
}

TEST_CASE("vec4 length is correctly calculated") {
    rmath::vec4 v {10.10f, -20.45f, 33.33f, 55.41f};

    CHECK(rmath::length(v) == doctest::Approx(68.566533f));
}
