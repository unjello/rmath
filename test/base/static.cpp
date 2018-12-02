#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <rmath/base.hpp>

struct tag {};

/**
 * could have just check if std::is_pod, but it got deprecated
 * in C++20 for aparently people are more interested in particular
 * traits that make a pod rather than pod itself
 */
TEST_CASE_TEMPLATE("base is a trivial type",
                   T,
                   rmath::base<2, uint32_t, tag>,
                   rmath::base<3, uint32_t, tag>,
                   rmath::base<4, uint32_t, tag>) {

    CHECK(std::is_trivial<T>::value == true);
}

TEST_CASE_TEMPLATE("base is a standard layout",
                   T,
                   rmath::base<2, uint32_t, tag>,
                   rmath::base<3, uint32_t, tag>,
                   rmath::base<4, uint32_t, tag>) {

    CHECK(std::is_standard_layout<T>::value == true);
}
