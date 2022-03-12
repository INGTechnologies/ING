
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
		static const __m256i CMATRIX3X2_TRANSPOSE_PERMUTE = _mm256_set_epi32(7, 3, 6, 2, 5, 1, 4, 0);
		static const __m256i CMATRIX3X2_TO_RMATRIX_PERMUTE = _mm256_set_epi32(7, 3, 6, 2, 5, 1, 4, 0);
#else



#endif



		/**
		 *	Method
		 */
#ifdef __AVX__
		CMatrix2x3 CMatrix3x2::Transpose() const {

			return _mm256_permutevar8x32_ps(m256, CMATRIX3X2_TRANSPOSE_PERMUTE);

		}

		Matrix3x2  CMatrix3x2::ToRMatrix() const {

			return _mm256_permutevar8x32_ps(m256, CMATRIX3X2_TO_RMATRIX_PERMUTE);

		}
#else



#endif

	}

}