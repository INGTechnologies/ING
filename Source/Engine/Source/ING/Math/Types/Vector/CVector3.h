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

			static inline float DotProduct(const CVector3& a, const CVector3& b) {
				return a.x * b.x + a.y * b.y + a.z * b.z;
			}



			/**
			 *	Operators
			 */
		public:
			inline float& operator[](unsigned char i) {
				return *(((float*)this) + i);
			}
			Matrix3x4			operator*(const Vector4& next);
			Matrix3x3			operator*(const Vector3& next);
			Matrix3x2			operator*(const Vector2& next);

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