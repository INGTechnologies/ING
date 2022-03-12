#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Math Type Declares
 */
#include <ING\Math\Types\TypeDeclares.h>



namespace ING {

	namespace Math {

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
			Vector2				Transpose() const;

			float				Length() const;

			static inline float	DotProduct(const CVector2& a, const CVector2& b) {
				return a.x * b.x + a.y * b.y;
			}



			/**
			 *	Operators
			 */
		public:
			inline float& operator[](unsigned char i) {
				return *(((float*)this) + i);
			}
			Matrix2x4			operator*(const Vector4& next);
			Matrix2x3			operator*(const Vector3& next);
			Matrix2x2			operator*(const Vector2& next);

		};



		static inline CVector2 operator+(const CVector2& a, const CVector2& b)	{ return CVector2(a.x + b.x, a.y + b.y); }

		static inline CVector2 operator-(const CVector2& a, const CVector2& b)	{ return CVector2(a.x - b.x, a.y - b.y); }

		static inline CVector2 operator*(const CVector2& a, float b)			{ return CVector2(a.x * b, a.y * b); }

		static inline CVector2 operator/(const CVector2& a, float b)			{ return CVector2(a.x / b, a.y / b); }



		static inline CVector2 operator+(const CVector2& a)						{ return a; }
		static inline CVector2 operator-(const CVector2& a)						{ return CVector2(-a.x,-a.y); }



		static inline void    operator+=(CVector2& a, const CVector2& b)		{ a.x += b.x; a.y += b.y; }

		static inline void    operator-=(CVector2& a, const CVector2& b)		{ a.x -= b.x; a.y -= b.y; }

		static inline void    operator*=(CVector2& a, float b)					{ a.x *= b; a.y *= b; }

		static inline void    operator/=(CVector2& a, float b)					{ a.x /= b; a.y /= b; }

	}

}