#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



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



		struct ING_API CVector4 {

			/**
			 *	Constructors
			 */
		public:
			CVector4(float _x, float _y, float _z, float _w) {
				x = _x;
				y = _y;
				z = _z;
				w = _w;
			}
			CVector4() :
				CVector4(0, 0, 0, 0)
			{

			}



			/**
			 *	Properties
			 */
		public:
			float x;
			float y;
			float z;
			float w;



			/**
			 *	Methods
			 */
		public:
					Vector4		Transpose();

			static	float		DotProduct(CVector4 a, CVector4 b) {
				return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
			}



			/**
			 *	Operators
			 */
		public:
			CVector4	operator+(CVector4 next) {
				return CVector4(x + next.x, y + next.y, z + next.z, w + next.w);
			}
			CVector4	operator-(CVector4 next) {
				return CVector4(x - next.x, y - next.y, z - next.z, w - next.w);
			}
			CVector4	operator*(float a) {
				return CVector4(x * a, y * a, z * a, w * a);
			}
			CVector4	operator/(float a) {
				return CVector4(x / a, y / a, z / a, w / a);
			}

			Matrix4x4	operator*(Vector4 next);
			Matrix4x3	operator*(Vector3 next);
			Matrix4x2	operator*(Vector2 next);

		};

	}

}