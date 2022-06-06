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

	struct ING_API TransformS : public S_Object
	{

		ING_REFLECT_STRUCT(TransformS, S_Object)



		/**
		 *	Constructors And Destructor
		 */
	public:
		TransformS();
		~TransformS();



		/**
		 *	Properties
		 */
	public:
		RVector3	localPosition;
		RVector3	localScale;

	};

}