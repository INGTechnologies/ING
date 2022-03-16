
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
		static const __m256i MATRIX2X3_TRANSPOSE_PERMUTE = _mm256_set_epi32(7, 3, 6, 2, 5, 1, 4, 0);
		static const __m256i MATRIX2X3_TO_CMATRIX_PERMUTE = _mm256_set_epi32(7, 3, 6, 2, 5, 1, 4, 0);
#else



#endif



		/**
		 *	Method
		 */
#ifdef __AVX__
		Matrix3x2 Matrix2x3::Transpose() const {

			return _mm256_permutevar8x32_ps(m256, MATRIX2X3_TRANSPOSE_PERMUTE);

		}

		CMatrix2x3 Matrix2x3::ToCMatrix() const {

			return _mm256_permutevar8x32_ps(m256, MATRIX2X3_TO_CMATRIX_PERMUTE);

		}
#else



#endif



		/**
		 *	Operators
		 */
#ifdef __AVX__
		static const __m256i M2X3_MUL_CM4X4_PERMUTE_1 = _mm256_set_epi32(3, 2, 1, 0, 7, 6, 5, 4);
		static const __m256i M2X3_MUL_CM4X4_PERMUTE_2 = _mm256_set_epi32(5, 7, 4, 6, 3, 1, 2, 0);

		static inline Matrix2x4 operator * (const Matrix2x3& a, const CMatrix3x4& b) {

			__m256 m256_3 = _mm256_permutevar8x32_ps(b.m256_1, M2X3_MUL_CM4X4_PERMUTE_1);
			__m256 m256_4 = _mm256_permutevar8x32_ps(b.m256_2, M2X3_MUL_CM4X4_PERMUTE_1);

			__m256 s1 = _mm256_mul_ps(a.m256, b.m256_1);
			__m256 s2 = _mm256_mul_ps(a.m256, b.m256_2);
			__m256 s3 = _mm256_mul_ps(a.m256, m256_3);
			__m256 s4 = _mm256_mul_ps(a.m256, m256_4);

			__m256 n1 = _mm256_hadd_ps(s1, s2);
			__m256 n2 = _mm256_hadd_ps(s3, s4);

			__m256 l1 = _mm256_hadd_ps(n1, n2);

			return _mm256_permutevar8x32_ps(l1, M2X3_MUL_CM4X4_PERMUTE_2);
		}

		static inline Matrix2x4 operator * (const Matrix2x3& a, const Matrix3x4& b) { return a * b.ToCMatrix(); }

		static inline Matrix2x4 operator * (const CMatrix2x3& a, const Matrix3x4& b) { return a.ToRMatrix() * b.ToCMatrix(); }

		static inline Matrix2x4 operator * (const CMatrix2x3& a, const CMatrix3x4& b) { return a.ToRMatrix() * b; }



		static const __m256i M2X3_MUL_CM4X3_PERMUTE_1 = _mm256_set_epi32(3, 2, 1, 0, 7, 6, 5, 4);
		static const __m256i M2X3_MUL_CM4X3_PERMUTE_2 = _mm256_set_epi32(5, 7, 4, 6, 3, 1, 2, 0);

		static inline Matrix2x3 operator * (const Matrix2x3& a, const CMatrix3x3& b) {

			__m256 m256_3 = _mm256_permutevar8x32_ps(b.m256_1, M2X3_MUL_CM4X3_PERMUTE_1);
			__m256 m256_4 = _mm256_permutevar8x32_ps(b.m256_2, M2X3_MUL_CM4X3_PERMUTE_1);

			__m256 s1 = _mm256_mul_ps(a.m256, b.m256_1);
			__m256 s2 = _mm256_mul_ps(a.m256, b.m256_2);
			__m256 s3 = _mm256_mul_ps(a.m256, m256_3);
			__m256 s4 = _mm256_mul_ps(a.m256, m256_4);

			__m256 n1 = _mm256_hadd_ps(s1, s2);
			__m256 n2 = _mm256_hadd_ps(s3, s4);

			__m256 l1 = _mm256_hadd_ps(n1, n2);

			return _mm256_permutevar8x32_ps(l1, M2X3_MUL_CM4X3_PERMUTE_2);
		}

		static inline Matrix2x3 operator * (const Matrix2x3& a, const Matrix3x3& b) { return a * b.ToCMatrix(); }

		static inline Matrix2x3 operator * (const CMatrix2x3& a, const Matrix3x3& b) { return a.ToRMatrix() * b.ToCMatrix(); }

		static inline Matrix2x3 operator * (const CMatrix2x3& a, const CMatrix3x3& b) { return a.ToRMatrix() * b; }



		static const __m256i M2X3_MUL_CM4X2_PERMUTE_1 = _mm256_set_epi32(3, 2, 1, 0, 7, 6, 5, 4);
		static const __m256i M2X3_MUL_CM4X2_PERMUTE_2 = _mm256_set_epi32(6, 7, 3, 2, 4, 5, 1, 0);

		static inline Matrix2x2 operator * (const Matrix2x3& a, const CMatrix3x2& b) {

			__m256 m256_2 = _mm256_permutevar8x32_ps(b.m256, M2X3_MUL_CM4X2_PERMUTE_1);

			__m256 s1 = _mm256_mul_ps(a.m256, b.m256);
			__m256 s3 = _mm256_mul_ps(a.m256, m256_2);

			__m256 s4 = _mm256_hadd_ps(s1, s3);
			__m256 s5 = _mm256_hadd_ps(s4, s4);

			__m128_x2 r(_mm256_permutevar8x32_ps(s5, M2X3_MUL_CM4X2_PERMUTE_2));

			return r.m128_1;
		}

		static inline Matrix2x2 operator * (const Matrix2x3& a, const Matrix3x2& b) { return a * b.ToCMatrix(); }

		static inline Matrix2x2 operator * (const CMatrix2x3& a, const Matrix3x2& b) { return a.ToRMatrix() * b.ToCMatrix(); }

		static inline Matrix2x2 operator * (const CMatrix2x3& a, const CMatrix3x2& b) { return a.ToRMatrix() * b; }
#else



#endif

	}

}