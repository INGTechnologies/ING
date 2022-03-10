
/**
 *	Include Types
 */
#include <ING\AMath\Types\Types.h>



namespace ING {

	namespace AMath {

		/**
		 *	Constants
		 */
		static const __m256i MATRIX4X4_TRANSPOSE_PERMUTE_1 = _mm256_set_epi32(7, 3, 5, 1, 6, 2, 4, 0);
		static const __m256i MATRIX4X4_TRANSPOSE_PERMUTE_2 = _mm256_set_epi32(7, 3, 5, 1, 6, 2, 4, 0);
		static const unsigned int MATRIX4X4_TRANSPOSE_SHUFFLE_1 = _MM256_SHUFFLE(1, 0, /**/ 1, 0, /**/ 1, 0, /**/ 1, 0);
		static const unsigned int MATRIX4X4_TRANSPOSE_SHUFFLE_2 = _MM256_SHUFFLE(3, 2, /**/ 3, 2, /**/ 3, 2, /**/ 3, 2);



		/**
		 *	Method
		 */
		Matrix4x4 Matrix4x4::Transpose() const {

			__m256 new_m256_1 = _mm256_shuffle_ps(m256_1,m256_2, MATRIX4X4_TRANSPOSE_SHUFFLE_1);
			__m256 new_m256_2 = _mm256_shuffle_ps(m256_1,m256_2, MATRIX4X4_TRANSPOSE_SHUFFLE_2);

			return Matrix4x4(_mm256_permutevar8x32_ps(new_m256_1, MATRIX4X4_TRANSPOSE_PERMUTE_1), _mm256_permutevar8x32_ps(new_m256_2, MATRIX4X4_TRANSPOSE_PERMUTE_2));

		}

	}

}