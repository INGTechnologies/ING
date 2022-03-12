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

		struct CMatrix4x3 {

			/**
			 *	Constructors And Destructor
			 */
#ifdef __AVX__
		public:
			inline CMatrix4x3(float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33, float m41, float m42, float m43) : 
				m256_1(_mm256_set_ps(m42, m32, m22, m12, m41, m31, m21, m11)),
				m256_2(_mm256_set_ps(0, 0, 0, 0, m43, m33, m23, m13))
			{}

			inline CMatrix4x3() : CMatrix4x3(m256_0_0_0_0_0_0_0_0, m256_0_0_0_0_0_0_0_0) {}

			inline CMatrix4x3(const CMatrix4x3& a) : CMatrix4x3(a.m256_1, a.m256_2) {}

			inline CMatrix4x3(__m256 m1, __m256 m2) : m256_1(m1), m256_2(m2) {}

			inline CMatrix4x3(__m128 m1, __m128 m2, __m128 m3, __m128 m4) : m128_1(m1), m128_2(m2), m128_3(m3), m128_4(m4){}

			inline ~CMatrix4x3() {}
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
					float m41;

					float m12;
					float m22;
					float m32;
					float m42;

					float m13;
					float m23;
					float m33;
					float m43;

				};

				struct {

					CVector4 c1;

					CVector4 c2;

					CVector4 c3;

				};

			};
#else



#endif



			/**
			 *	Methods
			 */
#ifdef __AVX__
		public:
			CMatrix3x4 Transpose() const;
			Matrix4x3  ToRMatrix() const;
#else



#endif



			/**
			 *	Operators
			 */
#ifdef __AVX__
		public:
			inline CVector4& operator[](unsigned char i) {
				return *((CVector4*)this + i);
			}
#else



#endif

		};



		/**
		 *	Constants
		 */
#ifdef __AVX__
		
#else

#endif



		 /**
		  *	Operators
		  */
#ifdef __AVX__
		static inline CMatrix4x3 operator+(const CMatrix4x3& a, const CMatrix4x3& b) { return CMatrix4x3(_mm256_add_ps(a.m256_1, b.m256_1), _mm256_add_ps(a.m256_2, b.m256_2)); }
		static inline CMatrix4x3 operator-(const CMatrix4x3& a, const CMatrix4x3& b) { return CMatrix4x3(_mm256_sub_ps(a.m256_1, b.m256_1), _mm256_sub_ps(a.m256_2, b.m256_2)); }
		static inline CMatrix4x3 operator*(const CMatrix4x3& a, float b) {

			__m256 mR;
			mR.m256_f32[0] = b;
			mR = _mm256_permutevar8x32_ps(mR, _M256_FP0_TO_ALL);

			return CMatrix4x3(_mm256_mul_ps(a.m256_1, mR), _mm256_mul_ps(a.m256_2, mR));
		}
		static inline CMatrix4x3 operator/(const CMatrix4x3& a, float b) {

			__m256 mR;
			mR.m256_f32[0] = b;
			mR = _mm256_permutevar8x32_ps(mR, _M256_FP0_TO_ALL);

			return CMatrix4x3(_mm256_div_ps(a.m256_1, mR), _mm256_div_ps(a.m256_2, mR));
		}



		static inline void operator+=(CMatrix4x3& a, const CMatrix4x3& b) { a.m256_1 = _mm256_add_ps(a.m256_1, b.m256_1); a.m256_2 = _mm256_add_ps(a.m256_2, b.m256_2); }
		static inline void operator-=(CMatrix4x3& a, const CMatrix4x3& b) { a.m256_1 = _mm256_sub_ps(a.m256_1, b.m256_1); a.m256_2 = _mm256_sub_ps(a.m256_2, b.m256_2); }
		static inline void operator*=(CMatrix4x3& a, float b) {

			__m256 mR;
			mR.m256_f32[0] = b;
			mR = _mm256_permutevar8x32_ps(mR, _M256_FP0_TO_ALL);

			a.m256_1 = _mm256_mul_ps(a.m256_1, mR);
			a.m256_2 = _mm256_mul_ps(a.m256_2, mR);
		}
		static inline void operator/=(CMatrix4x3& a, float b) {

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