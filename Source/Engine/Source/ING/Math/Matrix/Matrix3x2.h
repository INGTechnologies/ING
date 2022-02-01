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

		struct Matrix3x2 {
		public:
			Matrix3x2(Vector2 _x, Vector2 _y, Vector2 _z) {
				rows[0] = _x;
				rows[1] = _y;
				rows[2] = _z;
			}
			Matrix3x2() :
				Matrix3x2(
					Vector2(0, 0),
					Vector2(0, 0),
					Vector2(0, 0)
				)
			{

			}

		public:
			Vector2 rows[3];

		public:
			Matrix2x3 Transpose();

		public:
			Matrix3x2 operator+(Matrix3x2 next) {
				return Matrix3x2(rows[0] + next.rows[0], rows[1] + next.rows[1], rows[2] + next.rows[2]);
			}
			Matrix3x2 operator-(Matrix3x2 next) {
				return Matrix3x2(rows[0] - next.rows[0], rows[1] - next.rows[1], rows[2] - next.rows[2]);
			}
			Matrix3x2 operator*(float a) {
				return Matrix3x2(rows[0] * a, rows[1] * a, rows[2] * a);
			}
			Matrix3x2 operator/(float a) {
				return Matrix3x2(rows[0] / a, rows[1] / a, rows[2] / a);
			}

			Matrix3x4 operator*(Matrix2x4 next);
			Matrix3x3 operator*(Matrix2x3 next);
			Matrix3x2 operator*(Matrix2x2 next);
			CVector3 operator*(CVector2 next);

		};

	}

}