#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



namespace ING {

	namespace Math {

		struct Matrix2x4;
		struct Matrix2x3;
		struct Matrix2x2;

		struct Matrix3x4;
		struct Matrix3x3;
		struct Matrix3x2;

		struct Matrix4x4;
		struct Matrix4x3;
		struct Matrix4x2;

		struct CVector2;
		struct CVector3;
		struct CVector4;

		struct Vector2;
		struct Vector3;
		struct Vector4;



		struct ING_API CVector2 {

			/**
			 *	Constructors
			 */
		public:
			CVector2(float _x, float _y) {
				x = _x;
				y = _y;
			}
			CVector2() :
				CVector2(0, 0)
			{

			}



			/**
			 *	Properties
			 */
		public:
			float x;
			float y;



			/**
			 *	Methods
			 */
		public:
					Vector2 Transpose();

			static	float	DotProduct(CVector2 a, CVector2 b) {
				return a.x * b.x + a.y * b.y;
			}



			/**
			 *	Operators
			 */
		public:
			CVector2	operator+(CVector2 next) {
				return CVector2(x + next.x, y + next.y);
			}
			CVector2	operator-(CVector2 next) {
				return CVector2(x - next.x, y - next.y);
			}
			CVector2	operator*(float a) {
				return CVector2(x * a, y * a);
			}
			CVector2	operator/(float a) {
				return CVector2(x / a, y / a);
			}

			Matrix2x4	operator*(Vector4 next);
			Matrix2x3	operator*(Vector3 next);
			Matrix2x2	operator*(Vector2 next);

		};

	}

}