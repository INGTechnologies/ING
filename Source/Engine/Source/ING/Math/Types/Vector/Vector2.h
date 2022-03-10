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
			CVector2			Transpose() const;

			float				Length() const;

			static inline float	DotProduct(Vector2 a, Vector2 b) {
				return a.x * b.x + a.y * b.y;
			}



			/**
			 *	Operators
			 */
		public:
			inline float& operator[](unsigned char i) {
				return *(((float*)this) + i);
			}
			Vector4				operator*(Matrix2x4 next);
			Vector3				operator*(Matrix2x3 next);
			Vector2				operator*(Matrix2x2 next);
			float				operator*(CVector2 next);

		};



		static inline Vector2 operator+(const Vector2& a, const Vector2& b) { return Vector2(a.x + b.x, a.y + b.y); }

		static inline Vector2 operator-(const Vector2& a, const Vector2& b) { return Vector2(a.x - b.x, a.y - b.y); }

		static inline Vector2 operator*(const Vector2& a, float b)			{ return Vector2(a.x * b, a.y * b); }

		static inline Vector2 operator/(const Vector2& a, float b)			{ return Vector2(a.x / b, a.y / b); }



		static inline Vector2 operator+(const Vector2& a)					{ return a; }
		static inline Vector2 operator-(const Vector2& a)					{ return Vector2(-a.x,-a.y); }



		static inline void    operator+=(Vector2& a, const Vector2& b)		{ a.x += b.x; a.y += b.y; }

		static inline void    operator-=(Vector2& a, const Vector2& b)		{ a.x -= b.x; a.y -= b.y; }

		static inline void    operator*=(Vector2& a, float b)				{ a.x *= b; a.y *= b; }

		static inline void    operator/=(Vector2& a, float b)				{ a.x /= b; a.y /= b; }

	}

}