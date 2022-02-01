
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

		/**
		 *	Methods
		 */
		CVector4 Vector4::Transpose() {
			return CVector4(x, y, z, w);
		}



		/**
		 *	Operators
		 */
		Vector4 Vector4::operator*(Matrix4x4 next) {
			Matrix4x4 tNext = next.Transpose();
			return Vector4(
				Vector4::DotProduct(tNext.rows[0], *this),
				Vector4::DotProduct(tNext.rows[1], *this),
				Vector4::DotProduct(tNext.rows[2], *this),
				Vector4::DotProduct(tNext.rows[3], *this)
			);
		}

		Vector3 Vector4::operator*(Matrix4x3 next) {
			Matrix3x4 tNext = next.Transpose();
			return Vector3(
				Vector4::DotProduct(tNext.rows[0], *this),
				Vector4::DotProduct(tNext.rows[1], *this),
				Vector4::DotProduct(tNext.rows[2], *this)
			);
		}

		Vector2 Vector4::operator*(Matrix4x2 next) {
			Matrix2x4 tNext = next.Transpose();
			return Vector2(
				Vector4::DotProduct(tNext.rows[0], *this),
				Vector4::DotProduct(tNext.rows[1], *this)
			);
		}

		float Vector4::operator*(CVector4 next) {
			Vector4 tNext = next.Transpose();
			return (
				Vector4::DotProduct(tNext, *this)
			);
		}

	}

}