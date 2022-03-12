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

		struct CMatrix2x2 {

			/**
			 *	Constructors And Destructor
			 */
		public:
			inline CMatrix2x2(float m11, float m12, float m21, float m22) : m128(_mm_set_ps(m22, m21, m12, m11)) {}

			inline CMatrix2x2() : CMatrix2x2(m128_0_0_0_0) {}

			inline CMatrix2x2(CVector2 r1, CVector2 r2) : CMatrix2x2(r1.x, r1.y, r2.x, r2.y) {}

			inline CMatrix2x2(const CMatrix2x2& a) : m128(a.m128) {}

			inline CMatrix2x2(__m128 m) : m128(m) {}

			inline ~CMatrix2x2() {}



			/**
			 *	Properties
			 */
		public:
			union {
				__m128 m128;

				struct {

					float m11;
					float m21;
					float m12;
					float m22;

				};

				struct {

					CVector2 c1;
					CVector2 c2;

				};

			};



			/**
			 *	Methods
			 */
		public:
			CMatrix2x2 Transpose() const;
			Matrix2x2  ToRMatrix() const;



			/**
			 *	Operators
			 */
		public:
			inline CVector2& operator[](unsigned char i) {
				return *((CVector2*)this + i);
			}

		};



		static inline CMatrix2x2 operator+(const CMatrix2x2& a, const CMatrix2x2& b) { return _mm_add_ps(a.m128, b.m128); }
		static inline CMatrix2x2 operator-(const CMatrix2x2& a, const CMatrix2x2& b) { return _mm_sub_ps(a.m128, b.m128); }
		static inline CMatrix2x2 operator*(const CMatrix2x2& a, float b) {
			__m128 mR = _mm_set_ps(b, b, b, b);
			return _mm_mul_ps(a.m128, mR);
		}
		static inline CMatrix2x2 operator/(const CMatrix2x2& a, float b) {
			__m128 mR = _mm_set_ps(b, b, b, b);
			return _mm_div_ps(a.m128, mR);
		}



		static inline void operator+=(CMatrix2x2& a, const CMatrix2x2& b) { a.m128 = _mm_add_ps(a.m128, b.m128); }
		static inline void operator-=(CMatrix2x2& a, const CMatrix2x2& b) { a.m128 = _mm_sub_ps(a.m128, b.m128); }
		static inline void operator*=(CMatrix2x2& a, float b) {
			__m128 mR = _mm_set_ps(b, b, b, b);
			a.m128 = _mm_mul_ps(a.m128, mR);
		}
		static inline void operator/=(CMatrix2x2& a, float b) {
			__m128 mR = _mm_set_ps(b, b, b, b);
			a.m128 = _mm_div_ps(a.m128, mR);
		}

	}

}