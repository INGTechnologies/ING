#pragma once



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

		struct Matrix3x3 {
		public:
			Matrix3x3(Vector3 _x, Vector3 _y, Vector3 _z) {
				rows[0] = _x;
				rows[1] = _y;
				rows[2] = _z;
			}
			Matrix3x3() :
				Matrix3x3(
					Vector3(0, 0, 0),
					Vector3(0, 0, 0),
					Vector3(0, 0, 0)
				)
			{

			}

		public:
			Vector3 rows[3];

		public:
			Matrix3x3 Transpose();
			float Det();

		public:
			Matrix3x3 operator+(Matrix3x3 next) {
				return Matrix3x3(rows[0] + next.rows[0], rows[1] + next.rows[1], rows[2] + next.rows[2]);
			}
			Matrix3x3 operator-(Matrix3x3 next) {
				return Matrix3x3(rows[0] - next.rows[0], rows[1] - next.rows[1], rows[2] - next.rows[2]);
			}
			Matrix3x3 operator*(float a) {
				return Matrix3x3(rows[0] * a, rows[1] * a, rows[2] * a);
			}
			Matrix3x3 operator/(float a) {
				return Matrix3x3(rows[0] / a, rows[1] / a, rows[2] / a);
			}

			Matrix3x4 operator*(Matrix3x4 next);
			Matrix3x3 operator*(Matrix3x3 next);
			Matrix3x2 operator*(Matrix3x2 next);
			CVector3 operator*(CVector3 next);

		};

	}

}