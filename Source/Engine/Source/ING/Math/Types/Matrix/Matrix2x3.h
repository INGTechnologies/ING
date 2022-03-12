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

		struct ING_API Matrix2x3 {

			/**
			 *	Constructors
			 */
		public:
			Matrix2x3(const Vector3& _x, const Vector3& _y) {
				rows[0] = _x;
				rows[1] = _y;
			}
			Matrix2x3() :
				Matrix2x3(
					Vector3(0, 0, 0),
					Vector3(0, 0, 0)
				)
			{

			}



			/**
			 *	Properties
			 */
		public:
			Vector3		rows[2];



			/**
			 *	Methods
			 */
		public:
			Matrix3x2	Transpose() const;



			/**
			 *	Operators
			 */
		public:
			Matrix2x3	operator+(const Matrix2x3& next) {
				return Matrix2x3(rows[0] + next.rows[0], rows[1] + next.rows[1]);
			}
			Matrix2x3	operator-(const Matrix2x3& next) {
				return Matrix2x3(rows[0] - next.rows[0], rows[1] - next.rows[1]);
			}
			Matrix2x3	operator*(float a) {
				return Matrix2x3(rows[0] * a, rows[1] * a);
			}
			Matrix2x3	operator/(float a) {
				return Matrix2x3(rows[0] / a, rows[1] / a);
			}

			Matrix2x4	operator*(const Matrix3x4& next);
			Matrix2x3	operator*(const Matrix3x3& next);
			Matrix2x2	operator*(const Matrix3x2& next);
			CVector2	operator*(const CVector3& next);

		};

	}

}