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

		struct ING_API CVector4 {

			/**
			 *	Constructors
			 */
		public:
			CVector4(float _x, float _y, float _z, float _w) {
				x = _x;
				y = _y;
				z = _z;
				w = _w;
			}
			CVector4() :
				CVector4(0, 0, 0, 0)
			{

			}



			/**
			 *	Properties
			 */
		public:
			float x;
			float y;
			float z;
			float w;



			/**
			 *	Methods
			 */
		public:
			Vector4				Transpose() const;

			float				Length() const;

			static inline float	DotProduct(CVector4 a, CVector4 b) {
				return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
			}



			/**
			 *	Operators
			 */
		public:
			inline float& operator[](unsigned char i) {
				return *(((float*)this) + i);
			}
			Matrix4x4			operator*(const Vector4& next);
			Matrix4x3			operator*(const Vector3& next);
			Matrix4x2			operator*(const Vector2& next);

		};



		static inline CVector4 operator+(const CVector4& a, const CVector4& b)	{ return CVector4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w); }

		static inline CVector4 operator-(const CVector4& a, const CVector4& b)	{ return CVector4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w); }

		static inline CVector4 operator*(const CVector4& a, float b)			{ return CVector4(a.x * b, a.y * b, a.z * b, a.z * b); }

		static inline CVector4 operator/(const CVector4& a, float b)			{ return CVector4(a.x / b, a.y / b, a.z / b, a.z / b); }



		static inline CVector4 operator+(const CVector4& a)						{ return a; }
		static inline CVector4 operator-(const CVector4& a)						{ return CVector4(-a.x,-a.y,-a.z,-a.w); }



		static inline void    operator+=(CVector4& a, const CVector4& b)		{ a.x += b.x; a.y += b.y; a.z += b.z; a.w += b.w; }

		static inline void    operator-=(CVector4& a, const CVector4& b)		{ a.x -= b.x; a.y -= b.y; a.z -= b.z; a.w -= b.w; }

		static inline void    operator*=(CVector4& a, float b)					{ a.x *= b; a.y *= b; a.z *= b; a.w *= b; }

		static inline void    operator/=(CVector4& a, float b)					{ a.x /= b; a.y /= b; a.z /= b; a.w *= b; }

	}

}