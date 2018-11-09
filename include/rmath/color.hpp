#pragma once

#include <rmath/base.hpp>

namespace rmath {
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