#pragma once

/**
 *	Include AMath Types
 */
#include "../Types.h"



namespace ING {

	namespace AMath {

		/**
		 *	Constants
		 */
		static const __m128i V4_MUL_CM4X4_PERMUTE_1 = _mm_set_epi32(3, 1, 2, 0);



		/**
		 *	Methods
		 */
		CVector4 Vector4::Transpose() const {

			return m128;

		}



		/**
		 *	Operators
		 */
#ifdef __AVX__
		static inline float operator*(const Vector4& a, const CVector4& b) {

			__m128 mR = _mm_mul_ps(a.m128, b.m128);

			mR = _mm_hadd_ps(mR, m128_0_0_0_0);

			return _mm_hadd_ps(mR, mR).m128_f32[0];
		}

		static inline Vector2 operator*(const Vector4& a, const Matrix4x2& b) {

			CMatrix4x2 c_b = b.ToCMatrix();

			__m128_x2 ax2(&a.m128);

			__m256 s1 = _mm256_mul_ps(ax2.m256, c_b.m256);

			__m256 s2 = _mm256_hadd_ps(s1, s1);

			__m256 s3 = _mm256_hadd_ps(s2, s2);

			return Vector2(s3.m256_f32[0], s3.m256_f32[4]);

		}

		static inline Vector2 operator*(const Vector4& a, const CMatrix4x2& b) {

			__m128_x2 ax2(&a.m128);

			__m256 s1 = _mm256_mul_ps(ax2.m256, b.m256);

			__m256 s2 = _mm256_hadd_ps(s1, s1);

			__m256 s3 = _mm256_hadd_ps(s2, s2);

			return Vector2(s3.m256_f32[0],s3.m256_f32[4]);
		}

		static inline Vector3 operator*(const Vector4& a, const Matrix4x3& b) {

			CMatrix4x3 c_b = b.ToCMatrix();

			__m128_x2 ax2(&a.m128);

			__m256 s1 = _mm256_mul_ps(ax2.m256, c_b.m256_1);
			__m256 s2 = _mm256_mul_ps(ax2.m256, c_b.m256_2);

			__m128_x2 s3 = _mm256_hadd_ps(s1, s2);

			return _mm_permutevar_ps(_mm_hadd_ps(s3.m128_1, s3.m128_2), V4_MUL_CM4X4_PERMUTE_1);
		}

		static inline Vector3 operator*(const Vector4& a, const CMatrix4x3& b) {

			__m128_x2 ax2(&a.m128);

			__m256 s1 = _mm256_mul_ps(ax2.m256, b.m256_1);
			__m256 s2 = _mm256_mul_ps(ax2.m256, b.m256_2);

			__m128_x2 s3 = _mm256_hadd_ps(s1, s2);

			return _mm_permutevar_ps(_mm_hadd_ps(s3.m128_1, s3.m128_2), V4_MUL_CM4X4_PERMUTE_1);
		}

		static inline Vector4 operator*(const Vector4& a, const Matrix4x4& b) {

			CMatrix4x4 c_b = b.ToCMatrix();

			__m128_x2 ax2(&a.m128);

			__m256 s1 = _mm256_mul_ps(ax2.m256, c_b.m256_1);
			__m256 s2 = _mm256_mul_ps(ax2.m256, c_b.m256_2);

			__m128_x2 s3 = _mm256_hadd_ps(s1, s2);

			return _mm_permutevar_ps(_mm_hadd_ps(s3.m128_1, s3.m128_2), V4_MUL_CM4X4_PERMUTE_1);
		}

		static inline Vector4 operator*(const Vector4& a, const CMatrix4x4& b) {

			__m128_x2 ax2(&a.m128);

			__m256 s1 = _mm256_mul_ps(ax2.m256, b.m256_1);
			__m256 s2 = _mm256_mul_ps(ax2.m256, b.m256_2);

			__m128_x2 s3 = _mm256_hadd_ps(s1, s2);

			return _mm_permutevar_ps(_mm_hadd_ps(s3.m128_1,s3.m128_2), V4_MUL_CM4X4_PERMUTE_1);
		}
#else

#endif

	}

}