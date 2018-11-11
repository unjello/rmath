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

template <typename T>
const T length(vector2<T> const& v) {
    return std::round(std::sqrt((v.x * v.x) + (v.y * v.y)));
}
template <>
const float length(vector2<float> const& v) {
    return std::sqrt((v.x * v.x) + (v.y * v.y));
}
template <>
const double length(vector2<double> const& v) {
    return std::sqrt((v.x * v.x) + (v.y * v.y));
}

template <typename T>
const T length(vector3<T> const& v) {
    return std::round(std::sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z)));
}
template <>
const float length(vector3<float> const& v) {
    return std::sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}
template <>
const double length(vector3<double> const& v) {
    return std::sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}

template <typename T>
const T length(vector4<T> const& v) {
    return std::round(std::sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z) + (v.w * v.w)));
}
template <>
const float length(vector4<float> const& v) {
    return std::sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z) + (v.w * v.w));
}
template <>
const double length(vector4<double> const& v) {
    return std::sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z) + (v.w * v.w));
}

template <typename T>
vector2<T> operator+(vector2<T> const& a, vector2<T> const& b) {
    return vector2<T> {a.x + b.x, a.y + b.y};
}

template <typename T>
vector3<T> operator+(vector3<T> const& a, vector3<T> const& b) {
    return vector2<T> {a.x + b.x, a.y + b.y, a.z + b.z};
}

template <typename T>
vector4<T> operator+(vector4<T> const& a, vector4<T> const& b) {
    return vector2<T> {a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w};
}
}