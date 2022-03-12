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

			Vector4(const AMath::Vector4& amathV);



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
			Vector4				operator*(const Matrix4x4& next);
			Vector3				operator*(const Matrix4x3& next);
			Vector2				operator*(const Matrix4x2& next);
			float				operator*(const CVector4& next);

			void				operator=(const AMath::Vector4& amathV);

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