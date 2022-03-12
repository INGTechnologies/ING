
/**
 *	Include Types
 */
#include <ING\Math\Types\Types.h>



namespace ING {

	namespace Math {

		/**
		 *	Methods
		 */
		Matrix3x3	Matrix3x3::Transpose() const {
			return Matrix3x3(
				Vector3(rows[0].x, rows[1].x, rows[2].x),
				Vector3(rows[0].y, rows[1].y, rows[2].y),
				Vector3(rows[0].z, rows[1].z, rows[2].z)
			);
		}

		float		Matrix3x3::Det() const {

			Matrix2x2 a = Matrix2x2(
				Vector2(rows[1].y, rows[1].z),
				Vector2(rows[2].y, rows[2].z)
			);

			Matrix2x2 b = Matrix2x2(
				Vector2(rows[1].x, rows[1].z),
				Vector2(rows[2].x, rows[2].z)
			);

			Matrix2x2 c = Matrix2x2(
				Vector2(rows[1].x, rows[1].y),
				Vector2(rows[2].x, rows[2].y)
			);

			return rows[0].x * a.Det() - rows[0].y * b.Det() + rows[0].z * c.Det();
		}



		/**
		 *	Operators
		 */
		Matrix3x4 Matrix3x3::operator*(const Matrix3x4& next) {

			Matrix4x3 tNext = next.Transpose();

			return Matrix3x4(
				Vector4(Vector3::DotProduct(rows[0], tNext.rows[0]), Vector3::DotProduct(rows[0], tNext.rows[1]), Vector3::DotProduct(rows[0], tNext.rows[2]), Vector3::DotProduct(rows[0], tNext.rows[3])),
				Vector4(Vector3::DotProduct(rows[1], tNext.rows[0]), Vector3::DotProduct(rows[1], tNext.rows[1]), Vector3::DotProduct(rows[1], tNext.rows[2]), Vector3::DotProduct(rows[1], tNext.rows[3])),
				Vector4(Vector3::DotProduct(rows[2], tNext.rows[0]), Vector3::DotProduct(rows[2], tNext.rows[1]), Vector3::DotProduct(rows[2], tNext.rows[2]), Vector3::DotProduct(rows[2], tNext.rows[3]))
			);
		}

		Matrix3x3 Matrix3x3::operator*(const Matrix3x3& next) {

			Matrix3x3 tNext = next.Transpose();

			return Matrix3x3(
				Vector3(Vector3::DotProduct(rows[0], tNext.rows[0]), Vector3::DotProduct(rows[0], tNext.rows[1]), Vector3::DotProduct(rows[0], tNext.rows[2])),
				Vector3(Vector3::DotProduct(rows[1], tNext.rows[0]), Vector3::DotProduct(rows[1], tNext.rows[1]), Vector3::DotProduct(rows[1], tNext.rows[2])),
				Vector3(Vector3::DotProduct(rows[2], tNext.rows[0]), Vector3::DotProduct(rows[2], tNext.rows[1]), Vector3::DotProduct(rows[2], tNext.rows[2]))
			);
		}

		Matrix3x2 Matrix3x3::operator*(const Matrix3x2& next) {

			Matrix2x3 tNext = next.Transpose();

			return Matrix3x2(
				Vector2(Vector3::DotProduct(rows[0], tNext.rows[0]), Vector3::DotProduct(rows[0], tNext.rows[1])),
				Vector2(Vector3::DotProduct(rows[1], tNext.rows[0]), Vector3::DotProduct(rows[1], tNext.rows[1])),
				Vector2(Vector3::DotProduct(rows[2], tNext.rows[0]), Vector3::DotProduct(rows[2], tNext.rows[1]))
			);
		}

		CVector3 Matrix3x3::operator*(const CVector3& next) {

			Vector3 tNext = next.Transpose();

			return CVector3(
				Vector3::DotProduct(tNext, rows[0]),
				Vector3::DotProduct(tNext, rows[1]),
				Vector3::DotProduct(tNext, rows[2])
			);
		}

	}

}