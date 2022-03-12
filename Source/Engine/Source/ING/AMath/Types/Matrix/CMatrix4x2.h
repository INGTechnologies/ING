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

		struct CMatrix4x2 {

			/**
			 *	Constructors And Destructor
			 */
#ifdef __AVX__
		public:
			inline CMatrix4x2(float m11, float m12, float m21, float m22, float m31, float m32, float m41, float m42) : m256(_mm256_set_ps(m42, m32, m22, m12, m41, m31, m21, m11)) {}

			inline CMatrix4x2() : CMatrix4x2(m256_0_0_0_0_0_0_0_0) {}

			inline CMatrix4x2(const CMatrix4x2& a) : m256(a.m256) {}

			inline CMatrix4x2(__m256 m) : m256(m) {}

			inline CMatrix4x2(__m128 m1, __m128 m2) : m128_1(m1), m128_2(m2) {}

			inline ~CMatrix4x2() {}
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
					float m41;

					float m12;
					float m22;
					float m32;
					float m42;

				};

				struct {

					CVector4 c1;

					CVector4 c2;

				};

			};
#else



#endif



			/**
			 *	Methods
			 */
#ifdef __AVX__
		public:
			CMatrix2x4 Transpose() const;
			Matrix4x2  ToRMatrix() const;
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



#ifdef __AVX__
		static inline CMatrix4x2 operator+(const CMatrix4x2& a, const CMatrix4x2& b) { return _mm256_add_ps(a.m256, b.m256); }
		static inline CMatrix4x2 operator-(const CMatrix4x2& a, const CMatrix4x2& b) { return _mm256_sub_ps(a.m256, b.m256); }
		static inline CMatrix4x2 operator*(const CMatrix4x2& a, float b) {
			__m256 mR = _mm256_set_ps(b, b, b, b, b, b, b, b);
			return _mm256_mul_ps(a.m256, mR);
		}
		static inline CMatrix4x2 operator/(const CMatrix4x2& a, float b) {
			__m256 mR = _mm256_set_ps(b, b, b, b, b, b, b, b);
			return _mm256_div_ps(a.m256, mR);
		}



		static inline void operator+=(CMatrix4x2& a, const CMatrix4x2& b) { a.m256 = _mm256_add_ps(a.m256, b.m256); }
		static inline void operator-=(CMatrix4x2& a, const CMatrix4x2& b) { a.m256 = _mm256_sub_ps(a.m256, b.m256); }
		static inline void operator*=(CMatrix4x2& a, float b) {

			__m256 mR;
			mR.m256_f32[0] = b;
			mR = _mm256_permutevar8x32_ps(mR, _M256_FP0_TO_ALL);

			a.m256 = _mm256_mul_ps(a.m256, mR);
		}
		static inline void operator/=(CMatrix4x2& a, float b) {

			__m256 mR;
			mR.m256_f32[0] = b;
			mR = _mm256_permutevar8x32_ps(mR, _M256_FP0_TO_ALL);

			a.m256 = _mm256_div_ps(a.m256, mR);
		}
#else



#endif

	}

}