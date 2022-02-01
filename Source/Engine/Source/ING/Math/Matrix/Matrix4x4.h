#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Vector
 */
#include <ING/Math/Vector/Vector.h>



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
		struct CVector4;
		struct CVector4;

		struct Vector2;
		struct Vector3;
		struct Vector4;



		struct ING_API Matrix4x4 {

			/**
			 *	Constructors
			 */
		public:
			Matrix4x4(	Vector4 _x, Vector4 _y, Vector4 _z, Vector4 _w) {
				rows[0] = _x;
				rows[1] = _y;
				rows[2] = _z;
				rows[3] = _w;
			}
			Matrix4x4() :
				Matrix4x4(	Vector4(0, 0, 0, 0), 
							Vector4(0, 0, 0, 0), 
							Vector4(0, 0, 0, 0),
							Vector4(0, 0, 0, 0))
			{

			}



			/**
			 *	Properties
			 */
		public:
			Vector4		rows[4];



			/**
			 *	Methods
			 */
		public:
			Matrix4x4	Transpose();
			float		Det();



			/**
			 *	Operators
			 */
		public:
			Matrix4x4	operator+(Matrix4x4 next) {
				return Matrix4x4(rows[0] + next.rows[0], rows[1] + next.rows[1], rows[2] + next.rows[2], rows[3] + next.rows[3]);
			}
			Matrix4x4	operator-(Matrix4x4 next) {
				return Matrix4x4(rows[0] - next.rows[0], rows[1] - next.rows[1], rows[2] - next.rows[2], rows[3] - next.rows[3]);
			}
			Matrix4x4	operator*(float a) {
				return Matrix4x4(rows[0]*a, rows[1] * a, rows[2] * a, rows[3] * a);
			}
			Matrix4x4	operator/(float a) {
				return Matrix4x4(rows[0] / a, rows[1] / a, rows[2] / a, rows[3] / a);
			}

			Matrix4x4	operator*(Matrix4x4 next);
			Matrix4x3	operator*(Matrix4x3 next);
			Matrix4x2	operator*(Matrix4x2 next);
			CVector4	operator*(CVector4 next);

		};

	}

}