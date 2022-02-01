
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

		Matrix2x3 Matrix3x2::Transpose() {
			return Matrix2x3(
				Vector3(rows[0].x, rows[1].x, rows[2].x),
				Vector3(rows[0].y, rows[1].y, rows[2].y)
			);
		}

		Matrix3x4 Matrix3x2::operator*(Matrix2x4 next) {

			Matrix4x2 tNext = next.Transpose();

			return Matrix3x4(
				Vector4(Vector2::DotProduct(rows[0], tNext.rows[0]), Vector2::DotProduct(rows[0], tNext.rows[1]), Vector2::DotProduct(rows[0], tNext.rows[2]), Vector2::DotProduct(rows[0], tNext.rows[3])),
				Vector4(Vector2::DotProduct(rows[1], tNext.rows[0]), Vector2::DotProduct(rows[1], tNext.rows[1]), Vector2::DotProduct(rows[1], tNext.rows[2]), Vector2::DotProduct(rows[1], tNext.rows[3])),
				Vector4(Vector2::DotProduct(rows[2], tNext.rows[0]), Vector2::DotProduct(rows[2], tNext.rows[1]), Vector2::DotProduct(rows[2], tNext.rows[2]), Vector2::DotProduct(rows[2], tNext.rows[3]))
			);
		}

		Matrix3x3 Matrix3x2::operator*(Matrix2x3 next) {

			Matrix3x2 tNext = next.Transpose();

			return Matrix3x3(
				Vector3(Vector2::DotProduct(rows[0], tNext.rows[0]), Vector2::DotProduct(rows[0], tNext.rows[1]), Vector2::DotProduct(rows[0], tNext.rows[2])),
				Vector3(Vector2::DotProduct(rows[1], tNext.rows[0]), Vector2::DotProduct(rows[1], tNext.rows[1]), Vector2::DotProduct(rows[1], tNext.rows[2])),
				Vector3(Vector2::DotProduct(rows[2], tNext.rows[0]), Vector2::DotProduct(rows[2], tNext.rows[1]), Vector2::DotProduct(rows[2], tNext.rows[2]))
			);
		}

		Matrix3x2 Matrix3x2::operator*(Matrix2x2 next) {

			Matrix2x2 tNext = next.Transpose();

			return Matrix3x2(
				Vector2(Vector2::DotProduct(rows[0], tNext.rows[0]), Vector2::DotProduct(rows[0], tNext.rows[1])),
				Vector2(Vector2::DotProduct(rows[1], tNext.rows[0]), Vector2::DotProduct(rows[1], tNext.rows[1])),
				Vector2(Vector2::DotProduct(rows[2], tNext.rows[0]), Vector2::DotProduct(rows[2], tNext.rows[1]))
			);
		}

		CVector3 Matrix3x2::operator*(CVector2 next) {

			Vector2 tNext = next.Transpose();

			return CVector3(
				Vector2::DotProduct(tNext, rows[0]),
				Vector2::DotProduct(tNext, rows[1]),
				Vector2::DotProduct(tNext, rows[2])
			);
		}

	}

}