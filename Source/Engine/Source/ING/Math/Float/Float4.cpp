
/**
 *	Include Header
 */
#include "Float4.h"



namespace ING {

	namespace Math {

		/**
		 *	Constructors And Destructor
		 */
		Float4::Float4(Vector4 v) {

			factors[0] = v.w;

			factors[1] = v.x;

			factors[2] = v.y;

			factors[3] = v.z;

		}

		Float4::Float4(Vector3 v) {

			factors[0] = 0;

			factors[1] = v.x;

			factors[2] = v.y;

			factors[3] = v.z;

		}

		Float4::Float4(Vector2 v) {

			factors[0] = 0;

			factors[1] = v.x;

			factors[2] = v.y;

			factors[3] = 0;

		}

		Float4::Float4(float v) {

			factors[0] = 0;

			factors[1] = v;

			factors[2] = 0;

			factors[3] = 0;

		}

		Float4::Float4() : Float4(0) {



		}

		Float4::~Float4() {



		}



		/**
		 *	Operators
		 */
		Float4 Float4::operator*(Float4 next) {

			float w1 = factors[0];
			float x1 = factors[1];
			float y1 = factors[2];
			float z1 = factors[3];

			float w2 = next.factors[0];
			float x2 = next.factors[1];
			float y2 = next.factors[2];
			float z2 = next.factors[3];

			return Vector4(

				x1 * w2 * ( 1)   +   y1 * z2 * ( 1)   +   z1 * y2 * (-1)   +   w1 * x2,

				x1 * z2 * (-1)   +   y1 * w2 * ( 1)   +   z1 * x2 * ( 1)   +   w1 * y2,

				x1 * y2 * ( 1)   +   y1 * x2 * (-1)   +   z1 * w2 * ( 1)   +   w1 * z2,

				x1 * x2 * (-1)   +   y1 * y2 * (-1)   +   z1 * z2 * (-1)   +   w1 * w2
				
			);
		}

	}

}