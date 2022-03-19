#pragma once



#include <xmmintrin.h>
#include <immintrin.h>
#include <pmmintrin.h>



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



#ifdef __AVX__

#define _MM256_SHUFFLE(fp7,fp6,fp5,fp4,fp3,fp2,fp1,fp0) \
 (((fp7) << 128) | ((fp6) << 64) | ((fp5) << 32) | ((fp4) << 16) | ((fp3) << 8) | ((fp2) << 4) | ((fp1) << 2) | (fp0))

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



		static const __m256i M128_DUPLICATE_PERMUTE = _mm256_set_epi32(3,2,1,0,3,2,1,0);

		union __m128_x2 {

			__m128_x2(){}
			__m128_x2(__m256 m):m256(m){}
			__m128_x2(__m128 m1, __m128 m2):m128_1(m1),m128_2(m2){}
			__m128_x2(const __m128* m){
			
				m256 = _mm256_permutevar8x32_ps(*((__m256*)m), M128_DUPLICATE_PERMUTE);
			
			}

			__m256 m256;

			struct {

				__m128 m128_1;
				__m128 m128_2;

			};

		};



		static const __m256i _M256_FP0_TO_ALL = _mm256_set_epi32(0, 0, 0, 0, 0, 0, 0, 0);


		union __m128_x4 {

			__m128_x4() {}
			__m128_x4(__m256 m1, __m256 m2) :m256_1(m1), m256_2(m2) {}

			struct {

				__m256 m256_1;
				__m256 m256_2;

			};

			struct {

				__m128 m128_1;
				__m128 m128_2;
				__m128 m128_3;
				__m128 m128_4;

			};

		};

	}

}

#endif