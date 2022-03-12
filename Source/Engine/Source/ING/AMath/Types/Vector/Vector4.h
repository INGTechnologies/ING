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
 *	Declares Vectors
 */
#include "VectorDeclares.h"



namespace ING {

	namespace AMath {

		struct Vector4 {

			/**
			 *	Constructors And Destructor
			 */
		public:
			inline Vector4(float x, float y, float z, float w) : m128(_mm_set_ps(w,z,y,x)) {}

			inline Vector4() : Vector4(m128_0_0_0_0) {}

			inline Vector4(Vector4& a) : m128(a.m128) {}

			inline Vector4(__m128 m) : m128(m) {}

			inline ~Vector4() {}



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
			static float		DotProduct(const Vector4& v1, const Vector4& v2) {

				__m128 mR = _mm_mul_ps(v1.m128, v2.m128);

				mR = _mm_hadd_ps(mR, m128_0_0_0_0);

				return _mm_hadd_ps(mR, mR).m128_f32[0];

			}

			float				Length() const {

				__m128 mR = _mm_mul_ps(m128, m128);

				mR = _mm_hadd_ps(mR, m128_0_0_0_0);

				return sqrt(_mm_hadd_ps(mR, mR).m128_f32[0]);

			}

			CVector4			Transpose() const;



			/**
			 *	Operators
			 */
		public:
			inline float& operator[](unsigned char i) {
				return *(((float*)this) + i);
			}
			void			operator=(const Vector4& a) { 
			
				m128 = a.m128;
			
			}
			void			operator=(__m128 m128) {

				this->m128 = m128;

			}

		};



		static inline Vector4 operator+(const Vector4& a, const Vector4& b)	{ return _mm_add_ps(a.m128, a.m128); }

		static inline Vector4 operator-(const Vector4& a, const Vector4& b)	{ return _mm_sub_ps(a.m128, b.m128); }

		static inline Vector4 operator*(const Vector4& a, float b)			{ return _mm_set_ps(a.w * b, a.z * b, a.y * b, a.x * b); }

		static inline Vector4 operator/(const Vector4& a, float b)			{ return _mm_set_ps(a.w / b, a.z / b, a.y / b, a.x / b); }



		static inline Vector4 operator+(const Vector4& a)					{ return a.m128; }
		static inline Vector4 operator-(const Vector4& a)					{ return _mm_mul_ps(a.m128, m128_i1_i1_i1_i1); }



		static inline void    operator+=(Vector4& a, const Vector4& b)		{ a.m128 = _mm_add_ps(a.m128, a.m128); }

		static inline void    operator-=(Vector4& a, const Vector4& b)		{ a.m128 = _mm_sub_ps(a.m128, b.m128); }

		static inline void    operator*=(Vector4& a, float b)				{ a.m128 = _mm_set_ps(a.w * b, a.z * b, a.y * b, a.x * b); }

		static inline void    operator/=(Vector4& a, float b)				{ a.m128 = _mm_set_ps(a.w / b, a.z / b, a.y / b, a.x / b); }



		static inline float   operator*(const Vector4& a, const CVector4&  b);
		static inline Vector2 operator*(const Vector4& a, const Matrix4x2& b);
		static inline Vector3 operator*(const Vector4& a, const Matrix4x3& b);

		static inline Vector4 operator*(const Vector4& a, const CMatrix4x4& b);

	}

}