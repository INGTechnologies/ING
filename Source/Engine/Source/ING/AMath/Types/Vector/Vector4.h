#pragma once



#include <ING/Utils/Intrinsics/Intrinsics.h>



#include "VectorDeclares.h"



#include <math.h>



namespace ING {

	namespace AMath {

		struct Vector4 {

			/**
			 *	Constructors And Destructor
			 */
		public:
			inline Vector4(float x, float y, float z, float w) : m128(_mm_set_ps(w,z,y,x)) {}

			inline Vector4() : Vector4(0,0,0,0) {}

			inline Vector4(__m128 m) : m128(m) {}

			inline ~Vector4() {}



			/**
			 *	Properties
			 */
		public:
			__m128 m128;

			struct {

				float x, y, z, w;

			};



			/**
			 *	Methods
			 */
		public:
			static float		DotProduct(const Vector4& v1, const Vector4& v2) {

				__m128 mR = _mm_mul_ps(v1.m128, v2.m128);

				return mR.m128_f32[0] + mR.m128_f32[1] + mR.m128_f32[2] + mR.m128_f32[3];

			}

			float				Length() {

				return sqrt(x*x + y*y + z*z +w*w);

			}



			/**
			 *	Operators
			 */
		public:
			inline float&	operator[](unsigned char i) {

				return *(((float*)this) + i);
			}

		};

		static inline Vector4 operator+(Vector4& a, Vector4& b) { return _mm_add_ps(a.m128, a.m128); }

		static inline Vector4 operator-(Vector4& a, Vector4& b) { return _mm_sub_ps(a.m128, b.m128); }

		static inline Vector4 operator*(Vector4& a, float b)	{ return _mm_mul_ps(a.m128, _mm_set1_ps(b)); }

		static inline Vector4 operator/(Vector4& a, float b)	{ return _mm_div_ps(a.m128, _mm_set1_ps(b)); }

	}

}