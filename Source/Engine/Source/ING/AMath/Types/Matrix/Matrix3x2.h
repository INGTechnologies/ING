#pragma once

/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Declares Types
 */
#include "../TypeDeclares.h"



/**
 *	Include Vector
 */
#include "../Vector/Vector.h"



namespace ING {

	namespace AMath {

		struct Matrix3x2 {

			/**
			 *	Constructors And Destructor
			 */
#ifdef __AVX__
		public:
			inline Matrix3x2(float m11, float m12, float m21, float m22, float m31, float m32) : m256(_mm256_set_ps(0, 0, m32, m31, m22, m21, m12, m11)) {}

			inline Matrix3x2() : Matrix3x2(m256_0_0_0_0_0_0_0_0) {}

			inline Matrix3x2(const Matrix3x2& a) : m256(a.m256) {}

			inline Matrix3x2(__m256 m) : m256(m) {}

			inline Matrix3x2(__m128 m1, __m128 m2) : m128_1(m1), m128_2(m2) {}

			inline ~Matrix3x2() {}
#else
		public:
			inline Matrix3x2(float m11, float m12, float m13, float m21, float m22, float m23) : m128_1(_mm_set_ps(0, m23, m22, m21)), m128_2(_mm_set_ps(0, m13, m12, m11)) {}

			inline Matrix3x2() : Matrix3x2(m128_0_0_0_0, m128_0_0_0_0) {}

			inline Matrix3x2(const Matrix3x2& a) : m128_1(a.m128_1), m128_2(a.m128_2) {}

			inline Matrix3x2(__m128 m1, __m128 m2) : m128_1(m1), m128_2(m2) {}

			inline ~Matrix3x2() {}
#endif



			/**
			 *	Properties
			 */
#ifdef __AVX__
		public:
			union {
				__m256 m256;

				struct {
					__m128 m128_1;
					__m128 m128_2;
				};

				struct {

					float m11;
					float m12;

					float m21;
					float m22;

					float m31;
					float m32;

				};

				struct {

					Vector2 r1;

					Vector2 r2;

					Vector2 r3;

				};

			};
#else
		public:
			union {
				struct {
					__m128 m128_1;
					__m128 m128_2;
				};

				struct {

					float m11;
					float m12;
					float m13;

					float m1x;

					float m21;
					float m22;
					float m23;

					float m2x;

				};

				struct {

					Vector4 r1;

					Vector4 r2;

				};

			};
#endif



			/**
			 *	Methods
			 */
#ifdef __AVX__
		public:
			Matrix2x3 Transpose() const;
#else
		public:
			Matrix2x3 Transpose() const;
#endif



			/**
			 *	Operators
			 */
#ifdef __AVX__
		public:
			inline Vector2& operator[](unsigned char i) {
				return *((Vector2*)this + i);
			}
#else
		public:
			inline Vector2& operator[](unsigned char i) {
				return *((Vector2*)this + i);
			}
#endif

		};

		

#ifdef __AVX__
		static inline Matrix3x2 operator+(const Matrix3x2& a, const Matrix3x2& b) { return _mm256_add_ps(a.m256, b.m256); }
		static inline Matrix3x2 operator-(const Matrix3x2& a, const Matrix3x2& b) { return _mm256_sub_ps(a.m256, b.m256); }
		static inline Matrix3x2 operator*(const Matrix3x2& a, float b) {
			__m256 mR = _mm256_set_ps(0, 0, b, b, b, b, b, b);
			return _mm256_mul_ps(a.m256, mR);
		}
		static inline Matrix3x2 operator/(const Matrix3x2& a, float b) {
			__m256 mR = _mm256_set_ps(0, 0, b, b, b, b, b, b);
			return _mm256_div_ps(a.m256, mR);
		}



		static inline void operator+=(Matrix3x2& a, const Matrix3x2& b) { a.m256 = _mm256_add_ps(a.m256, b.m256); }
		static inline void operator-=(Matrix3x2& a, const Matrix3x2& b) { a.m256 = _mm256_sub_ps(a.m256, b.m256); }
		static inline void operator*=(Matrix3x2& a, float b) {
			__m256 mR = _mm256_set_ps(0, 0, b, b, b, b, b, b);
			a.m256 = _mm256_mul_ps(a.m256, mR);
		}
		static inline void operator/=(Matrix3x2& a, float b) {
			__m256 mR = _mm256_set_ps(0, 0, b, b, b, b, b, b);
			a.m256 = _mm256_div_ps(a.m256, mR);
		}
#else
		static inline Matrix3x2 operator+(const Matrix3x2& a, const Matrix3x2& b) { return Matrix3x2(_mm_add_ps(a.m128_1, b.m128_1), _mm_add_ps(a.m128_2, b.m128_2)); }
		static inline Matrix3x2 operator-(const Matrix3x2& a, const Matrix3x2& b) { return Matrix3x2(_mm_sub_ps(a.m128_1, b.m128_1), _mm_sub_ps(a.m128_2, b.m128_2)); }
		static inline Matrix3x2 operator*(const Matrix3x2& a, float b) {
			__m128 mR = _mm_set_ps(b, b, b, b);
			return Matrix3x2(_mm_mul_ps(a.m128_1, mR), _mm_mul_ps(a.m128_2, mR));
		}
		static inline Matrix3x2 operator/(const Matrix3x2& a, float b) {
			__m128 mR = _mm_set_ps(b, b, b, b);
			return Matrix3x2(_mm_div_ps(a.m128_1, mR), _mm_div_ps(a.m128_2, mR));
		}



		static inline void operator+=(Matrix3x2& a, const Matrix3x2& b) { a.m128_1 = _mm_add_ps(a.m128_1, b.m128_1); a.m128_2 = _mm_add_ps(a.m128_1, b.m128_1); }
		static inline void operator-=(Matrix3x2& a, const Matrix3x2& b) { a.m128_1 = _mm_sub_ps(a.m128_1, b.m128_1); a.m128_2 = _mm_sub_ps(a.m128_2, b.m128_2); }
		static inline void operator*=(Matrix3x2& a, float b) {
			__m128 mR = _mm_set_ps(b, b, b, b);
			a.m128_1 = _mm_mul_ps(a.m128_1, mR);
			a.m128_2 = _mm_mul_ps(a.m128_2, mR);
		}
		static inline void operator/=(Matrix3x2& a, float b) {
			__m128 mR = _mm_set_ps(b, b, b, b);
			a.m128_1 = _mm_div_ps(a.m128_1, mR);
			a.m128_2 = _mm_div_ps(a.m128_2, mR);
		}
#endif

	}

}