
/**
 *	Include Types
 */
#include <ING\AMath\Types\Types.h>



namespace ING {

	namespace AMath {

		/**
		 *	Constants
		 */
		static const __m128i CMATRIX2X2_TRANSPOSE_PERMUTE = _mm_set_epi32(3, 1, 2, 0);
		static const __m128i CMATRIX2X2_TO_RMATRIX_PERMUTE = _mm_set_epi32(3, 1, 2, 0);



		/**
		 *	Method
		 */
		CMatrix2x2 CMatrix2x2::Transpose() const {

			return _mm_permutevar_ps(m128, CMATRIX2X2_TRANSPOSE_PERMUTE);

		}

		Matrix2x2  CMatrix2x2::ToRMatrix() const {

			return _mm_permutevar_ps(m128, CMATRIX2X2_TO_RMATRIX_PERMUTE);

		}

	}

}