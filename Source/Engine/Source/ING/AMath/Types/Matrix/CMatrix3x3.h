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

		struct CMatrix3x3 {

			/**
			 *	Constructors And Destructor
			 */
#ifdef __AVX__
		public:
			inline CMatrix3x3(float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33) : 
				m256_1(_mm256_set_ps(0, m23, m22, m21, 0, m13, m12, m11)),
				m256_2(_mm256_set_ps(0,0,0,0,0, m33, m32, m31))
			{}

			inline CMatrix3x3() : CMatrix3x3(m256_0_0_0_0_0_0_0_0, m256_0_0_0_0_0_0_0_0) {}

			inline CMatrix3x3(const CMatrix3x3& a) : CMatrix3x3(a.m256_1, a.m256_2) {}

			inline CMatrix3x3(__m256 m1, __m256 m2) : m256_1(m1), m256_2(m2) {}

			inline CMatrix3x3(__m128 m1, __m128 m2, __m128 m3, __m128 m4) : m128_1(m1), m128_2(m2), m128_3(m3), m128_4(m4) {}

			inline ~CMatrix3x3() {}
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
					float m21;
					float m31;
					float mx1;

					float m12;
					float m22;
					float m32;
					float mx2;

					float m13;
					float m23;
					float m33;

				};

				struct {

					CVector3 c1;

					CVector3 c2;

					CVector3 c3;

				};

			};
#else



#endif



			 /**
			  *	Methods
			  */
#ifdef __AVX__
		public:
			CMatrix3x3 Transpose() const;
			Matrix3x3  ToRMatrix() const;
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
		static inline CMatrix3x3 operator+(const CMatrix3x3& a, const CMatrix3x3& b) { return CMatrix3x3(_mm256_add_ps(a.m256_1, b.m256_1), _mm256_add_ps(a.m256_2, b.m256_2)); }
		static inline CMatrix3x3 operator-(const CMatrix3x3& a, const CMatrix3x3& b) { return CMatrix3x3(_mm256_sub_ps(a.m256_1, b.m256_1), _mm256_sub_ps(a.m256_2, b.m256_2)); }
		static inline CMatrix3x3 operator*(const CMatrix3x3& a, float b) {

			__m256 mR;
			mR.m256_f32[0] = b;
			mR = _mm256_permutevar8x32_ps(mR, _M256_FP0_TO_ALL);

			return CMatrix3x3(_mm256_mul_ps(a.m256_1, mR), _mm256_mul_ps(a.m256_2, mR));
		}
		static inline CMatrix3x3 operator/(const CMatrix3x3& a, float b) {

			__m256 mR;
			mR.m256_f32[0] = b;
			mR = _mm256_permutevar8x32_ps(mR, _M256_FP0_TO_ALL);

			return CMatrix3x3(_mm256_div_ps(a.m256_1, mR), _mm256_div_ps(a.m256_2, mR));
		}



		static inline void operator+=(CMatrix3x3& a, const CMatrix3x3& b) { a.m256_1 = _mm256_add_ps(a.m256_1, b.m256_1); a.m256_2 = _mm256_add_ps(a.m256_2, b.m256_2); }
		static inline void operator-=(CMatrix3x3& a, const CMatrix3x3& b) { a.m256_1 = _mm256_sub_ps(a.m256_1, b.m256_1); a.m256_2 = _mm256_sub_ps(a.m256_2, b.m256_2); }
		static inline void operator*=(CMatrix3x3& a, float b) {

			__m256 mR;
			mR.m256_f32[0] = b;
			mR = _mm256_permutevar8x32_ps(mR, _M256_FP0_TO_ALL);

			a.m256_1 = _mm256_mul_ps(a.m256_1, mR);
			a.m256_2 = _mm256_mul_ps(a.m256_2, mR);
		}
		static inline void operator/=(CMatrix3x3& a, float b) {

			__m256 mR;
			mR.m256_f32[0] = b;
			mR = _mm256_permutevar8x32_ps(mR, _M256_FP0_TO_ALL);

			a.m256_1 = _mm256_div_ps(a.m256_1, mR);
			a.m256_2 = _mm256_div_ps(a.m256_2, mR);
		}
#else



#endif

	}

}