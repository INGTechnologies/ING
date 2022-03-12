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

		struct ING_API Matrix4x4 {

			/**
			 *	Constructors
			 */
		public:
			Matrix4x4(const Vector4& _x, const Vector4& _y, const Vector4& _z, const Vector4& _w) {
				rows[0] = _x;
				rows[1] = _y;
				rows[2] = _z;
				rows[3] = _w;
			}
			Matrix4x4() :
				Matrix4x4(	Vector4(0, 0, 0, 0), 
							Vector4(0, 0, 0, 0), 
							Vector4(0, 0, 0, 0),
							Vector4(0, 0, 0, 0))
			{

			}



			/**
			 *	Properties
			 */
		public:
			Vector4		rows[4];



			/**
			 *	Methods
			 */
		public:
			Matrix4x4			Transpose() const;
			Matrix4x4			Cofactor() const;
			Matrix4x4			Inverse() const;
			static	Matrix4x4	Identity();
			float				Det() const;



			/**
			 *	Operators
			 */
		public:
			Matrix4x4	operator+(const Matrix4x4 next) {
				return Matrix4x4(rows[0] + next.rows[0], rows[1] + next.rows[1], rows[2] + next.rows[2], rows[3] + next.rows[3]);
			}
			Matrix4x4	operator-(const Matrix4x4 next) {
				return Matrix4x4(rows[0] - next.rows[0], rows[1] - next.rows[1], rows[2] - next.rows[2], rows[3] - next.rows[3]);
			}
			Matrix4x4	operator*(float a) {
				return Matrix4x4(rows[0]*a, rows[1] * a, rows[2] * a, rows[3] * a);
			}
			Matrix4x4	operator/(float a) {
				return Matrix4x4(rows[0] / a, rows[1] / a, rows[2] / a, rows[3] / a);
			}

			Matrix4x4	operator*(const Matrix4x4& next);
			Matrix4x3	operator*(const Matrix4x3& next);
			Matrix4x2	operator*(const Matrix4x2& next);
			CVector4	operator*(const CVector4& next);

		};

	}

}