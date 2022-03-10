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



		struct ING_API CVector3 {

			/**
			 *	Constructors
			 */
		public:
			CVector3(float _x, float _y, float _z) {
				x = _x;
				y = _y;
				z = _z;
			}
			CVector3() :
				CVector3(0, 0, 0)
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
			Vector3				Transpose() const;

			float				Length() const;

			static inline float DotProduct(CVector3 a, CVector3 b) {
				return a.x * b.x + a.y * b.y + a.z * b.z;
			}



			/**
			 *	Operators
			 */
		public:
			inline float& operator[](unsigned char i) {
				return *(((float*)this) + i);
			}
			Matrix3x4			operator*(Vector4 next);
			Matrix3x3			operator*(Vector3 next);
			Matrix3x2			operator*(Vector2 next);

		};



		static inline CVector3 operator+(const CVector3& a, const CVector3& b)	{ return CVector3(a.x + b.x, a.y + b.y, a.z + b.z); }

		static inline CVector3 operator-(const CVector3& a, const CVector3& b)	{ return CVector3(a.x - b.x, a.y - b.y, a.z - b.z); }

		static inline CVector3 operator*(const CVector3& a, float b)			{ return CVector3(a.x * b, a.y * b, a.z * b); }

		static inline CVector3 operator/(const CVector3& a, float b)			{ return CVector3(a.x / b, a.y / b, a.z / b); }



		static inline CVector3 operator+(const CVector3& a)						{ return a; }
		static inline CVector3 operator-(const CVector3& a)						{ return CVector3(-a.x,-a.y,-a.z); }



		static inline void    operator+=(CVector3& a, const CVector3& b)		{ a.x += b.x; a.y += b.y; a.z += b.z; }

		static inline void    operator-=(CVector3& a, const CVector3& b)		{ a.x -= b.x; a.y -= b.y; a.z -= b.z; }

		static inline void    operator*=(CVector3& a, float b)					{ a.x *= b; a.y *= b; a.z *= b; }

		static inline void    operator/=(CVector3& a, float b)					{ a.x /= b; a.y /= b; a.z /= b; }

	}

}