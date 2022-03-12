#pragma once

/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Math Type Declares
 */
#include <ING\Math\Types\TypeDeclares.h>



/**
 *	Include AMath Type Declares
 */
#include <ING\AMath\Types\TypeDeclares.h>



/**
 *	Include Vector
 */
#include "../Vector/Vector.h"



namespace ING {

	namespace AMath {

		struct CMatrix3x2 {

			/**
			 *	Constructors And Destructor
			 */
#ifdef __AVX__
		public:
			inline CMatrix3x2(float m11, float m12, float m21, float m22, float m31, float m32) : m256(_mm256_set_ps(0, m32, m22, m12, 0, m31, m21, m11)) {}

			inline CMatrix3x2() : CMatrix3x2(m256_0_0_0_0_0_0_0_0) {}

			inline CMatrix3x2(const CMatrix3x2& a) : m256(a.m256) {}

			inline CMatrix3x2(__m256 m) : m256(m) {}

			inline CMatrix3x2(__m128 m1, __m128 m2) : m128_1(m1), m128_2(m2) {}

			inline ~CMatrix3x2() {}
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
					float m21;
					float m31;

					float mx1;

					float m12;
					float m22;
					float m32;

				};

				struct {

					CVector3 c1;

					CVector3 c2;

				};

			};
#else

#endif



			/**
			 *	Methods
			 */
#ifdef __AVX__
		public:
			CMatrix2x3 Transpose() const;
			Matrix3x2  ToRMatrix() const;
#else

#endif



			/**
			 *	Operators
			 */
#ifdef __AVX__
		public:
			inline CVector3& operator[](unsigned char i) {
				return *((CVector3*)this + i);
			}
#else

#endif

		};

		

#ifdef __AVX__
		static inline CMatrix3x2 operator+(const CMatrix3x2& a, const CMatrix3x2& b) { return _mm256_add_ps(a.m256, b.m256); }
		static inline CMatrix3x2 operator-(const CMatrix3x2& a, const CMatrix3x2& b) { return _mm256_sub_ps(a.m256, b.m256); }
		static inline CMatrix3x2 operator*(const CMatrix3x2& a, float b) {
			__m256 mR = _mm256_set_ps(0, b, b, b, 0, b, b, b);
			return _mm256_mul_ps(a.m256, mR);
		}
		static inline CMatrix3x2 operator/(const CMatrix3x2& a, float b) {
			__m256 mR = _mm256_set_ps(0, b, b, b, 0, b, b, b);
			return _mm256_div_ps(a.m256, mR);
		}



		static inline void operator+=(CMatrix3x2& a, const CMatrix3x2& b) { a.m256 = _mm256_add_ps(a.m256, b.m256); }
		static inline void operator-=(CMatrix3x2& a, const CMatrix3x2& b) { a.m256 = _mm256_sub_ps(a.m256, b.m256); }
		static inline void operator*=(CMatrix3x2& a, float b) {
			__m256 mR = _mm256_set_ps(0, b, b, b, 0, b, b, b);
			a.m256 = _mm256_mul_ps(a.m256, mR);
		}
		static inline void operator/=(CMatrix3x2& a, float b) {
			__m256 mR = _mm256_set_ps(0, b, b, b, 0, b, b, b);
			a.m256 = _mm256_div_ps(a.m256, mR);
		}
#else

#endif

	}

}