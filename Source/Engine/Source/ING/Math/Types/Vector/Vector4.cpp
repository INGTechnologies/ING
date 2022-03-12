
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
		 *	Constructors
		 */
		Vector4::Vector4(const AMath::Vector4& amathV) {

			memcpy(this, &amathV, 16);

		}



		/**
		 *	Methods
		 */
		CVector4 Vector4::Transpose() const {
			return CVector4(x, y, z, w);
		}

		float	Vector4::Length() const {

			return sqrt(x*x + y*y + z*z + w*w);

		}



		/**
		 *	Operators
		 */
		Vector4 Vector4::operator*(const Matrix4x4& next) {
			Matrix4x4 tNext = next.Transpose();
			return Vector4(
				Vector4::DotProduct(tNext.rows[0], *this),
				Vector4::DotProduct(tNext.rows[1], *this),
				Vector4::DotProduct(tNext.rows[2], *this),
				Vector4::DotProduct(tNext.rows[3], *this)
			);
		}

		Vector3 Vector4::operator*(const Matrix4x3& next) {
			Matrix3x4 tNext = next.Transpose();
			return Vector3(
				Vector4::DotProduct(tNext.rows[0], *this),
				Vector4::DotProduct(tNext.rows[1], *this),
				Vector4::DotProduct(tNext.rows[2], *this)
			);
		}

		Vector2 Vector4::operator*(const Matrix4x2& next) {
			Matrix2x4 tNext = next.Transpose();
			return Vector2(
				Vector4::DotProduct(tNext.rows[0], *this),
				Vector4::DotProduct(tNext.rows[1], *this)
			);
		}

		float Vector4::operator*(const CVector4& next) {
			Vector4 tNext = next.Transpose();
			return (
				Vector4::DotProduct(tNext, *this)
			);
		}

		void  Vector4::operator=(const AMath::Vector4& amathV) {

			memcpy(this,&amathV,16);

		}

	}

}