#pragma once

/**
 *	Include AMath Types
 */
#include "../Types.h"



namespace ING {

	namespace AMath {

		/**
		 *	Constants
		 */
		static const __m256i V4_MUL_CV4_PERMUTE_1 = _mm256_set_epi32(1, 1, 1, 1, 0, 0, 0, 0);
		static const __m256i V4_MUL_CV4_PERMUTE_2 = _mm256_set_epi32(3, 3, 3, 3, 2, 2, 2, 2);



		/**
		 *	Methods
		 */
		Vector4	CVector4::Transpose() const {

			return m128;

		}



		/**
		 *	Operators
		 */
#ifdef __AVX__
		static inline Matrix4x4 operator*(const CVector4& a, const Vector4& b) {

			__m128_x2 mR3(b.m128, b.m128);


			__m128_x2 mR(a.m128, m128_0_0_0_0);

			__m128_x2 mR2(mR.m256);

			mR.m256 = _mm256_permutevar8x32_ps(mR.m256, V4_MUL_CV4_PERMUTE_1);
			mR2.m256 = _mm256_permutevar8x32_ps(mR2.m256, V4_MUL_CV4_PERMUTE_2);
			
			return Matrix4x4(
				_mm256_mul_ps(mR.m256, mR3.m256),
				_mm256_mul_ps(mR2.m256, mR3.m256)
			);
		}
#else



#endif

	}

}