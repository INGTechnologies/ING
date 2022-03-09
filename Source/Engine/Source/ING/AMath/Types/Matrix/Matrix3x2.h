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



namespace ING {

	namespace AMath {

		struct Matrix3x2 {

			/**
			 *	Constructors And Destructor
			 */
#ifdef __AVX__
		public:
			inline Matrix3x2(float m11, float m12, float m21, float m22, float m31, float m32) : m256(_mm256_set_ps(0, 0, m32, m31, m22, m21, m12, m11)) {}

			inline Matrix3x2() : Matrix3x2(m256_0_0_0_0_0_0_0_0) {}

			inline Matrix3x2(const Matrix3x2& a) : m256(a.m256) {}

			inline Matrix3x2(__m256 m) : m256(m) {}

			inline ~Matrix3x2() {}
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

					float m11;
					float m12;

					float m21;
					float m22;

					float m31;
					float m32;

				};

				struct {

					Vector2 r1;

					Vector2 r2;

					Vector2 r3;

				};

			};
#else



#endif



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