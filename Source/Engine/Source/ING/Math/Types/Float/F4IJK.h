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
#include <ING/Math/Types/Vector/Vector.h>



/**
 *	Include Matrix
 */
#include <ING/Math/Types/Matrix/Matrix.h>



/**
 *	Include Math Type Declares
 */
#include <ING\Math\Types\TypeDeclares.h>



namespace ING {

	namespace Math {

		struct ING_API F4IJK {

			/**
			 *	Constructors And Destructor
			 */
		public:
			F4IJK	(const Vector4&	v);

			F4IJK	(const Vector3&	v);

			F4IJK	(const Vector2&	v);

			F4IJK	(float		v);

			F4IJK	();

			~F4IJK	();



			/**
			 *	Properties
			 */
		public:
			union
			{

				float factors[4];

				struct {

					float w,x,y,z;

				};

			};



			/**
			 *	Operators
			 */
		public:
			F4IJK operator*(const F4IJK& next);

		};

	}

}