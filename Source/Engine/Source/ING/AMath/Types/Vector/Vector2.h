#pragma once



#include <ING/Utils/Intrinsics/Intrinsics.h>



#include "VectorDeclares.h"



namespace ING {

	namespace AMath {

		struct Vector2 {

			/**
			 *	Constructors And Destructor
			 */
		public:
			Vector2(float x, float y) : m128(_mm_set_ps(0,0,y,x)) {}

			Vector2() : Vector2(0,0) {}

			Vector2(__m128 m) : m128(m) {}

			~Vector2() {}



			/**
			 *	Properties
			 */
		public:
			union {

				__m128 m128;

				struct {

					float x, y;

				};

			};



			/**
			 *	Methods
			 */
		public:
			static float	DotProduct		(Vector2 v1, Vector2 v2);



			/**
			 *	Operators
			 */
		public:
			Vector2 operator+(Vector2& a) { return _mm_add_ps(m128,a.m128); }

			Vector2 operator-(Vector2& a) { return _mm_sub_ps(m128,a.m128); }

			Vector2 operator*(float a) { return _mm_mul_ps(m128,_mm_set1_ps(a)); }

			Vector2 operator/(float a) { return _mm_div_ps(m128, _mm_set1_ps(a)); }

			float&	operator[](unsigned char i) {

				return *(((float*)this) + i);
			}

		};

	}

}