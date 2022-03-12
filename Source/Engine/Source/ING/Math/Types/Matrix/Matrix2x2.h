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

		struct ING_API Matrix2x2 {

			/**
			 *	Constructors
			 */
		public:
			Matrix2x2(const Vector2& _x, const Vector2& _y) {
				rows[0] = _x;
				rows[1] = _y;
			}
			Matrix2x2() :
				Matrix2x2(
					Vector2(0, 0),
					Vector2(0, 0)
				)
			{

			}



			/**
			 *	Properties
			 */
		public:
			Vector2		rows[2];



			/**
			 *	Methods
			 */
		public:
			Matrix2x2	Transpose() const;
			float		Det() const;



			/**
			 *	Operators
			 */
		public:
			Matrix2x2	operator+(const Matrix2x2& next) {
				return Matrix2x2(rows[0] + next.rows[0], rows[1] + next.rows[1]);
			}
			Matrix2x2	operator-(const Matrix2x2& next) {
				return Matrix2x2(rows[0] - next.rows[0], rows[1] - next.rows[1]);
			}
			Matrix2x2	operator*(float a) {
				return Matrix2x2(rows[0] * a, rows[1] * a);
			}
			Matrix2x2	operator/(float a) {
				return Matrix2x2(rows[0] / a, rows[1] / a);
			}

			Matrix2x4	operator*(const Matrix2x4& next);
			Matrix2x3	operator*(const Matrix2x3& next);
			Matrix2x2	operator*(const Matrix2x2& next);
			CVector2	operator*(const CVector2& next);

		};

	}

}