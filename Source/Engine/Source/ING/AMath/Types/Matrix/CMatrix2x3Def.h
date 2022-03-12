
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
		static const __m256i CMATRIX2X3_TRANSPOSE_PERMUTE = _mm256_set_epi32(7, 5, 3, 1, 6, 4, 2, 0);
		static const __m256i CMATRIX2X3_TO_RMATRIX_PERMUTE = _mm256_set_epi32(7, 5, 3, 1, 6, 4, 2, 0);
#else



#endif



		/**
		 *	Method
		 */
#ifdef __AVX__
		CMatrix3x2 CMatrix2x3::Transpose() const {

			return _mm256_permutevar8x32_ps(m256, CMATRIX2X3_TRANSPOSE_PERMUTE);

		}

		Matrix2x3  CMatrix2x3::ToRMatrix() const {

			return _mm256_permutevar8x32_ps(m256, CMATRIX2X3_TO_RMATRIX_PERMUTE);

		}
#else



#endif

	}

}