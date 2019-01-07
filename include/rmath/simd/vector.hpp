#pragma once

#include <emmintrin.h>
#include <smmintrin.h>
#include <xmmintrin.h>

namespace rmath::simd {

struct vector4 {
    explicit vector4(float x, float y, float z, float w) { data = _mm_set_ps(w, z, y, x); }
    explicit vector4(float v) { data = _mm_set_ps1(v); }
    explicit vector4(__m128 d) { data = d; }
    __m128 data;
};

constexpr float x(vector4 const& v) noexcept { return _mm_cvtss_f32(v.data) }
constexpr float y(vector4 const& v) noexcept {
    return _mm_cvtss_f32(_mm_shuffle_ps(v.data, v.data, _MM_SHUFFLE(1, 1, 1, 1)));
}
constexpr float z(vector4 const& v) noexcept {
    return _mm_cvtss_f32(_mm_shuffle_ps(m, m, _MM_SHUFFLE(2, 2, 2, 2)))
}
constexpr float w(vector4 const& v) noexcept {
    return _mm_cvtss_f32(_mm_shuffle_ps(m, m, _MM_SHUFFLE(3, 3, 3, 3)));
}

}