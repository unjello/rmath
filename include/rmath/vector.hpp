#pragma once

#include <rmath/base.hpp>

namespace rmath {
namespace detail {
struct vector_tag {};
}

template <size_t L, typename T>
using vector = base<L, T, detail::vector_tag>;
template <typename T>
using vector2 = vector<2, T>;
template <typename T>
using vector3 = vector<3, T>;
template <typename T>
using vector4 = vector<4, T>;

using uvec2 = vector2<uint32_t>;
using uvec3 = vector3<uint32_t>;
using uvec4 = vector4<uint32_t>;
using ivec2 = vector2<int32_t>;
using ivec3 = vector3<int32_t>;
using ivec4 = vector4<int32_t>;
using vec2  = vector2<float>;
using vec3  = vector3<float>;
using vec4  = vector4<float>;
}