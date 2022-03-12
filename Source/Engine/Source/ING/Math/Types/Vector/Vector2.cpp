
/**
 *	Include Math Types
 */
#include <ING\Math\Types\Types.h>



/**
 *	Include AMath Types
 */
#include <ING\AMath\Types\Types.h>



namespace ING {

	namespace Math {

		/**
		 *	Methods
		 */
		CVector2 Vector2::Transpose() const {
			return CVector2(x, y);
		}

		float	Vector2::Length() const {

			return sqrt(x * x + y * y);

		}



		/**
		 *	Operators
		 */
		Vector4 Vector2::operator*(const Matrix2x4& next) {
			Matrix4x2 tNext = next.Transpose();
			return Vector4(
				Vector2::DotProduct(tNext.rows[0], *this),
				Vector2::DotProduct(tNext.rows[1], *this),
				Vector2::DotProduct(tNext.rows[2], *this),
				Vector2::DotProduct(tNext.rows[3], *this)
			);
		}

		Vector3 Vector2::operator*(const Matrix2x3& next) {
			Matrix3x2 tNext = next.Transpose();
			return Vector3(
				Vector2::DotProduct(tNext.rows[0], *this),
				Vector2::DotProduct(tNext.rows[1], *this),
				Vector2::DotProduct(tNext.rows[2], *this)
			);
		}

		Vector2 Vector2::operator*(const Matrix2x2& next) {
			Matrix2x2 tNext = next.Transpose();
			return Vector2(
				Vector2::DotProduct(tNext.rows[0], *this),
				Vector2::DotProduct(tNext.rows[1], *this)
			);
		}

		float Vector2::operator*(const CVector2& next) {
			Vector2 tNext = next.Transpose();
			return (
				Vector2::DotProduct(tNext, *this)
			);
		}


	}

}