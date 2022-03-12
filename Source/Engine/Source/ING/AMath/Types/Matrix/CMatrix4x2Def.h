
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
		static const __m256i CMATRIX4X2_TRANSPOSE_PERMUTE = _mm256_set_epi32(7, 5, 3, 1, 6, 4, 2, 0);
		static const __m256i CMATRIX4X2_TO_RMATRIX_PERMUTE = _mm256_set_epi32(7, 5, 3, 1, 6, 4, 2, 0);
#else



#endif



		/**
		 *	Method
		 */
#ifdef __AVX__
		CMatrix2x4 CMatrix4x2::Transpose() const {
			return _mm256_permutevar8x32_ps(m256, CMATRIX4X2_TRANSPOSE_PERMUTE);
		}

		Matrix4x2  CMatrix4x2::ToRMatrix() const {
			return _mm256_permutevar8x32_ps(m256, CMATRIX4X2_TO_RMATRIX_PERMUTE);
		}
#else



#endif

	}

}