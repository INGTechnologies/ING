
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

		Vector3 CVector3::Transpose() {
			return Vector3(
				x, y, z
			);
		}

		Matrix3x4 CVector3::operator*(Vector4 next) {
			return Matrix3x4(
				next * x,
				next * y,
				next * z
			);
		}

		Matrix3x3 CVector3::operator*(Vector3 next) {
			return Matrix3x3(
				next * x,
				next * y,
				next * z
			);
		}

		Matrix3x2 CVector3::operator*(Vector2 next) {
			return Matrix3x2(
				next * x,
				next * y,
				next * z
			);
		}

	}

}