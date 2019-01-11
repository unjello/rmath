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

inline float x(vector4 const& v) noexcept { return _mm_cvtss_f32(v.data); }
inline float y(vector4 const& v) noexcept {
    return _mm_cvtss_f32(_mm_shuffle_ps(v.data, v.data, _MM_SHUFFLE(1, 1, 1, 1)));
}
inline float z(vector4 const& v) noexcept {
    return _mm_cvtss_f32(_mm_shuffle_ps(v.data, v.data, _MM_SHUFFLE(2, 2, 2, 2)));
}
inline float w(vector4 const& v) noexcept {
    return _mm_cvtss_f32(_mm_shuffle_ps(v.data, v.data, _MM_SHUFFLE(3, 3, 3, 3)));
}

inline vector4 operator+(vector4 a, vector4 b) { return vector4(_mm_add_ps(a.data, b.data)); }
inline vector4 operator-(vector4 a, vector4 b) { return vector4(_mm_sub_ps(a.data, b.data)); }
inline vector4 operator*(vector4 a, vector4 b) { return vector4(_mm_mul_ps(a.data, b.data)); }
inline vector4 operator/(vector4 a, vector4 b) { return vector4(_mm_div_ps(a.data, b.data)); }
inline vector4 operator*(vector4 a, float b) { return vector4(_mm_mul_ps(a.data, _mm_set_ps1(b))); }
inline vector4 operator/(vector4 a, float b) { return vector4(_mm_div_ps(a.data, _mm_set_ps1(b))); }
inline vector4 operator*(float a, vector4 b) { return vector4(_mm_mul_ps(_mm_set_ps1(a), b.data)); }
inline vector4 operator/(float a, vector4 b) { return vector4(_mm_div_ps(_mm_set_ps1(a), b.data)); }
}