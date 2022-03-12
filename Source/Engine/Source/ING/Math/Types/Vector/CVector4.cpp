
/**
 *	Include Types
 */
#include <ING\Math\Types\Types.h>



namespace ING {

	namespace Math {

		/**
		 *	Methods
		 */
		Vector4 CVector4::Transpose() const {
			return Vector4(x, y, z, w);
		}

		float	CVector4::Length() const {

			return sqrt(x * x + y * y + z * z + w * w);

		}



		/**
		 *	Operators
		 */
		Matrix4x4 CVector4::operator*(const Vector4& next) {
			return Matrix4x4(
				next * x,
				next * y,
				next * z,
				next * w
			);
		}

		Matrix4x3 CVector4::operator*(const Vector3& next) {
			return Matrix4x3(
				next * x,
				next * y,
				next * z,
				next * w
			);
		}

		Matrix4x2 CVector4::operator*(const Vector2& next) {
			return Matrix4x2(
				next * x,
				next * y,
				next * z,
				next * w
			);
		}

	}

}