
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

		CVector2 Vector2::Transpose() {
			return CVector2(x, y);
		}


		Vector4 Vector2::operator*(Matrix2x4 next) {
			Matrix4x2 tNext = next.Transpose();
			return Vector4(
				Vector2::DotProduct(tNext.rows[0], *this),
				Vector2::DotProduct(tNext.rows[1], *this),
				Vector2::DotProduct(tNext.rows[2], *this),
				Vector2::DotProduct(tNext.rows[3], *this)
			);
		}

		Vector3 Vector2::operator*(Matrix2x3 next) {
			Matrix3x2 tNext = next.Transpose();
			return Vector3(
				Vector2::DotProduct(tNext.rows[0], *this),
				Vector2::DotProduct(tNext.rows[1], *this),
				Vector2::DotProduct(tNext.rows[2], *this)
			);
		}

		Vector2 Vector2::operator*(Matrix2x2 next) {
			Matrix2x2 tNext = next.Transpose();
			return Vector2(
				Vector2::DotProduct(tNext.rows[0], *this),
				Vector2::DotProduct(tNext.rows[1], *this)
			);
		}

		float Vector2::operator*(CVector2 next) {
			Vector2 tNext = next.Transpose();
			return (
				Vector2::DotProduct(tNext, *this)
			);
		}


	}

}