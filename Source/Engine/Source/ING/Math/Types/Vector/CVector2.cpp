
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
		Vector2 CVector2::Transpose() const {
			return Vector2(
				x, y
			);
		}

		float	CVector2::Length() const {

			return sqrt(x * x + y * y);

		}



		/**
		 *	Operators
		 */
		Matrix2x4 CVector2::operator*(const Vector4& next) {
			return Matrix2x4(
				next * x,
				next * y
			);
		}

		Matrix2x3 CVector2::operator*(const Vector3& next) {
			return Matrix2x3(
				next * x,
				next * y
			);
		}

		Matrix2x2 CVector2::operator*(const Vector2& next) {
			return Matrix2x2(
				next * x,
				next * y
			);
		}

	}

}