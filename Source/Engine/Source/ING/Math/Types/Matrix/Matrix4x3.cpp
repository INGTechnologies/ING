
/**
 *	Include Types
 */
#include <ING\Math\Types\Types.h>



namespace ING {

	namespace Math {

		/**
		 *	Methods
		 */
		Matrix3x4 Matrix4x3::Transpose() const {
			return Matrix3x4(
				Vector4(rows[0].x, rows[1].x, rows[2].x, rows[3].x),
				Vector4(rows[0].y, rows[1].y, rows[2].y, rows[3].y),
				Vector4(rows[0].z, rows[1].z, rows[2].z, rows[3].z)
			);
		}



		/**
		 *	Operators
		 */
		Matrix4x4 Matrix4x3::operator*(const Matrix3x4& next) {
			Matrix4x3 tNext = next.Transpose();

			return Matrix4x4(
				Vector4(Vector3::DotProduct(rows[0], tNext.rows[0]), Vector3::DotProduct(rows[0], tNext.rows[1]), Vector3::DotProduct(rows[0], tNext.rows[2]), Vector3::DotProduct(rows[0], tNext.rows[3])),
				Vector4(Vector3::DotProduct(rows[1], tNext.rows[0]), Vector3::DotProduct(rows[1], tNext.rows[1]), Vector3::DotProduct(rows[1], tNext.rows[2]), Vector3::DotProduct(rows[1], tNext.rows[3])),
				Vector4(Vector3::DotProduct(rows[2], tNext.rows[0]), Vector3::DotProduct(rows[2], tNext.rows[1]), Vector3::DotProduct(rows[2], tNext.rows[2]), Vector3::DotProduct(rows[2], tNext.rows[3])),
				Vector4(Vector3::DotProduct(rows[3], tNext.rows[0]), Vector3::DotProduct(rows[3], tNext.rows[1]), Vector3::DotProduct(rows[3], tNext.rows[2]), Vector3::DotProduct(rows[3], tNext.rows[3]))
			);
		}

		Matrix4x3 Matrix4x3::operator*(const Matrix3x3& next) {
			Matrix3x3 tNext = next.Transpose();

			return Matrix4x3(
				Vector3(Vector3::DotProduct(rows[0], tNext.rows[0]), Vector3::DotProduct(rows[0], tNext.rows[1]), Vector3::DotProduct(rows[0], tNext.rows[2])),
				Vector3(Vector3::DotProduct(rows[1], tNext.rows[0]), Vector3::DotProduct(rows[1], tNext.rows[1]), Vector3::DotProduct(rows[1], tNext.rows[2])),
				Vector3(Vector3::DotProduct(rows[2], tNext.rows[0]), Vector3::DotProduct(rows[2], tNext.rows[1]), Vector3::DotProduct(rows[2], tNext.rows[2])),
				Vector3(Vector3::DotProduct(rows[3], tNext.rows[0]), Vector3::DotProduct(rows[3], tNext.rows[1]), Vector3::DotProduct(rows[3], tNext.rows[2]))
			);
		}

		Matrix4x2 Matrix4x3::operator*(const Matrix3x2& next) {
			Matrix2x3 tNext = next.Transpose();

			return Matrix4x2(
				Vector2(Vector3::DotProduct(rows[0], tNext.rows[0]), Vector3::DotProduct(rows[0], tNext.rows[1])),
				Vector2(Vector3::DotProduct(rows[1], tNext.rows[0]), Vector3::DotProduct(rows[1], tNext.rows[1])),
				Vector2(Vector3::DotProduct(rows[2], tNext.rows[0]), Vector3::DotProduct(rows[2], tNext.rows[1])),
				Vector2(Vector3::DotProduct(rows[3], tNext.rows[0]), Vector3::DotProduct(rows[3], tNext.rows[1]))
			);
		}

		CVector4 Matrix4x3::operator*(const CVector3& next) {
			Vector3 tNext = next.Transpose();

			return CVector4(
				Vector3::DotProduct(rows[0], tNext),
				Vector3::DotProduct(rows[1], tNext),
				Vector3::DotProduct(rows[2], tNext),
				Vector3::DotProduct(rows[3], tNext)
			);
		}

	}

}