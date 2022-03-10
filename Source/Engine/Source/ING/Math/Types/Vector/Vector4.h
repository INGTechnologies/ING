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



		struct ING_API Vector4 {

			/**
			 *	Constructors
			 */
		public:
			Vector4(float _x, float _y, float _z, float _w) {
				x = _x;
				y = _y;
				z = _z;
				w = _w;
			}
			Vector4() :
				Vector4(0, 0, 0, 0)
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
			CVector4			Transpose	() const;

			float				Length		() const;

			static inline float	DotProduct	(Vector4 a, Vector4 b) {
				return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
			}



			/**
			 *	Operators
			 */
		public:
			inline float& operator[](unsigned char i) {
				return *(((float*)this) + i);
			}
			Vector4				operator*(Matrix4x4 next);
			Vector3				operator*(Matrix4x3 next);
			Vector2				operator*(Matrix4x2 next);
			float				operator*(CVector4 next);

		};



		static inline Vector4 operator+(const Vector4& a, const Vector4& b) { return Vector4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w); }

		static inline Vector4 operator-(const Vector4& a, const Vector4& b) { return Vector4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w); }

		static inline Vector4 operator*(const Vector4& a, float b)			{ return Vector4(a.x * b, a.y * b, a.z * b, a.z * b); }

		static inline Vector4 operator/(const Vector4& a, float b)			{ return Vector4(a.x / b, a.y / b, a.z / b, a.z / b); }



		static inline Vector4 operator+(const Vector4& a)					{ return a; }
		static inline Vector4 operator-(const Vector4& a)					{ return Vector4(-a.x,-a.y,-a.z,-a.w); }



		static inline void    operator+=(Vector4& a, const Vector4& b)		{ a.x += b.x; a.y += b.y; a.z += b.z; a.w += b.w; }

		static inline void    operator-=(Vector4& a, const Vector4& b)		{ a.x -= b.x; a.y -= b.y; a.z -= b.z; a.w -= b.w; }

		static inline void    operator*=(Vector4& a, float b)				{ a.x *= b; a.y *= b; a.z *= b; a.w *= b; }

		static inline void    operator/=(Vector4& a, float b)				{ a.x /= b; a.y /= b; a.z /= b; a.w *= b; }

	}

}