#pragma once

/**
 *	Include Vector
 */
#include <ING/Math/Types/Vector/Vector.h>



/**
 *	Include Matrix
 */
#include <ING/Math/Types/Matrix/Matrix.h>



/**
 *	Include Math Type Declares
 */
#include <ING\Math\Types\TypeDeclares.h>



namespace ING {

	namespace Math {

		struct ING_API Quaternion : public Vector4 {

			/**
			 *	Constructors
			 */
		public:
			Quaternion(float _x, float _y, float _z, float _w) {
				x = _x;
				y = _y;
				z = _z;
				w = _w;
			}

			Quaternion(const Vector4& v) :
				Quaternion(v.x, v.y, v.z, v.w)
			{



			}

			Quaternion() :
				Quaternion(0, 0, 0, 0)
			{

			}



			/**
			 *	Methods
			 */
		public:
			static Quaternion Euler(const Vector3& eulerAngles);



			/**
			 *	Operators
			 */
		public:
			Vector3 operator*(const Vector3& next);

		};

	}

}