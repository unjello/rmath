#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <rmath/vector.hpp>

TEST_CASE("uvec2 distance is correctly calculated") {
    rmath::uvec2 v1 {10, 20}, v2 {30, 5};

    CHECK(rmath::distance(v1, v2) == 25);
}

TEST_CASE("uvec2 distance_sq is correctly calculated") {
    rmath::uvec2 v1 {10, 20}, v2 {30, 5};

    CHECK(rmath::distance_sq(v1, v2) == 625);
}

TEST_CASE("ivec3 distance is correctly calculated") {
    rmath::ivec3 v1 {10, 20, -5}, v2 {30, -5, 10};

    CHECK(rmath::distance(v1, v2) == 35);
}

TEST_CASE("ivec3 distance_sq is correctly calculated") {
    rmath::ivec3 v1 {10, 20, -5}, v2 {30, -5, 10};

    CHECK(rmath::distance_sq(v1, v2) == 1250);
}

TEST_CASE("vec4 distance is correctly calculated") {
    rmath::vec4 v1 {10.0f, 20.0f, -5.0f, 8.88f}, v2 {30.0f, -5.0f, 10.11f, 5.1f};

    CHECK(rmath::distance(v1, v2) == doctest::Approx(35.603378f));
}

TEST_CASE("vec4 distance_sq is correctly calculated") {
    rmath::vec4 v1 {10.0f, 20.0f, -5.0f, 8.88f}, v2 {30.0f, -5.0f, 10.11f, 5.1f};

    CHECK(rmath::distance_sq(v1, v2) == doctest::Approx(1267.6005f));
}