
/**
 *	Include Types
 */
#include <ING\Math\Types\Types.h>



namespace ING {

	namespace Math {

		/**
		 *	Methods
		 */
		Matrix3x2 Matrix2x3::Transpose() const {
			return Matrix3x2(
				Vector2(rows[0].x, rows[1].x),
				Vector2(rows[0].y, rows[1].y),
				Vector2(rows[0].z, rows[1].z)
			);
		}



		/**
		 *	Operators
		 */
		Matrix2x4 Matrix2x3::operator*(const Matrix3x4& next) {

			Matrix4x3 tNext = next.Transpose();

			return Matrix2x4(
				Vector4(Vector3::DotProduct(rows[0], tNext.rows[0]), Vector3::DotProduct(rows[0], tNext.rows[1]), Vector3::DotProduct(rows[0], tNext.rows[2]), Vector3::DotProduct(rows[0], tNext.rows[3])),
				Vector4(Vector3::DotProduct(rows[1], tNext.rows[0]), Vector3::DotProduct(rows[1], tNext.rows[1]), Vector3::DotProduct(rows[1], tNext.rows[2]), Vector3::DotProduct(rows[1], tNext.rows[3]))
			);
		}

		Matrix2x3 Matrix2x3::operator*(const Matrix3x3& next) {

			Matrix3x3 tNext = next.Transpose();

			return Matrix2x3(
				Vector3(Vector3::DotProduct(rows[0], tNext.rows[0]), Vector3::DotProduct(rows[0], tNext.rows[1]), Vector3::DotProduct(rows[0], tNext.rows[2])),
				Vector3(Vector3::DotProduct(rows[1], tNext.rows[0]), Vector3::DotProduct(rows[1], tNext.rows[1]), Vector3::DotProduct(rows[1], tNext.rows[2]))
			);
		}

		Matrix2x2 Matrix2x3::operator*(const Matrix3x2& next) {

			Matrix2x3 tNext = next.Transpose();

			return Matrix2x2(
				Vector2(Vector3::DotProduct(rows[0], tNext.rows[0]), Vector3::DotProduct(rows[0], tNext.rows[1])),
				Vector2(Vector3::DotProduct(rows[1], tNext.rows[0]), Vector3::DotProduct(rows[1], tNext.rows[1]))
			);
		}

		CVector2 Matrix2x3::operator*(const CVector3& next) {

			Vector3 tNext = next.Transpose();

			return CVector2(
				Vector3::DotProduct(tNext, rows[0]),
				Vector3::DotProduct(tNext, rows[1])
			);
		}

	}

}