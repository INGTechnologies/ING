
/**
 *	Include Types
 */
#include <ING\Math\Types\Types.h>



namespace ING {

	namespace Math {

		/**
		 *	Methods
		 */
		Matrix4x2 Matrix2x4::Transpose() const {
			return Matrix4x2(
				Vector2(rows[0].x, rows[1].x),
				Vector2(rows[0].y, rows[1].y),
				Vector2(rows[0].z, rows[1].z),
				Vector2(rows[0].w, rows[1].w)
			);
		}



		/**
		 *	Operators
		 */
		Matrix2x4 Matrix2x4::operator*(const Matrix4x4& next) {

			Matrix4x4 tNext = next.Transpose();

			return Matrix2x4(
				Vector4(Vector4::DotProduct(rows[0], tNext.rows[0]), Vector4::DotProduct(rows[0], tNext.rows[1]), Vector4::DotProduct(rows[0], tNext.rows[2]), Vector4::DotProduct(rows[0], tNext.rows[3])),
				Vector4(Vector4::DotProduct(rows[1], tNext.rows[0]), Vector4::DotProduct(rows[1], tNext.rows[1]), Vector4::DotProduct(rows[1], tNext.rows[2]), Vector4::DotProduct(rows[1], tNext.rows[3]))
			);
		}

		Matrix2x3 Matrix2x4::operator*(const Matrix4x3& next) {

			Matrix3x4 tNext = next.Transpose();

			return Matrix2x3(
				Vector3(Vector4::DotProduct(rows[0], tNext.rows[0]), Vector4::DotProduct(rows[0], tNext.rows[1]), Vector4::DotProduct(rows[0], tNext.rows[2])),
				Vector3(Vector4::DotProduct(rows[1], tNext.rows[0]), Vector4::DotProduct(rows[1], tNext.rows[1]), Vector4::DotProduct(rows[1], tNext.rows[2]))
			);
		}

		Matrix2x2 Matrix2x4::operator*(const Matrix4x2& next) {

			Matrix2x4 tNext = next.Transpose();

			return Matrix2x2(
				Vector2(Vector4::DotProduct(rows[0], tNext.rows[0]), Vector4::DotProduct(rows[0], tNext.rows[1])),
				Vector2(Vector4::DotProduct(rows[1], tNext.rows[0]), Vector4::DotProduct(rows[1], tNext.rows[1]))
			);
		}

		CVector2 Matrix2x4::operator*(const CVector4& next) {

			Vector4 tNext = next.Transpose();

			return CVector2(
				Vector4::DotProduct(tNext, rows[0]),
				Vector4::DotProduct(tNext, rows[1])
			);
		}

	}

}