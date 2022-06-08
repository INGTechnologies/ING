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

	struct ING_API S_TransformS : public S_Object
	{

		ING_REFLECT_STRUCT(S_TransformS, S_Object)



		/**
		 *	Constructors And Destructor
		 */
	public:
		S_TransformS();
		~S_TransformS();



		/**
		 *	Properties
		 */
	public:
		RVector3	localPosition;
		RVector3	localScale;

	};

}