#pragma once

#include <emmintrin.h>
#include <smmintrin.h>
#include <xmmintrin.h>

namespace rmath::simd {

struct vector4 {
    explicit vector4(float x, float y, float z, float w) { data = _mm_set_ps(w, z, y, x); }
    explicit vector4(float v) { data = _mm_set_ps1(v); }
    __m128 data;
};

}