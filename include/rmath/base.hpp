#pragma once
#include <cstddef>
#include <cstdint>

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
        T data[2];
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
        T data[4];
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
        T data[4];
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

/**
 * @defgroup plus-scalar
 * @ingroup airthmetic-operators
 * @brief addition of vector/point/etc and scalar
 * @{
 */
template <typename T, typename U, typename Tag>
constexpr base<2, T, Tag> operator+(base<2, T, Tag> const& a, U b) noexcept {
    return base<2, T, Tag> {a.x + b, a.y + b};
}

template <typename T, typename U, typename Tag>
constexpr base<3, T, Tag> operator+(base<3, T, Tag> const& a, U b) noexcept {
    return base<3, T, Tag> {a.x + b, a.y + b, a.z + b};
}

template <typename T, typename U, typename Tag>
constexpr base<4, T, Tag> operator+(base<4, T, Tag> const& a, U b) noexcept {
    return base<4, T, Tag> {a.x + b, a.y + b, a.z + b, a.w + b};
}

template <typename T, typename U, typename Tag>
constexpr base<2, T, Tag> operator+(U a, base<2, T, Tag> const& b) noexcept {
    return base<2, T, Tag> {a + b.x, a + b.y};
}

template <typename T, typename U, typename Tag>
constexpr base<3, T, Tag> operator+(U a, base<3, T, Tag> const& b) noexcept {
    return base<3, T, Tag> {a + b.x, a + b.y, a + b.z};
}

template <typename T, typename U, typename Tag>
constexpr base<4, T, Tag> operator+(U a, base<4, T, Tag> const& b) noexcept {
    return base<4, T, Tag> {a + b.x, a + b.y, a + b.z, a + b.w};
}
/** @} */

/**
 * @defgroup minus-scalar
 * @ingroup airthmetic-operators
 * @brief substraction of vector/point/etc and scalar
 * @{
 */
template <typename T, typename U, typename Tag>
constexpr base<2, T, Tag> operator-(base<2, T, Tag> const& a, U b) noexcept {
    return base<2, T, Tag> {a.x - b, a.y - b};
}

template <typename T, typename U, typename Tag>
constexpr base<3, T, Tag> operator-(base<3, T, Tag> const& a, U b) noexcept {
    return base<3, T, Tag> {a.x - b, a.y - b, a.z - b};
}

template <typename T, typename U, typename Tag>
constexpr base<4, T, Tag> operator-(base<4, T, Tag> const& a, U b) noexcept {
    return base<4, T, Tag> {a.x - b, a.y - b, a.z - b, a.w - b};
}

template <typename T, typename U, typename Tag>
constexpr base<2, T, Tag> operator-(U a, base<2, T, Tag> const& b) noexcept {
    return base<2, T, Tag> {a - b.x, a - b.y};
}

template <typename T, typename U, typename Tag>
constexpr base<3, T, Tag> operator-(U a, base<3, T, Tag> const& b) noexcept {
    return base<3, T, Tag> {a - b.x, a - b.y, a - b.z};
}

template <typename T, typename U, typename Tag>
constexpr base<4, T, Tag> operator-(U a, base<4, T, Tag> const& b) noexcept {
    return base<4, T, Tag> {a - b.x, a - b.y, a - b.z, a - b.w};
}
/** @} */

/**
 * @defgroup mul-scalar
 * @ingroup airthmetic-operators
 * @brief multiplication of vector/point/etc and scalar
 * @{
 */
template <typename T, typename U, typename Tag>
constexpr base<2, T, Tag> operator*(base<2, T, Tag> const& a, U b) noexcept {
    return base<2, T, Tag> {a.x * b, a.y * b};
}

template <typename T, typename U, typename Tag>
constexpr base<3, T, Tag> operator*(base<3, T, Tag> const& a, U b) noexcept {
    return base<3, T, Tag> {a.x * b, a.y * b, a.z * b};
}

template <typename T, typename U, typename Tag>
constexpr base<4, T, Tag> operator*(base<4, T, Tag> const& a, U b) noexcept {
    return base<4, T, Tag> {a.x * b, a.y * b, a.z * b, a.w * b};
}

template <typename T, typename U, typename Tag>
constexpr base<2, T, Tag> operator*(U a, base<2, T, Tag> const& b) noexcept {
    return base<2, T, Tag> {a * b.x, a * b.y};
}

template <typename T, typename U, typename Tag>
constexpr base<3, T, Tag> operator*(U a, base<3, T, Tag> const& b) noexcept {
    return base<3, T, Tag> {a * b.x, a * b.y, a * b.z};
}

template <typename T, typename U, typename Tag>
constexpr base<4, T, Tag> operator*(U a, base<4, T, Tag> const& b) noexcept {
    return base<4, T, Tag> {a * b.x, a * b.y, a * b.z, a * b.w};
}
/** @} */

/**
 * @defgroup div-scalar
 * @ingroup airthmetic-operators
 * @brief division of vector/point/etc and scalar. It's marked as noexcept
 *        since division by zero is not an exception in standard C++.
 * @{
 */
template <typename T, typename U, typename Tag>
constexpr base<2, T, Tag> operator/(base<2, T, Tag> const& a, U b) noexcept {
    return base<2, T, Tag> {a.x / b, a.y / b};
}

template <typename T, typename U, typename Tag>
constexpr base<3, T, Tag> operator/(base<3, T, Tag> const& a, U b) noexcept {
    return base<3, T, Tag> {a.x / b, a.y / b, a.z / b};
}

template <typename T, typename U, typename Tag>
constexpr base<4, T, Tag> operator/(base<4, T, Tag> const& a, U b) noexcept {
    return base<4, T, Tag> {a.x / b, a.y / b, a.z / b, a.w / b};
}

template <typename T, typename U, typename Tag>
constexpr base<2, T, Tag> operator/(U a, base<2, T, Tag> const& b) noexcept {
    return base<2, T, Tag> {a / b.x, a / b.y};
}

template <typename T, typename U, typename Tag>
constexpr base<3, T, Tag> operator/(U a, base<3, T, Tag> const& b) noexcept {
    return base<3, T, Tag> {a / b.x, a / b.y, a / b.z};
}

template <typename T, typename U, typename Tag>
constexpr base<4, T, Tag> operator/(U a, base<4, T, Tag> const& b) noexcept {
    return base<4, T, Tag> {a / b.x, a / b.y, a / b.z, a / b.w};
}
/** @} */
}
