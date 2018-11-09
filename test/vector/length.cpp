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
