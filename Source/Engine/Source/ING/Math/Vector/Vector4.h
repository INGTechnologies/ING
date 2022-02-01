#pragma once



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

		struct Vector4 {
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

		public:
			float x;
			float y;
			float z;
			float w;

		public:
			CVector4 Transpose();

		public:
			Vector4 operator+(Vector4 next) {
				return Vector4(x + next.x, y + next.y, z + next.z, w + next.w);
			}
			Vector4 operator-(Vector4 next) {
				return Vector4(x - next.x, y - next.y, z - next.z, w - next.w);
			}
			Vector4 operator*(float a) {
				return Vector4(x * a, y * a, z * a, w * a);
			}
			Vector4 operator/(float a) {
				return Vector4(x / a, y / a, z / a, w / a);
			}

			Vector4 operator*(Matrix4x4 next);
			Vector3 operator*(Matrix4x3 next);
			Vector2 operator*(Matrix4x2 next);
			float operator*(CVector4 next);

		public:
			static float DotProduct(Vector4 a, Vector4 b) {
				return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
			}

		};

	}

}

#endif