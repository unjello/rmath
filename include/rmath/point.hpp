#pragma once
#include <cstddef>
#include <cstdint>

namespace rmath {

template <size_t L, typename T>
struct point;

template <typename T>
struct point<2, T> {
    typedef T           value_type;
    typedef point<2, T> type;

    union {
        struct {
            T x, y;
        };
        T data[2];
    };

    constexpr point()                   = default;
    constexpr point(point<2, T>& const) = default;
};

template <typename T>
struct point<3, T> {
    typedef T           value_type;
    typedef point<3, T> type;

    union {
        struct {
            T x, y, z;
        };
        T data[4];
    };

    constexpr point()                   = default;
    constexpr point(point<3, T>& const) = default;
};

template <typename T>
struct point<4, T> {
    typedef T           value_type;
    typedef point<4, T> type;

    union {
        struct {
            T x, y, z, w;
        };
        T data[4];
    };

    constexpr point()                   = default;
    constexpr point(point<4, T>& const) = default;
};

typedef point<2, unsigned int> upt2;
typedef point<3, unsigned int> upt3;
typedef point<4, unsigned int> upt4;

typedef point<2, int> ipt2;
typedef point<3, int> ipt3;
typedef point<4, int> ipt4;

typedef point<2, float> pt2;
typedef point<3, float> pt3;
typedef point<4, float> pt4;
}