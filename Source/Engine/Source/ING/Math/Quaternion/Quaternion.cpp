
/**
 *	Include Header
 */
#include "Quaternion.h"



/**
 *	Include Complex
 */
#include <ING/Math/Complex/Complex.h>



namespace ING {

	namespace Math {

		/**
		 *	Operators
		 */
		Vector3 Quaternion::operator*(Vector3 next) {

			/* Find q (Quaternion In Complex4 Type)*/
			Complex4 q = *this;

			/* Find Inverted q (Inverted Quaternion In Complex4 Type)*/
			Complex4 invQ = *this;
			invQ.factors[1] = -invQ.factors[1];
			invQ.factors[2] = -invQ.factors[2];
			invQ.factors[3] = -invQ.factors[3];

			/* Find v (Position In Complex4 Type)*/
			Complex4 v = next;

			Complex4 result = q * v * invQ;

			return Vector3(result.factors[1], result.factors[2], result.factors[3]);
		}

	}

}