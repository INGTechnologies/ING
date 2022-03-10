#pragma once

/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Declares Vectors
 */
#include "VectorDeclares.h"



namespace ING {

	namespace AMath {

		struct CVector4 {

			/**
			 *	Constructors And Destructor
			 */
		public:
			inline CVector4(float x, float y, float z, float w) : m128(_mm_set_ps(w,z,y,x)) {}

			inline CVector4() : CVector4(m128_0_0_0_0) {}

			inline CVector4(CVector4& a) : m128(a.m128) {}

			inline CVector4(__m128 m) : m128(m) {}

			inline ~CVector4() {}



			/**
			 *	Properties
			 */
		public:
			union {
				__m128 m128;

				struct {

					float x, y, z, w;

				};
			};



			/**
			 *	Methods
			 */
		public:
			static float		DotProduct(const CVector4& v1, const CVector4& v2) {

				__m128 mR = _mm_mul_ps(v1.m128, v2.m128);

				return mR.m128_f32[0] + mR.m128_f32[1] + mR.m128_f32[2] + mR.m128_f32[3];

			}

			float				Length() const {

				return sqrt(x*x + y*y + z*z +w*w);

			}

			Vector4				Transpose() const;



			/**
			 *	Operators
			 */
		public:
			inline float& operator[](unsigned char i) {
				return *(((float*)this) + i);
			}
			void			operator=(const CVector4& a) {
			
				m128 = a.m128;
			
			}
			void			operator=(__m128 m128) {

				this->m128 = m128;

			}

		};



		static inline CVector4 operator+(const CVector4& a, const CVector4& b)	{ return _mm_add_ps(a.m128, a.m128); }

		static inline CVector4 operator-(const CVector4& a, const CVector4& b)	{ return _mm_sub_ps(a.m128, b.m128); }

		static inline CVector4 operator*(const CVector4& a, float b)			{ return _mm_set_ps(a.w * b, a.z * b, a.y * b, a.x * b); }

		static inline CVector4 operator/(const CVector4& a, float b)			{ return _mm_set_ps(a.w / b, a.z / b, a.y / b, a.x / b); }



		static inline CVector4 operator+(const CVector4& a)						{ return a.m128; }
		static inline CVector4 operator-(const CVector4& a)						{ return _mm_mul_ps(a.m128, m128_i1_i1_i1_i1); }



		static inline void    operator+=(CVector4& a, const CVector4& b)		{ a.m128 = _mm_add_ps(a.m128, a.m128); }

		static inline void    operator-=(CVector4& a, const CVector4& b)		{ a.m128 = _mm_sub_ps(a.m128, b.m128); }

		static inline void    operator*=(CVector4& a, float b)					{ a.m128 = _mm_set_ps(a.w * b, a.z * b, a.y * b, a.x * b); }

		static inline void    operator/=(CVector4& a, float b)					{ a.m128 = _mm_set_ps(a.w / b, a.z / b, a.y / b, a.x / b); }

	}

}