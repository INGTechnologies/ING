#pragma once



#include <ING/Utils/Intrinsics/Intrinsics.h>



#include "VectorDeclares.h"



namespace ING {

	namespace AMath {

		struct Vector3 {

			/**
			 *	Constructors And Destructor
			 */
		public:
			Vector3(float x, float y, float z) : m128(_mm_set_ps(0,z,y,x)) {}

			Vector3() : Vector3(0,0,0) {}

			Vector3(__m128 m) : m128(m) {}

			~Vector3() {}



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
			static float	DotProduct		(Vector3 v1, Vector3 v2);



			/**
			 *	Operators
			 */
		public:
			Vector3 operator+(Vector3& a) { return _mm_add_ps(m128,a.m128); }

			Vector3 operator-(Vector3& a) { return _mm_sub_ps(m128,a.m128); }

			Vector3 operator*(float a) { return _mm_mul_ps(m128,_mm_set1_ps(a)); }

			Vector3 operator/(float a) { return _mm_div_ps(m128, _mm_set1_ps(a)); }

			float&	operator[](unsigned char i) {

				return *(((float*)this) + i);
			}

		};

	}

}