
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
		static const __m128i MATRIX2X2_TO_CMATRIX_PERMUTE = _mm_set_epi32(3, 1, 2, 0);



		/**
		 *	Method
		 */
		Matrix2x2 Matrix2x2::Transpose() const {

			return _mm_permutevar_ps(m128, MATRIX2X2_TRANSPOSE_PERMUTE);

		}
		CMatrix2x2 Matrix2x2::ToCMatrix() const {

			return _mm_permutevar_ps(m128, MATRIX2X2_TO_CMATRIX_PERMUTE);

		}



		/**
		 *	Operators
		 */
#ifdef __AVX__
		static const __m256i M2X2_MUL_CM2X4_PERMUTE_1 = _mm256_set_epi32(3,2,1,0,3,2,1,0);
		static const __m256i M2X2_MUL_CM2X4_PERMUTE_2 = _mm256_set_epi32(1,0,7,6,5,4,3,2);
		static const __m256i M2X2_MUL_CM2X4_PERMUTE_3 = _mm256_set_epi32(5,3,1,7,6,4,2,0);

		static inline Matrix2x4 operator * (const Matrix2x2& a, const CMatrix2x4& b) {

			__m256 m256 = _mm256_permutevar8x32_ps(*((__m256*)(&a.m128)), M2X2_MUL_CM2X4_PERMUTE_1);

			__m256 m256_3 = _mm256_permutevar8x32_ps(b.m256, M2X2_MUL_CM2X4_PERMUTE_2);

			__m256 s1 = _mm256_mul_ps(m256, b.m256);
			__m256 s3 = _mm256_mul_ps(m256, m256_3);

			__m128_x2 l(_mm256_hadd_ps(s1, s3));

			return _mm256_permutevar8x32_ps(l.m256, M2X2_MUL_CM2X4_PERMUTE_3);
		}

		static inline Matrix2x4 operator * (const Matrix2x2& a, const Matrix2x4& b) { return a * b.ToCMatrix(); }

		static inline Matrix2x4 operator * (const CMatrix2x2& a, const Matrix2x4& b) { return a.ToRMatrix() * b.ToCMatrix(); }

		static inline Matrix2x4 operator * (const CMatrix2x2& a, const CMatrix2x4& b) { return a.ToRMatrix() * b; }



		static const __m256i M2X2_MUL_CM2X3_PERMUTE_1 = _mm256_set_epi32(3, 2, 1, 0, 3, 2, 1, 0);
		static const __m256i M2X2_MUL_CM2X3_PERMUTE_2 = _mm256_set_epi32(1, 0, 7, 6, 5, 4, 3, 2);
		static const __m256i M2X2_MUL_CM2X3_PERMUTE_3 = _mm256_set_epi32(5, 3, 1, 7, 6, 4, 2, 0);

		static inline Matrix2x3 operator * (const Matrix2x2& a, const CMatrix2x3& b) {

			__m256 m256 = _mm256_permutevar8x32_ps(*((__m256*)(&a.m128)), M2X2_MUL_CM2X3_PERMUTE_1);

			__m256 m256_3 = _mm256_permutevar8x32_ps(b.m256, M2X2_MUL_CM2X3_PERMUTE_2);

			__m256 s1 = _mm256_mul_ps(m256, b.m256);
			__m256 s3 = _mm256_mul_ps(m256, m256_3);

			__m128_x2 l(_mm256_hadd_ps(s1, s3));

			return _mm256_permutevar8x32_ps(l.m256, M2X2_MUL_CM2X3_PERMUTE_3);
		}

		static inline Matrix2x3 operator * (const Matrix2x2& a, const Matrix2x3& b) { return a * b.ToCMatrix(); }

		static inline Matrix2x3 operator * (const CMatrix2x2& a, const Matrix2x3& b) { return a.ToRMatrix() * b.ToCMatrix(); }

		static inline Matrix2x3 operator * (const CMatrix2x2& a, const CMatrix2x3& b) { return a.ToRMatrix() * b; }



		static const __m128i M2X2_MUL_CM2X2_PERMUTE_1 = _mm_set_epi32(1,0,3,2);
		static const __m128i M2X2_MUL_CM2X2_PERMUTE_2 = _mm_set_epi32(1,3,2,0);

		static inline Matrix2x2 operator * (const Matrix2x2& a, const CMatrix2x2& b) {

			__m128 bP1 = _mm_permutevar_ps(b.m128, M2X2_MUL_CM2X2_PERMUTE_1);

			__m128 s1 = _mm_mul_ps(a.m128, b.m128);
			__m128 s3 = _mm_mul_ps(a.m128, bP1);

			return _mm_permutevar_ps(_mm_hadd_ps(s1, s3), M2X2_MUL_CM2X2_PERMUTE_2);

		}

		static inline Matrix2x2 operator * (const Matrix2x2& a, const Matrix2x2& b) { return a * b.ToCMatrix(); }

		static inline Matrix2x2 operator * (const CMatrix2x2& a, const Matrix2x2& b) { return a.ToRMatrix() * b.ToCMatrix(); }

		static inline Matrix2x2 operator * (const CMatrix2x2& a, const CMatrix2x2& b) { return a.ToRMatrix() * b; }
#else



#endif

	}

}