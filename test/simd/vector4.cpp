#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <rmath/simd/vector.hpp>

using namespace rmath::simd;

TEST_CASE("vector4 is created correctly") {
    vector4 v {0.1f};

    CHECK(x(v) == doctest::Approx(0.1f));
    CHECK(y(v) == doctest::Approx(0.1f));
    CHECK(z(v) == doctest::Approx(0.1f));
    CHECK(w(v) == doctest::Approx(0.1f));
}