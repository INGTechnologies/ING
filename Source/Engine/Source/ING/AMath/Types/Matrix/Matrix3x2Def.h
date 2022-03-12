
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
		static const __m256i MATRIX3X2_TRANSPOSE_PERMUTE = _mm256_set_epi32(7, 5, 3, 1, 6, 4, 2, 0);
		static const __m256i MATRIX3X2_TO_CMATRIX_PERMUTE = _mm256_set_epi32(7, 5, 3, 1, 6, 4, 2, 0);
#else



#endif



		/**
		 *	Method
		 */
#ifdef __AVX__
		Matrix2x3 Matrix3x2::Transpose() const {

			return _mm256_permutevar8x32_ps(m256, MATRIX3X2_TRANSPOSE_PERMUTE);

		}
		CMatrix3x2 Matrix3x2::ToCMatrix() const {

			return _mm256_permutevar8x32_ps(m256, MATRIX3X2_TO_CMATRIX_PERMUTE);

	}
#else



#endif

	}

}