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

		struct Matrix4x2 {

			/**
			 *	Constructors And Destructor
			 */
#ifdef __AVX__
		public:
			inline Matrix4x2(float m11, float m12, float m21, float m22, float m31, float m32, float m41, float m42) : m256(_mm256_set_ps(m42, m41, m32, m31, m22, m21, m12, m11)) {}

			inline Matrix4x2() : Matrix4x2(m256_0_0_0_0_0_0_0_0) {}

			inline Matrix4x2(const Matrix4x2& a) : m256(a.m256) {}

			inline Matrix4x2(__m256 m) : m256(m) {}

			inline ~Matrix4x2() {}
#else



#endif



			 /**
			  *	Properties
			  */
#ifdef __AVX__
		public:
			union {
				__m256 m256;

				struct {

					float m11;
					float m12;

					float m21;
					float m22;

					float m31;
					float m32;

					float m41;
					float m42;

				};

				struct {

					Vector2 r1;

					Vector2 r2;

					Vector2 r3;

					Vector2 r4;

				};

			};
#else



#endif



			  /**
			   *	Operators
			   */
		public:
			inline Vector2& operator[](unsigned char i) {
				return *((Vector2*)this + i);
			}

		};



		static inline Matrix4x2 operator+(const Matrix4x2& a, const Matrix4x2& b) { return _mm256_add_ps(a.m256, b.m256); }
		static inline Matrix4x2 operator-(const Matrix4x2& a, const Matrix4x2& b) { return _mm256_sub_ps(a.m256, b.m256); }
		static inline Matrix4x2 operator*(const Matrix4x2& a, float b) {
			__m256 mR = _mm256_set_ps(b, b, b, b, b, b, b, b);
			return _mm256_mul_ps(a.m256, mR);
		}
		static inline Matrix4x2 operator/(const Matrix4x2& a, float b) {
			__m256 mR = _mm256_set_ps(b, b, b, b, b, b, b, b);
			return _mm256_div_ps(a.m256, mR);
		}



		static inline void operator+=(Matrix4x2& a, const Matrix4x2& b) { a.m256 = _mm256_add_ps(a.m256, b.m256); }
		static inline void operator-=(Matrix4x2& a, const Matrix4x2& b) { a.m256 = _mm256_sub_ps(a.m256, b.m256); }
		static inline void operator*=(Matrix4x2& a, float b) {
			__m256 mR = _mm256_set_ps(b, b, b, b, b, b, b, b);
			a.m256 = _mm256_mul_ps(a.m256, mR);
		}
		static inline void operator/=(Matrix4x2& a, float b) {
			__m256 mR = _mm256_set_ps(b, b, b, b, b, b, b, b);
			a.m256 = _mm256_div_ps(a.m256, mR);
		}

	}

}