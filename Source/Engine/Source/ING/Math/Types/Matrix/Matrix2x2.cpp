
/**
 *	Include Types
 */
#include <ING\Math\Types\Types.h>



namespace ING {

	namespace Math {



		/**
		 *	Methods
		 */
		Matrix2x2	Matrix2x2::Transpose() const {
			return Matrix2x2(
				Vector2(rows[0].x, rows[1].x),
				Vector2(rows[0].y, rows[1].y)
			);
		}

		float		Matrix2x2::Det() const {
			return rows[0].x * rows[1].y - rows[0].y * rows[1].x;
		}



		/**
		 *	Operators
		 */
		Matrix2x4	Matrix2x2::operator*(const Matrix2x4& next) {

			Matrix4x2 tNext = next.Transpose();

			return Matrix2x4(
				Vector4(Vector2::DotProduct(rows[0], tNext.rows[0]), Vector2::DotProduct(rows[0], tNext.rows[1]), Vector2::DotProduct(rows[0], tNext.rows[2]), Vector2::DotProduct(rows[0], tNext.rows[3])),
				Vector4(Vector2::DotProduct(rows[1], tNext.rows[0]), Vector2::DotProduct(rows[1], tNext.rows[1]), Vector2::DotProduct(rows[1], tNext.rows[2]), Vector2::DotProduct(rows[1], tNext.rows[3]))
			);
		}

		Matrix2x3	Matrix2x2::operator*(const Matrix2x3& next) {

			Matrix3x2 tNext = next.Transpose();

			return Matrix2x3(
				Vector3(Vector2::DotProduct(rows[0], tNext.rows[0]), Vector2::DotProduct(rows[0], tNext.rows[1]), Vector2::DotProduct(rows[0], tNext.rows[2])),
				Vector3(Vector2::DotProduct(rows[1], tNext.rows[0]), Vector2::DotProduct(rows[1], tNext.rows[1]), Vector2::DotProduct(rows[1], tNext.rows[2]))
			);
		}

		Matrix2x2	Matrix2x2::operator*(const Matrix2x2& next) {

			Matrix2x2 tNext = next.Transpose();

			return Matrix2x2(
				Vector2(Vector2::DotProduct(rows[0], tNext.rows[0]), Vector2::DotProduct(rows[0], tNext.rows[1])),
				Vector2(Vector2::DotProduct(rows[1], tNext.rows[0]), Vector2::DotProduct(rows[1], tNext.rows[1]))
			);
		}

		CVector2	Matrix2x2::operator*(const CVector2& next) {

			Vector2 tNext = next.Transpose();

			return CVector2(
				Vector2::DotProduct(tNext, rows[0]),
				Vector2::DotProduct(tNext, rows[1])
			);
		}

	}

}
