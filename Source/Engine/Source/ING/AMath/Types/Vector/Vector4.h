#pragma once



#include <ING/Utils/Intrinsics/Intrinsics.h>



namespace ING {

	namespace AMath {

		#include "VectorDeclares.h"



		union Vector4 {

			/**
			 *	Constructors And Destructor
			 */
		public:
			Vector4(float x, float y, float z, float w) {

				this->x = x;
				this->y = y;
				this->z = z;
				this->w = w;

			}

			Vector4(__m128 m128) {

				this->m128 = m128;

			}

			~Vector4() {



			}


			/**
			 *	Properties
			 */
		public:
			__m128 m128;

			struct {

				float x;
				float y;
				float z;
				float w;

			};


			/**
			 *	Operators
			 */
		public:
			Vector4 operator+(Vector4 a) {

				return _mm_add_ps(m128,a.m128);

			}
			Vector4 operator+(Vector4 a) {

				return _mm_add_ps(m128,a.m128);

			}

		};

	}

}