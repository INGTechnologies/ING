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



namespace ING {

	namespace AMath {

		struct CVector3 {

			/**
			 *	Constructors And Destructor
			 */
		public:
			inline CVector3(float x, float y, float z) : m128(_mm_set_ps(0,z,y,x)) {}

			inline CVector3() : CVector3(m128_0_0_0_0) {}

			inline CVector3(const CVector3& a) : m128(a.m128) {}

			inline CVector3(__m128 m) : m128(m) {}

			CVector3(const Math::CVector3& m);

			inline ~CVector3() {}



			/**
			 *	Properties
			 */
		public:
			union {
				__m128 m128;

				struct {

					float x, y, z;

				};
			};



			/**
			 *	Methods
			 */
		public:

			static float		DotProduct(const CVector3& v1, const CVector3& v2) {

				__m128 mR = _mm_mul_ps(v1.m128, v2.m128);

				mR = _mm_hadd_ps(mR, m128_0_0_0_0);

				return _mm_hadd_ps(mR, mR).m128_f32[0];

			}

			float				Length() const {

				__m128 mR = _mm_mul_ps(m128, m128);

				mR = _mm_hadd_ps(mR, m128_0_0_0_0);

				return sqrt(_mm_hadd_ps(mR, mR).m128_f32[0]);

			}

			Vector3				Transpose() const;



			/**
			 *	Operators
			 */
		public:
			inline float& operator[](unsigned char i) {
				return *(((float*)this) + i);
			}
			void			operator=(const CVector3& a) {
			
				m128 = a.m128;
			
			}
			void			operator=(__m128 m128) {

				this->m128 = m128;

			}
			void			operator=(const Math::CVector3& mathV3) {

				memcpy(this,&mathV3,12);

			}

		};



		static inline CVector3 operator+(const CVector3& a, const CVector3& b)			{ return _mm_add_ps(a.m128, b.m128); }

		static inline CVector3 operator-(const CVector3& a, const CVector3& b)			{ return _mm_sub_ps(a.m128, b.m128); }

		static inline CVector3 operator*(const CVector3& a, float b)					{ return _mm_set_ps(0, a.z * b, a.y * b, a.x * b); }

		static inline CVector3 operator/(const CVector3& a, float b)					{ return _mm_set_ps(0, a.z / b, a.y / b, a.x / b); }


		static inline CVector3 operator+(const CVector3& a)								{ return a.m128; }
		static inline CVector3 operator-(const CVector3& a)								{ return _mm_mul_ps(a.m128, m128_i1_i1_i1_i1); }



		static inline void    operator+=(CVector3& a, const CVector3& b)				{ a.m128 = _mm_add_ps(a.m128, a.m128); }

		static inline void    operator-=(CVector3& a, const CVector3& b)				{ a.m128 = _mm_sub_ps(a.m128, b.m128); }

		static inline void    operator*=(CVector3& a, float b)							{ a.m128 = _mm_set_ps(0, a.z * b, a.y * b, a.x * b); }

		static inline void    operator/=(CVector3& a, float b)							{ a.m128 = _mm_set_ps(0, a.z / b, a.y / b, a.x / b); }

	}

}