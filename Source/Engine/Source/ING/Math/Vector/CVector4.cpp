
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
		Vector4 CVector4::Transpose() {
			return Vector4(x, y, z, w);
		}



		/**
		 *	Operators
		 */
		Matrix4x4 CVector4::operator*(Vector4 next) {
			return Matrix4x4(
				next * x,
				next * y,
				next * z,
				next * w
			);
		}

		Matrix4x3 CVector4::operator*(Vector3 next) {
			return Matrix4x3(
				next * x,
				next * y,
				next * z,
				next * w
			);
		}

		Matrix4x2 CVector4::operator*(Vector2 next) {
			return Matrix4x2(
				next * x,
				next * y,
				next * z,
				next * w
			);
		}

	}

}