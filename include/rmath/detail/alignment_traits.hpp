#pragma once
#include <cstddef>

namespace rmath::detail {
template <size_t L, size_t V>
struct alignment_constant {
    static constexpr size_t          value = V;
    typedef size_t                   value_type;
    typedef alignment_constant<L, V> type;
    constexpr                        operator value_type() { return value; }
};

template <size_t L>
struct align_to : public alignment_constant<L, 8> {};
template <>
struct align_to<2> : public alignment_constant<2, 2> {};
template <>
struct align_to<3> : public alignment_constant<3, 4> {};
template <>
struct align_to<4> : public alignment_constant<4, 4> {};
}