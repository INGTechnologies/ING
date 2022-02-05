#pragma once

/**
 *	Include Entry Point
 */
#include <ING/EntryPoint/EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Vector
 */
#include <ING/Math/Vector/Vector.h>



/**
 *	Include Matrix
 */
#include <ING/Math/Matrix/Matrix.h>



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
		struct CVector4;
		struct CVector4;

		struct Vector2;
		struct Vector3;
		struct Vector4;



		struct ING_API F4IJK {

			/**
			 *	Constructors And Destructor
			 */
		public:
			F4IJK	(Vector4	v);

			F4IJK	(Vector3	v);

			F4IJK	(Vector2	v);

			F4IJK	(float		v);

			F4IJK	();

			~F4IJK	();



			/**
			 *	Properties
			 */
		public:
			float factors[4];



			/**
			 *	Operators
			 */
		public:
			F4IJK operator*(F4IJK next);

		};

	}

}