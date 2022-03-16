
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
		static const __m256i MATRIX3X4_TRANSPOSE_PERMUTE = _mm256_set_epi32(7, 3, 5, 1, 6, 2, 4, 0);
		static const unsigned int MATRIX3X4_TRANSPOSE_SHUFFLE_1 = _MM_SHUFFLE(1, 0, 1, 0);
		static const unsigned int MATRIX3X4_TRANSPOSE_SHUFFLE_2 = _MM_SHUFFLE(3, 2, 3, 2);

		static const __m256i MATRIX3X4_TO_CMATRIX_PERMUTE = _mm256_set_epi32(7, 3, 5, 1, 6, 2, 4, 0);
		static const unsigned int MATRIX3X4_TO_CMATRIX_SHUFFLE_1 = _MM_SHUFFLE(1, 0, 1, 0);
		static const unsigned int MATRIX3X4_TO_CMATRIX_SHUFFLE_2 = _MM_SHUFFLE(3, 2, 3, 2);
#else



#endif



		/**
		 *	Method
		 */
#ifdef __AVX__
		Matrix4x3  Matrix3x4::Transpose() const {

			return Matrix4x3(
				_mm256_permutevar8x32_ps(
					_mm256_shuffle_ps(m256_1, m256_2, MATRIX3X4_TRANSPOSE_SHUFFLE_1),
					MATRIX3X4_TRANSPOSE_PERMUTE
				),
				_mm256_permutevar8x32_ps(
					_mm256_shuffle_ps(m256_1, m256_2, MATRIX3X4_TRANSPOSE_SHUFFLE_2),
					MATRIX3X4_TRANSPOSE_PERMUTE
				)
			);
		}

		CMatrix3x4 Matrix3x4::ToCMatrix() const {

			return CMatrix3x4(
				_mm256_permutevar8x32_ps(
					_mm256_shuffle_ps(m256_1, m256_2, MATRIX3X4_TO_CMATRIX_SHUFFLE_1),
					MATRIX3X4_TO_CMATRIX_PERMUTE
				),
				_mm256_permutevar8x32_ps(
					_mm256_shuffle_ps(m256_1, m256_2, MATRIX3X4_TO_CMATRIX_SHUFFLE_2),
					MATRIX3X4_TO_CMATRIX_PERMUTE
				)
			);
		}
#else



#endif



		/**
		 *	Operators
		 */
#ifdef __AVX__
		static const __m256i M3X4_MUL_CM3X4_PERMUTE_1 = _mm256_set_epi32(3, 2, 1, 0, 7, 6, 5, 4);
		static const __m256i M3X4_MUL_CM3X4_PERMUTE_2 = _mm256_set_epi32(5, 7, 4, 6, 3, 1, 2, 0);

		static inline Matrix3x4 operator * (const Matrix3x4& a, const CMatrix4x4& b) {

			__m256 m256_3 = _mm256_permutevar8x32_ps(b.m256_1, M3X4_MUL_CM3X4_PERMUTE_1);
			__m256 m256_4 = _mm256_permutevar8x32_ps(b.m256_2, M3X4_MUL_CM3X4_PERMUTE_1);

			__m256 s1 = _mm256_mul_ps(a.m256_1, b.m256_1);
			__m256 s2 = _mm256_mul_ps(a.m256_1, b.m256_2);
			__m256 s3 = _mm256_mul_ps(a.m256_1, m256_3);
			__m256 s4 = _mm256_mul_ps(a.m256_1, m256_4);
			__m256 s5 = _mm256_mul_ps(a.m256_2, b.m256_1);
			__m256 s6 = _mm256_mul_ps(a.m256_2, b.m256_2);
			__m256 s7 = _mm256_mul_ps(a.m256_2, m256_3);
			__m256 s8 = _mm256_mul_ps(a.m256_2, m256_4);

			__m256 n1 = _mm256_hadd_ps(s1, s2);
			__m256 n2 = _mm256_hadd_ps(s3, s4);
			__m256 n3 = _mm256_hadd_ps(s5, s6);
			__m256 n4 = _mm256_hadd_ps(s7, s8);

			__m256 l1 = _mm256_hadd_ps(n1, n2);
			__m256 l2 = _mm256_hadd_ps(n3, n4);

			return Matrix3x4(
				_mm256_permutevar8x32_ps(l1, M3X4_MUL_CM3X4_PERMUTE_2),
				_mm256_permutevar8x32_ps(l2, M3X4_MUL_CM3X4_PERMUTE_2)
			);
		}

		static inline Matrix3x4 operator * (const Matrix3x4& a, const Matrix4x4& b) { return a * b.ToCMatrix(); }

		static inline Matrix3x4 operator * (const CMatrix3x4& a, const Matrix4x4& b) { return a.ToRMatrix() * b.ToCMatrix(); }

		static inline Matrix3x4 operator * (const CMatrix3x4& a, const CMatrix4x4& b) { return a.ToRMatrix() * b; }



		static const __m256i M3X4_MUL_CM4X3_PERMUTE_1 = _mm256_set_epi32(3, 2, 1, 0, 7, 6, 5, 4);
		static const __m256i M3X4_MUL_CM4X3_PERMUTE_2 = _mm256_set_epi32(5, 7, 4, 6, 3, 1, 2, 0);

		static inline Matrix3x3 operator * (const Matrix3x4& a, const CMatrix4x3& b) {

			__m256 m256_3 = _mm256_permutevar8x32_ps(b.m256_1, M3X4_MUL_CM4X3_PERMUTE_1);
			__m256 m256_4 = _mm256_permutevar8x32_ps(b.m256_2, M3X4_MUL_CM4X3_PERMUTE_1);

			__m256 s1 = _mm256_mul_ps(a.m256_1, b.m256_1);
			__m256 s2 = _mm256_mul_ps(a.m256_1, b.m256_2);
			__m256 s3 = _mm256_mul_ps(a.m256_1, m256_3);
			__m256 s4 = _mm256_mul_ps(a.m256_1, m256_4);
			__m256 s5 = _mm256_mul_ps(a.m256_2, b.m256_1);
			__m256 s6 = _mm256_mul_ps(a.m256_2, b.m256_2);
			__m256 s7 = _mm256_mul_ps(a.m256_2, m256_3);
			__m256 s8 = _mm256_mul_ps(a.m256_2, m256_4);

			__m256 n1 = _mm256_hadd_ps(s1, s2);
			__m256 n2 = _mm256_hadd_ps(s3, s4);
			__m256 n3 = _mm256_hadd_ps(s5, s6);
			__m256 n4 = _mm256_hadd_ps(s7, s8);

			__m256 l1 = _mm256_hadd_ps(n1, n2);
			__m256 l2 = _mm256_hadd_ps(n3, n4);

			return Matrix3x3(
				_mm256_permutevar8x32_ps(l1, M3X4_MUL_CM4X3_PERMUTE_2),
				_mm256_permutevar8x32_ps(l2, M3X4_MUL_CM4X3_PERMUTE_2)
			);
		}

		static inline Matrix3x3 operator * (const Matrix3x4& a, const Matrix4x3& b) { return a * b.ToCMatrix(); }

		static inline Matrix3x3 operator * (const CMatrix3x4& a, const Matrix4x3& b) { return a.ToRMatrix() * b.ToCMatrix(); }

		static inline Matrix3x3 operator * (const CMatrix3x4& a, const CMatrix4x3& b) { return a.ToRMatrix() * b; }



		static const __m256i M3X4_MUL_CM4X2_PERMUTE_1 = _mm256_set_epi32(3, 2, 1, 0, 7, 6, 5, 4);
		static const __m256i M3X4_MUL_CM4X2_PERMUTE_2 = _mm256_set_epi32(6, 7, 3, 2, 4, 5, 1, 0);

		static inline Matrix3x2 operator * (const Matrix3x4& a, const CMatrix4x2& b) {

			__m256 m256_3 = _mm256_permutevar8x32_ps(b.m256, M3X4_MUL_CM4X2_PERMUTE_1);

			__m256 s1 = _mm256_mul_ps(a.m256_1, b.m256);
			__m256 s3 = _mm256_mul_ps(a.m256_1, m256_3);
			__m256 s5 = _mm256_mul_ps(a.m256_2, b.m256);
			__m256 s7 = _mm256_mul_ps(a.m256_2, m256_3);

			__m256 n1 = _mm256_hadd_ps(s1, s3);
			__m256 n2 = _mm256_hadd_ps(s5, s7);

			__m256 l1 = _mm256_hadd_ps(n1, n2);

			return _mm256_permutevar8x32_ps(l1, M3X4_MUL_CM4X2_PERMUTE_2);
		}

		static inline Matrix3x2 operator * (const Matrix3x4& a, const Matrix4x2& b) { return a * b.ToCMatrix(); }

		static inline Matrix3x2 operator * (const CMatrix3x4& a, const Matrix4x2& b) { return a.ToRMatrix() * b.ToCMatrix(); }

		static inline Matrix3x2 operator * (const CMatrix3x4& a, const CMatrix4x2& b) { return a.ToRMatrix() * b; }
#else



#endif

	}

}