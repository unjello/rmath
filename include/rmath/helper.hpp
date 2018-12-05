#pragma once

#include <cmath>
#include <type_traits>

template <typename T, typename U>
T round(U v) {
    if constexpr (std::is_integral<T>::value) {
        return std::round(v);
    } else {
        return v;
    }
}