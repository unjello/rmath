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

float x(vector4 const& v) noexcept { return _mm_cvtss_f32(v.data); }
float y(vector4 const& v) noexcept {
    return _mm_cvtss_f32(_mm_shuffle_ps(v.data, v.data, _MM_SHUFFLE(1, 1, 1, 1)));
}
float z(vector4 const& v) noexcept {
    return _mm_cvtss_f32(_mm_shuffle_ps(v.data, v.data, _MM_SHUFFLE(2, 2, 2, 2)));
}
float w(vector4 const& v) noexcept {
    return _mm_cvtss_f32(_mm_shuffle_ps(v.data, v.data, _MM_SHUFFLE(3, 3, 3, 3)));
}

vector4 operator+(vector4 a, vector4 b) { return vector4(_mm_add_ps(a.data, b.data)); }
vector4 operator-(vector4 a, vector4 b) { return vector4(_mm_sub_ps(a.data, b.data)); }
vector4 operator*(vector4 a, vector4 b) { return vector4(_mm_mul_ps(a.data, b.data)); }
vector4 operator/(vector4 a, vector4 b) { return vector4(_mm_div_ps(a.data, b.data)); }
}