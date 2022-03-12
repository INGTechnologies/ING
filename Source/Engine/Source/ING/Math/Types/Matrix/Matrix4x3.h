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

		struct ING_API Matrix4x3 {

			/**
			 *	Constructors
			 */
		public:
			Matrix4x3(const Vector3& _x, const Vector3& _y, const Vector3& _z, const Vector3& _w) {
				rows[0] = _x;
				rows[1] = _y;
				rows[2] = _z;
				rows[3] = _w;
			}
			Matrix4x3() :
				Matrix4x3(
					Vector3(0, 0, 0),
					Vector3(0, 0, 0),
					Vector3(0, 0, 0),
					Vector3(0, 0, 0)
				)
			{

			}



			/**
			 *	Properties
			 */
		public:
			Vector3		rows[4];



			/**
			 *	Methods
			 */
		public:
			Matrix3x4	Transpose() const;



			/**
			 *	Operators
			 */
		public:
			Matrix4x3	operator+(const Matrix4x3& next) {
				return Matrix4x3(rows[0] + next.rows[0], rows[1] + next.rows[1], rows[2] + next.rows[2], rows[3] + next.rows[3]);
			}
			Matrix4x3	operator-(const Matrix4x3& next) {
				return Matrix4x3(rows[0] - next.rows[0], rows[1] - next.rows[1], rows[2] - next.rows[2], rows[3] - next.rows[3]);
			}
			Matrix4x3	operator*(float a) {
				return Matrix4x3(rows[0] * a, rows[1] * a, rows[2] * a, rows[3] * a);
			}
			Matrix4x3	operator/(float a) {
				return Matrix4x3(rows[0] / a, rows[1] / a, rows[2] / a, rows[3] / a);
			}

			Matrix4x4	operator*(const Matrix3x4& next);
			Matrix4x3	operator*(const Matrix3x3& next);
			Matrix4x2	operator*(const Matrix3x2& next);
			CVector4	operator*(const CVector3& next);

		};

	}

}