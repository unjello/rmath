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
    if constexpr (std::is_integral<T>::value) {
        return std::round(std::sqrt((v.x * v.x) + (v.y * v.y)));
    } else {
        return std::sqrt((v.x * v.x) + (v.y * v.y));
    }
}

template <typename T>
const T length(vector3<T> const& v) {
    if constexpr (std::is_integral<T>::value) {
        return std::round(std::sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z)));
    } else {
        return std::sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
    }
}

template <typename T>
const T length(vector4<T> const& v) {
    if constexpr (std::is_integral<T>::value) {
        return std::round(std::sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z) + (v.w * v.w)));
    } else {
        return std::sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z) + (v.w * v.w));
    }
}

/** @defgroup airthmetic-operators */

/**
 * @defgroup vector-plus-vector
 * @ingroup airthmetic-operators
 * @brief addition of two vectors
 * @{
 */
template <typename T>
constexpr vector2<T> operator+(vector2<T> const& a, vector2<T> const& b) noexcept {
    return vector2<T> {a.x + b.x, a.y + b.y};
}

template <typename T>
constexpr vector3<T> operator+(vector3<T> const& a, vector3<T> const& b) noexcept {
    return vector3<T> {a.x + b.x, a.y + b.y, a.z + b.z};
}

template <typename T>
constexpr vector4<T> operator+(vector4<T> const& a, vector4<T> const& b) noexcept {
    return vector4<T> {a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w};
}
/** @} */

/**
 * @defgroup vector-plus-scalar
 * @ingroup airthmetic-operators
 * @brief addition of vector and scalar
 * @{
 */
template <typename T, typename U>
constexpr vector2<T> operator+(vector2<T> const& a, U b) noexcept {
    return vector2<T> {a.x + b, a.y + b};
}

template <typename T, typename U>
constexpr vector3<T> operator+(vector3<T> const& a, U b) noexcept {
    return vector3<T> {a.x + b, a.y + b, a.z + b};
}

template <typename T, typename U>
constexpr vector4<T> operator+(vector4<T> const& a, U b) noexcept {
    return vector4<T> {a.x + b, a.y + b, a.z + b, a.w + b};
}

template <typename T, typename U>
constexpr vector2<T> operator+(U a, vector2<T> const& b) noexcept {
    return vector2<T> {a + b.x, a + b.y};
}

template <typename T, typename U>
constexpr vector3<T> operator+(U a, vector3<T> const& b) noexcept {
    return vector3<T> {a + b.x, a + b.y, a + b.z};
}

template <typename T, typename U>
constexpr vector4<T> operator+(U a, vector4<T> const& b) noexcept {
    return vector4<T> {a + b.x, a + b.y, a + b.z, a + b.w};
}
/** @} */

/**
 * @defgroup vector-minus-vector
 * @ingroup airthmetic-operators
 * @brief substraction of two vectors
 * @{
 */
template <typename T>
constexpr vector2<T> operator-(vector2<T> const& a, vector2<T> const& b) noexcept {
    return vector2<T> {a.x - b.x, a.y - b.y};
}

template <typename T>
constexpr vector3<T> operator-(vector3<T> const& a, vector3<T> const& b) noexcept {
    return vector3<T> {a.x - b.x, a.y - b.y, a.z - b.z};
}

template <typename T>
constexpr vector4<T> operator-(vector4<T> const& a, vector4<T> const& b) noexcept {
    return vector4<T> {a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w};
}
/** @} */

/**
 * @defgroup vector-minus-scalar
 * @ingroup airthmetic-operators
 * @brief substraction of vector and scalar
 * @{
 */
template <typename T, typename U>
constexpr vector2<T> operator-(vector2<T> const& a, U b) noexcept {
    return vector2<T> {a.x - b, a.y - b};
}

template <typename T, typename U>
constexpr vector3<T> operator-(vector3<T> const& a, U b) noexcept {
    return vector3<T> {a.x - b, a.y - b, a.z - b};
}

template <typename T, typename U>
constexpr vector4<T> operator-(vector4<T> const& a, U b) noexcept {
    return vector4<T> {a.x - b, a.y - b, a.z - b, a.w - b};
}

template <typename T, typename U>
constexpr vector2<T> operator-(U a, vector2<T> const& b) noexcept {
    return vector2<T> {a - b.x, a - b.y};
}

template <typename T, typename U>
constexpr vector3<T> operator-(U a, vector3<T> const& b) noexcept {
    return vector3<T> {a - b.x, a - b.y, a - b.z};
}

template <typename T, typename U>
constexpr vector4<T> operator-(U a, vector4<T> const& b) noexcept {
    return vector4<T> {a - b.x, a - b.y, a - b.z, a - b.w};
}
/** @} */

/**
 * @defgroup vector-mul-scalar
 * @ingroup airthmetic-operators
 * @brief multiplication of vector and scalar
 * @{
 */
template <typename T, typename U>
constexpr vector2<T> operator*(vector2<T> const& a, U b) noexcept {
    return vector2<T> {a.x * b, a.y * b};
}

template <typename T, typename U>
constexpr vector3<T> operator*(vector3<T> const& a, U b) noexcept {
    return vector3<T> {a.x * b, a.y * b, a.z * b};
}

template <typename T, typename U>
constexpr vector4<T> operator*(vector4<T> const& a, U b) noexcept {
    return vector4<T> {a.x * b, a.y * b, a.z * b, a.w * b};
}

template <typename T, typename U>
constexpr vector2<T> operator*(U a, vector2<T> const& b) noexcept {
    return vector2<T> {a * b.x, a * b.y};
}

template <typename T, typename U>
constexpr vector3<T> operator*(U a, vector3<T> const& b) noexcept {
    return vector3<T> {a * b.x, a * b.y, a * b.z};
}

template <typename T, typename U>
constexpr vector4<T> operator*(U a, vector4<T> const& b) noexcept {
    return vector4<T> {a * b.x, a * b.y, a * b.z, a * b.w};
}
/** @} */

/**
 * @defgroup vector-div-scalar
 * @ingroup airthmetic-operators
 * @brief division of vector and scalar. It's marked as noexcept since division
 *        by zero is not an exception in standard C++.
 * @{
 */
template <typename T, typename U>
constexpr vector2<T> operator/(vector2<T> const& a, U b) noexcept {
    return vector2<T> {a.x / b, a.y / b};
}

template <typename T, typename U>
constexpr vector3<T> operator/(vector3<T> const& a, U b) noexcept {
    return vector3<T> {a.x / b, a.y / b, a.z / b};
}

template <typename T, typename U>
constexpr vector4<T> operator/(vector4<T> const& a, U b) noexcept {
    return vector4<T> {a.x / b, a.y / b, a.z / b, a.w / b};
}

template <typename T, typename U>
constexpr vector2<T> operator/(U a, vector2<T> const& b) noexcept {
    return vector2<T> {a / b.x, a / b.y};
}

template <typename T, typename U>
constexpr vector3<T> operator/(U a, vector3<T> const& b) noexcept {
    return vector3<T> {a / b.x, a / b.y, a / b.z};
}

template <typename T, typename U>
constexpr vector4<T> operator/(U a, vector4<T> const& b) noexcept {
    return vector4<T> {a / b.x, a / b.y, a / b.z, a / b.w};
}
/** @} */
}