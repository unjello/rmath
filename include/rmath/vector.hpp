#pragma once

#include <rmath/base.hpp>
#include <rmath/helper.hpp>
#include <rmath/point.hpp>

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

template <size_t L, typename T>
constexpr T length_sq(vector<L, T> const& v) {
    T aggregate = 0;
    for (auto i = 0; i < vector<L, T>::component_size; ++i) {
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
template <typename T>
constexpr vector2<T> operator+(vector2<T> const& a, vector2<T> const& b) noexcept {
    return vector2<T> {x(a) + x(b), y(a) + y(b)};
}


template <typename T>
constexpr vector2<T> operator-(vector2<T> const& a, vector2<T> const& b) noexcept {
    return vector2<T> {x(a) - x(b), y(a) - y(b)};
}

template <typename T>
constexpr vector3<T> operator-(vector3<T> const& a, vector3<T> const& b) noexcept {
    return vector3<T> {x(a) - x(b), y(a) - y(b), z(a) - z(b)};
}

template <typename T>
constexpr vector4<T> operator-(vector4<T> const& a, vector4<T> const& b) noexcept {
    return vector4<T> {x(a) - x(b), y(a) - y(b), z(a) - z(b), w(a) - w(b)};
}

template <typename T>
constexpr point2<T> operator+(point2<T> const& a, vector2<T> const& b) noexcept {
    return point2<T> {x(a) + x(b), y(a) + y(b)};
}
template <typename T>
constexpr point2<T> operator+(vector2<T> const& a, point2<T> const& b) noexcept {
    return operator+(b, a);
}

template <typename T>
constexpr point3<T> operator+(point3<T> const& a, vector3<T> const& b) noexcept {
    return point3<T> {x(a) + x(b), y(a) + y(b), z(a) + z(b)};
}
template <typename T>
constexpr point3<T> operator+(vector3<T> const& a, point3<T> const& b) noexcept {
    return operator+(b, a);
}

template <typename T>
constexpr point4<T> operator+(point4<T> const& a, vector4<T> const& b) noexcept {
    return point4<T> {x(a) + x(b), y(a) + y(b), z(a) + z(b), w(a) + w(b)};
}
template <typename T>
constexpr point4<T> operator+(vector4<T> const& a, point4<T> const& b) noexcept {
    return operator+(b, a);
}

template <typename T>
constexpr vector2<T> operator-(point2<T> const& a, point2<T> const& b) noexcept {
    return vector2<T> {x(a) - x(b), y(a) - y(b)};
}

template <typename T>
constexpr vector3<T> operator-(point3<T> const& a, point3<T> const& b) noexcept {
    return vector3<T> {x(a) - x(b), y(a) - y(b), z(a) - z(b)};
}

template <typename T>
constexpr vector4<T> operator-(point4<T> const& a, point4<T> const& b) noexcept {
    return vector4<T> {x(a) - x(b), y(a) - y(b), z(a) - z(b), w(a) - w(b)};
}
/** @} */

template <class T>
const T distance(vector2<T> const& a, vector2<T> const& b) noexcept {
    return round<T>(std::sqrt((x(a) - x(b)) * (x(a) - x(b)) + (y(a) - y(b)) * (y(a) - y(b))));
}
template <class T>
const T distance(vector3<T> const& a, vector3<T> const& b) noexcept {
    return round<T>(std::sqrt((x(a) - x(b)) * (x(a) - x(b)) + (y(a) - y(b)) * (y(a) - y(b))
                              + (z(a) - z(b)) * (z(a) - z(b))));
}
template <class T>
const T distance(vector4<T> const& a, vector4<T> const& b) noexcept {
    return round<T>(std::sqrt((x(a) - x(b)) * (x(a) - x(b)) + (y(a) - y(b)) * (y(a) - y(b))
                              + (z(a) - z(b)) * (z(a) - z(b)) + (w(a) - w(b)) * (w(a) - w(b))));
}
template <class T>
constexpr T distance_sq(vector2<T> const& a, vector2<T> const& b) noexcept {
    return (x(a) - x(b)) * (x(a) - x(b)) + (y(a) - y(b)) * (y(a) - y(b));
}
template <class T>
constexpr T distance_sq(vector3<T> const& a, vector3<T> const& b) noexcept {
    return (x(a) - x(b)) * (x(a) - x(b)) + (y(a) - y(b)) * (y(a) - y(b))
        + (z(a) - z(b)) * (z(a) - z(b));
}
template <class T>
constexpr T distance_sq(vector4<T> const& a, vector4<T> const& b) noexcept {
    return (x(a) - x(b)) * (x(a) - x(b)) + (y(a) - y(b)) * (y(a) - y(b))
        + (z(a) - z(b)) * (z(a) - z(b)) + (w(a) - w(b)) * (w(a) - w(b));
}
}