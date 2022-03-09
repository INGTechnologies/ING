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

		struct Matrix2x3 {

			/**
			 *	Constructors And Destructor
			 */
#ifdef __AVX__
		public:
			inline Matrix2x3(float m11, float m12, float m13, float m21, float m22, float m23) : m256(_mm256_set_ps(0, m23, m22, m21, 0, m13, m12, m11)) {}

			inline Matrix2x3() : Matrix2x3(m256_0_0_0_0_0_0_0_0) {}

			inline Matrix2x3(const Matrix2x3& a) : m256(a.m256) {}

			inline Matrix2x3(__m256 m) : m256(m) {}

			inline ~Matrix2x3() {}
#else



#endif



			/**
			 *	Properties
			 */
#ifdef __AVX2__
		public:
			union {
				__m256 m256;

				struct {

					float m11;
					float m12;
					float m13;

					float m1x;

					float m21;
					float m22;
					float m23;

					float m2x;

				};

				struct {

					Vector3 r1;

					Vector3 r2;

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