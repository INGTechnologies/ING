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
		public:
			inline Vector2& operator[](unsigned char i) {
				return *((Vector2*)this + i);
			}

		};

	}

}