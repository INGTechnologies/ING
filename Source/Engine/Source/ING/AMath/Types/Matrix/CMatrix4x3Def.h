
/**
 *	Include Types
 */
#include <ING\AMath\Types\Types.h>



namespace ING {

	namespace AMath {

		/**
		 *	Constants
		 */
#ifdef __AVX__
		static const __m256i CMATRIX4X3_TRANSPOSE_PERMUTE = _mm256_set_epi32(7, 3, 5, 1, 6, 2, 4, 0);
		static const unsigned int CMATRIX4X3_TRANSPOSE_SHUFFLE_1 = _MM_SHUFFLE(1, 0, 1, 0);
		static const unsigned int CMATRIX4X3_TRANSPOSE_SHUFFLE_2 = _MM_SHUFFLE(3, 2, 3, 2);

		static const __m256i CMATRIX4X3_TO_RMATRIX_PERMUTE = _mm256_set_epi32(7, 3, 5, 1, 6, 2, 4, 0);
		static const unsigned int CMATRIX4X3_TO_RMATRIX_SHUFFLE_1 = _MM_SHUFFLE(1, 0, 1, 0);
		static const unsigned int CMATRIX4X3_TO_RMATRIX_SHUFFLE_2 = _MM_SHUFFLE(3, 2, 3, 2);
#else



#endif



		/**
		 *	Method
		 */
#ifdef __AVX__
		CMatrix3x4 CMatrix4x3::Transpose() const {

			return CMatrix3x4(
				_mm256_permutevar8x32_ps(
					_mm256_shuffle_ps(m256_1, m256_2, CMATRIX4X3_TRANSPOSE_SHUFFLE_1),
					CMATRIX4X3_TRANSPOSE_PERMUTE
				),
				_mm256_permutevar8x32_ps(
					_mm256_shuffle_ps(m256_1, m256_2, CMATRIX4X3_TRANSPOSE_SHUFFLE_2),
					CMATRIX4X3_TRANSPOSE_PERMUTE
				)
			);
		}

		Matrix4x3  CMatrix4x3::ToRMatrix() const {

			return Matrix4x3(
				_mm256_permutevar8x32_ps(
					_mm256_shuffle_ps(m256_1, m256_2, CMATRIX4X3_TO_RMATRIX_SHUFFLE_1),
					CMATRIX4X3_TO_RMATRIX_PERMUTE
				),
				_mm256_permutevar8x32_ps(
					_mm256_shuffle_ps(m256_1, m256_2, CMATRIX4X3_TO_RMATRIX_SHUFFLE_2),
					CMATRIX4X3_TO_RMATRIX_PERMUTE
				)
			);
		}
#else



#endif

	}

}