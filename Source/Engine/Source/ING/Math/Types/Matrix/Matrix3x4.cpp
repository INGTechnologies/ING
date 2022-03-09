
/**
 *	Include Types
 */
#include <ING\Math\Types\Types.h>



namespace ING {

	namespace Math {

		/**
		 *	Methods
		 */
		Matrix4x3 Matrix3x4::Transpose() {
			return Matrix4x3(
				Vector3(rows[0].x, rows[1].x, rows[2].x),
				Vector3(rows[0].y, rows[1].y, rows[2].y),
				Vector3(rows[0].z, rows[1].z, rows[2].z),
				Vector3(rows[0].w, rows[1].w, rows[2].w)
			);
		}



		/**
		 *	Operators
		 */
		Matrix3x4 Matrix3x4::operator*(Matrix4x4 next) {

			Matrix4x4 tNext = next.Transpose();

			return Matrix3x4(
				Vector4(Vector4::DotProduct(rows[0], tNext.rows[0]), Vector4::DotProduct(rows[0], tNext.rows[1]), Vector4::DotProduct(rows[0], tNext.rows[2]), Vector4::DotProduct(rows[0], tNext.rows[3])),
				Vector4(Vector4::DotProduct(rows[1], tNext.rows[0]), Vector4::DotProduct(rows[1], tNext.rows[1]), Vector4::DotProduct(rows[1], tNext.rows[2]), Vector4::DotProduct(rows[1], tNext.rows[3])),
				Vector4(Vector4::DotProduct(rows[2], tNext.rows[0]), Vector4::DotProduct(rows[2], tNext.rows[1]), Vector4::DotProduct(rows[2], tNext.rows[2]), Vector4::DotProduct(rows[2], tNext.rows[3]))
			);
		}

		Matrix3x3 Matrix3x4::operator*(Matrix4x3 next) {

			Matrix3x4 tNext = next.Transpose();

			return Matrix3x3(
				Vector3(Vector4::DotProduct(rows[0], tNext.rows[0]), Vector4::DotProduct(rows[0], tNext.rows[1]), Vector4::DotProduct(rows[0], tNext.rows[2])),
				Vector3(Vector4::DotProduct(rows[1], tNext.rows[0]), Vector4::DotProduct(rows[1], tNext.rows[1]), Vector4::DotProduct(rows[1], tNext.rows[2])),
				Vector3(Vector4::DotProduct(rows[2], tNext.rows[0]), Vector4::DotProduct(rows[2], tNext.rows[1]), Vector4::DotProduct(rows[2], tNext.rows[2]))
			);
		}

		Matrix3x2 Matrix3x4::operator*(Matrix4x2 next) {

			Matrix2x4 tNext = next.Transpose();

			return Matrix3x2(
				Vector2(Vector4::DotProduct(rows[0], tNext.rows[0]), Vector4::DotProduct(rows[0], tNext.rows[1])),
				Vector2(Vector4::DotProduct(rows[1], tNext.rows[0]), Vector4::DotProduct(rows[1], tNext.rows[1])),
				Vector2(Vector4::DotProduct(rows[2], tNext.rows[0]), Vector4::DotProduct(rows[2], tNext.rows[1]))
			);
		}

		CVector3 Matrix3x4::operator*(CVector4 next) {

			Vector4 tNext = next.Transpose();

			return CVector3(
				Vector4::DotProduct(tNext, rows[0]),
				Vector4::DotProduct(tNext, rows[1]),
				Vector4::DotProduct(tNext, rows[2])
			);
		}

	}

}