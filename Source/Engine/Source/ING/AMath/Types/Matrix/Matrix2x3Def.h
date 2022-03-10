
/**
 *	Include Types
 */
#include <ING\AMath\Types\Types.h>



namespace ING {

	namespace AMath {

		/**
		 *	Constants
		 */
		static const __m256i MATRIX2X3_TRANSPOSE_PERMUTE = _mm256_set_epi32(7, 3, 6, 2, 5, 1, 4, 0);



		/**
		 *	Method
		 */
		Matrix3x2 Matrix2x3::Transpose() const {

			return _mm256_permutevar8x32_ps(m256, MATRIX2X3_TRANSPOSE_PERMUTE);

		}

	}

}