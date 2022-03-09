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

		struct Matrix2x4 {

			/**
			 *	Constructors And Destructor
			 */
#ifdef __AVX__
		public:
			inline Matrix2x4(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24) : m256(_mm256_set_ps(m24, m23, m22, m21, m14, m13, m12, m11)) {}

			inline Matrix2x4() : Matrix2x4(m256_0_0_0_0_0_0_0_0) {}

			inline Matrix2x4(const Matrix2x4& a) : m256(a.m256) {}

			inline Matrix2x4(__m256 m) : m256(m) {}

			inline ~Matrix2x4() {}
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
					float m13;
					float m14;

					float m21;
					float m22;
					float m23;
					float m24;

				};

				struct {

					Vector4 r1;

					Vector4 r2;

				};

			};
#else



#endif



			/**
			 *	Operators
			 */
		public:
			inline Vector4& operator[](unsigned char i) {
				return *((Vector4*)this + i);
			}

		};

	}

}