#pragma once

#include <rmath/generic/base.hpp>
#include <rmath/generic/point.hpp>
#include <rmath/helper.hpp>

namespace rmath::generic {
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

template <size_t L, typename T>
constexpr T length_sq(vector<L, T> const& v) {
    T aggregate = 0;
    for (size_t i = 0; i < vector<L, T>::component_size; ++i) {
        aggregate += v.data[i] * v.data[i];
    }
    return aggregate;
}

template <size_t L, typename T>
constexpr T length(vector<L, T> const& v) {
    return round<T>(std::sqrt(length_sq(v)));
}

/**
 * @defgroup point-operators
 * @ingroup euclidean-operators
 * @brief adding and substracting points and vectors (directions)
 * @{
 */
namespace detail {
template <size_t L, typename T, size_t... i>
constexpr vector<L, T>
vec_plus_vec(vector<L, T> const& a, vector<L, T> const& b, std::integer_sequence<size_t, i...>) {
    return vector<L, T> {(a.data[i] + b.data[i])...};
}
template <size_t L, typename T, size_t... i>
constexpr vector<L, T>
vec_minus_vec(vector<L, T> const& a, vector<L, T> const& b, std::integer_sequence<size_t, i...>) {
    return vector<L, T> {(a.data[i] - b.data[i])...};
}
template <size_t L, typename T, size_t... i>
constexpr point<L, T>
pt_plus_vec(point<L, T> const& a, vector<L, T> const& b, std::integer_sequence<size_t, i...>) {
    return point<L, T> {(a.data[i] + b.data[i])...};
}
template <size_t L, typename T, size_t... i>
constexpr vector<L, T>
pt_minus_pt(point<L, T> const& a, point<L, T> const& b, std::integer_sequence<size_t, i...>) {
    return vector<L, T> {(a.data[i] - b.data[i])...};
}
}

template <size_t L, typename T, size_t... i>
constexpr vector<L, T> operator+(vector<L, T> const& a, vector<L, T> const& b) noexcept {
    return vec_plus_vec(a, b, std::make_integer_sequence<size_t, L>());
}

template <size_t L, typename T, size_t... i>
constexpr vector<L, T> operator-(vector<L, T> const& a, vector<L, T> const& b) noexcept {
    return vec_minus_vec(a, b, std::make_integer_sequence<size_t, L>());
}

template <size_t L, typename T, size_t... i>
constexpr point<L, T> operator+(point<L, T> const& a, vector<L, T> const& b) noexcept {
    return pt_plus_vec(a, b, std::make_integer_sequence<size_t, L>());
}

template <size_t L, typename T, size_t... i>
constexpr point<L, T> operator+(vector<L, T> const& a, point<L, T> const& b) noexcept {
    return pt_plus_vec(b, a, std::make_integer_sequence<size_t, L>());
}

template <size_t L, typename T, size_t... i>
constexpr vector<L, T> operator-(point<L, T> const& a, point<L, T> const& b) noexcept {
    return pt_minus_pt(b, a, std::make_integer_sequence<size_t, L>());
}

/** @} */

template <size_t L, class T>
constexpr T distance_sq(vector<L, T> const& a, vector<L, T> const& b) noexcept {
    T aggregate = 0;
    for (size_t i = 0; i < vector<L, T>::component_size; ++i) {
        aggregate += (a.data[i] - b.data[i]) * (a.data[i] - b.data[i]);
    }
    return aggregate;
}

template <size_t L, class T>
const T distance(vector<L, T> const& a, vector<L, T> const& b) noexcept {
    return round<T>(std::sqrt(distance_sq(a, b)));
}
}