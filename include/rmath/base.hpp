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
}
