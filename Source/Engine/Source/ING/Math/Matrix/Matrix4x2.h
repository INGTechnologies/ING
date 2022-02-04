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



		struct ING_API Matrix4x2 {

			/**
			 *	Constructors
			 */
		public:
			Matrix4x2(Vector2 _x, Vector2 _y, Vector2 _z, Vector2 _w) {
				rows[0] = _x;
				rows[1] = _y;
				rows[2] = _z;
				rows[3] = _w;
			}
			Matrix4x2() :
				Matrix4x2(
					Vector2(0, 0),
					Vector2(0, 0),
					Vector2(0, 0),
					Vector2(0, 0)
				)
			{

			}



			/**
			 *	Properties
			 */
		public:
			Vector2		rows[4];



			/**
			 *	Methods
			 */
		public:
			Matrix2x4	Transpose();



			/**
			 *	Operators
			 */
		public:
			Matrix4x2	operator+(Matrix4x2 next) {
				return Matrix4x2(rows[0] + next.rows[0], rows[1] + next.rows[1], rows[2] + next.rows[2], rows[3] + next.rows[3]);
			}
			Matrix4x2	operator-(Matrix4x2 next) {
				return Matrix4x2(rows[0] - next.rows[0], rows[1] - next.rows[1], rows[2] - next.rows[2], rows[3] - next.rows[3]);
			}
			Matrix4x2	operator*(float a) {
				return Matrix4x2(rows[0] * a, rows[1] * a, rows[2] * a, rows[3] * a);
			}
			Matrix4x2	operator/(float a) {
				return Matrix4x2(rows[0] / a, rows[1] / a, rows[2] / a, rows[3] / a);
			}

			Matrix4x4	operator*(Matrix2x4 next);
			Matrix4x3	operator*(Matrix2x3 next);
			Matrix4x2	operator*(Matrix2x2 next);
			CVector4	operator*(CVector2 next);

		};

	}

}