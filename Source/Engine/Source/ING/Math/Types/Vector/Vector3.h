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



		struct ING_API Vector3 {

			/**
			 *	Constructors
			 */
		public:
			Vector3(float _x, float _y, float _z) {
				x = _x;
				y = _y;
				z = _z;
			}
			Vector3() :
				Vector3(0, 0, 0)
			{

			}



			/**
			 *	Properties
			 */
		public:
			float x;
			float y;
			float z;



			/**
			 *	Methods
			 */
		public:
			CVector3			Transpose() const;

			float				Length() const;

			static inline float	DotProduct(Vector3 a, Vector3 b) {
				return a.x * b.x + a.y * b.y + a.z * b.z;
			}



			/**
			 *	Operators
			 */
		public:
			inline float& operator[](unsigned char i) {
				return *(((float*)this) + i);
			}
			Vector4				operator*(Matrix3x4 next);
			Vector3				operator*(Matrix3x3 next);
			Vector2				operator*(Matrix3x2 next);
			float				operator*(CVector3 next);

		};



		static inline Vector3 operator+(const Vector3& a, const Vector3& b) { return Vector3(a.x + b.x, a.y + b.y, a.z + b.z); }

		static inline Vector3 operator-(const Vector3& a, const Vector3& b) { return Vector3(a.x - b.x, a.y - b.y, a.z - b.z); }

		static inline Vector3 operator*(const Vector3& a, float b)			{ return Vector3(a.x * b, a.y * b, a.z * b); }

		static inline Vector3 operator/(const Vector3& a, float b)			{ return Vector3(a.x / b, a.y / b, a.z / b); }



		static inline Vector3 operator+(const Vector3& a)					{ return a; }
		static inline Vector3 operator-(const Vector3& a)					{ return Vector3(-a.x,-a.y,-a.z); }



		static inline void    operator+=(Vector3& a, const Vector3& b)		{ a.x += b.x; a.y += b.y; a.z += b.z; }

		static inline void    operator-=(Vector3& a, const Vector3& b)		{ a.x -= b.x; a.y -= b.y; a.z -= b.z; }

		static inline void    operator*=(Vector3& a, float b)				{ a.x *= b; a.y *= b; a.z *= b; }

		static inline void    operator/=(Vector3& a, float b)				{ a.x /= b; a.y /= b; a.z /= b; }

	}

}