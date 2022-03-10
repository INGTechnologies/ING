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

		struct Matrix2x2 {

			/**
			 *	Constructors And Destructor
			 */
		public:
			inline Matrix2x2(float m11, float m12, float m21, float m22) : m128(_mm_set_ps(m11, m12, m21, m22)) {}

			inline Matrix2x2() : Matrix2x2(m128_0_0_0_0) {}

			inline Matrix2x2(Vector2 r1, Vector2 r2) : Matrix2x2(r1.x, r1.y, r2.x, r2.y) {}

			inline Matrix2x2(CVector2 r1, CVector2 r2) : Matrix2x2(r1.x, r2.x, r1.y, r2.y) {}

			inline Matrix2x2(const Matrix2x2& a) : m128(a.m128) {}

			inline Matrix2x2(__m128 m) : m128(m) {}

			inline ~Matrix2x2() {}



			/**
			 *	Properties
			 */
		public:
			union {
				__m128 m128;

				struct {

					float m11;
					float m12;
					float m21;
					float m22;

				};

				struct {

					Vector2 r1;
					Vector2 r2;

				};

			};



			/**
			 *	Operators
			 */
#ifdef __AVX__ 
		public:
			inline Vector2& operator[](unsigned char i) {
				return *((Vector2*)this + i);
			}
#else



#endif

		};



#ifdef __AVX__
		static inline Matrix2x2 operator+(const Matrix2x2& a, const Matrix2x2& b) { return _mm_add_ps(a.m128, b.m128); }
		static inline Matrix2x2 operator-(const Matrix2x2& a, const Matrix2x2& b) { return _mm_sub_ps(a.m128, b.m128); }
		static inline Matrix2x2 operator*(const Matrix2x2& a, float b) {
			__m128 mR = _mm_set_ps(b, b, b, b);
			return _mm_mul_ps(a.m128, mR);
		}
		static inline Matrix2x2 operator/(const Matrix2x2& a, float b) {
			__m128 mR = _mm_set_ps(b, b, b, b);
			return _mm_div_ps(a.m128, mR);
		}



		static inline void operator+=(Matrix2x2& a, const Matrix2x2& b) { a.m128 = _mm_add_ps(a.m128, b.m128); }
		static inline void operator-=(Matrix2x2& a, const Matrix2x2& b) { a.m128 = _mm_sub_ps(a.m128, b.m128); }
		static inline void operator*=(Matrix2x2& a, float b) {
			__m128 mR = _mm_set_ps(b, b, b, b);
			a.m128 = _mm_mul_ps(a.m128, mR);
		}
		static inline void operator/=(Matrix2x2& a, float b) {
			__m128 mR = _mm_set_ps(b, b, b, b);
			a.m128 = _mm_div_ps(a.m128, mR);
		}
#else



#endif

	}

}