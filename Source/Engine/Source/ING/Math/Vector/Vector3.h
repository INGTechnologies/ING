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

		struct Vector3 {
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

		public:
			float x;
			float y;
			float z;

		public:
			CVector3 Transpose();

		public:
			Vector3 operator+(Vector3 next) {
				return Vector3(x + next.x, y + next.y, z + next.z);
			}
			Vector3 operator-(Vector3 next) {
				return Vector3(x - next.x, y - next.y, z - next.z);
			}
			Vector3 operator*(float a) {
				return Vector3(x * a, y * a, z * a);
			}
			Vector3 operator/(float a) {
				return Vector3(x / a, y / a, z / a);
			}

			Vector4 operator*(Matrix3x4 next);
			Vector3 operator*(Matrix3x3 next);
			Vector2 operator*(Matrix3x2 next);
			float operator*(CVector3 next);

		public:
			static float DotProduct(Vector3 a, Vector3 b) {
				return a.x * b.x + a.y * b.y + a.z*b.z;
			}

		};

	}

}

#endif