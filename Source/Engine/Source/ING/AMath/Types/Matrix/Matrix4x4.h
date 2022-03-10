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

		struct Matrix4x4 {

			/**
			 *	Constructors And Destructor
			 */
#ifdef __AVX__
		public:
			inline Matrix4x4(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44) :
				m256_1(_mm256_set_ps(m24, m23, m22, m21, m14, m13, m12, m11)) ,
				m256_2(_mm256_set_ps(m44, m43, m42, m41, m34, m33, m32, m31))
			{}

			inline Matrix4x4() : Matrix4x4(m256_0_0_0_0_0_0_0_0, m256_0_0_0_0_0_0_0_0) {}

			inline Matrix4x4(const Matrix4x4& a) : Matrix4x4(a.m256_1, a.m256_2) {}

			inline Matrix4x4(__m256 m1, __m256 m2) : m256_1(m1), m256_2(m2) {}

			inline Matrix4x4(__m128 m1, __m128 m2, __m128 m3, __m128 m4) : m128_1(m1), m128_2(m2), m128_3(m3), m128_4(m4) {}

			inline ~Matrix4x4() {}
#else



#endif




			/**
			 *	Properties
			 */
#ifdef __AVX__
		public:
			union {
				struct {
					__m256 m256_1;
					__m256 m256_2;
				};

				struct {
					__m128 m128_1;
					__m128 m128_2;
					__m128 m128_3;
					__m128 m128_4;
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

					float m41;
					float m42;
					float m43;
					float m44;

				};

				struct {

					Vector4 r1;

					Vector4 r2;

					Vector4 r3;

					Vector4 r4;

				};

			};
#else



#endif



			/**
			 *	Methods
			 */
#ifdef __AVX__
		public:
			Matrix4x4 Transpose() const;
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
		static inline Matrix4x4 operator+(const Matrix4x4& a, const Matrix4x4& b) { return Matrix4x4(_mm256_add_ps(a.m256_1, b.m256_1), _mm256_add_ps(a.m256_2, b.m256_2)); }
		static inline Matrix4x4 operator-(const Matrix4x4& a, const Matrix4x4& b) { return Matrix4x4(_mm256_sub_ps(a.m256_1, b.m256_1), _mm256_sub_ps(a.m256_2, b.m256_2)); }
		static inline Matrix4x4 operator*(const Matrix4x4& a, float b) {
			__m256 mR = _mm256_set_ps(b, b, b, b, b, b, b, b);
			return Matrix4x4(_mm256_mul_ps(a.m256_1, mR), _mm256_mul_ps(a.m256_2, mR));
		}
		static inline Matrix4x4 operator/(const Matrix4x4& a, float b) { 
			__m256 mR = _mm256_set_ps(b,b,b,b,b,b,b,b);
			return Matrix4x4(_mm256_div_ps(a.m256_1, mR), _mm256_div_ps(a.m256_2, mR));
		}



		static inline void operator+=(Matrix4x4& a, const Matrix4x4& b) { a.m256_1 = _mm256_add_ps(a.m256_1, b.m256_1); a.m256_2 = _mm256_add_ps(a.m256_2, b.m256_2); }
		static inline void operator-=(Matrix4x4& a, const Matrix4x4& b) { a.m256_1 = _mm256_sub_ps(a.m256_1, b.m256_1); a.m256_2 = _mm256_sub_ps(a.m256_2, b.m256_2); }
		static inline void operator*=(Matrix4x4& a, float b) {
			__m256 mR = _mm256_set_ps(b, b, b, b, b, b, b, b);
			a.m256_1 = _mm256_mul_ps(a.m256_1, mR);
			a.m256_2 = _mm256_mul_ps(a.m256_2, mR);
		}
		static inline void operator/=(Matrix4x4& a, float b) {
			__m256 mR = _mm256_set_ps(b, b, b, b, b, b, b, b);
			a.m256_1 = _mm256_div_ps(a.m256_1, mR);
			a.m256_2 = _mm256_div_ps(a.m256_2, mR);
		}
#else



#endif

	}

}