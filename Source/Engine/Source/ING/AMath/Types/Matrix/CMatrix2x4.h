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

		struct CMatrix2x4 {

			/**
			 *	Constructors And Destructor
			 */
#ifdef __AVX__
		public:
			inline CMatrix2x4(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24) : m256(_mm256_set_ps(m24, m14, m23, m13, m22, m12, m21, m11)) {}

			inline CMatrix2x4() : CMatrix2x4(m256_0_0_0_0_0_0_0_0) {}

			inline CMatrix2x4(const CMatrix2x4& a) : m256(a.m256) {}

			inline CMatrix2x4(__m256 m) : m256(m) {}

			inline CMatrix2x4(__m128 m1, __m128 m2) : m128_1(m1), m128_2(m2) {}

			inline ~CMatrix2x4() {}
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
					float m14;

					float m21;
					float m22;
					float m23;
					float m24;

				};

				struct {

					CVector2 c1;

					CVector2 c2;

					CVector2 c3;

					CVector2 c4;

				};

			};
#else

#endif



			/**
			 *	Methods
			 */
#ifdef __AVX__
		public:
			CMatrix4x2 Transpose() const;
			Matrix2x4  ToRMatrix() const;
#else

#endif



			/**
			 *	Operators
			 */
#ifdef __AVX__
		public:
			inline CVector2& operator[](unsigned char i) {
				return *((CVector2*)this + i);
			}
#else

#endif

		};



#ifdef __AVX__
		static inline CMatrix2x4 operator+(const CMatrix2x4& a, const CMatrix2x4& b) { return _mm256_add_ps(a.m256, b.m256); }
		static inline CMatrix2x4 operator-(const CMatrix2x4& a, const CMatrix2x4& b) { return _mm256_sub_ps(a.m256, b.m256); }
		static inline CMatrix2x4 operator*(const CMatrix2x4& a, float b) {

			__m256 mR;
			mR.m256_f32[0] = b;
			mR = _mm256_permutevar8x32_ps(mR, _M256_FP0_TO_ALL);
			return _mm256_mul_ps(a.m256, mR);
		}
		static inline CMatrix2x4 operator/(const CMatrix2x4& a, float b) {

			__m256 mR;
			mR.m256_f32[0] = b;
			mR = _mm256_permutevar8x32_ps(mR, _M256_FP0_TO_ALL);

			return _mm256_div_ps(a.m256, mR);
		}



		static inline void operator+=(CMatrix2x4& a, const CMatrix2x4& b) { a.m256 = _mm256_add_ps(a.m256, b.m256); }
		static inline void operator-=(CMatrix2x4& a, const CMatrix2x4& b) { a.m256 = _mm256_sub_ps(a.m256, b.m256); }
		static inline void operator*=(CMatrix2x4& a, float b) {

			__m256 mR;
			mR.m256_f32[0] = b;
			mR = _mm256_permutevar8x32_ps(mR, _M256_FP0_TO_ALL);

			a.m256 = _mm256_mul_ps(a.m256, mR);
		}
		static inline void operator/=(CMatrix2x4& a, float b) {

			__m256 mR;
			mR.m256_f32[0] = b;
			mR = _mm256_permutevar8x32_ps(mR, _M256_FP0_TO_ALL);

			a.m256 = _mm256_div_ps(a.m256, mR);
		}
#else

#endif

	}

}