#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Math Type Declares
 */
#include <ING\Math\Types\TypeDeclares.h>



/**
 *	Include AMath Type Declares
 */
#include <ING\AMath\Types\TypeDeclares.h>



namespace ING {

	namespace Math {

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
			Vector4				operator*(const Matrix2x4& next);
			Vector3				operator*(const Matrix2x3& next);
			Vector2				operator*(const Matrix2x2& next);
			float				operator*(const CVector2& next);

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