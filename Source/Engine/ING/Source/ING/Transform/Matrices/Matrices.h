#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Math
 */
#include <ING/Math/Math.h>

using namespace ING::Math;



/**
 *	Include Reflection
 */
#include <ING/Reflection/Reflection.h>

using namespace ING::Reflection;



namespace ING {

	struct ING_API S_TransformM : public S_Object
	{

		ING_REFLECT_STRUCT(S_TransformM, S_Object)



		/**
		 *	Constructors And Destructor
		 */
	public:
		S_TransformM	();
		~S_TransformM	();



		/**
		 *	Properties
		 */
	public:
		RMatrix4x4	translationMatrix;
		RMatrix4x4	scaleMatrix;
		RMatrix4x4	rotationMatrix;
		RMatrix4x4	localMatrix;
		RMatrix4x4	worldMatrix;

	};

}