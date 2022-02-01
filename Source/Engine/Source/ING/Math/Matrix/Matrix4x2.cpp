
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

		Matrix2x4 Matrix4x2::Transpose() {
			return Matrix2x4(
				Vector4(rows[0].x, rows[1].x, rows[2].x, rows[3].x),
				Vector4(rows[0].y, rows[1].y, rows[2].y, rows[3].y)
			);
		}


		Matrix4x4 Matrix4x2::operator*(Matrix2x4 next) {
			Matrix4x2 tNext = next.Transpose();

			return Matrix4x4(
				Vector4(Vector2::DotProduct(rows[0], tNext.rows[0]), Vector2::DotProduct(rows[0], tNext.rows[1]), Vector2::DotProduct(rows[0], tNext.rows[2]), Vector2::DotProduct(rows[0], tNext.rows[3])),
				Vector4(Vector2::DotProduct(rows[1], tNext.rows[0]), Vector2::DotProduct(rows[1], tNext.rows[1]), Vector2::DotProduct(rows[1], tNext.rows[2]), Vector2::DotProduct(rows[1], tNext.rows[3])),
				Vector4(Vector2::DotProduct(rows[2], tNext.rows[0]), Vector2::DotProduct(rows[2], tNext.rows[1]), Vector2::DotProduct(rows[2], tNext.rows[2]), Vector2::DotProduct(rows[2], tNext.rows[3])),
				Vector4(Vector2::DotProduct(rows[3], tNext.rows[0]), Vector2::DotProduct(rows[3], tNext.rows[1]), Vector2::DotProduct(rows[3], tNext.rows[2]), Vector2::DotProduct(rows[3], tNext.rows[3]))
			);
		}

		Matrix4x3 Matrix4x2::operator*(Matrix2x3 next) {
			Matrix3x2 tNext = next.Transpose();

			return Matrix4x3(
				Vector3(Vector2::DotProduct(rows[0], tNext.rows[0]), Vector2::DotProduct(rows[0], tNext.rows[1]), Vector2::DotProduct(rows[0], tNext.rows[2])),
				Vector3(Vector2::DotProduct(rows[1], tNext.rows[0]), Vector2::DotProduct(rows[1], tNext.rows[1]), Vector2::DotProduct(rows[1], tNext.rows[2])),
				Vector3(Vector2::DotProduct(rows[2], tNext.rows[0]), Vector2::DotProduct(rows[2], tNext.rows[1]), Vector2::DotProduct(rows[2], tNext.rows[2])),
				Vector3(Vector2::DotProduct(rows[3], tNext.rows[0]), Vector2::DotProduct(rows[3], tNext.rows[1]), Vector2::DotProduct(rows[3], tNext.rows[2]))
			);
		}

		Matrix4x2 Matrix4x2::operator*(Matrix2x2 next) {
			Matrix2x2 tNext = next.Transpose();

			return Matrix4x2(
				Vector2(Vector2::DotProduct(rows[0], tNext.rows[0]), Vector2::DotProduct(rows[0], tNext.rows[1])),
				Vector2(Vector2::DotProduct(rows[1], tNext.rows[0]), Vector2::DotProduct(rows[1], tNext.rows[1])),
				Vector2(Vector2::DotProduct(rows[2], tNext.rows[0]), Vector2::DotProduct(rows[2], tNext.rows[1])),
				Vector2(Vector2::DotProduct(rows[3], tNext.rows[0]), Vector2::DotProduct(rows[3], tNext.rows[1]))
			);
		}

		CVector4 Matrix4x2::operator*(CVector2 next) {
			Vector2 tNext = next.Transpose();

			return CVector4(
				Vector2::DotProduct(rows[0], tNext),
				Vector2::DotProduct(rows[1], tNext),
				Vector2::DotProduct(rows[2], tNext),
				Vector2::DotProduct(rows[3], tNext)
			);
		}

	}

}