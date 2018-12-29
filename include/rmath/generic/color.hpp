#pragma once

#include <rmath/generic/base.hpp>

namespace rmath::generic {
namespace detail {
struct color_tag {};
}

template <size_t L, typename T>
using color = base<L, T, detail::color_tag>;

using ucolor3 = color<3, uint32_t>;
using ucolor4 = color<4, uint32_t>;
using color3  = color<3, float>;
using color4  = color<4, float>;
}