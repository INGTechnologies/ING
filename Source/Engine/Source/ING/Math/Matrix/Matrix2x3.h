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

		struct Matrix2x3 {
		public:
			Matrix2x3(Vector3 _x, Vector3 _y) {
				rows[0] = _x;
				rows[1] = _y;
			}
			Matrix2x3() :
				Matrix2x3(
					Vector3(0, 0, 0),
					Vector3(0, 0, 0)
				)
			{

			}

		public:
			Vector3 rows[2];

		public:
			Matrix3x2 Transpose();

		public:
			Matrix2x3 operator+(Matrix2x3 next) {
				return Matrix2x3(rows[0] + next.rows[0], rows[1] + next.rows[1]);
			}
			Matrix2x3 operator-(Matrix2x3 next) {
				return Matrix2x3(rows[0] - next.rows[0], rows[1] - next.rows[1]);
			}
			Matrix2x3 operator*(float a) {
				return Matrix2x3(rows[0] * a, rows[1] * a);
			}
			Matrix2x3 operator/(float a) {
				return Matrix2x3(rows[0] / a, rows[1] / a);
			}

			Matrix2x4 operator*(Matrix3x4 next);
			Matrix2x3 operator*(Matrix3x3 next);
			Matrix2x2 operator*(Matrix3x2 next);
			CVector2 operator*(CVector3 next);

		};

	}

}