#pragma once
#include <cstddef>
#include <cstdint>
#include <utility>

namespace rmath {

template <size_t L, typename T, typename Tag>
struct base;

template <typename T, typename Tag>
struct base<2, T, Tag> {
    typedef T value_type;

    union {
        struct {
            T x, y;
        };
        std::array<T, 2> data;
    };

    constexpr base()                       = default;
    constexpr base(base<2, T, Tag> const&) = default;

    constexpr explicit base(T scalar)
        : x(scalar)
        , y(scalar) {}
    constexpr base(T _x, T _y)
        : x(_x)
        , y(_y) {}

    static constexpr size_t size() { return 2; }
};

template <typename T, typename Tag>
struct base<3, T, Tag> {
    typedef T value_type;

    union {
        struct {
            T x, y, z;
        };
        struct {
            T r, g, b;
        };
        std::array<T, 3> data;
    };

    constexpr base()                       = default;
    constexpr base(base<3, T, Tag> const&) = default;

    constexpr explicit base(T scalar)
        : x(scalar)
        , y(scalar)
        , z(scalar) {}
    constexpr base(T _x, T _y, T _z)
        : x(_x)
        , y(_y)
        , z(_z) {}

    static constexpr size_t size() { return 3; }
};

template <typename T, typename Tag>
struct base<4, T, Tag> {
    typedef T value_type;

    union {
        struct {
            T x, y, z, w;
        };
        struct {
            T r, g, b, a;
        };
        std::array<T, 4> data;
    };

    constexpr base()                       = default;
    constexpr base(base<4, T, Tag> const&) = default;

    constexpr explicit base(T scalar)
        : x(scalar)
        , y(scalar)
        , z(scalar)
        , w(scalar) {}
    constexpr base(T _x, T _y, T _z, T _w)
        : x(_x)
        , y(_y)
        , z(_z)
        , w(_w) {}

    static constexpr size_t size() { return 4; }
};

namespace detail {
template <size_t L, typename T, typename U, typename Tag, typename F>
constexpr base<L, T, Tag> op_binary(base<L, T, Tag> const& a, U b, F f) {
    return op_binary(a, b, f, std::make_integer_sequence<size_t, L>());
}

template <size_t L, typename T, typename U, typename Tag, typename F, size_t... i>
constexpr base<L, T, Tag>
op_binary(base<L, T, Tag> const& a, U b, F f, std::integer_sequence<size_t, i...>) {
    return base<L, T, Tag> {f(a.data[i], b)...};
}

template <size_t L, typename T, typename U, typename Tag, typename F>
constexpr base<L, T, Tag> op_binary(U a, base<L, T, Tag> const& b, F f) {
    return op_binary(a, b, f, std::make_integer_sequence<size_t, L>());
}

template <size_t L, typename T, typename U, typename Tag, typename F, size_t... i>
constexpr base<L, T, Tag>
op_binary(U a, base<L, T, Tag> const& b, F f, std::integer_sequence<size_t, i...>) {
    return base<L, T, Tag> {f(a, b.data[i])...};
}
}

/**
 * @defgroup plus-scalar
 * @ingroup airthmetic-operators
 * @brief addition of vector/point/etc and scalar
 * @{
 */
template <size_t L, typename T, typename U, typename Tag>
constexpr base<L, T, Tag> operator+(base<L, T, Tag> const& a, U b) noexcept {
    return detail::op_binary(a, b, [](auto _1, auto _2) { return _1 + _2; });
}

template <size_t L, typename T, typename U, typename Tag>
constexpr base<L, T, Tag> operator+(U a, base<L, T, Tag> const& b) noexcept {
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
constexpr base<L, T, Tag> operator-(base<L, T, Tag> const& a, U b) noexcept {
    return detail::op_binary(a, b, [](auto _1, auto _2) { return _1 - _2; });
}

template <size_t L, typename T, typename U, typename Tag>
constexpr base<L, T, Tag> operator-(U a, base<L, T, Tag> const& b) noexcept {
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
constexpr base<L, T, Tag> operator*(base<L, T, Tag> const& a, U b) noexcept {
    return detail::op_binary(a, b, [](auto _1, auto _2) { return _1 * _2; });
}

template <size_t L, typename T, typename U, typename Tag>
constexpr base<L, T, Tag> operator*(U a, base<L, T, Tag> const& b) noexcept {
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
constexpr base<L, T, Tag> operator/(base<L, T, Tag> const& a, U b) noexcept {
    return detail::op_binary(a, b, [](auto _1, auto _2) { return _1 / _2; });
}

template <size_t L, typename T, typename U, typename Tag>
constexpr base<L, T, Tag> operator/(U a, base<L, T, Tag> const& b) noexcept {
    return detail::op_binary(a, b, [](auto _1, auto _2) { return _2 / _2; });
}
/** @} */
}
