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

		struct Matrix3x3 {

			/**
			 *	Constructors And Destructor
			 */
#ifdef __AVX__
		public:
			inline Matrix3x3(float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33) : 
				m256(_mm256_set_ps(0, m23, m22, m21, 0, m13, m12, m11)),
				m128(_mm_set_ps(0, m13, m12, m11))
			{}

			inline Matrix3x3() : Matrix3x3(m256_0_0_0_0_0_0_0_0, m128_0_0_0_0) {}

			inline Matrix3x3(const Matrix3x3& a) : Matrix3x3(a.m256, a.m128) {}

			inline Matrix3x3(__m256 m1, __m128 m2) : m256(m1), m128(m2) {}

			inline ~Matrix3x3() {}
#else



#endif



			/**
			 *	Properties
			 */
#ifdef __AVX__
		public:
			union {
				struct {
					__m256 m256;
					__m128 m128;
				};

				struct {

					float m11;
					float m12;
					float m13;

					float m1x;

					float m21;
					float m22;
					float m23;

					float m2x;

					float m31;
					float m32;
					float m33;

				};

				struct {

					Vector3 r1;

					Vector3 r2;

					Vector3 r3;

				};

			};
#else



#endif



			/**
			 *	Operators
			 */
		public:
			inline Vector3& operator[](unsigned char i) {
				return *((Vector3*)((char*)this + i * 4));
			}

		};

	}

}