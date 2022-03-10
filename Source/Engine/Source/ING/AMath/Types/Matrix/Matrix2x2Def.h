
/**
 *	Include Types
 */
#include <ING\AMath\Types\Types.h>



namespace ING {

	namespace AMath {

		/**
		 *	Constants
		 */
		static const __m128i MATRIX2X2_TRANSPOSE_PERMUTE = _mm_set_epi32(3, 1, 2, 0);



		/**
		 *	Method
		 */
		Matrix2x2 Matrix2x2::Transpose() const {

			return _mm_permutevar_ps(m128, MATRIX2X2_TRANSPOSE_PERMUTE);

		}

	}

}