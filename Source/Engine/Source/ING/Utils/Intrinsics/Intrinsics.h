#pragma once



#include <xmmintrin.h>

namespace ING {

	namespace Utils {

		static const __m128 m128_1_0_0_0		= _mm_set_ps( 1,  0,  0,  0);
		static const __m128 m128_0_1_0_0		= _mm_set_ps( 0,  1,  0,  0);
		static const __m128 m128_0_0_1_0		= _mm_set_ps( 0,  0,  1,  0);
		static const __m128 m128_0_0_0_1		= _mm_set_ps( 0,  0,  0,  1);

		static const __m128 m128_i1_0_0_0		= _mm_set_ps(-1,  0,  0,  0);
		static const __m128 m128_0_i1_0_0		= _mm_set_ps( 0, -1,  0,  0);
		static const __m128 m128_0_0_i1_0		= _mm_set_ps( 0,  0, -1,  0);
		static const __m128 m128_0_0_0_i1		= _mm_set_ps( 0,  0,  0, -1);

		static const __m128 m128_1_1_1_1		= _mm_set_ps( 1,  1,  1,  1);
		static const __m128 m128_i1_i1_i1_i1	= _mm_set_ps(-1, -1, -1, -1);
		static const __m128 m128_0_0_0_0		= _mm_set_ps( 0,  0,  0,  0);

	}

}



#ifdef __AVX2__
#include <immintrin.h>

namespace ING {

	namespace Utils {

		static const __m256 m256_1_0_0_0_0_0_0_0			= _mm256_set_ps(1, 0, 0, 0, 0, 0, 0, 0);
		static const __m256 m256_0_1_0_0_0_0_0_0			= _mm256_set_ps(0, 1, 0, 0, 0, 0, 0, 0);
		static const __m256 m256_0_0_1_0_0_0_0_0			= _mm256_set_ps(0, 0, 1, 0, 0, 0, 0, 0);
		static const __m256 m256_0_0_0_1_0_0_0_0			= _mm256_set_ps(0, 0, 0, 1, 0, 0, 0, 0);
		static const __m256 m256_0_0_0_0_1_0_0_0			= _mm256_set_ps(0, 0, 0, 0, 1, 0, 0, 0);
		static const __m256 m256_0_0_0_0_0_1_0_0			= _mm256_set_ps(0, 0, 0, 0, 0, 1, 0, 0);
		static const __m256 m256_0_0_0_0_0_0_1_0			= _mm256_set_ps(0, 0, 0, 0, 0, 0, 1, 0);
		static const __m256 m256_0_0_0_0_0_0_0_1			= _mm256_set_ps(0, 0, 0, 0, 0, 0, 0, 1);

		static const __m256 m256_i1_0_0_0_0_0_0_0			= _mm256_set_ps(-1, 0, 0, 0, 0, 0, 0, 0);
		static const __m256 m256_0_i1_0_0_0_0_0_0			= _mm256_set_ps(0, -1, 0, 0, 0, 0, 0, 0);
		static const __m256 m256_0_0_i1_0_0_0_0_0			= _mm256_set_ps(0, 0, -1, 0, 0, 0, 0, 0);
		static const __m256 m256_0_0_0_i1_0_0_0_0			= _mm256_set_ps(0, 0, 0, -1, 0, 0, 0, 0);
		static const __m256 m256_0_0_0_0_i1_0_0_0			= _mm256_set_ps(0, 0, 0, 0, -1, 0, 0, 0);
		static const __m256 m256_0_0_0_0_0_i1_0_0			= _mm256_set_ps(0, 0, 0, 0, 0, -1, 0, 0);
		static const __m256 m256_0_0_0_0_0_0_i1_0			= _mm256_set_ps(0, 0, 0, 0, 0, 0, -1, 0);
		static const __m256 m256_0_0_0_0_0_0_0_i1			= _mm256_set_ps(0, 0, 0, 0, 0, 0, 0, -1);

		static const __m256 m256_1_1_1_1_1_1_1_1			= _mm256_set_ps(1, 1, 1, 1, 1, 1, 1, 1);
		static const __m256 m256_i1_i1_i1_i1_i1_i1_i1_i1	= _mm256_set_ps(-1, -1, -1, -1, -1, -1, -1, -1);
		static const __m256 m256_0_0_0_0_0_0_0_0			= _mm256_set_ps(0, 0, 0, 0, 0, 0, 0, 0);

	}

}

#endif