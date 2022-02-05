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



		struct ING_API Float4 {

			/**
			 *	Constructors And Destructor
			 */
		public:
			Float4	(Vector4	v);

			Float4	(Vector3	v);

			Float4	(Vector2	v);

			Float4	(float		v);

			Float4	();

			~Float4	();



			/**
			 *	Properties
			 */
		public:
			float factors[4];



			/**
			 *	Operators
			 */
		public:
			Float4 operator*(Float4 next);

		};

	}

}