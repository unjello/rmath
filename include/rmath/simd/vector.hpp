#pragma once

#include <emmintrin.h>
#include <smmintrin.h>
#include <xmmintrin.h>

namespace rmath::simd {

struct vector4 {
    __m128 data;
};

}