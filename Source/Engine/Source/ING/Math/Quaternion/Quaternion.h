#pragma once

/**
 *	Include Vector
 */
#include <ING/Math/Vector/Vector.h>



/**
 *	Include Matrix
 */
#include <ING/Math/Matrix/Matrix.h>



namespace ING {

	namespace Math {

		struct Matrix2x4;
		struct Matrix2x3;
		struct Matrix2x2;

		struct Matrix3x4;
		struct Matrix3x3;
		struct Matrix3x2;

		struct Matrix4x4;
		struct Matrix4x3;
		struct Matrix4x2;

		struct CVector2;
		struct CVector3;
		struct CVector4;

		struct Vector2;
		struct Vector3;
		struct Vector4;



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

			Quaternion(Vector4 v) :
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
			static Quaternion Euler(Vector3 eulerAngles);



			/**
			 *	Operators
			 */
		public:
			Vector3 operator*(Vector3 next);

		};

	}

}