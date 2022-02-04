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



		struct ING_API Vector2 {

			/**
			 *	Constructors
			 */
		public:
			Vector2(float _x,float _y) {
				x = _x;
				y = _y;
			}
			Vector2():
				Vector2(0,0)
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
					CVector2	Transpose();

			static	float		DotProduct(Vector2 a, Vector2 b) {
				return a.x * b.x + a.y * b.y;
			}



			/**
			 *	Operators
			 */
		public:
			Vector2 operator+(Vector2 next) {
				return Vector2(x+next.x,y+next.y);
			}
			Vector2 operator-(Vector2 next) {
				return Vector2(x - next.x, y - next.y);
			}
			Vector2 operator*(float a) {
				return Vector2(x*a, y*a);
			}
			Vector2 operator/(float a) {
				return Vector2(x / a, y / a);
			}

			Vector4 operator*(Matrix2x4 next);
			Vector3 operator*(Matrix2x3 next);
			Vector2 operator*(Matrix2x2 next);
			float	operator*(CVector2 next);

		};

	}

}