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



namespace ING {

	namespace AMath {

		struct Matrix3x4 {

			/**
			 *	Constructors And Destructor
			 */
#ifdef __AVX__
		public:
			inline Matrix3x4(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, float m31, float m32, float m33, float m34) : m256(_mm256_set_ps(m24, m23, m22, m21, m14, m13, m12, m11)) {
			
				r3 = _mm_set_ps(m34, m33, m32, m31);
			
			}

			inline Matrix3x4() : Matrix3x4(m256_0_0_0_0_0_0_0_0, m128_0_0_0_0) {}

			inline Matrix3x4(const Matrix3x4& a) : Matrix3x4(a.m256, a.m128) {}

			inline Matrix3x4(__m256 m1, __m128 m2) : m256(m1), m128(m2) {}

			inline Matrix3x4(__m128 m1, __m128 m2, __m128 m3) : m128_1(m1), m128_2(m2), m128_3(m3) {}

			inline ~Matrix3x4() {}
#else



#endif



			/**
			 *	Properties
			 */
#ifdef __AVX__
		public:
			union {
				struct {
					__m256 m256;
					__m128 m128;
				};

				struct {
					__m128 m128_1;
					__m128 m128_2;
					__m128 m128_3;
				};

				struct {

					float m11;
					float m12;
					float m13;
					float m14;

					float m21;
					float m22;
					float m23;
					float m24;

					float m31;
					float m32;
					float m33;
					float m34;

				};

				struct {

					Vector4 r1;

					Vector4 r2;

					Vector4 r3;

				};

			};
#else



#endif



			/**
			 *	Operators
			 */
#ifdef __AVX__
		public:
			inline Vector4& operator[](unsigned char i) {
				return *((Vector4*)((char*)this + i * 4));
			}
#else



#endif

		};

		

#ifdef __AVX__
		static inline Matrix3x4 operator+(const Matrix3x4& a, const Matrix3x4& b) { return Matrix3x4(_mm256_add_ps(a.m256, b.m256), _mm_add_ps(a.m128, b.m128)); }
		static inline Matrix3x4 operator-(const Matrix3x4& a, const Matrix3x4& b) { return Matrix3x4(_mm256_sub_ps(a.m256, b.m256), _mm_sub_ps(a.m128, b.m128)); }
		static inline Matrix3x4 operator*(const Matrix3x4& a, float b) {
			__m256 mR = _mm256_set_ps(b, b, b, b, b, b, b, b);
			__m128 mR2 = _mm_set_ps(b, b, b, b);
			return Matrix3x4(_mm256_mul_ps(a.m256, mR), _mm_mul_ps(a.m128, mR2));
		}
		static inline Matrix3x4 operator/(const Matrix3x4& a, float b) {
			__m256 mR = _mm256_set_ps(b, b, b, b, b, b, b, b);
			__m128 mR2 = _mm_set_ps(b, b, b, b);
			return Matrix3x4(_mm256_div_ps(a.m256, mR), _mm_div_ps(a.m128, mR2));
		}



		static inline void operator+=(Matrix3x4& a, const Matrix3x4& b) { a.m256 = _mm256_add_ps(a.m256, b.m256); a.m128 = _mm_add_ps(a.m128, b.m128); }
		static inline void operator-=(Matrix3x4& a, const Matrix3x4& b) { a.m256 = _mm256_sub_ps(a.m256, b.m256); a.m128 = _mm_sub_ps(a.m128, b.m128); }
		static inline void operator*=(Matrix3x4& a, float b) {
			__m256 mR = _mm256_set_ps(b, b, b, b, b, b, b, b);
			__m128 mR2 = _mm_set_ps(b, b, b, b);
			a.m256 = _mm256_mul_ps(a.m256, mR);
			a.m128 = _mm_mul_ps(a.m128, mR2);
		}
		static inline void operator/=(Matrix3x4& a, float b) {
			__m256 mR = _mm256_set_ps(b, b, b, b, b, b, b, b);
			__m128 mR2 = _mm_set_ps(b, b, b, b);
			a.m256 = _mm256_div_ps(a.m256, mR);
			a.m128 = _mm_div_ps(a.m128, mR2);
		}
#else



#endif

	}

}