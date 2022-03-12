#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Vector
 */
#include <ING/Math/Types/Vector/Vector.h>



/**
 *	Include Math Type Declares
 */
#include <ING\Math\Types\TypeDeclares.h>



namespace ING {

	namespace Math {

		struct ING_API Matrix3x4 {

			/**
			 *	Constructors
			 */
		public:
			Matrix3x4(const Vector4& _x, const Vector4& _y, const Vector4& _z) {
				rows[0] = _x;
				rows[1] = _y;
				rows[2] = _z;
			}
			Matrix3x4() :
				Matrix3x4(
					Vector4(0, 0, 0, 0),
					Vector4(0, 0, 0, 0),
					Vector4(0, 0, 0, 0)
				)
			{

			}

				

			/**
			 *	Properties
			 */
		public:
			Vector4		rows[3];



			/**
			 *	Methods
			 */
		public:
			Matrix4x3	Transpose() const;



			/**
			 *	Operators
			 */
		public:
			Matrix3x4	operator+(const Matrix3x4& next) {
				return Matrix3x4(rows[0] + next.rows[0], rows[1] + next.rows[1], rows[2] + next.rows[2]);
			}
			Matrix3x4	operator-(const Matrix3x4& next) {
				return Matrix3x4(rows[0] - next.rows[0], rows[1] - next.rows[1], rows[2] - next.rows[2]);
			}
			Matrix3x4	operator*(float a) {
				return Matrix3x4(rows[0] * a, rows[1] * a, rows[2] * a);
			}
			Matrix3x4	operator/(float a) {
				return Matrix3x4(rows[0] / a, rows[1] / a, rows[2] / a);
			}

			Matrix3x4	operator*(const Matrix4x4& next);
			Matrix3x3	operator*(const Matrix4x3& next);
			Matrix3x2	operator*(const Matrix4x2& next);
			CVector3	operator*(const CVector4& next);

		};

	}

}