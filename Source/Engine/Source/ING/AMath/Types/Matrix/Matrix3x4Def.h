
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
		static const __m256i MATRIX3X4_TRANSPOSE_PERMUTE = _mm256_set_epi32(7, 3, 5, 1, 6, 2, 4, 0);
		static const unsigned int MATRIX3X4_TRANSPOSE_SHUFFLE_1 = _MM_SHUFFLE(1, 0, 1, 0);
		static const unsigned int MATRIX3X4_TRANSPOSE_SHUFFLE_2 = _MM_SHUFFLE(3, 2, 3, 2);

		static const __m256i MATRIX3X4_TO_CMATRIX_PERMUTE = _mm256_set_epi32(7, 3, 5, 1, 6, 2, 4, 0);
		static const unsigned int MATRIX3X4_TO_CMATRIX_SHUFFLE_1 = _MM_SHUFFLE(1, 0, 1, 0);
		static const unsigned int MATRIX3X4_TO_CMATRIX_SHUFFLE_2 = _MM_SHUFFLE(3, 2, 3, 2);
#else



#endif



		/**
		 *	Method
		 */
#ifdef __AVX__
		Matrix4x3  Matrix3x4::Transpose() const {

			return Matrix4x3(
				_mm256_permutevar8x32_ps(
					_mm256_shuffle_ps(m256_1, m256_2, MATRIX3X4_TRANSPOSE_SHUFFLE_1),
					MATRIX3X4_TRANSPOSE_PERMUTE
				),
				_mm256_permutevar8x32_ps(
					_mm256_shuffle_ps(m256_1, m256_2, MATRIX3X4_TRANSPOSE_SHUFFLE_2),
					MATRIX3X4_TRANSPOSE_PERMUTE
				)
			);
		}

		CMatrix3x4 Matrix3x4::ToCMatrix() const {

			return CMatrix3x4(
				_mm256_permutevar8x32_ps(
					_mm256_shuffle_ps(m256_1, m256_2, MATRIX3X4_TO_CMATRIX_SHUFFLE_1),
					MATRIX3X4_TO_CMATRIX_PERMUTE
				),
				_mm256_permutevar8x32_ps(
					_mm256_shuffle_ps(m256_1, m256_2, MATRIX3X4_TO_CMATRIX_SHUFFLE_2),
					MATRIX3X4_TO_CMATRIX_PERMUTE
				)
			);
		}
#else



#endif

	}

}