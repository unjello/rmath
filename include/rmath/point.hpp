#pragma once

#include <rmath/base.hpp>

namespace rmath {
namespace detail {
struct point_tag {};
}

template <size_t L, typename T>
using point = base<L, T, detail::point_tag>;
template <typename T>
using point2 = point<2, T>;
template <typename T>
using point3 = point<3, T>;
template <typename T>
using point4 = point<4, T>;

using upt2 = point2<uint32_t>;
using upt3 = point3<uint32_t>;
using upt4 = point4<uint32_t>;
using ipt2 = point2<int32_t>;
using ipt3 = point3<int32_t>;
using ipt4 = point4<int32_t>;
using pt2  = point2<float>;
using pt3  = point3<float>;
using pt4  = point4<float>;
}