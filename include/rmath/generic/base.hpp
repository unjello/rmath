#pragma once
#include <cstddef>
#include <cstdint>
#include <utility>

namespace rmath::generic {

template <size_t L, typename T, typename Tag>
struct base {
    typedef T               value_type;
    typedef Tag             tag_type;
    typedef base<L, T, Tag> self_type;
    constexpr static size_t component_size = L;

    alignas(16) std::array<value_type, L> data;

    constexpr base()                 = default;
    constexpr base(self_type const&) = default;

    constexpr base(value_type s) {
        for (auto i = 0; i != component_size; ++i)
            data[i] = s;
    }
    template <typename... Tail>
    constexpr explicit base(value_type&& t0, Tail&&... tail) {
        construct<0>(std::forward<value_type>(t0), tail...);
    }

    [[nodiscard]] constexpr static size_t size() noexcept { return component_size; }

    template <size_t offset, class... Tail>
    constexpr void construct(value_type&& t0, Tail&&... tail) {
        data[offset] = t0;
        construct<offset + 1>(std::forward<value_type>(tail)...);
    }
    template <size_t>
    constexpr void construct() {}
};

template <size_t L, typename T, typename Tag>
constexpr T& x(base<L, T, Tag>& v) noexcept {
    return v.data[0];
}
template <size_t L, typename T, typename Tag>
constexpr T& y(base<L, T, Tag>& v) noexcept {
    return v.data[1];
}
template <size_t L, typename T, typename Tag>
constexpr T& z(base<L, T, Tag>& v) noexcept {
    return v.data[2];
}
template <size_t L, typename T, typename Tag>
constexpr T& w(base<L, T, Tag>& v) noexcept {
    return v.data[3];
}
template <size_t L, typename T, typename Tag>
[[nodiscard]] inline constexpr T x(base<L, T, Tag> const& v) noexcept {
    return v.data[0];
}
template <size_t L, typename T, typename Tag>
[[nodiscard]] inline constexpr T y(base<L, T, Tag> const& v) noexcept {
    return v.data[1];
}
template <size_t L, typename T, typename Tag>
[[nodiscard]] inline constexpr T z(base<L, T, Tag> const& v) noexcept {
    return v.data[2];
}
template <size_t L, typename T, typename Tag>
[[nodiscard]] inline constexpr T w(base<L, T, Tag> const& v) noexcept {
    return v.data[3];
}

namespace detail {
template <size_t L, typename T, typename U, typename Tag, typename F>
[[nodiscard]] inline constexpr base<L, T, Tag> op_binary(base<L, T, Tag> const& a, U b, F f) {
    return op_binary(a, b, f, std::make_integer_sequence<size_t, L>());
}

template <size_t L, typename T, typename U, typename Tag, typename F, size_t... i>
[[nodiscard]] inline constexpr base<L, T, Tag>
op_binary(base<L, T, Tag> const& a, U b, F f, std::integer_sequence<size_t, i...>) {
    return base<L, T, Tag>{f(a.data[i], b)...};
}

template <size_t L, typename T, typename U, typename Tag, typename F>
[[nodiscard]] inline constexpr base<L, T, Tag> op_binary(U a, base<L, T, Tag> const& b, F f) {
    return op_binary(a, b, f, std::make_integer_sequence<size_t, L>());
}

template <size_t L, typename T, typename U, typename Tag, typename F, size_t... i>
[[nodiscard]] inline constexpr base<L, T, Tag>
op_binary(U a, base<L, T, Tag> const& b, F f, std::integer_sequence<size_t, i...>) {
    return base<L, T, Tag>{f(a, b.data[i])...};
}

template <size_t L, typename T, typename Tag, typename F>
[[nodiscard]] inline constexpr base<L, T, Tag> op_unary(base<L, T, Tag> const& v, F f) {
    return op_unary(v, f, std::make_integer_sequence<size_t, L>());
}

template <size_t L, typename T, typename Tag, typename F, size_t... i>
[[nodiscard]] inline constexpr base<L, T, Tag>
op_unary(base<L, T, Tag> const& v, F f, std::integer_sequence<size_t, i...>) {
    return base<L, T, Tag>{f(v.data[i])...};
}
}

/**
 * @defgroup plus-scalar
 * @ingroup airthmetic-operators
 * @brief addition of vector/point/etc and scalar
 * @{
 */
template <size_t L, typename T, typename U, typename Tag>
[[nodiscard]] inline constexpr base<L, T, Tag> operator+(base<L, T, Tag> const& a, U b) noexcept {
    return detail::op_binary(a, b, [](auto _1, auto _2) { return _1 + _2; });
}

template <size_t L, typename T, typename U, typename Tag>
[[nodiscard]] inline constexpr base<L, T, Tag> operator+(U a, base<L, T, Tag> const& b) noexcept {
    return detail::op_binary(a, b, [](auto _1, auto _2) { return _1 + _2; });
}
/** @} */

/**
 * @defgroup minus-scalar
 * @ingroup airthmetic-operators
 * @brief substraction of vector/point/etc and scalar
 * @{
 */
template <size_t L, typename T, typename U, typename Tag>
[[nodiscard]] inline constexpr base<L, T, Tag> operator-(base<L, T, Tag> const& a, U b) noexcept {
    return detail::op_binary(a, b, [](auto _1, auto _2) { return _1 - _2; });
}

template <size_t L, typename T, typename U, typename Tag>
[[nodiscard]] inline constexpr base<L, T, Tag> operator-(U a, base<L, T, Tag> const& b) noexcept {
    return detail::op_binary(a, b, [](auto _1, auto _2) { return _1 - _2; });
}
/** @} */

/**
 * @defgroup mul-scalar
 * @ingroup airthmetic-operators
 * @brief multiplication of vector/point/etc and scalar
 * @{
 */
template <size_t L, typename T, typename U, typename Tag>
[[nodiscard]] inline constexpr base<L, T, Tag> operator*(base<L, T, Tag> const& a, U b) noexcept {
    return detail::op_binary(a, b, [](auto _1, auto _2) { return _1 * _2; });
}

template <size_t L, typename T, typename U, typename Tag>
[[nodiscard]] inline constexpr base<L, T, Tag> operator*(U a, base<L, T, Tag> const& b) noexcept {
    return detail::op_binary(a, b, [](auto _1, auto _2) { return _1 * _2; });
}
/** @} */

/**
 * @defgroup div-scalar
 * @ingroup airthmetic-operators
 * @brief division of vector/point/etc and scalar. It's marked as noexcept
 *        since division by zero is not an exception in standard C++.
 * @{
 */
template <size_t L, typename T, typename U, typename Tag>
[[nodiscard]] inline constexpr base<L, T, Tag> operator/(base<L, T, Tag> const& a, U b) noexcept {
    return detail::op_binary(a, b, [](auto _1, auto _2) { return _1 / _2; });
}

template <size_t L, typename T, typename U, typename Tag>
[[nodiscard]] inline constexpr base<L, T, Tag> operator/(U a, base<L, T, Tag> const& b) noexcept {
    return detail::op_binary(a, b, [](auto _1, auto _2) { return _2 / _2; });
}
/** @} */

template <size_t L, typename T, typename Tag>
[[nodiscard]] inline constexpr base<L, T, Tag> operator+(base<L, T, Tag> const& a) noexcept {
    return base<L, T, Tag>{a};
}

template <size_t L, typename T, typename Tag>
[[nodiscard]] inline constexpr base<L, T, Tag> operator-(base<L, T, Tag> const& a) noexcept {
    return detail::op_unary(a, [](auto i) { return -i; });
}

template <size_t L, typename T, typename Tag>
[[nodiscard]] inline constexpr base<L, T, Tag> abs(base<L, T, Tag> const& v) noexcept {
    return detail::op_unary(v, [](auto i) { return std::abs(i); });
}

template <size_t L, typename T, typename Tag>
[[nodiscard]] inline constexpr base<L, T, Tag> floor(base<L, T, Tag> const& v) noexcept {
    if constexpr (std::is_integral_v<T> == true) {
        return v;
    } else {
        return detail::op_unary(v, [](auto i) { return std::floor(i); });
    }
}

/**
 * @brief returns a vector with fractional parts of `v`
 *
 * For integral (`int`, `unsigned int`, etc) it returns vector containing
 * zero, as integers cannot have fractional part.
 *
 * For floating numbers, it returns fractional part calculated as:
 *    i - floor(i)
 * which for positive numbers means 4.11 -> 0.11, but for negative it means
 * -4.11 -> 0.89.
 *
 * @see https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/fract.xhtml
 */
template <size_t L, typename T, typename Tag>
[[nodiscard]] inline constexpr base<L, T, Tag> fract(base<L, T, Tag> const& v) noexcept {
    if constexpr (std::is_integral_v<T> == true) {
        return 0;
    } else {
        return detail::op_unary(v, [](auto i) { return i - std::floor(i); });
    }
}

template <size_t L, typename T, typename U, typename Tag>
[[nodiscard]] inline constexpr base<L, T, Tag> mod(base<L, T, Tag> const& a, U b) noexcept {
    if constexpr (std::is_integral_v<T> == true) {
        return detail::op_binary(a, b, [](auto _1, auto _2) { return _1 % _2; });

    } else {
        return detail::op_binary(a, b, [](auto _1, auto _2) { return std::fmod(_1, _2); });
    }
}

template <size_t L, typename T, typename U, typename Tag>
[[nodiscard]] inline constexpr base<L, T, Tag> sin(base<L, T, Tag> const& a) noexcept {
    return detail::op_unary(a, [](auto _1) { return std::sin(_1); });
}

template <size_t L, typename T, typename U, typename Tag>
[[nodiscard]] inline constexpr base<L, T, Tag> cos(base<L, T, Tag> const& a) noexcept {
    return detail::op_unary(a, [](auto _1) { return std::cos(_1); });
}
}
