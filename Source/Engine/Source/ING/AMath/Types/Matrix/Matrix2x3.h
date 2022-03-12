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

		struct Matrix2x3 {

			/**
			 *	Constructors And Destructor
			 */
#ifdef __AVX__
		public:
			inline Matrix2x3(float m11, float m12, float m13, float m21, float m22, float m23) : m256(_mm256_set_ps(0, m23, m22, m21, 0, m13, m12, m11)) {}

			inline Matrix2x3() : Matrix2x3(m256_0_0_0_0_0_0_0_0) {}

			inline Matrix2x3(const Matrix2x3& a) : m256(a.m256) {}

			inline Matrix2x3(__m256 m) : m256(m) {}

			inline Matrix2x3(__m128 m1, __m128 m2) : m128_1(m1), m128_2(m2) {}

			inline ~Matrix2x3() {}
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

					Vector3 r1;

					Vector3 r2;

				};

			};
#else

#endif



			/**
			 *	Methods
			 */
#ifdef __AVX__
		public:
			Matrix3x2  Transpose() const;
			CMatrix2x3 ToCMatrix() const;
#else

#endif



			/**
			 *	Operators
			 */
#ifdef __AVX__
		public:
			inline Vector3& operator[](unsigned char i) {
				return *((Vector3*)((char*)this + i * 4));
			}
#else

#endif

		};



#ifdef __AVX__
		static inline Matrix2x3 operator+(const Matrix2x3& a, const Matrix2x3& b) { return _mm256_add_ps(a.m256, b.m256); }
		static inline Matrix2x3 operator-(const Matrix2x3& a, const Matrix2x3& b) { return _mm256_sub_ps(a.m256, b.m256); }
		static inline Matrix2x3 operator*(const Matrix2x3& a, float b) {
			__m256 mR = _mm256_set_ps(0, b, b, b, 0, b, b, b);
			return _mm256_mul_ps(a.m256, mR);
		}
		static inline Matrix2x3 operator/(const Matrix2x3& a, float b) {
			__m256 mR = _mm256_set_ps(0, b, b, b, 0, b, b, b);
			return _mm256_div_ps(a.m256, mR);
		}



		static inline void operator+=(Matrix2x3& a, const Matrix2x3& b) { a.m256 = _mm256_add_ps(a.m256, b.m256); }
		static inline void operator-=(Matrix2x3& a, const Matrix2x3& b) { a.m256 = _mm256_sub_ps(a.m256, b.m256); }
		static inline void operator*=(Matrix2x3& a, float b) {
			__m256 mR = _mm256_set_ps(0, b, b, b, 0, b, b, b);
			a.m256 = _mm256_mul_ps(a.m256, mR);
		}
		static inline void operator/=(Matrix2x3& a, float b) {
			__m256 mR = _mm256_set_ps(0, b, b, b, 0, b, b, b);
			a.m256 = _mm256_div_ps(a.m256, mR);
		}
#else

#endif

	}

}