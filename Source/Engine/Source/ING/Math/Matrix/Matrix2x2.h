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

		struct Matrix2x2 {
		public:
			Matrix2x2(Vector2 _x, Vector2 _y) {
				rows[0] = _x;
				rows[1] = _y;
			}
			Matrix2x2() :
				Matrix2x2(
					Vector2(0, 0),
					Vector2(0, 0)
				)
			{

			}

		public:
			Vector2 rows[2];

		public:
			Matrix2x2 Transpose();
			float Det();

		public:
			Matrix2x2 operator+(Matrix2x2 next) {
				return Matrix2x2(rows[0] + next.rows[0], rows[1] + next.rows[1]);
			}
			Matrix2x2 operator-(Matrix2x2 next) {
				return Matrix2x2(rows[0] - next.rows[0], rows[1] - next.rows[1]);
			}
			Matrix2x2 operator*(float a) {
				return Matrix2x2(rows[0] * a, rows[1] * a);
			}
			Matrix2x2 operator/(float a) {
				return Matrix2x2(rows[0] / a, rows[1] / a);
			}

			Matrix2x4 operator*(Matrix2x4 next);
			Matrix2x3 operator*(Matrix2x3 next);
			Matrix2x2 operator*(Matrix2x2 next);
			CVector2 operator*(CVector2 next);

		};

	}

}