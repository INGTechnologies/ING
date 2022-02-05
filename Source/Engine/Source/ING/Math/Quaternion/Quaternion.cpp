
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
		 *	Methods
		 */
		Quaternion Quaternion::Euler(Vector3 eulerAngles) {

			Quaternion result;

			float cy = cos(eulerAngles.z * 0.5f);
			float sy = sin(eulerAngles.z * 0.5f);
			float cp = cos(eulerAngles.y * 0.5f);
			float sp = sin(eulerAngles.y * 0.5f);
			float cr = cos(eulerAngles.x * 0.5f);
			float sr = sin(eulerAngles.x * 0.5f);

			result.w = cr * cp * cy + sr * sp * sy;
			result.x = sr * cp * cy - cr * sp * sy;
			result.y = cr * sp * cy + sr * cp * sy;
			result.z = cr * cp * sy - sr * sp * cy;

			return result;

		}



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