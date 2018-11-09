#pragma once

#include <rmath/base.hpp>

namespace rmath {
namespace detail {
struct vector_tag {};
}

template <size_t L, typename T>
using vector = base<L, T, detail::vector_tag>;

using uvec2 = vector<2, uint32_t>;
using uvec3 = vector<3, uint32_t>;
using uvec4 = vector<4, uint32_t>;
using ivec2 = vector<2, int32_t>;
using ivec3 = vector<3, int32_t>;
using ivec4 = vector<4, int32_t>;
using vec2  = vector<2, float>;
using vec3  = vector<3, float>;
using vec4  = vector<4, float>;
}