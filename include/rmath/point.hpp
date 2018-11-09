#pragma once

#include <rmath/base.hpp>

namespace rmath {
namespace detail {
struct point_tag {};
}

template <size_t L, typename T>
using point = base<L, T, detail::point_tag>;

using upt2 = point<2, uint32_t>;
using upt3 = point<3, uint32_t>;
using upt4 = point<4, uint32_t>;
using ipt2 = point<2, int32_t>;
using ipt3 = point<3, int32_t>;
using ipt4 = point<4, int32_t>;
using pt2  = point<2, float>;
using pt3  = point<3, float>;
using pt4  = point<4, float>;
}