
/**
 *	Include Types
 */
#include <ING\Math\Types\Types.h>



namespace ING {

	namespace Math {

		/**
		 *	Methods
		 */
		Matrix4x4	Matrix4x4::Transpose() {
			return Matrix4x4(
				Vector4(rows[0].x, rows[1].x, rows[2].x, rows[3].x),
				Vector4(rows[0].y, rows[1].y, rows[2].y, rows[3].y),
				Vector4(rows[0].z, rows[1].z, rows[2].z, rows[3].z),
				Vector4(rows[0].w, rows[1].w, rows[2].w, rows[3].w)
			);
		}

		Matrix4x4	Matrix4x4::Cofactor() {

			return Matrix4x4(

				Vector4(

					Matrix3x3(

						Vector3(rows[1].y, rows[1].z, rows[1].w),

						Vector3(rows[2].y, rows[2].z, rows[2].w),

						Vector3(rows[3].y, rows[3].z, rows[3].w)

					).Det(),

					Matrix3x3(

						Vector3(rows[1].x, rows[1].z, rows[1].w),

						Vector3(rows[2].x, rows[2].z, rows[2].w),

						Vector3(rows[3].x, rows[3].z, rows[3].w)

					).Det(),

					Matrix3x3(

						Vector3(rows[1].x, rows[1].y, rows[1].w),

						Vector3(rows[2].x, rows[2].y, rows[2].w),

						Vector3(rows[3].x, rows[3].y, rows[3].w)

					).Det(),

					Matrix3x3(

						Vector3(rows[1].x, rows[1].y, rows[1].z),

						Vector3(rows[2].x, rows[2].y, rows[2].z),

						Vector3(rows[3].x, rows[3].y, rows[3].z)

					).Det()

				),

				Vector4(

					Matrix3x3(

						Vector3(rows[0].y, rows[0].z, rows[0].w),

						Vector3(rows[2].y, rows[2].z, rows[2].w),

						Vector3(rows[3].y, rows[3].z, rows[3].w)

					).Det(),

					Matrix3x3(

						Vector3(rows[0].x, rows[0].z, rows[0].w),

						Vector3(rows[2].x, rows[2].z, rows[2].w),

						Vector3(rows[3].x, rows[3].z, rows[3].w)

					).Det(),

					Matrix3x3(

						Vector3(rows[0].x, rows[0].y, rows[0].w),

						Vector3(rows[2].x, rows[2].y, rows[2].w),

						Vector3(rows[3].x, rows[3].y, rows[3].w)

					).Det(),

					Matrix3x3(

						Vector3(rows[0].x, rows[0].y, rows[0].z),

						Vector3(rows[2].x, rows[2].y, rows[2].z),

						Vector3(rows[3].x, rows[3].y, rows[3].z)

					).Det()

				),

				Vector4(

					Matrix3x3(

						Vector3(rows[0].y, rows[0].z, rows[0].w),

						Vector3(rows[1].y, rows[1].z, rows[1].w),

						Vector3(rows[3].y, rows[3].z, rows[3].w)

					).Det(),

					Matrix3x3(

						Vector3(rows[0].x, rows[0].z, rows[0].w),

						Vector3(rows[1].x, rows[1].z, rows[1].w),

						Vector3(rows[3].x, rows[3].z, rows[3].w)

					).Det(),

					Matrix3x3(

						Vector3(rows[0].x, rows[0].y, rows[0].w),

						Vector3(rows[1].x, rows[1].y, rows[1].w),

						Vector3(rows[3].x, rows[3].y, rows[3].w)

					).Det(),

					Matrix3x3(

						Vector3(rows[0].x, rows[0].y, rows[0].z),

						Vector3(rows[1].x, rows[1].y, rows[1].z),

						Vector3(rows[3].x, rows[3].y, rows[3].z)

					).Det()

				),

				Vector4(

					Matrix3x3(

						Vector3(rows[0].y, rows[0].z, rows[0].w),

						Vector3(rows[1].y, rows[1].z, rows[1].w),

						Vector3(rows[2].y, rows[2].z, rows[2].w)

					).Det(),

					Matrix3x3(

						Vector3(rows[0].x, rows[0].z, rows[0].w),

						Vector3(rows[1].x, rows[1].z, rows[1].w),

						Vector3(rows[2].x, rows[2].z, rows[2].w)

					).Det(),

					Matrix3x3(

						Vector3(rows[0].x, rows[0].y, rows[0].w),

						Vector3(rows[1].x, rows[1].y, rows[1].w),

						Vector3(rows[2].x, rows[2].y, rows[2].w)

					).Det(),

					Matrix3x3(

						Vector3(rows[0].x, rows[0].y, rows[0].z),

						Vector3(rows[1].x, rows[1].y, rows[1].z),

						Vector3(rows[2].x, rows[2].y, rows[2].z)

					).Det()

				)

			);

		}

		Matrix4x4	Matrix4x4::Inverse() {

			return (*this).Cofactor() / Det();

		}

		Matrix4x4	Matrix4x4::Identity() {

			return Matrix4x4(	

				Vector4(1,0,0,0),
				Vector4(0,1,0,0),
				Vector4(0,0,1,0),
				Vector4(0,0,0,1)

			);

		}

		float		Matrix4x4::Det() {

			Matrix3x3 a = Matrix3x3(
				Vector3(rows[1].y, rows[1].z, rows[1].w),
				Vector3(rows[2].y, rows[2].z, rows[2].w),
				Vector3(rows[3].y, rows[3].z, rows[3].w)
			);

			Matrix3x3 b = Matrix3x3(
				Vector3(rows[1].x, rows[1].z, rows[1].w),
				Vector3(rows[2].x, rows[2].z, rows[2].w),
				Vector3(rows[3].x, rows[3].z, rows[3].w)
			);

			Matrix3x3 c = Matrix3x3(
				Vector3(rows[1].x, rows[1].y, rows[1].w),
				Vector3(rows[2].x, rows[2].y, rows[2].w),
				Vector3(rows[3].x, rows[3].y, rows[3].w)
			);

			Matrix3x3 d = Matrix3x3(
				Vector3(rows[1].x, rows[1].y, rows[1].z),
				Vector3(rows[2].x, rows[2].y, rows[2].z),
				Vector3(rows[3].x, rows[3].y, rows[3].z)
			);

			return rows[0].x * a.Det() - rows[0].y * b.Det() + rows[0].z * c.Det() - rows[0].w * d.Det();
		}



		/**
		 *	Operators
		 */
		Matrix4x4 Matrix4x4::operator*(Matrix4x4 next) {

			Matrix4x4 tNext = next.Transpose();

			return Matrix4x4(
				Vector4(Vector4::DotProduct(rows[0], tNext.rows[0]), Vector4::DotProduct(rows[0], tNext.rows[1]), Vector4::DotProduct(rows[0], tNext.rows[2]), Vector4::DotProduct(rows[0], tNext.rows[3])),
				Vector4(Vector4::DotProduct(rows[1], tNext.rows[0]), Vector4::DotProduct(rows[1], tNext.rows[1]), Vector4::DotProduct(rows[1], tNext.rows[2]), Vector4::DotProduct(rows[1], tNext.rows[3])),
				Vector4(Vector4::DotProduct(rows[2], tNext.rows[0]), Vector4::DotProduct(rows[2], tNext.rows[1]), Vector4::DotProduct(rows[2], tNext.rows[2]), Vector4::DotProduct(rows[2], tNext.rows[3])),
				Vector4(Vector4::DotProduct(rows[3], tNext.rows[0]), Vector4::DotProduct(rows[3], tNext.rows[1]), Vector4::DotProduct(rows[3], tNext.rows[2]), Vector4::DotProduct(rows[3], tNext.rows[3]))
			);
		}

		Matrix4x3 Matrix4x4::operator*(Matrix4x3 next) {

			Matrix3x4 tNext = next.Transpose();

			return Matrix4x3(
				Vector3(Vector4::DotProduct(rows[0], tNext.rows[0]), Vector4::DotProduct(rows[0], tNext.rows[1]), Vector4::DotProduct(rows[0], tNext.rows[2])),
				Vector3(Vector4::DotProduct(rows[1], tNext.rows[0]), Vector4::DotProduct(rows[1], tNext.rows[1]), Vector4::DotProduct(rows[1], tNext.rows[2])),
				Vector3(Vector4::DotProduct(rows[2], tNext.rows[0]), Vector4::DotProduct(rows[2], tNext.rows[1]), Vector4::DotProduct(rows[2], tNext.rows[2])),
				Vector3(Vector4::DotProduct(rows[3], tNext.rows[0]), Vector4::DotProduct(rows[3], tNext.rows[1]), Vector4::DotProduct(rows[3], tNext.rows[2]))
			);
		}

		Matrix4x2 Matrix4x4::operator*(Matrix4x2 next) {

			Matrix2x4 tNext = next.Transpose();

			return Matrix4x2(
				Vector2(Vector4::DotProduct(rows[0], tNext.rows[0]), Vector4::DotProduct(rows[0], tNext.rows[1])),
				Vector2(Vector4::DotProduct(rows[1], tNext.rows[0]), Vector4::DotProduct(rows[1], tNext.rows[1])),
				Vector2(Vector4::DotProduct(rows[2], tNext.rows[0]), Vector4::DotProduct(rows[2], tNext.rows[1])),
				Vector2(Vector4::DotProduct(rows[3], tNext.rows[0]), Vector4::DotProduct(rows[3], tNext.rows[1]))
			);
		}

		CVector4 Matrix4x4::operator*(CVector4 next) {

			Vector4 tNext = next.Transpose();

			return CVector4(
				Vector4::DotProduct(tNext, rows[0]),
				Vector4::DotProduct(tNext, rows[1]),
				Vector4::DotProduct(tNext, rows[2]),
				Vector4::DotProduct(tNext, rows[3])
			);
		}

	}

}