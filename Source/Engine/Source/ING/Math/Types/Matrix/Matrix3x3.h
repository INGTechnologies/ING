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

		struct ING_API Matrix3x3 {

			/**
			 *	Constructors
			 */
		public:
			Matrix3x3(const Vector3& _x, const Vector3& _y, const Vector3& _z) {
				rows[0] = _x;
				rows[1] = _y;
				rows[2] = _z;
			}
			Matrix3x3() :
				Matrix3x3(
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
			Vector3		rows[3];



			/**
			 *	Methods
			 */
		public:
			Matrix3x3	Transpose() const;
			float		Det() const;



			/**
			 *	Operators
			 */
		public:
			Matrix3x3	operator+(const Matrix3x3& next) {
				return Matrix3x3(rows[0] + next.rows[0], rows[1] + next.rows[1], rows[2] + next.rows[2]);
			}
			Matrix3x3	operator-(const Matrix3x3& next) {
				return Matrix3x3(rows[0] - next.rows[0], rows[1] - next.rows[1], rows[2] - next.rows[2]);
			}
			Matrix3x3	operator*(float a) {
				return Matrix3x3(rows[0] * a, rows[1] * a, rows[2] * a);
			}
			Matrix3x3	operator/(float a) {
				return Matrix3x3(rows[0] / a, rows[1] / a, rows[2] / a);
			}

			Matrix3x4	operator*(const Matrix3x4& next);
			Matrix3x3	operator*(const Matrix3x3& next);
			Matrix3x2	operator*(const Matrix3x2& next);
			CVector3	operator*(const CVector3& next);

		};

	}

}