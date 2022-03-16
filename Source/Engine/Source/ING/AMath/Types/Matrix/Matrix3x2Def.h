
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



		/**
		 *	Operators
		 */
#ifdef __AVX__
		static const __m256i M3X2_MUL_CM2X4_PERMUTE_1 = _mm256_set_epi32(3, 2, 1, 0, 7, 6, 5, 4);
		static const __m256i M3X2_MUL_CM2X4_PERMUTE_2 = _mm256_set_epi32(1, 0, 7, 6, 5, 4, 3, 2);
		static const __m256i M3X2_MUL_CM2X4_PERMUTE_3 = _mm256_set_epi32(5, 4, 3, 2, 1, 0, 7, 6);
		static const __m256i M3X2_MUL_CM2X4_PERMUTE_4 = _mm256_set_epi32(5, 3, 1, 7, 6, 4, 2, 0);
		static const __m256i M3X2_MUL_CM2X4_PERMUTE_5 = _mm256_set_epi32(1, 7, 5, 3, 2, 0, 6, 4);

		static inline Matrix3x4 operator * (const Matrix3x2& a, const CMatrix2x4& b) {

			__m256 m256_2 = _mm256_permutevar8x32_ps(b.m256, M3X2_MUL_CM2X4_PERMUTE_1);
			__m256 m256_3 = _mm256_permutevar8x32_ps(b.m256, M3X2_MUL_CM2X4_PERMUTE_2);
			__m256 m256_4 = _mm256_permutevar8x32_ps(b.m256, M3X2_MUL_CM2X4_PERMUTE_3);

			__m256 s1 = _mm256_mul_ps(a.m256, b.m256);
			__m256 s2 = _mm256_mul_ps(a.m256, m256_2);
			__m256 s3 = _mm256_mul_ps(a.m256, m256_3);
			__m256 s4 = _mm256_mul_ps(a.m256, m256_4);

			__m128_x4 l(_mm256_hadd_ps(s1, s3), _mm256_hadd_ps(s2, s4));

			__m128_x2 l1(l.m128_1, l.m128_3);
			__m128_x2 l2(l.m128_2, l.m128_4);

			return Matrix3x4(
				_mm256_permutevar8x32_ps(l1.m256, M3X2_MUL_CM2X4_PERMUTE_4),
				_mm256_permutevar8x32_ps(l2.m256, M3X2_MUL_CM2X4_PERMUTE_5)
			);
		}

		static inline Matrix3x4 operator * (const Matrix3x2& a, const Matrix2x4& b) { return a * b.ToCMatrix(); }

		static inline Matrix3x4 operator * (const CMatrix3x2& a, const Matrix2x4& b) { return a.ToRMatrix() * b.ToCMatrix(); }

		static inline Matrix3x4 operator * (const CMatrix3x2& a, const CMatrix2x4& b) { return a.ToRMatrix() * b; }



		static const __m256i M3X2_MUL_CM4X3_PERMUTE_1 = _mm256_set_epi32(3, 2, 1, 0, 7, 6, 5, 4);
		static const __m256i M3X2_MUL_CM4X3_PERMUTE_2 = _mm256_set_epi32(5, 7, 4, 6, 3, 1, 2, 0);

		static inline Matrix3x3 operator * (const Matrix3x2& a, const CMatrix2x3& b) {

			__m256 m256_2 = _mm256_permutevar8x32_ps(b.m256, M3X2_MUL_CM2X4_PERMUTE_1);
			__m256 m256_3 = _mm256_permutevar8x32_ps(b.m256, M3X2_MUL_CM2X4_PERMUTE_2);
			__m256 m256_4 = _mm256_permutevar8x32_ps(b.m256, M3X2_MUL_CM2X4_PERMUTE_3);

			__m256 s1 = _mm256_mul_ps(a.m256, b.m256);
			__m256 s2 = _mm256_mul_ps(a.m256, m256_2);
			__m256 s3 = _mm256_mul_ps(a.m256, m256_3);
			__m256 s4 = _mm256_mul_ps(a.m256, m256_4);

			__m128_x4 l(_mm256_hadd_ps(s1, s3), _mm256_hadd_ps(s2, s4));

			__m128_x2 l1(l.m128_1, l.m128_3);
			__m128_x2 l2(l.m128_2, l.m128_4);

			return Matrix3x3(
				_mm256_permutevar8x32_ps(l1.m256, M3X2_MUL_CM2X4_PERMUTE_4),
				_mm256_permutevar8x32_ps(l2.m256, M3X2_MUL_CM2X4_PERMUTE_5)
			);
		}

		static inline Matrix3x3 operator * (const Matrix3x2& a, const Matrix2x3& b) { return a * b.ToCMatrix(); }

		static inline Matrix3x3 operator * (const CMatrix3x2& a, const Matrix2x3& b) { return a.ToRMatrix() * b.ToCMatrix(); }

		static inline Matrix3x3 operator * (const CMatrix3x2& a, const CMatrix2x3& b) { return a.ToRMatrix() * b; }



		static const __m256i M3X2_MUL_CM2X2_PERMUTE_1 = _mm256_set_epi32(3, 2, 1, 0, 3, 2, 1, 0);
		static const __m256i M3X2_MUL_CM2X2_PERMUTE_2 = _mm256_set_epi32(1, 0, 3, 2, 1, 0, 3, 2);
		static const __m256i M3X2_MUL_CM2X2_PERMUTE_3 = _mm256_set_epi32(5, 7, 6, 4, 1, 3, 2, 0);

		static inline Matrix3x2 operator * (const Matrix3x2& a, const CMatrix2x2& b) {

			__m256 m256_1 = _mm256_permutevar8x32_ps(*((__m256*)(&b.m128)), M3X2_MUL_CM2X2_PERMUTE_1);
			__m256 m256_2 = _mm256_permutevar8x32_ps(m256_1, M3X2_MUL_CM2X2_PERMUTE_2);

			__m256 s1 = _mm256_mul_ps(a.m256, m256_1);
			__m256 s2 = _mm256_mul_ps(a.m256, m256_2);

			return _mm256_permutevar8x32_ps(_mm256_hadd_ps(s1, s2), M3X2_MUL_CM2X2_PERMUTE_3);
		}

		static inline Matrix3x2 operator * (const Matrix3x2& a, const Matrix2x2& b) { return a * b.ToCMatrix(); }

		static inline Matrix3x2 operator * (const CMatrix3x2& a, const Matrix2x2& b) { return a.ToRMatrix() * b.ToCMatrix(); }

		static inline Matrix3x2 operator * (const CMatrix3x2& a, const CMatrix2x2& b) { return a.ToRMatrix() * b; }
#else



#endif

	}

}